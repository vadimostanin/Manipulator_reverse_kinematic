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

GiNaCErrorFunction::GiNaCErrorFunction( std::shared_ptr<GiNaC::ex> ex ):
	m_Ex( ex )
{
}

std::vector<double> GiNaCErrorFunction::evaluate() const
{
	GiNaC::lst functionVars;
	auto legAngleIter = std::begin( m_legsAngles );
	auto angleXYSymbolIter = std::begin( m_ginacXYoZAngles );
	auto angleXZSymbolIter = std::begin( m_ginacXZoYAngles );
	for(  ; legAngleIter != std::end( m_legsAngles ) ; legAngleIter ++, angleXYSymbolIter++, angleXZSymbolIter++ )
	{
		{
			const double radian = *legAngleIter;

//			std::cout << "(**angleXYSymbolIter)=" << (**angleXYSymbolIter) << std::endl;

			functionVars.append( (**angleXYSymbolIter) == radian );
		}
		legAngleIter++;
		{
			const double radian = *legAngleIter;

			functionVars.append( (**angleXZSymbolIter) == radian );
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
	std::cout << "f=" << f << std::endl;

	if (GiNaC::is_a<GiNaC::numeric>(f))
	{
		errors.push_back( GiNaC::ex_to<GiNaC::numeric>(f).to_double() );
		std::cout << "error=" << errors.front() << std::endl;
	}

	return std::move(errors);
}

IFuncSh GiNaCErrorFunction::diff( const IFuncDiffParams & iParams )
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
		m_legsAngles = std::move( obj.getLegsAngles() );
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
		m_ginacXYoZAngles = std::move( obj.getXYSymbols() );
		m_ginacXZoYAngles = std::move( obj.getXZSymbols() );
		obj.getAngleSymbol( m_ginacAngleDegree );
	}
}
