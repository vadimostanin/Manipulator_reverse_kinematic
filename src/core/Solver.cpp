/*
 * Solver.cpp
 *
 *  Created on: Dec 11, 2017
 *      Author: user
 */

#include "Solver.h"
#include "Utils.h"

#include <cmath>
#include <iostream>
#include <cassert>
#include <numeric>
#include <sstream>

Solver::Solver( const ShLegManipulator & manipulator ) : m_manipulator( manipulator )
{
	fillPredefinedDerErrorFunctions();
}

Solver::~Solver()
{
}

void Solver::fillPredefinedDerErrorFunctions()
{
	m_preDefinedDerivativeFunctions.clear();

	DerivativeFuncsStorage funcsStorage;
	funcsStorage.getFunc( m_manipulator->size(), m_preDefinedDerivativeFunctions );

	ErrorFuncStorage errorStorage;
	errorStorage.getFunc( m_manipulator->size(), m_preDefinedErrorFunction );
}

void Solver::initPreSolv( int32_t x, int32_t y, int32_t z )
{
	m_learningRates.clear();
	const size_t legsCount = m_manipulator->size();

	const double deltaAngleMax = m_ratioRadiansPer1PixelError * this->getErrorFunctionValue( x, y, z );
//	const double minError = 0.0000001;
	std::vector<double> errors = forwardv3( x, y, z );
	for( auto error : errors )
	{
//		std::cout << "error=" << error << "; ";
		if( std::isnan( std::abs( error ) ) )
		{
			error = 1;
		}
 		double learningRate = std::abs( deltaAngleMax / error );
		if( learningRate > 0.1 )
		{
			learningRate = 0.1;
		}
		m_learningRates.push_back( learningRate );
	}
//	std::cout << std::endl;

//	printLearningRates();

//	for( size_t leg_i = 0 ; leg_i < legsCount ; leg_i++ )
//	{
//		double expLegI = std::exp(leg_i);
//		double sigmoid = 1 / ( 1 + expLegI );
//		m_learningRates.push_back( 0.001 * sigmoid + 0.001 );
//	}


//	m_learningRates.assign( legsCount, 0.001 );

	m_errors.clear();
	m_errors.assign( legsCount, 0.0 );
}

void Solver::updateLearningRate( const std::vector<double> & currentErrors )
{
	static std::vector<double> prevErrors = currentErrors;

	assert( m_learningRates.size() == currentErrors.size() );

	auto prevErrorIter = std::begin( prevErrors );
	auto currErrorIter = std::begin( currentErrors );
	auto learningRateIter = std::begin( m_learningRates );
	for( ; currErrorIter != std::end( currentErrors ) ; currErrorIter++, prevErrorIter++, learningRateIter++ )
	{
		char prevErrorSign = (*prevErrorIter) / std::abs( (*prevErrorIter) );
		char currErrorSign = (*currErrorIter) / std::abs( (*currErrorIter) );

		if( prevErrorSign != currErrorSign )
		{
			(*learningRateIter) /= 2.0;
		}
	}

	prevErrors = currentErrors;
}

void Solver::initGiNaCVars()
{
	m_ginacXYoZAngles.clear();
	m_ginacXZoYAngles.clear();
	const size_t size = m_manipulator->size();
	for( size_t leg_i = 0; leg_i < size ; leg_i ++ )
	{
		std::string xyAngleName = std::string("angleXY_") + std::to_string( leg_i );
		m_ginacXYoZAngles.emplace_back( std::make_shared<GiNaC::symbol>( xyAngleName ) );

		std::string xzAngleName = std::string("angleXZ_") + std::to_string( leg_i );
		m_ginacXZoYAngles.emplace_back( std::make_shared<GiNaC::symbol>( xzAngleName ) );
	}
}

void Solver::initGiNaCErrorFunction( int32_t targetX, int32_t targetY, int32_t targetZ )
{
	GiNaC::ex exComponentX;
	GiNaC::ex exComponentY;
	GiNaC::ex exComponentZ;
	GiNaC::ex sumXYoZAngles;
	GiNaC::ex sumXZoYAngles;
	GiNaC::ex anglesLengthedOffsettedX;
	GiNaC::ex anglesLengthedOffsettedY;
	GiNaC::ex anglesLengthedOffsettedZ;
//	int accumulativeAngle = 0.0;
	uint32_t leg_i = 0;
	for( const auto & leg : *m_manipulator )
	{
		const auto &symbolXYoZAngle = *m_ginacXYoZAngles[leg_i];
		const auto &symbolXZoYAngle = *m_ginacXZoYAngles[leg_i];

		if( true == leg->getAngleXYEnabled() )
		{
			sumXYoZAngles += symbolXYoZAngle;//angle_1, angle_1 + angle_2, angle_1 + angle_2 + angle_3
		}
		if( true == leg->getAngleXZEnabled() )
		{
			sumXZoYAngles += symbolXZoYAngle;
		}

//		std::cout << "sumAngles=" << sumAngles << std::endl;

		TypePrecision initialX, initialY, initialZ = 0;
		TypePrecision offsetX, offsetY, offsetZ = 0;
		leg->getInitialPosition( initialX, initialY, initialZ );
		leg->getInitialOffsets( offsetX, offsetY, offsetZ );
//		initialX = (int)initialX;
//		initialY = (int)initialY;
//		initialZ = (int)initialZ;

		const int32_t length = leg->getLength();
		{
			GiNaC::ex sumAngleLengthX = length * GiNaC::cos( sumXYoZAngles ) * GiNaC::cos( sumXZoYAngles ) + offsetX;//length * cos( angle_0 ), length * cos( angle_0 + angle_1 ), length * cos( angle_0 + angle_1 + angle_2 )

//			std::cout << "sumAngleLength=" << sumAngleLengthX << std::endl;

			GiNaC::ex currAngleLengthX = sumAngleLengthX;

			if( leg_i == 0 )
			{
				currAngleLengthX += initialX;
			}

//			std::cout << "currAngleLength=" << currAngleLengthX << std::endl;

			anglesLengthedOffsettedX += currAngleLengthX;

			std::cout << "anglesLengthedOffsettedX=" << anglesLengthedOffsettedX << std::endl;
		}

		{
			GiNaC::ex sumAngleLengthY = length * GiNaC::sin( sumXYoZAngles ) + offsetY;//length * cos( angle_0 ), length * cos( angle_0 + angle_1 ), length * cos( angle_0 + angle_1 + angle_2 )

//			std::cout << "sumAngleLengthY=" << sumAngleLengthY << std::endl;

			GiNaC::ex currAngleLengthY = sumAngleLengthY;

			if( leg_i == 0 )
			{
				currAngleLengthY += initialY;
			}

//			std::cout << "currAngleLengthY=" << currAngleLengthY << std::endl;

			anglesLengthedOffsettedY += currAngleLengthY;

//			std::cout << "anglesLengthedOffsettedY=" << anglesLengthedOffsettedY << std::endl;
		}

		{
			GiNaC::ex sumAngleLengthZ = length * GiNaC::cos( sumXYoZAngles ) * GiNaC::sin( sumXZoYAngles ) + offsetZ;//length * cos( angle_0 ), length * cos( angle_0 + angle_1 ), length * cos( angle_0 + angle_1 + angle_2 )

//			std::cout << "sumAngleLengthY=" << sumAngleLengthY << std::endl;

			GiNaC::ex currAngleLengthZ = sumAngleLengthZ;

			if( leg_i == 0 )
			{
				currAngleLengthZ += initialZ;
			}

//			std::cout << "currAngleLengthY=" << currAngleLengthY << std::endl;

			anglesLengthedOffsettedZ += currAngleLengthZ;

//			std::cout << "anglesLengthedOffsettedY=" << anglesLengthedOffsettedY << std::endl;
		}


//		const double angle = leg->getAngle();
//		const double radian = Utils::deg2Rad( angle );
//		accumulativeAngle += angle;




		leg_i++;
	}

	exComponentX = anglesLengthedOffsettedX - targetX;
//	std::cout << "exComponentX=" << exComponentX << std::endl;

	exComponentY = anglesLengthedOffsettedY - targetY;
//	std::cout << "exComponentY=" << exComponentY << std::endl;

	exComponentZ = anglesLengthedOffsettedZ - targetZ;
//	std::cout << "exComponentZ=" << exComponentZ << std::endl;

	GiNaC::ex errorFunction = GiNaC::sqrt( GiNaC::pow( exComponentX, 2 ) + GiNaC::pow( exComponentY, 2 ) + GiNaC::pow( exComponentZ, 2 ) );//GiNaC::sqrt( GiNaC::pow( 100 * GiNaC::cos( angle_0 ) + 200 - 258, 2 ) + GiNaC::pow( 100 * GiNaC::sin( angle_0 ) + 200 - 279, 2 ) );
	std::cout << "errorFunction=" << errorFunction << std::endl;
	m_errorFunction = errorFunction;

	m_errorDerivativeFunctions.clear();

	auto angleXYSymbolIter = std::begin( m_ginacXYoZAngles );
	auto angleXZSymbolIter = std::begin( m_ginacXZoYAngles );
	for( size_t leg_i = 0 ; leg_i < m_manipulator->size() ; leg_i++, angleXYSymbolIter++, angleXZSymbolIter++ )
	{
		{
			GiNaC::ex derivative = errorFunction.diff( **angleXYSymbolIter, 1 );
	//		std::cout << "derivative=" << derivative << std::endl;
			m_errorDerivativeFunctions.emplace_back( derivative );
		}
		{
			GiNaC::ex derivative = errorFunction.diff( **angleXZSymbolIter, 1 );
	//		std::cout << "derivative=" << derivative << std::endl;
			m_errorDerivativeFunctions.emplace_back( derivative );
		}
	}
}

