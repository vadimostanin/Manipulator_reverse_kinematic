/*
 * InterpolateMove.cpp
 *
 *  Created on: Jan 23, 2018
 *      Author: vadym_ostanin
 */

#include "InterpolatedMove2.h"
#include "InterpolationExp5.h"
#include "InterpolationFade.h"
#include "InterpolationSine.h"
#include "InterpolatedStopStartSine.h"
#include <cassert>
#include <iostream>
#include <sstream>
#include <iterator>
#include <cmath>
#include <algorithm>

std::shared_ptr<InterpolatedMove2> InterpolatedMove2::m_instance;
InterpolatedMove2::InterpolatedMove2( uint32_t vars_count ) : m_currentVars( vars_count ), m_currentA( 0.0 )
{
	m_interpolationStandart = std::make_shared<InterpolationSine>();
	m_interpolationStopStart = std::make_shared<InterpolationSine>();

	m_interpolationCurrent = m_interpolationStandart;
}

void InterpolatedMove2::init( uint32_t vars_count )
{
	m_instance = std::make_shared<InterpolatedMove2>( vars_count );
}

InterpolatedMove2 & InterpolatedMove2::get()
{
	return *m_instance;
}

void InterpolatedMove2::setVars( const std::vector<double> & newVars )
{
//	assert( m_prevVars.size() == newVars.size() );

	m_vVars.push_back( newVars );

	mergeVars();
}

void InterpolatedMove2::mergeVars()
{
	if( m_vVars.size() < 2 )
	{
		return;
	}
	else if( m_vVars.size() == 2 )
	{
		std::vector<double> varsFrom = *(std::begin(m_vVars));
		std::vector<double> varsTo = *(std::next(std::begin(m_vVars)));


		double maxVarDiff = 0.0;
		{
			auto newVarIter = std::begin( varsTo );
			const auto endIter = std::end( varsTo );

			auto prevVarIter = std::begin( varsFrom );

			for( ; newVarIter != endIter ; newVarIter++, prevVarIter++ )
			{
				double newVar = *newVarIter;
				double prevVar = *prevVarIter;
				if( maxVarDiff < ( newVar - prevVar ) )
				{
					maxVarDiff = std::abs( newVar - prevVar );
				}
			}
		}
		auto newVarIter = std::begin( varsTo );
		const auto endIter = std::end( varsTo );

		auto prevVarIter = std::begin( varsFrom );

		VarTimeMoveInfo vTMInfo;
		for( ; newVarIter != endIter ; newVarIter++, prevVarIter++ )
		{
			double newVar = *newVarIter;
			double prevVar = *prevVarIter;
			VarMoveInfo varMoveInfo;
			varMoveInfo.range.beginVar = prevVar;
			varMoveInfo.range.endVar = newVar;
			varMoveInfo.varRateRatio = ( newVar - prevVar ) / maxVarDiff;

			vTMInfo.varMoveInfo.push_back( varMoveInfo );
		}

		vTMInfo.timeRange.beginTime = std::chrono::milliseconds::zero();
		vTMInfo.timeRange.endTime = vTMInfo.timeRange.beginTime + std::chrono::milliseconds( m_moveTimeConstant );

		vTMInfo.elapsed = std::chrono::milliseconds::zero();

		m_queueRanges.push( vTMInfo );
	}
	else if( m_vVars.size() > 2 )
	{
		std::vector<double> & varsFrom = m_currentVars;
		std::vector<double> & varsTo = m_vVars.back();

		double maxVarDiff = 0.0;
		{
			auto newVarIter = std::begin( varsTo );
			const auto endIter = std::end( varsTo );

			auto prevVarIter = std::begin( varsFrom );

			for( ; newVarIter != endIter ; newVarIter++, prevVarIter++ )
			{
				double newVar = *newVarIter;
				double prevVar = *prevVarIter;
				if( maxVarDiff < ( newVar - prevVar ) )
				{
					maxVarDiff = std::abs( newVar - prevVar );
				}
			}
		}
		double newA = findSameASlopeOppositeDirection();

		auto newVarIter = std::begin( varsTo );
		const auto endIter = std::end( varsTo );
		auto prevVarIter = std::begin( varsFrom );

		VarTimeMoveInfo vTMInfo;
		for( ; newVarIter != endIter ; newVarIter++, prevVarIter++ )
		{
			double newVar = *newVarIter;
			double prevVar = *prevVarIter;
			VarMoveInfo varMoveInfo;
			double startPrevVar = m_interpolationCurrent->getStart( prevVar, newVar, newA );
			varMoveInfo.range.beginVar = startPrevVar;
			varMoveInfo.range.endVar = newVar;
			varMoveInfo.varRateRatio = ( newVar - prevVar ) / maxVarDiff;

			vTMInfo.varMoveInfo.push_back( varMoveInfo );
		}


		vTMInfo.timeRange.beginTime = std::chrono::milliseconds::zero();
		vTMInfo.timeRange.endTime = vTMInfo.timeRange.beginTime + std::chrono::milliseconds( m_moveTimeConstant );

		vTMInfo.elapsed = std::chrono::milliseconds( (uint64_t) ( ( vTMInfo.timeRange.endTime - vTMInfo.timeRange.beginTime ).count() * newA ) );

		std::queue<VarTimeMoveInfo> empty;
		std::swap( m_queueRanges, empty );

		m_queueRanges.push( vTMInfo );

		m_vVars.erase( std::begin( m_vVars ), std::next( std::begin( m_vVars ) ) );
		m_interpolationCurrent = m_interpolationStopStart;
//		m_vVars.erase( std::prev( m_vVars.end() ), std::end( m_vVars ) );
	}

//	m_prevVars = newVars;
}

