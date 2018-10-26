/*
 * DistanceDerivates.cpp
 *
 *  Created on: 19 мар. 2018 г.
 *      Author: vadim
 */

#include "GiNaCErrorFunction.h"

#include "DistanceDataParams.h"
#include "GiNaCTypesDataParams.h"
#include "GiNaCFuncDiffParams.h"
#include "LegAnglesDataParams.h"
#include "AngleFuncParams.h"
#include "../Utils.h"
#include <assert.h>

GiNaCErrorFunction::GiNaCErrorFunction( std::shared_ptr<GiNaC::ex> ex ):
	m_Ex( ex )
{
}

std::vector<double> GiNaCErrorFunction::evaluate() const
{
	assert( m_legsCurrentAngles.size() == m_legsInitialAngles.size() );

	GiNaC::lst functionVars;
	auto legCurrentAngleIter = std::begin( m_legsCurrentAngles );
	auto legCurrentAngleEndIter = std::end( m_legsCurrentAngles );
	auto legInitialAngleIter = std::begin( m_legsInitialAngles );
	auto currentAngleXYSymbolIter = std::begin( m_ginacCurrentXYoZAnglesSymbols );
	auto currentAngleXZSymbolIter = std::begin( m_ginacCurrentXZoYAnglesSymbols );
	auto initialAngleXYSymbolIter = std::begin( m_ginacInitialXYoZAnglesSymbols );
	auto initialAngleXZSymbolIter = std::begin( m_ginacInitialXZoYAnglesSymbols );
	for(  ; legCurrentAngleIter != legCurrentAngleEndIter ; legCurrentAngleIter ++, currentAngleXYSymbolIter++, currentAngleXZSymbolIter++,
															initialAngleXYSymbolIter++, initialAngleXZSymbolIter++, legInitialAngleIter++ )
	{
		{
			const double radian = *legCurrentAngleIter;

//			std::cout << "(**angleXYSymbolIter)=" << (**angleXYSymbolIter) << std::endl;

			functionVars.append( (**currentAngleXYSymbolIter) == radian );
		}
		legCurrentAngleIter++;
		{
			const double radian = *legCurrentAngleIter;

			functionVars.append( (**currentAngleXZSymbolIter) == radian );
		}
		{
			const double radian = *legInitialAngleIter;

//			std::cout << "(**angleXYSymbolIter)=" << (**angleXYSymbolIter) << std::endl;

			functionVars.append( (**initialAngleXYSymbolIter) == radian );
		}
		legInitialAngleIter++;
		{
			const double radian = *legInitialAngleIter;

			functionVars.append( (**initialAngleXZSymbolIter) == radian );
		}
	}

	functionVars.append( *m_ginacTargetX == m_X );
	functionVars.append( *m_ginacTargetY == m_Y );
	functionVars.append( *m_ginacTargetZ == m_Z );

	if( m_IsAngled )
	{
		functionVars.append( *m_ginacAngleDegree == Utils::deg2Rad( m_AngleDegree ) );
	}


	std::vector<double> errors;
	GiNaC::ex perLegAngleLength;

	GiNaC::ex f = GiNaC::evalf( m_Ex->subs( functionVars ) );
//	std::cout << "m_Ex=" << *m_Ex << std::endl;
//	std::cout << "error=" << f << std::endl;

	if (GiNaC::is_a<GiNaC::numeric>(f))
	{
		errors.push_back( GiNaC::ex_to<GiNaC::numeric>(f).to_double() );
//		std::cout << "error=" << errors.front() << std::endl;
	}

	return std::move(errors);
}

IFuncSh GiNaCErrorFunction::diff( const IFuncParams & iParams )
{
	const auto & params = static_cast<const GiNaCFuncDiffParams&>( iParams );
    auto cloned = std::make_shared<GiNaCErrorFunction>(
    		std::make_shared<GiNaC::ex>( GiNaC::diff( *m_Ex, *params.getSymbols(), params.getDepth() ) )
    				);

    return cloned;
}

void GiNaCErrorFunction::onReceive( const IFuncParams & data )
{
	if( IFuncParams::eParamType::eDistance == data.type() )
	{
		const auto & obj = static_cast<const DistanceDataParams&>( data );
		m_X = obj.getX();
		m_Y = obj.getY();
		m_Z = obj.getZ();
	}
	else if( IFuncParams::eParamType::eLegsAngles == data.type() )
	{
		const auto & obj = static_cast<const LegAnglesDataParams&>( data );
		m_legsCurrentAngles = std::move( obj.getLegsCurrentAngles() );
		m_legsInitialAngles = std::move( obj.getLegsInitialAngles() );
	}
	else if( IFuncParams::eParamType::eAngle == data.type() )
	{
		const auto & obj = static_cast<const AngleFuncParams&>( data );
		m_AngleDegree = obj.getAngle();
		m_IsAngled = true;
	}
	else if( IFuncParams::eParamType::eGiNaCTypes == data.type() )
	{
		const auto & obj = static_cast<const GiNaCTypesDataParams&>( data );
		obj.getTargetSymbols( m_ginacTargetX, m_ginacTargetY, m_ginacTargetZ );
		m_ginacCurrentXYoZAnglesSymbols = std::move( obj.getCurrentXYSymbols() );
		m_ginacCurrentXZoYAnglesSymbols = std::move( obj.getCurrentXZSymbols() );
		m_ginacInitialXYoZAnglesSymbols = std::move( obj.getInitialXYSymbols() );
		m_ginacInitialXZoYAnglesSymbols = std::move( obj.getInitialXZSymbols() );
		obj.getAngleSymbol( m_ginacAngleDegree );
	}
}