std::string Solver::generateErroFunctionDerivatives()
{
	GiNaC::ex exComponentX;
	GiNaC::ex exComponentY;
	GiNaC::ex exComponentZ;

	GiNaC::ex sumXYAngles;
	GiNaC::ex sumXZAngles;
	GiNaC::ex anglesLengthedOffsettedX;
	GiNaC::ex anglesLengthedOffsettedY;
	GiNaC::ex anglesLengthedOffsettedZ;

	GiNaC::symbol symbolTargetX( "targetX" );
	GiNaC::symbol symbolTargetY( "targetY" );
	GiNaC::symbol symbolTargetZ( "targetZ" );

	GiNaC::symbol symbolInitialX( "initialX" );
	GiNaC::symbol symbolInitialY( "initialY" );
	GiNaC::symbol symbolInitialZ( "initialZ" );

	GiNaC::symbol symbolInitialOffsetX( "initialOffsetX" );
	GiNaC::symbol symbolInitialOffsetY( "initialOffsetY" );
	GiNaC::symbol symbolInitialOffsetZ( "initialOffsetZ" );

//	int accumulativeAngle = 0.0;

	initGiNaCVars();

	const size_t legsCount = m_manipulator->size();
	for( size_t leg_i = 0 ; leg_i < legsCount ; leg_i++ )
	{
		const auto &symbolXYAngle = *m_ginacXYoZAngles[leg_i];
		const auto &symbolXZAngle = *m_ginacXZoYAngles[leg_i];

		sumXYAngles += ( symbolXYAngle );//angle_1, angle_1 + angle_2, angle_1 + angle_2 + angle_3
		sumXZAngles += ( symbolXZAngle );//angle_1, angle_1 + angle_2, angle_1 + angle_2 + angle_3

//		std::cout << "sumAngles=" << sumAngles << std::endl;

		GiNaC::symbol symbolCurrentLength( std::string( "length_" ) + std::to_string( leg_i ) );

		{
			GiNaC::ex sumAngleLengthX = symbolCurrentLength * GiNaC::cos( sumXYAngles ) * GiNaC::cos( sumXZAngles ) + symbolInitialOffsetX;//length * cos( angle_0 ), length * cos( angle_0 + angle_1 ), length * cos( angle_0 + angle_1 + angle_2 )

//			std::cout << "sumAngleLength=" << sumAngleLengthX << std::endl;

			GiNaC::ex currAngleLengthX = sumAngleLengthX;

			if( leg_i == 0 )
			{
				currAngleLengthX += symbolInitialX;
			}

//			std::cout << "currAngleLength=" << currAngleLengthX << std::endl;

			anglesLengthedOffsettedX += currAngleLengthX;

			std::cout << "anglesLengthedOffsettedX=" << anglesLengthedOffsettedX << std::endl;
		}

		{
			GiNaC::ex sumAngleLengthY = symbolCurrentLength * GiNaC::sin( sumXYAngles ) + symbolInitialOffsetY;//length * cos( angle_0 ), length * cos( angle_0 + angle_1 ), length * cos( angle_0 + angle_1 + angle_2 )

//			std::cout << "sumAngleLengthY=" << sumAngleLengthY << std::endl;

			GiNaC::ex currAngleLengthY = sumAngleLengthY;

			if( leg_i == 0 )
			{
				currAngleLengthY += symbolInitialY;
			}

//			std::cout << "currAngleLengthY=" << currAngleLengthY << std::endl;

			anglesLengthedOffsettedY += currAngleLengthY;

//			std::cout << "anglesLengthedOffsettedY=" << anglesLengthedOffsettedY << std::endl;
		}

		{
			GiNaC::ex sumAngleLengthZ = symbolCurrentLength * GiNaC::cos( sumXYAngles ) * GiNaC::sin( sumXZAngles ) + symbolInitialOffsetZ;//length * cos( angle_0 ), length * cos( angle_0 + angle_1 ), length * cos( angle_0 + angle_1 + angle_2 )

//			std::cout << "sumAngleLengthY=" << sumAngleLengthY << std::endl;

			GiNaC::ex currAngleLengthZ = sumAngleLengthZ;

			if( leg_i == 0 )
			{
				currAngleLengthZ += symbolInitialZ;
			}

//			std::cout << "currAngleLengthY=" << currAngleLengthY << std::endl;

			anglesLengthedOffsettedZ += currAngleLengthZ;

//			std::cout << "anglesLengthedOffsettedY=" << anglesLengthedOffsettedY << std::endl;
		}
	}

	exComponentX = anglesLengthedOffsettedX - symbolTargetX;
	std::cout << "exComponentX=" << exComponentX << std::endl;

	exComponentY = anglesLengthedOffsettedY - symbolTargetY;
//	std::cout << "exComponentY=" << exComponentY << std::endl;

	exComponentZ = anglesLengthedOffsettedZ - symbolTargetZ;
//	std::cout << "exComponentZ=" << exComponentZ << std::endl;

	GiNaC::ex errorFunction = GiNaC::sqrt( GiNaC::pow( exComponentX, 2 ) + GiNaC::pow( exComponentY, 2 ) + GiNaC::pow( exComponentZ, 2 ) );//GiNaC::sqrt( GiNaC::pow( 100 * GiNaC::cos( angle_0 ) + 200 - 258, 2 ) + GiNaC::pow( 100 * GiNaC::sin( angle_0 ) + 200 - 279, 2 ) );

	std::stringstream sErrorFunction;
	{
		size_t anglesCount = m_ginacXYoZAngles.size();

//		std::cout << "derivative=" << derivative << std::endl;

		sErrorFunction << "\n";
		sErrorFunction << "double error_Legs_" + std::to_string( anglesCount ) + "( std::vector<double> & params )\n";
		sErrorFunction << "{\n";
		sErrorFunction << "\tassert( params.size() == " + std::to_string( m_ginacXYoZAngles.size() * 4 + 9 ) + " );\n\n";
		sErrorFunction << "\tdouble initialX       = params[ 0 ];\n";
		sErrorFunction << "\tdouble initialY       = params[ 1 ];\n";
		sErrorFunction << "\tdouble initialZ       = params[ 2 ];\n";
		sErrorFunction << "\tdouble initialOffsetX = params[ 3 ];\n";
		sErrorFunction << "\tdouble initialOffsetY = params[ 4 ];\n";
		sErrorFunction << "\tdouble initialOffsetZ = params[ 5 ];\n";
		sErrorFunction << "\tdouble targetX        = params[ 6 ];\n";
		sErrorFunction << "\tdouble targetY        = params[ 7 ];\n";
		sErrorFunction << "\tdouble targetZ        = params[ 8 ];\n";

		for( size_t angle_i = 0 ; angle_i < anglesCount ; angle_i++ )
		{
			sErrorFunction << "\tdouble length_" + std::to_string( angle_i ) + " = params[ 9 + " + std::to_string( angle_i * 4 + 0 ) + " ];\n";
			sErrorFunction << "\tdouble angleXY_" + std::to_string( angle_i ) + " = params[ 9 + " + std::to_string( angle_i * 4 + 1 ) + " ];\n";
			sErrorFunction << "\tdouble angleXZ_" + std::to_string( angle_i ) + " = params[ 9 + " + std::to_string( angle_i * 4 + 2 ) + " ];\n";
			sErrorFunction << "\tdouble angleZY_" + std::to_string( angle_i ) + " = params[ 9 + " + std::to_string( angle_i * 4 + 3 ) + " ];\n";
		}
		sErrorFunction << "\n";
		sErrorFunction << "\tdouble result = " << errorFunction << ";\n";
		sErrorFunction << "\n";
		sErrorFunction << "\treturn result;\n";
		sErrorFunction << "}\n";


		GiNaC::FUNCP_1P fp;
		GiNaC::compile_ex( errorFunction, GiNaC::symbol(), fp, std::string( "error_Legs_" ) + std::to_string( anglesCount ) + ".txt" );
	}


//	std::cout << "errorFunction=" << errorFunction << std::endl;

	std::stringstream sDerivates;
	{
		size_t anglesCount = m_ginacXYoZAngles.size();
		auto angleSymbolIter = std::begin( m_ginacXYoZAngles );
		uint32_t leg_i = 0;
		for( ; angleSymbolIter != std::end( m_ginacXYoZAngles ) ; angleSymbolIter++, leg_i++ )
		{
			GiNaC::ex derivative = errorFunction.diff( **angleSymbolIter, 1 );
	//		std::cout << "derivative=" << derivative << std::endl;

			sDerivates << "\n";
			sDerivates << "double derivative_XY_" + std::to_string( legsCount ) + "_Legs_" + std::to_string( leg_i ) + "( std::vector<double> & params )\n";
			sDerivates << "{\n";
			sDerivates << "\tassert( params.size() == " + std::to_string( m_ginacXYoZAngles.size() * 4 + 9 ) + " );\n\n";
			sDerivates << "\tdouble initialX       = params[ 0 ];\n";
			sDerivates << "\tdouble initialY       = params[ 1 ];\n";
			sDerivates << "\tdouble initialZ       = params[ 2 ];\n";
			sDerivates << "\tdouble initialOffsetX = params[ 3 ];\n";
			sDerivates << "\tdouble initialOffsetY = params[ 4 ];\n";
			sDerivates << "\tdouble initialOffsetZ = params[ 5 ];\n";
			sDerivates << "\tdouble targetX        = params[ 6 ];\n";
			sDerivates << "\tdouble targetY        = params[ 7 ];\n";
			sDerivates << "\tdouble targetZ        = params[ 8 ];\n";

			for( size_t angle_i = 0 ; angle_i < anglesCount ; angle_i++ )
			{
				sDerivates << "\tdouble length_" + std::to_string( angle_i ) + " = params[ 9 + " + std::to_string( angle_i * 4 + 0 ) + " ];\n";
				sDerivates << "\tdouble angleXY_" + std::to_string( angle_i ) + " = params[ 9 + " + std::to_string( angle_i * 4 + 1 ) + " ];\n";
				sDerivates << "\tdouble angleXZ_" + std::to_string( angle_i ) + " = params[ 9 + " + std::to_string( angle_i * 4 + 2 ) + " ];\n";
				sDerivates << "\tdouble angleZY_" + std::to_string( angle_i ) + " = params[ 9 + " + std::to_string( angle_i * 4 + 3 ) + " ];\n";
			}
			sDerivates << "\n";
			sDerivates << "\tdouble result = " << derivative << ";\n";
			sDerivates << "\n";
			sDerivates << "\treturn result;\n";
			sDerivates << "}\n";


			GiNaC::FUNCP_1P fp;
			GiNaC::compile_ex( derivative, GiNaC::symbol(), fp, std::string( "derivative_XY_" ) + std::to_string( leg_i ) + ".txt" );

		}
	}
	{
		size_t anglesCount = m_ginacXZoYAngles.size();
		auto angleSymbolIter = std::begin( m_ginacXZoYAngles );
		uint32_t leg_i = 0;
		for( ; angleSymbolIter != std::end( m_ginacXZoYAngles ) ; angleSymbolIter++, leg_i++ )
		{
			GiNaC::ex derivative = errorFunction.diff( **angleSymbolIter, 1 );
	//		std::cout << "derivative=" << derivative << std::endl;

			sDerivates << "\n";
			sDerivates << "double derivative_XZ_" + std::to_string( legsCount ) + "_Legs_" + std::to_string( leg_i ) + "( std::vector<double> & params )\n";
			sDerivates << "{\n";
			sDerivates << "\tassert( params.size() == " + std::to_string( m_ginacXZoYAngles.size() * 4 + 9 ) + " );\n\n";
			sDerivates << "\tdouble initialX       = params[ 0 ];\n";
			sDerivates << "\tdouble initialY       = params[ 1 ];\n";
			sDerivates << "\tdouble initialZ       = params[ 2 ];\n";
			sDerivates << "\tdouble initialOffsetX = params[ 3 ];\n";
			sDerivates << "\tdouble initialOffsetY = params[ 4 ];\n";
			sDerivates << "\tdouble initialOffsetZ = params[ 5 ];\n";
			sDerivates << "\tdouble targetX        = params[ 6 ];\n";
			sDerivates << "\tdouble targetY        = params[ 7 ];\n";
			sDerivates << "\tdouble targetZ        = params[ 8 ];\n";

			for( size_t angle_i = 0 ; angle_i < anglesCount ; angle_i++ )
			{
				sDerivates << "\tdouble length_" + std::to_string( angle_i ) + " = params[ 9 + " + std::to_string( angle_i * 4 + 0 ) + " ];\n";
				sDerivates << "\tdouble angleXY_" + std::to_string( angle_i ) + " = params[ 9 + " + std::to_string( angle_i * 4 + 1 ) + " ];\n";
				sDerivates << "\tdouble angleXZ_" + std::to_string( angle_i ) + " = params[ 9 + " + std::to_string( angle_i * 4 + 2 ) + " ];\n";
				sDerivates << "\tdouble angleZY_" + std::to_string( angle_i ) + " = params[ 9 + " + std::to_string( angle_i * 4 + 3 ) + " ];\n";
			}
			sDerivates << "\n";
			sDerivates << "\tdouble result = " << derivative << ";\n";
			sDerivates << "\n";
			sDerivates << "\treturn result;\n";
			sDerivates << "}\n";



			GiNaC::FUNCP_1P fp;
			GiNaC::compile_ex( derivative, GiNaC::symbol(), fp, std::string( "derivative_XZ_" ) + std::to_string( leg_i ) + ".txt" );

		}
	}




	return std::move( sErrorFunction.str() + sDerivates.str() );
}

