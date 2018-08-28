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

GiNaCErrorFunction::GiNaCErrorFunction()
{
}

void GiNaCErrorFunction::add( const std::shared_ptr<GiNaC::ex> func )
{
	m_Funcs.emplace_back( func );
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


	std::vector<double> errors( m_legsAngles.size() );
	GiNaC::ex perLegAngleLength;
	auto errorIter = std::begin( errors );
	for( const auto & func : m_Funcs )
	{
		GiNaC::ex f = GiNaC::evalf( func->subs( functionVars ) );
//		std::cout << "(*derivativeIter)=" << (*derivativeIter) << std::endl;
//		std::cout << "f=" << f << std::endl;

		if (GiNaC::is_a<GiNaC::numeric>(f))
		{
			(*errorIter) = GiNaC::ex_to<GiNaC::numeric>(f).to_double();
//			std::cout << "errorIter=" << (*errorIter) << std::endl;
		}
	}
	return std::move(errors);
}

IFuncSh GiNaCErrorFunction::diff( const IFuncDiffParams & iParams )
{
    auto cloned = std::make_shared<GiNaCErrorFunction>();
    const auto & params = static_cast<const GiNaCFuncDiffParams&>( iParams );
    for( const auto func : m_Funcs )
    {
    	cloned->add( std::make_shared<GiNaC::ex>( GiNaC::diff( *func, *params.getSymbols(), params.getDepth() ) ) );
    }

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
	else if( IFuncParams::eParamType::eGiNaCTypes == data.type() )
	{
		const auto & obj = static_cast<const GiNaCTypesDataParams&>( data );
		obj.getTargetSymbols( m_ginacTargetX, m_ginacTargetY, m_ginacTargetZ );
		m_ginacXYoZAngles = std::move( obj.getXYSymbols() );
		m_ginacXZoYAngles = std::move( obj.getXZSymbols() );
	}
}
