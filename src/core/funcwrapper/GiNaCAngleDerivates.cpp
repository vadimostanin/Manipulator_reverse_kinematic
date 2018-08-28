/*
 * DistanceDerivates.cpp
 *
 *  Created on: 19 мар. 2018 г.
 *      Author: vadim
 */

#include "GiNaCAngleDerivates.h"

#include "AngleDataChunk.h"
#include "../Utils.h"
#include "GiNaCTypesDataParams.h"
#include "LegAnglesDataParams.h"

GiNaCAngleDerivates::GiNaCAngleDerivates()
{
}

std::vector<double> GiNaCAngleDerivates::evaluate() const
{
	GiNaC::lst functionVars;
	auto legAngleIter = std::begin( m_legsAngles );
	auto legsAnglesIterEnd = std::end( m_legsAngles );
	auto angleXYSymbolIter = std::begin( m_ginacXYoZAngles );
	auto angleXZSymbolIter = std::begin( m_ginacXZoYAngles );
	for(  ; legAngleIter != legsAnglesIterEnd ; legAngleIter ++, angleXYSymbolIter++, angleXZSymbolIter++ )
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
	functionVars.append( ( *m_ginacTargetAngle) == m_Angle );
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

IFuncSh GiNaCAngleDerivates::diff( const IFuncDiffParams & params )
{
    auto cloned = std::make_shared<GiNaCAngleDerivates>();
    return cloned;
}

void GiNaCAngleDerivates::onReceive( const IFuncParams & data )
{
	if( IFuncParams::eParamType::eAngle == data.type() )
	{
		const auto & obj = static_cast<const AngleDataChunk&>( data );
		m_Angle = Utils::deg2Rad( obj.getAngle() );
	}
	else if( IFuncParams::eParamType::eLegsAngles == data.type() )
	{
		const auto & obj = static_cast<const LegAnglesDataParams&>( data );
		m_legsAngles = std::move( obj.getLegsAngles() );
	}
	else if( IFuncParams::eParamType::eGiNaCTypes == data.type() )
	{
		const auto & obj = static_cast<const GiNaCTypesDataParams&>( data );
		obj.getAngleAngle( m_ginacTargetAngle );
		m_ginacXYoZAngles = std::move( obj.getXYSymbols() );
		m_ginacXZoYAngles = std::move( obj.getXZSymbols() );
	}
}