void Solver::printLearningRates()
{
	uint32_t rate_i = 0;
	for( const auto rate : this->m_learningRates )
	{
		std::cout << "rate_" << rate_i << "=" << rate << "; ";
		rate_i++;
	}
	std::cout << std::endl;
}

void Solver::shuffleLegs()
{
	try
	{
		shuffleReverseIncrementLegs( m_manipulator->size() );
	}
	catch( std::exception & ex )
	{
		assert( false );// catch in debug mode
		int a = 0;
		a++;
	}
}

void Solver::shuffleLeg( const ShLeg & leg )
{

	double angleXYMin, angleXYMax, angleXZMin, angleXZMax;
	leg->getAngleXYLimits( angleXYMin, angleXYMax );
	leg->getAngleXZLimits( angleXZMin, angleXZMax );

	const int32_t angleBandWidthXY = ( (int)angleXYMax - (int)angleXYMin );
	double angleXY = 0.0;
	if( 0 != angleBandWidthXY )
	{
		const int32_t random = rand();
		angleXY = angleXYMin + random % angleBandWidthXY;
		leg->setAngleXY( angleXY );
	}

	const int32_t angleBandWidthXZ = ( (int)angleXZMax - (int)angleXZMin );
	double angleXZ = 0.0;
	if( 0 != angleBandWidthXZ )
	{
		const int32_t random = rand();
		angleXZ = angleXZMin + random % angleBandWidthXZ;
		leg->setAngleXZ( angleXZ );
	}
}

void Solver::shuffleReverseIncrementLegs( uint32_t legsCount )
{
	assert( legsCount <= m_manipulator->size());
	try
	{
		auto legIt = ( *m_manipulator ).rbegin();
		auto legEndIt = ( *m_manipulator ).rbegin() + legsCount;
		for( ; legIt != legEndIt ; legIt++ )
		{
			shuffleLeg( *legIt );
		}
	}
	catch( std::exception & ex )
	{
		assert( false );// catch in debug mode
		int a = 0;
		a++;
	}
}

void Solver::solveFromCurrent( int32_t x, int32_t y, int32_t z, double epsilon, uint32_t maxSteps, SolveEndCb cbPerStep )
{
//	int size = m_manipulator->size();
//	initGiNaCVars();
//	initGiNaCErrorFunction( x, y, z );
	std::vector<double> errorCurrent;
	std::vector<double> errorPrev;

	initPreSolv( x, y, z );

//	double accumulatedCurrentError = 0.0;
//	double accumulatedPrevError = 0.0;
	uint32_t stepsCounter = 0;
//	printLearningRates();
	do
	{
		errorPrev = errorCurrent;
		errorCurrent = oneStep( x, y, z );
//		errorCurrent = oneStepV2( x, y, z );

//		accumulatedPrevError = accumulatedCurrentError;
//		accumulatedCurrentError = std::accumulate( std::begin( errorCurrent ), std::end( errorCurrent ), 0.0 );

		stepsCounter++;
//		std::cout << "accumulatedCurrentError=" << accumulatedCurrentError << std::endl;
	}
	while( /*std::abs( accumulatedPrevError - accumulatedCurrentError ) >= epsilon && */ getErrorFunctionValue( x, y, z ) >= epsilon &&
		   stepsCounter < maxSteps );


	cbPerStep( getError() );

	std::cout << "stepsCounter=" << stepsCounter << std::endl;
//	printLearningRates();
//	std::cout << std::endl << std::endl;
}