void InterpolatedMove2::getVars( std::vector<double> & vars )
{
	vars = m_currentVars;

//	std::stringstream ioss;
//	copy(vars.begin(), vars.end(),
//		 std::ostream_iterator<double>(ioss,","));
//	std::cout << ioss.str() << std::endl;

}

bool InterpolatedMove2::update( const std::chrono::milliseconds & delta )
{
	if( true == m_queueRanges.empty() )
	{
		return false;
	}

//	currTMInfo.
	VarTimeMoveInfo & currTMInfo = m_queueRanges.front();

	assert( m_currentVars.size() == currTMInfo.varMoveInfo.size() );

	currTMInfo.elapsed += delta;
	auto varInfoIter = std::begin( currTMInfo.varMoveInfo );
	auto varInfoEndIter = std::end( currTMInfo.varMoveInfo );
	auto currVarIter = std::begin( m_currentVars );
	bool percentageFinished = false;
	const double timePercentage = ( ( currTMInfo.timeRange.beginTime.count() + currTMInfo.elapsed.count() ) / ( ( double )( currTMInfo.timeRange.endTime.count() - currTMInfo.timeRange.beginTime.count() ) ) );
	m_currentA = timePercentage;
	if( 1.0 >= timePercentage )
	{
		for( ; varInfoIter != varInfoEndIter ; varInfoIter++, currVarIter++ )
		{
			const auto & varInfo = ( *varInfoIter );
			const double ratio = timePercentage;// * varInfo.varRateRatio;
	//		std::cout << "ratio=" << ratio << ", timePercentage=" << timePercentage << std::endl;
			(* currVarIter ) = m_interpolationCurrent->apply3( varInfo.range.beginVar, varInfo.range.endVar, ratio );
		}
	}
	else
	{
		percentageFinished = true;
		m_interpolationCurrent = m_interpolationStandart;
	}

	if( true == percentageFinished )
	{
		m_queueRanges.pop();
		m_vVars.erase( std::begin( m_vVars ), std::next( std::begin( m_vVars ) ) );
	}
	return true;
}

double InterpolatedMove2::findSameASlopeStraightDirection()
{
	double oldA = m_currentA;

	double oldAdiff = m_interpolationCurrent->diff( oldA );
	double minA = 0.0;
	double maxA = 1.0;
	double deltaA = 0.001;
	double minOldNewADelta = 10000;
	double minNewA = 0.0;
	for( double a_i = minA ; a_i < maxA ; a_i += deltaA )
	{
		double currADiff = m_interpolationCurrent->diff( a_i );
		if( abs( oldAdiff - currADiff ) < minOldNewADelta )
		{
			minOldNewADelta = oldAdiff - currADiff;
			minNewA = a_i;
		}
		else// exit if found closest
		{
			break;
		}
	}
	return minNewA;
}

double InterpolatedMove2::findSameASlopeOppositeDirection()
{
	double oldA = m_currentA;

	double oldAdiff = m_interpolationCurrent->diff( oldA );
	double minA = 0.0;
	double maxA = 1.0;
	double deltaA = 0.001;
	double minOldNewADelta = 10000;
	double minNewA = 0.0;
	for( double a_i = maxA ; a_i >= minA ; a_i -= deltaA )
	{
		double currADiff = m_interpolationCurrent->diff( a_i );
		if( abs( oldAdiff - currADiff ) < minOldNewADelta )
		{
			minOldNewADelta = oldAdiff - currADiff;
			minNewA = a_i;
		}
		else// exit if found closest
		{
			break;
		}
	}
	return minNewA;
}
