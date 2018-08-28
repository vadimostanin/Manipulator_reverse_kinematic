/*
 * DistanceDerivates.cpp
 *
 *  Created on: 19 мар. 2018 г.
 *      Author: vadim
 */

#include "DistanceDerivates.h"

#include "DistanceDataParams.h"
#include "GiNaCTypesDataParams.h"
#include "LegAnglesDataParams.h"

DistanceDerivates::DistanceDerivates()
{
}

std::vector<double> DistanceDerivates::evaluate() const
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
	for( const auto diff : *this )
	{
		(*errorIter) = diff->evaluate().front();
//		std::cout << "errorIter=" << (*errorIter) << std::endl;

		errorIter++;
	}
	return std::move(errors);
}

IFuncSh DistanceDerivates::diff( const IFuncDiffParams & params )
{
    auto cloned = std::make_shared<DistanceDerivates>();
    return cloned;
}

void DistanceDerivates::onReceive( const IFuncParams & data )
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