void Solver::solvePerpendicular( int32_t x, int32_t y, int32_t z, double angle, double epsilon, uint32_t maxSteps, SolveEndCb cbPerStep )
{
	const auto & lastLeg = m_manipulator->back();
	uint32_t lastLegLength = lastLeg->getLength();
	int32_t withoutLastLegX = x + lastLegLength * std::cos( Utils::deg2Rad( angle - 90 ) );
	int32_t withoutLastLegY = y + lastLegLength * std::sin( Utils::deg2Rad( angle - 90 ) );
	int32_t withoutLastLegZ = 0;


	ShLegManipulator legsOrigin = m_manipulator;
	ShLegManipulator legMinusLast = std::make_shared<LegManipulator>( std::begin( *m_manipulator ), std::prev( std::end( *m_manipulator ) ) );
	m_manipulator = legMinusLast;

	fillPredefinedDerErrorFunctions();
	initPreSolv( x, y, z );
	solveFromCurrent( withoutLastLegX, withoutLastLegY, withoutLastLegZ, epsilon, maxSteps, cbPerStep );

	double lastLegAccumulativeAngle = lastLeg->getAccumulativeParentAngleXY();
	double lastLegAngle = lastLegAccumulativeAngle - 90;// angle + 90 + lastLegAccumulativeAngle
	double normalLastLegAngle = ( (int)( lastLegAngle / 360 ) ) * 360 - lastLegAngle + angle;
	lastLeg->setAngleXY( normalLastLegAngle );

//	std::cout << "normalLastLegAngle=" << normalLastLegAngle << std::endl;

	m_manipulator.reset();
	m_manipulator = legsOrigin;
	fillPredefinedDerErrorFunctions();
	initPreSolv( x, y, z );
}

void Solver::solveContiniouslyShuffling( int32_t x, int32_t y, int32_t z, double epsilon, uint32_t maxStepsPerSolving, uint32_t maxSolvingCount, SolveEndCb cbPerStep )
{
	solveFromCurrent( x, y, z, epsilon, maxStepsPerSolving );

	double distance = getErrorFunctionValue( x, y, z );
	uint32_t solvingCounter = 0;
	while( distance > m_minEcceptableDistance && solvingCounter < maxSolvingCount )
	{
	    shuffleLegs();
	    solveFromCurrent( x, y, z, epsilon, maxStepsPerSolving );

	    distance = getErrorFunctionValue( x, y, z );

	    solvingCounter++;
	}
	cbPerStep( getError() );
}

void Solver::solvePerpendicularShuffling( int32_t x, int32_t y, int32_t z, double angle, double epsilon, uint32_t maxStepsPerSolving, uint32_t maxSolvingCount, SolveEndCb cbPerStep )
{
	solvePerpendicular( x, y, z, angle, epsilon, maxStepsPerSolving );

	double distance = getErrorFunctionValue( x, y, z );
	uint32_t solvingCounter = 0;
	while( distance > m_minEcceptableDistance && solvingCounter < maxSolvingCount )
	{
	    shuffleLegs();
	    solvePerpendicular( x, y, z, angle, epsilon, maxStepsPerSolving );

	    distance = getErrorFunctionValue( x, y, z );

	    solvingCounter++;
	}
	cbPerStep( getError() );
}

void Solver::solveContiniouslyShufflingLessError( int32_t x, int32_t y, int32_t z, double epsilon, uint32_t maxStepsPerSolving, uint32_t maxSolvingCount, SolveEndCb cbPerStep )
{
	std::vector<ShLegManipulator> solvedManipulators;

	ShLegManipulator originManipulator = m_manipulator;

	ShLegManipulator clonedManipulator = originManipulator->clone();

	setCurrentManipulator( clonedManipulator );

	solveFromCurrent( x, y, z, epsilon, maxStepsPerSolving, empty );
	if( getErrorFunctionValue( x, y, z ) < m_minEcceptableDistance && isPathPossble( originManipulator, clonedManipulator ) )
	{
		solvedManipulators.push_back( clonedManipulator );
	}


	for( uint32_t solv_i = 1 ; solv_i < maxSolvingCount ; solv_i++ )
	{
		ShLegManipulator clonedManipulator = originManipulator->clone();
		setCurrentManipulator( clonedManipulator );
		shuffleLegs();
		solveFromCurrent( x, y, z, epsilon, maxStepsPerSolving, empty );
		if( getErrorFunctionValue( x, y, z ) < m_minEcceptableDistance && isPathPossble( originManipulator, clonedManipulator ) )
		{
			solvedManipulators.push_back( clonedManipulator );
		}
	}

	std::sort( std::begin( solvedManipulators ), std::end( solvedManipulators ),
			[&]( const ShLegManipulator & right, const ShLegManipulator & left )
			{
				TypePrecision rightFinalX, rightFinalY, rightFinalZ;
				TypePrecision leftFinalX, leftFinalY, leftFinalZ;
				right->getLastLeg()->getCalulatedFinalPosition( rightFinalX, rightFinalY, rightFinalZ );

				left->getLastLeg()->getCalulatedFinalPosition( leftFinalX, leftFinalY, leftFinalZ );

				double rightDistance = Utils::distance( rightFinalX, rightFinalY, rightFinalZ, x, y, z );

				double leftDistance = Utils::distance( leftFinalX, leftFinalY, leftFinalZ, x, y, z );

				return rightDistance < leftDistance;
			}
	);

	originManipulator->deepAssign( solvedManipulators[0] );

	setCurrentManipulator( originManipulator );
}

void Solver::solveContiniouslyShufflingLessAngle( int32_t x, int32_t y, int32_t z, double epsilon, uint32_t maxStepsPerSolving, uint32_t maxSolvingCount, SolveEndCb cbPerStep )
{
	std::vector<ShLegManipulator> solvedManipulators;

	ShLegManipulator originManipulator = m_manipulator;

	ShLegManipulator clonedManipulator = originManipulator->clone();

	setCurrentManipulator( clonedManipulator );

	solveFromCurrent( x, y, z, epsilon, maxStepsPerSolving, empty );
	if( getErrorFunctionValue( x, y, z ) < m_minEcceptableDistance && isPathPossble( originManipulator, clonedManipulator ) )
	{
		solvedManipulators.push_back( clonedManipulator );
	}


	for( uint32_t solv_i = 1 ; solv_i < maxSolvingCount ; solv_i++ )
	{
		ShLegManipulator clonedManipulator = originManipulator->clone();
		setCurrentManipulator( clonedManipulator );
		shuffleLegs();
		solveFromCurrent( x, y, z, epsilon, maxStepsPerSolving, empty );
		if( getErrorFunctionValue( x, y, z ) < m_minEcceptableDistance && isPathPossble( originManipulator, clonedManipulator ) )
		{
			solvedManipulators.push_back( clonedManipulator );
		}
	}

	std::sort( std::begin( solvedManipulators ), std::end( solvedManipulators ),
			[&]( const ShLegManipulator & right, const ShLegManipulator & left )
			{
				double rigthDiffAngles = 0.0;
				std::for_each( std::begin( *right ), std::end( *right ), [&]( ShLeg & shLeg )
				{
					double originAngle = originManipulator->getLeg( shLeg->getLevel() )->getAngleXY();
					double rightAngle = shLeg->getAngleXY();

					rigthDiffAngles += std::abs( std::abs( originAngle ) - std::abs( rightAngle ) );
				});

				double leftDiffAngles = 0.0;
				std::for_each( std::begin( *left ), std::end( *left ), [&]( ShLeg & shLeg )
				{
					double originAngle = originManipulator->getLeg( shLeg->getLevel() )->getAngleXY();
					double leftAngle = shLeg->getAngleXY();

					leftDiffAngles += std::abs( std::abs( originAngle ) - std::abs( leftAngle ) );
				});

				return rigthDiffAngles < leftDiffAngles;
			}
	);

	uint32_t manipulator_i = 0;
	std::for_each( std::begin( solvedManipulators ), std::end( solvedManipulators ), [&]( ShLegManipulator & shMan )
			{
				double diffAngle = 0.0;
				std::for_each( std::begin( *shMan ), std::end( *shMan ), [&]( ShLeg & shLeg )
				{
					double originAngle = originManipulator->getLeg( shLeg->getLevel() )->getAngleXY();
					double leftAngle = shLeg->getAngleXY();

					diffAngle += std::abs( std::abs( originAngle ) - std::abs( leftAngle ) );
				});
				std::cout << "manipulator " << manipulator_i << ", diffAngle=" << diffAngle << std::endl;
				manipulator_i++;
			});


	if(false == solvedManipulators.empty())
	{
		originManipulator->deepAssign( solvedManipulators[0] );
	}

	setCurrentManipulator( originManipulator );
}

void Solver::solveContIterShufLessAngle( int32_t x, int32_t y, int32_t z, double epsilon, int32_t maxStepsPerSolving, SolveEndCb cbPerStep )
{
	std::vector<ShLegManipulator> solvedManipulators;

	ShLegManipulator originManipulator = m_manipulator;

	ShLegManipulator clonedManipulator = originManipulator->clone();

	setCurrentManipulator( clonedManipulator );

	solveFromCurrent( x, y, z, epsilon, maxStepsPerSolving, empty );
	if( getErrorFunctionValue( x, y, z ) < m_minEcceptableDistance && isPathPossble( originManipulator, clonedManipulator ) )
	{
		solvedManipulators.push_back( clonedManipulator );
	}

	const uint32_t legCount = m_manipulator->size();
	for( uint32_t leg_i = 0 ; leg_i < legCount ; leg_i++ )
	{
		for( uint32_t i = 0 ; i < 2 ; i ++ )
		{
			ShLegManipulator clonedManipulator = originManipulator->clone();
			setCurrentManipulator( clonedManipulator );
			const uint32_t legFromEnd = legCount - leg_i - 1;
			shuffleLeg( (*m_manipulator)[legFromEnd] );
			solveFromCurrent( x, y, z, epsilon, maxStepsPerSolving, empty );
			if( getErrorFunctionValue( x, y, z ) < m_minEcceptableDistance && isPathPossble( originManipulator, clonedManipulator ) )
			{
				solvedManipulators.push_back( clonedManipulator );
			}
		}
		for( uint32_t i = 0 ; i < 2 ; i ++ )
		{
			ShLegManipulator clonedManipulator = originManipulator->clone();
			setCurrentManipulator( clonedManipulator );
			const uint32_t legsCount = leg_i + 1;
			shuffleReverseIncrementLegs( legsCount );
			solveFromCurrent( x, y, z, epsilon, maxStepsPerSolving, empty );
			if( getErrorFunctionValue( x, y, z ) < m_minEcceptableDistance && isPathPossble( originManipulator, clonedManipulator ) )
			{
				solvedManipulators.push_back( clonedManipulator );
			}
		}
	}

	std::sort( std::begin( solvedManipulators ), std::end( solvedManipulators ),
			[&]( const ShLegManipulator & right, const ShLegManipulator & left )
			{
				double rigthDiffAngles = 0.0;
				std::for_each( std::begin( *right ), std::end( *right ), [&]( ShLeg & shLeg )
				{
					double originAngle = originManipulator->getLeg( shLeg->getLevel() )->getAngleXY();
					double rightAngle = shLeg->getAngleXY();

					rigthDiffAngles += std::abs( std::abs( originAngle ) - std::abs( rightAngle ) );
				});

				double leftDiffAngles = 0.0;
				std::for_each( std::begin( *left ), std::end( *left ), [&]( ShLeg & shLeg )
				{
					double originAngle = originManipulator->getLeg( shLeg->getLevel() )->getAngleXY();
					double leftAngle = shLeg->getAngleXY();

					leftDiffAngles += std::abs( std::abs( originAngle ) - std::abs( leftAngle ) );
				});

				return rigthDiffAngles < leftDiffAngles;
			}
	);

	uint32_t manipulator_i = 0;
	std::for_each( std::begin( solvedManipulators ), std::end( solvedManipulators ), [&]( ShLegManipulator & shMan )
			{
				double diffAngle = 0.0;
				std::for_each( std::begin( *shMan ), std::end( *shMan ), [&]( ShLeg & shLeg )
				{
					double originAngle = originManipulator->getLeg( shLeg->getLevel() )->getAngleXY();
					double leftAngle = shLeg->getAngleXY();

					diffAngle += std::abs( std::abs( originAngle ) - std::abs( leftAngle ) );
				});
				std::cout << "manipulator " << manipulator_i << ", diffAngle=" << diffAngle << std::endl;
				manipulator_i++;
			});


	if(false == solvedManipulators.empty())
	{
		originManipulator->deepAssign( solvedManipulators[0] );
	}

	setCurrentManipulator( originManipulator );
}

void Solver::solveContIterShuf( int32_t x, int32_t y, int32_t z, double epsilon, int32_t maxStepsPerSolving, SolveEndCb cbPerStep )
{
	std::vector<ShLegManipulator> solvedManipulators;

	ShLegManipulator originManipulator = m_manipulator;

	bool manipulatorFound = false;

	do
	{
		ShLegManipulator clonedManipulator = originManipulator->clone();

		setCurrentManipulator( clonedManipulator );

		solveFromCurrent( x, y, z, epsilon, maxStepsPerSolving, empty );
		if( getErrorFunctionValue( x, y, z ) < m_minEcceptableDistance && isPathPossble( originManipulator, clonedManipulator ) )
		{
			manipulatorFound = true;
			break;
		}

		const uint32_t legCount = m_manipulator->size();
		for( uint32_t leg_i = 0 ; leg_i < legCount ; leg_i++ )
		{
			if( true == manipulatorFound )
			{
				break;
			}
			for( uint32_t i = 0 ; i < 2 ; i ++ )
			{
				ShLegManipulator clonedManipulator = originManipulator->clone();
				setCurrentManipulator( clonedManipulator );
				const uint32_t legFromEnd = legCount - leg_i - 1;
				shuffleLeg( (*m_manipulator)[legFromEnd] );
				solveFromCurrent( x, y, z, epsilon, maxStepsPerSolving, empty );
				if( getErrorFunctionValue( x, y, z ) < m_minEcceptableDistance && isPathPossble( originManipulator, clonedManipulator ) )
				{
					manipulatorFound = true;
					break;
				}
			}
			if( true == manipulatorFound )
			{
				break;
			}
			for( uint32_t i = 0 ; i < 2 ; i ++ )
			{
				ShLegManipulator clonedManipulator = originManipulator->clone();
				setCurrentManipulator( clonedManipulator );
				const uint32_t legsCount = leg_i + 1;
				shuffleReverseIncrementLegs( legsCount );
				solveFromCurrent( x, y, z, epsilon, maxStepsPerSolving, empty );
				if( getErrorFunctionValue( x, y, z ) < m_minEcceptableDistance && isPathPossble( originManipulator, clonedManipulator ) )
				{
					manipulatorFound = true;
					break;
				}
			}
		}
	}while( false );
	if( true == manipulatorFound )
	{
		originManipulator->deepAssign( m_manipulator );
	}

	setCurrentManipulator( originManipulator );
}

bool Solver::isPathPossble( ShLegManipulator manipulatorFrom, ShLegManipulator manipulatorTo )
{
	assert( manipulatorFrom->size() == manipulatorTo->size() );

	std::cout << __FUNCTION__ << std::endl;

	auto manFromIter = std::begin( *manipulatorFrom );
	auto manToIter = std::begin( *manipulatorTo );
	const auto manToEndIter = std::end( *manipulatorTo );
	const uint32_t stepsCount = 100;
	std::vector<double> anglesDiff;
	for( ; manToIter != manToEndIter ; manToIter++, manFromIter++ )
	{
		const double angleXYDiff = (*manToIter)->getAngleXY() - (*manFromIter)->getAngleXY();
		anglesDiff.push_back( angleXYDiff / stepsCount );

		const double angleXZDiff = (*manToIter)->getAngleXZ() - (*manFromIter)->getAngleXZ();
		anglesDiff.push_back( angleXZDiff / stepsCount );

		const double angleZYDiff = (*manToIter)->getAngleZY() - (*manFromIter)->getAngleZY();
		anglesDiff.push_back( angleZYDiff / stepsCount );
	}

	ShLegManipulator manipulatorSimulated = manipulatorFrom->clone();
	for( uint32_t step_i = 0 ; step_i < stepsCount ; step_i++ )
	{
		manToIter = std::begin( *manipulatorTo );
		manFromIter = std::begin( *manipulatorFrom );
		auto manSimIter = std::begin( *manipulatorSimulated );
		auto anglesDiffIter = std::begin( anglesDiff );
		for( ; manToIter != manToEndIter ; manToIter++, manFromIter++, manSimIter++ )
		{
			(*manSimIter)->setAngleXY( (*manSimIter)->getAngleXY() + (*anglesDiffIter) );
			anglesDiffIter++;

			(*manSimIter)->setAngleXZ( (*manSimIter)->getAngleXZ() + (*anglesDiffIter) );
			anglesDiffIter++;

			(*manSimIter)->setAngleZY( (*manSimIter)->getAngleZY() + (*anglesDiffIter) );
			anglesDiffIter++;
		}
		if( isFinalTooClose( manipulatorSimulated, m_minClosestDistance ) )
		{
			std::cout << "isPathPossble too close" << std::endl;
			return false;
		}
	}

	TypePrecision x, y, z;
	manipulatorTo->getLastLeg()->getCalulatedFinalPosition( x, y, z );

	double error = getErrorFunctionValue( manipulatorSimulated, x, y, z );
	bool pathPossible = false;
	if( error <= m_minEcceptableDistance )
	{
		pathPossible = true;
	}

	return pathPossible;
}

std::vector<double> Solver::oneStep( int32_t x, int32_t y, int32_t z )
{
	m_errors = forwardv3( x, y, z );
	updateLearningRate( m_errors );
	backward( m_errors );
	m_errors = forwardv3( x, y, z );

	return m_errors;
}

std::vector<double> Solver::oneStepV2( int32_t x, int32_t y, int32_t z )
{
	std::vector<double> errorsPerLeg( m_anglesPerLeg );
	const uint32_t legsCount = m_manipulator->size();
	for( uint32_t leg_i = 0 ; leg_i < legsCount ; leg_i++ )
	{
		errorsPerLeg = forwardLegv3( leg_i, x, y, z );
		backwardLeg( leg_i, errorsPerLeg );
	}
	m_errors = forwardv3( x, y, z );
	updateLearningRate( m_errors );

	return m_errors;
}

std::vector<double> Solver::forwardv3( int32_t targetX, int32_t targetY, int32_t targetZ )
{
	std::vector<double> errors( m_manipulator->size() * m_anglesPerLeg, 0.0 );

	assert( m_preDefinedDerivativeFunctions.size() == errors.size() );

//	auto errorIter = std::begin( errors );
	auto errorIter = std::prev( std::end( errors ) );
//	auto derivativeIter = std::begin( m_preDefinedDerivativeFunctions );
	auto derivativeIter = std::prev( std::end( m_preDefinedDerivativeFunctions ) );
	std::vector<double> params;//offsetX, offsetY, targetX, targetY, length * m_leg.size(), angle * m_leg.size()
	fillParams( targetX, targetY, targetZ, params );
//	for( ; derivativeIter != std::end( m_preDefinedDerivativeFunctions ) ; derivativeIter++, errorIter++ )
	for( ; derivativeIter != std::prev( std::begin( m_preDefinedDerivativeFunctions ) ) ; derivativeIter--, errorIter-- )
	{
		(*errorIter) = (*derivativeIter)( params );
//			std::cout << "errorIter=" << (*errorIter) << std::endl;
	}

	return errors;
}

std::vector<double> Solver::forwardLegv3( uint32_t legIndex, int32_t targetX, int32_t targetY, int32_t targetZ )
{
	std::vector<double> errors( m_anglesPerLeg );

	std::vector<double> params;//offsetX, offsetY, targetX, targetY, length * m_leg.size(), angle * m_leg.size()
	fillParams( targetX, targetY, targetZ, params );
	errors[ 0 ] = m_preDefinedDerivativeFunctions[ legIndex * m_anglesPerLeg ]( params );
	errors[ 1 ] = m_preDefinedDerivativeFunctions[ legIndex * m_anglesPerLeg + 1 ]( params );

	return errors;
}

void Solver::fillParams( int32_t targetX, int32_t targetY, int32_t targetZ, std::vector<double> & params )
{
	TypePrecision initialX, initialY, initialZ;
	TypePrecision initialOffsetX, initialOffsetY, initialOffsetZ;
	(*m_manipulator)[0]->getInitialPosition( initialX, initialY, initialZ );
	(*m_manipulator)[0]->getInitialOffsets( initialOffsetX, initialOffsetY, initialOffsetZ );
	initialX = (int)initialX;
	initialY = (int)initialY;
	initialZ = (int)initialZ;
	params.resize( 4 * m_manipulator->size() + 9, 0.0 );
	params[0] = initialX;
	params[1] = initialY;
	params[2] = initialZ;
	params[3] = initialOffsetX;
	params[4] = initialOffsetY;
	params[5] = initialOffsetZ;
	params[6] = targetX;
	params[7] = targetY;
	params[8] = targetZ;
	const size_t legsCount = m_manipulator->size();
	for( size_t leg_i = 0 ; leg_i < legsCount ; leg_i++ )
	{
		const auto & leg = (*m_manipulator)[leg_i];
		params[ 9 + leg_i * 4 + 0 ] = leg->getLength();
		params[ 9 + leg_i * 4 + 1 ] = Utils::deg2Rad( leg->getAngleXY() );
		params[ 9 + leg_i * 4 + 2 ] = Utils::deg2Rad( leg->getAngleXZ() );
		params[ 9 + leg_i * 4 + 3 ] = Utils::deg2Rad( leg->getAngleZY() );
	}
}

std::vector<double> Solver::forwardv2( int32_t expectedX, int32_t expectedY, int32_t expectedZ )
{
	assert( m_ginacXYoZAngles.size() == m_manipulator->size() );

	std::vector<double> errors( m_manipulator->size() * m_anglesPerLeg, 0.0 );//angles XYoZ and angles XZoY

	assert( m_errorDerivativeFunctions.size() == errors.size() );//error of angles XYoZ and angles XZoY

	GiNaC::lst anglesValues;
	auto legIter = std::begin( *m_manipulator );
	auto angleXYSymbolIter = std::begin( m_ginacXYoZAngles );
	auto angleXZSymbolIter = std::begin( m_ginacXZoYAngles );
	for(  ; legIter != std::end( *m_manipulator ) ; legIter++, angleXYSymbolIter++, angleXZSymbolIter++ )
	{
		{
			const double angle = (*legIter)->getAngleXY();
			const double radian = Utils::deg2Rad( angle );

			anglesValues.append( (**angleXYSymbolIter) == radian );
		}
		{
			const double angle = (*legIter)->getAngleXZ();
			const double radian = Utils::deg2Rad( angle );

			anglesValues.append( (**angleXZSymbolIter) == radian );
		}
	}

	GiNaC::ex perLegAngleLength;
	auto errorIter = std::begin( errors );
	auto derivativeIter = std::begin( m_errorDerivativeFunctions );
	for( ; derivativeIter != std::end( m_errorDerivativeFunctions ) ; derivativeIter++, errorIter++ )
	{
		GiNaC::ex f = GiNaC::evalf( (*derivativeIter).subs( anglesValues ) );

		if (GiNaC::is_a<GiNaC::numeric>(f))
		{
			(*errorIter) = GiNaC::ex_to<GiNaC::numeric>(f).to_double();
//			std::cout << "errorIter=" << (*errorIter) << std::endl;
		}
	}

	return errors;
}

std::vector<double> Solver::forwardv1( int32_t expectedX, int32_t expectedY )
{
	std::vector<double> errors;

	double predictedX = 0.0;
	double predictedY = 0.0;

	const int32_t offsetX = 200;
	const int32_t offsetY = 200;

//	const int32_t offsettedExpectedX = expectedX - offsetX;
//	const int32_t offsettedExpectedY = expectedY - offsetY;

	int32_t accumulativeAngle = 0.0;
	for( const auto & leg : *m_manipulator )
	{
		const double angle = leg->getAngleXY();
		const double radian = Utils::deg2Rad( angle );
		const int32_t length = leg->getLength();
		accumulativeAngle += angle;

		double accumulativeRadian = radian;//Utils::deg2Rad( accumulativeAngle );
		predictedX += length * std::cos( accumulativeRadian );
		predictedY += length * std::sin( accumulativeRadian );

		const double deltaX = length*cos(accumulativeRadian) + offsetX - expectedX;
		const double deltaY = length*sin(accumulativeRadian) + offsetY - expectedY;
		const double squaredDistance = deltaX * deltaX + deltaY * deltaY;
		const double distance = std::sqrt( squaredDistance );

		const double numerator =
				( -1 ) * length * offsetX * std::sin(accumulativeRadian)
				+          length * offsetY * std::cos(accumulativeRadian)
				+          length * expectedX * std::sin(accumulativeRadian)
				-          length * expectedY * std::cos(accumulativeRadian);

		errors.push_back( numerator / distance );
	}

	//error function(angle)=sqrt( ( x - x0 )^2 std::+ ( y - y0 )^2 )=
	//					   =sqrt( ( length*cos(angle) - x0 )^2 + ( length*sin(angle) - y0 )^2 )

	//error derivative function(angle)=( length * x0 * sin(angle) - length * y0 * cos(angle) ) /
	//								   (sqrt( ( length*cos(angle) - x0 )^2 + ( length*sin(angle) - y0 )^2 ))



//	std::cout << "error=" << error << std::endl;

	return errors;
}

void Solver::backwardLeg( uint32_t legIndex, const std::vector<double> & angleErrors )
{
	assert( m_anglesPerLeg == angleErrors.size() );

//	std::stringstream ioss;
//	copy(angleErrors.begin(), angleErrors.end(),
//	     std::ostream_iterator<double>(ioss,","));
//	std::cout << ioss.str() << std::endl;

	auto legIter = std::begin( *m_manipulator ) + legIndex;
	auto errorIter = std::begin( angleErrors );
	auto learningRateIter = std::begin( m_learningRates );

//	auto legIter = std::prev( std::end( *m_manipulator ) );
//	auto errorIter = std::prev( std::end( angleErrors ) );
//	auto learningRateIter = std::prev( std::end( m_learningRates ) );
//	int angle_i = 0;
	do
	{
		{
			//update angle XYoZ
			double angleXYoZ = (*legIter)->getAngleXY();
			double radianXYoZ = Utils::deg2Rad( angleXYoZ );

			double gradient = *errorIter;
	//		std::cout << "gradient=" << gradient << std::endl;

			double radianDelta = gradient * (*learningRateIter);
			double radianNew = radianXYoZ - radianDelta;

			if( true == std::isnan( std::abs( radianNew ) ) )
			{
				continue;//skip iteration
			}
	//		std::cout << "radianNew=" << radianNew << std::endl;
			double angleNew = Utils::rad2Deg( radianNew );

	//		std::cout << "angleDelta=" << Utils::rad2Deg( radianDelta ) << std::endl;
	//		std::cout << "backward radianNew=" << radianNew << std::endl;

			(*legIter)->setAngleXY( angleNew );

			const uint32_t legIter_i = std::distance( std::begin( *m_manipulator ), legIter );
			bool crossed = isCrossingLegsFound( *legIter, legIter_i );
			bool tooClose = isFinalTooClose( m_minClosestDistance );
	//		bool tooBigAngle = isAccumulativeAngleTooBig( 360 );
			if( true == crossed || true == tooClose/* || true == tooBigAngle*/ )
			{
//				std::cout << crossed << " == crossed || " << tooClose << " == tooClose" << std::endl;
	//			std::cout << "before" << std::endl;
	//			(*legIter)->print();
				(*legIter)->setAngleXY( angleXYoZ );//revert old angle
	//			std::cout << "after" << std::endl;
	//			(*legIter)->print();
			}
		}

		{
			//update angle XZoY
			double angleXZoY = (*legIter)->getAngleXZ();
			double radianXZoY = Utils::deg2Rad( angleXZoY );

			double gradient = *(errorIter + 1 );
	//		std::cout << "gradient=" << gradient << std::endl;

			double radianDelta = gradient * (*( learningRateIter + 1 ) );
			double radianNew = radianXZoY - radianDelta;

			if( true == std::isnan( std::abs( radianNew ) ) )
			{
				continue;//skip iteration
			}
	//		std::cout << "radianNew=" << radianNew << std::endl;
			double angleNew = Utils::rad2Deg( radianNew );

	//		std::cout << "angleDelta=" << Utils::rad2Deg( radianDelta ) << std::endl;
	//		std::cout << "backward radianNew=" << radianNew << std::endl;

			(*legIter)->setAngleXZ( angleNew );

//			const size_t legIter_i = std::distance( std::begin( *m_manipulator ), legIter );
			bool crossed = false;//isCrossingLegsFound( *legIter, legIter_i );
			bool tooClose = isFinalTooClose( m_minClosestDistance );
	//		bool tooBigAngle = isAccumulativeAngleTooBig( 360 );
			if( true == crossed || true == tooClose/* || true == tooBigAngle*/ )
			{
				std::cout << crossed << " == crossed || " << tooClose << " == tooClose" << std::endl;
	//			std::cout << "before" << std::endl;
	//			(*legIter)->print();
				(*legIter)->setAngleXZ( angleXZoY );//revert old angle
	//			std::cout << "after" << std::endl;
	//			(*legIter)->print();
			}
		}
	}while( false );
}

void Solver::backward( const std::vector<double> & angleErrors )
{
	assert( m_manipulator->size() * m_anglesPerLeg == angleErrors.size() );
	assert( m_manipulator->size() * m_anglesPerLeg == m_learningRates.size() );

//	std::stringstream ioss;
//	copy(angleErrors.begin(), angleErrors.end(),
//	     std::ostream_iterator<double>(ioss,","));
//	std::cout << ioss.str() << std::endl;

	auto legIter = std::begin( *m_manipulator );
	auto errorIter = std::begin( angleErrors );
	auto learningRateIter = std::begin( m_learningRates );

//	auto legIter = std::prev( std::end( *m_manipulator ) );
//	auto errorIter = std::prev( std::end( angleErrors ) );
//	auto learningRateIter = std::prev( std::end( m_learningRates ) );
//	int angle_i = 0;
	for(  ; legIter != std::end( *m_manipulator ) ; legIter++, errorIter += m_anglesPerLeg, learningRateIter += m_anglesPerLeg )
//	for(  ; legIter != std::prev( std::begin( *m_manipulator ) ) ; legIter--, errorIter -= m_anglesPerLeg, learningRateIter -= m_anglesPerLeg )
	{
		{
			//update angle XYoZ
			double angleXYoZ = (*legIter)->getAngleXY();
			double radianXYoZ = Utils::deg2Rad( angleXYoZ );

			double gradient = *errorIter;
	//		std::cout << "gradient=" << gradient << std::endl;

			double radianDelta = gradient * (*learningRateIter);
			double radianNew = radianXYoZ - radianDelta;

			if( true == std::isnan( std::abs( radianNew ) ) )
			{
				continue;//skip iteration
			}
	//		std::cout << "radianNew=" << radianNew << std::endl;
			double angleNew = Utils::rad2Deg( radianNew );

	//		std::cout << "angleDelta=" << Utils::rad2Deg( radianDelta ) << std::endl;
	//		std::cout << "backward radianNew=" << radianNew << std::endl;

			(*legIter)->setAngleXY( angleNew );

			const uint32_t legIter_i = std::distance( std::begin( *m_manipulator ), legIter );
			bool crossed = isCrossingLegsFound( *legIter, legIter_i );
			bool tooClose = isFinalTooClose( m_minClosestDistance );
	//		bool tooBigAngle = isAccumulativeAngleTooBig( 360 );
			if( true == crossed || true == tooClose/* || true == tooBigAngle*/ )
			{
//				std::cout << crossed << " == crossed || " << tooClose << " == tooClose" << std::endl;
	//			std::cout << "before" << std::endl;
	//			(*legIter)->print();
				(*legIter)->setAngleXY( angleXYoZ );//revert old angle
	//			std::cout << "after" << std::endl;
	//			(*legIter)->print();
			}
		}

		{
			//update angle XZoY
			double angleXZoY = (*legIter)->getAngleXZ();
			double radianXZoY = Utils::deg2Rad( angleXZoY );

			double gradient = *(errorIter + 1 );
	//		std::cout << "gradient=" << gradient << std::endl;

			double radianDelta = gradient * (*( learningRateIter + 1 ) );
			double radianNew = radianXZoY - radianDelta;

			if( true == std::isnan( std::abs( radianNew ) ) )
			{
				continue;//skip iteration
			}
	//		std::cout << "radianNew=" << radianNew << std::endl;
			double angleNew = Utils::rad2Deg( radianNew );

	//		std::cout << "angleDelta=" << Utils::rad2Deg( radianDelta ) << std::endl;
	//		std::cout << "backward radianNew=" << radianNew << std::endl;

			(*legIter)->setAngleXZ( angleNew );

//			const size_t legIter_i = std::distance( std::begin( *m_manipulator ), legIter );
			bool crossed = false;//isCrossingLegsFound( *legIter, legIter_i );
			bool tooClose = isFinalTooClose( m_minClosestDistance );
	//		bool tooBigAngle = isAccumulativeAngleTooBig( 360 );
			if( true == crossed || true == tooClose/* || true == tooBigAngle*/ )
			{
				std::cout << crossed << " == crossed || " << tooClose << " == tooClose" << std::endl;
	//			std::cout << "before" << std::endl;
	//			(*legIter)->print();
				(*legIter)->setAngleXZ( angleXZoY );//revert old angle
	//			std::cout << "after" << std::endl;
	//			(*legIter)->print();
			}
		}
	}
}

bool Solver::isCrossingLegsFound( const ShLeg& crossLeg, uint32_t legIndex )
{
	bool crossed = false;
	const uint32_t legsCount = m_manipulator->size();
	for( uint32_t leg_i = 0 ; leg_i < legsCount ; leg_i++ )//cross legs checking
	{
		ShLeg legLoop = (*m_manipulator)[leg_i];
		const int32_t crossLegDist = legIndex - leg_i;
		const uint32_t legsDistance = crossLegDist < 0 ? ( -1 ) * crossLegDist : crossLegDist;
		if( legsDistance < 2 )
		{
			continue;
		}
		if( legLoop->isCrossing( *crossLeg ) )
		{
//			int ax, ay, bx, by, cx, cy, dx, dy;
//			legLoop->getInitialPosition( ax, ay );
//			legLoop->getCalulatedFinalPosition( bx, by );
//			crossLeg->getInitialPosition( cx, cy );
//			crossLeg->getCalulatedFinalPosition( dx, dy );
//			std::cout << "( "<< ax << ", " << ay << " ), " << "( "<< bx << ", " << by << " }" << std::endl;
//			std::cout << "( "<< cx << ", " << cy << " ), " << "( "<< dx << ", " << dy << " )" << std::endl;
			crossed = true;
		}
	}
	return crossed;
}

bool Solver::isFinalTooClose( const int32_t minDistance )
{
	return isFinalTooClose( m_manipulator, minDistance );
}

bool Solver::isFinalTooClose( ShLegManipulator manipulator, const int32_t minDistance )
{
	bool tooClose = false;
	const auto & lastLeg = manipulator->getLastLeg();
	const auto & preLastLeg = manipulator->getPreLastLeg();
	TypePrecision finalX, finalY, finalZ;
	lastLeg->getCalulatedFinalPosition( finalX, finalY, finalZ );
	finalX = (int)finalX;
	finalY = (int)finalY;
	finalZ = (int)finalZ;
	const size_t legsCount = manipulator->size();
	for( size_t leg_i = 0 ; leg_i < legsCount ; leg_i++ )//cross legs checking
	{
		const auto &legLoop = (*manipulator)[leg_i];
		if( lastLeg == legLoop || preLastLeg == legLoop )
		{
			continue;
		}
		TypePrecision legLoopInitialX, legLoopInitialY, legLoopInitialZ;
		TypePrecision legLoopFinalX, legLoopFinalY, legLoopFinalZ;
		legLoop->getInitialPosition( legLoopInitialX, legLoopInitialY, legLoopInitialZ );
		legLoop->getCalulatedFinalPosition( legLoopFinalX, legLoopFinalY, legLoopFinalZ );

		legLoopInitialX = (int)legLoopInitialX;
		legLoopInitialY = (int)legLoopInitialY;
		legLoopInitialZ = (int)legLoopInitialZ;
		legLoopFinalX = (int)legLoopFinalX;
		legLoopFinalY = (int)legLoopFinalY;
		legLoopFinalZ = (int)legLoopFinalZ;

		//a
		const double legLoopInitial_lastLegFinal_distance =
				Utils::distance( legLoopInitialX, legLoopInitialY, legLoopInitialZ, finalX, finalY, finalZ );
		//b
		const double legLoopFinal_lastLegFinal_distance =
				Utils::distance( legLoopFinalX, legLoopFinalY, legLoopFinalZ, finalX, finalY, finalZ );
		//c
		const double legLoopInitial_legLoopFinal_distance = legLoop->getLength();

		double triangleX = 0.0;
		const double distance = Utils::distanceByTriangle( legLoopInitial_lastLegFinal_distance,
				legLoopFinal_lastLegFinal_distance, legLoopInitial_legLoopFinal_distance, triangleX );

//		double legLoopInitial_lastLegFinal_angle = Utils::getDegAngle( distance, legLoopInitial_lastLegFinal_distance );
//		uint8_t legLoopInitial_lastLegFinal_quoter = Utils::getQouterByAngle( legLoopInitial_lastLegFinal_angle );

//		double legLoopFinal_lastLegFinal_angle = 90 + Utils::getDegAngle( distance, legLoopFinal_lastLegFinal_distance );
//		uint8_t legLoopFinal_lastLegFinal_quoter = Utils::getQouterByAngle( legLoopFinal_lastLegFinal_angle );
//
//		const bool isBelongToSegment = legLoopInitial_lastLegFinal_quoter != legLoopFinal_lastLegFinal_quoter;
		const bool isBelongToSegment = triangleX < legLoopInitial_legLoopFinal_distance && triangleX > 0.0;

		if( true == isBelongToSegment && distance <= minDistance )
		{
			tooClose = true;
//			std::cout << "leg " << legLoop->getLevel() << ", distance=" << distance << std::endl;
			break;
		}

	}
	return tooClose;
}

//bool Solver::isFinalTooClose( const int32_t minDistance )
//{
//	bool tooClose = false;
//	const auto & lastLeg = (*m_manipulator)[ m_manipulator->size() - 1 ];
//	TypePrecision finalX, finalY, finalZ;
//	lastLeg->getCalulatedFinalPosition( finalX, finalY, finalZ );
//	finalX = (int)finalX;
//	finalY = (int)finalY;
//	finalZ = (int)finalZ;
//	const size_t legsCount = m_manipulator->size();
//	for( size_t leg_i = 0 ; leg_i < legsCount ; leg_i++ )//cross legs checking
//	{
//		const auto &legLoop = (*m_manipulator)[leg_i];
//		if( lastLeg == legLoop )
//		{
//			continue;
//		}
//		TypePrecision legLoopInitialX, legLoopInitialY, legLoopInitialZ;
//		TypePrecision legLoopFinalX, legLoopFinalY, legLoopFinalZ;
//		legLoop->getInitialPosition( legLoopInitialX, legLoopInitialY, legLoopInitialZ );
//		legLoop->getCalulatedFinalPosition( legLoopFinalX, legLoopFinalY, legLoopFinalZ );
//
//		legLoopInitialX = (int)legLoopInitialX;
//		legLoopInitialY = (int)legLoopInitialY;
//		legLoopInitialZ = (int)legLoopInitialZ;
//		legLoopFinalX = (int)legLoopFinalX;
//		legLoopFinalY = (int)legLoopFinalY;
//		legLoopFinalZ = (int)legLoopFinalZ;
//
//		//a
//		const double legLoopInitial_lastLegFinal_distance =
//				Utils::distance( legLoopInitialX, legLoopInitialY, legLoopInitialZ, finalX, finalY, finalZ );
//		//b
//		const double legLoopFinal_lastLegFinal_distance =
//				Utils::distance( legLoopFinalX, legLoopFinalY, legLoopFinalZ, finalX, finalY, finalZ );
//		//c
//		const double legLoopInitial_legLoopFinal_distance = legLoop->getLength();
//
//		const double distance = Utils::distance( legLoopInitial_lastLegFinal_distance,
//				legLoopFinal_lastLegFinal_distance, legLoopInitial_legLoopFinal_distance );
//
//		if( distance <= minDistance )
//		{
//			tooClose = true;
//		}
//
//	}
//	return tooClose;
//}

//bool Solver::isFinalTooClose( const int32_t minDistance )
//{
//	bool tooClose = false;
//	const auto & lastLeg = (*m_manipulator)[ m_manipulator->size() - 1 ];
//	TypePrecision finalX, finalY, finalZ;
//	lastLeg->getCalulatedFinalPosition( finalX, finalY, finalZ );
//	finalX = (int)finalX;
//	finalY = (int)finalY;
//	finalZ = (int)finalZ;
//	const size_t legsCount = m_manipulator->size();
//	for( size_t leg_i = 0 ; leg_i < legsCount ; leg_i++ )//cross legs checking
//	{
//		const auto &legLoop = (*m_manipulator)[leg_i];
//		if( lastLeg == legLoop )
//		{
//			continue;
//		}
//		TypePrecision legLoopInitialX, legLoopInitialY, legLoopInitialZ;
//		TypePrecision legLoopFinalX, legLoopFinalY, legLoopFinalZ;
//		legLoop->getInitialPosition( legLoopInitialX, legLoopInitialY, legLoopInitialZ );
//		legLoop->getCalulatedFinalPosition( legLoopFinalX, legLoopFinalY, legLoopFinalZ );
//
//		legLoopInitialX = (int)legLoopInitialX;
//		legLoopInitialY = (int)legLoopInitialY;
//		legLoopInitialZ = (int)legLoopInitialZ;
//		legLoopFinalX = (int)legLoopFinalX;
//		legLoopFinalY = (int)legLoopFinalY;
//		legLoopFinalZ = (int)legLoopFinalZ;
//
//		double perpLength = 0.0;
//
//		bool isPerpExist = Utils::isPerpendicularBelongToSegment( legLoopInitialX, legLoopInitialY, legLoopInitialZ,
//											   legLoopFinalX,   legLoopFinalY,   legLoopFinalZ,
//											   finalX,          finalY,          finalZ,
//											   perpLength );
//		if( false == isPerpExist )
//		{
//			continue;
//		}
//		if( perpLength <= minDistance )
//		{
//			tooClose = true;
//		}
//	}
//	return tooClose;
//}

bool Solver::isAccumulativeAngleTooBig( const double maxAngle )
{
	bool tooBig = false;
	const auto & lastLeg = m_manipulator->getLastLeg();
	const auto & firstLeg = m_manipulator->getFirstLeg();

	double accumulativeAngle = lastLeg->getAccumulativeParentAngleXY() + lastLeg->getAngleXY() - firstLeg->getAngleXY();

	std::cout << "accumulativeAngle "<< accumulativeAngle << std::endl;

	if( accumulativeAngle > maxAngle )
	{
		tooBig = true;
	}
	return tooBig;
}

std::vector<double> Solver::getError()
{
	return m_errors;
}

double Solver::getErrorFunctionValue( TypePrecision targetX, TypePrecision targetY, TypePrecision targetZ )
{
	return getErrorFunctionValue( m_manipulator, targetX, targetY, targetZ );
}

//double Solver::getErrorFunctionValue( ShLegManipulator manipulator )
//{
//	GiNaC::lst anglesValues;
//	auto legIter = std::begin( *manipulator );
//	auto angleXYSymbolIter = std::begin( m_ginacXYoZAngles );
//	auto angleXZSymbolIter = std::begin( m_ginacXZoYAngles );
//	for(  ; legIter != std::end( *manipulator ) ; legIter++, angleXYSymbolIter++, angleXZSymbolIter++ )
//	{
//		{
//			const double angle = (*legIter)->getAngleXY();
//			const double radian = Utils::deg2Rad( angle );
//
//			anglesValues.append( (**angleXYSymbolIter) == radian );
//		}
//		{
//			const double angle = (*legIter)->getAngleXZ();
//			const double radian = Utils::deg2Rad( angle );
//
//			anglesValues.append( (**angleXZSymbolIter) == radian );
//		}
//	}
//	std::cout << "m_errorFunction=" << m_errorFunction << std::endl;
//	GiNaC::ex f = GiNaC::evalf( m_errorFunction.subs( anglesValues ) );
//	double result = 0.0f;
//	if (GiNaC::is_a<GiNaC::numeric>(f))
//	{
//		result = GiNaC::ex_to<GiNaC::numeric>(f).to_double();
//		std::cout << "error=" << result << std::endl;
//	}
//	return result;
//}

double Solver::getErrorFunctionValue( ShLegManipulator manipulator, TypePrecision targetX, TypePrecision targetY, TypePrecision targetZ )
{
	GiNaC::lst anglesValues;
//	auto legIter = std::begin( *manipulator );
	std::vector<double> params;
	fillParams( targetX, targetY, targetZ, params );
	double result = m_preDefinedErrorFunction( params );
	return result;
}

void Solver::setCurrentManipulator( ShLegManipulator manipulator )
{
	m_manipulator = manipulator;
}

ShLegManipulator Solver::getCurrentManipulator() const
{
	return m_manipulator;
}
