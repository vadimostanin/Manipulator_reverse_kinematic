/*
 * DistanceDerivates.cpp
 *
 *  Created on: 19 мар. 2018 г.
 *      Author: vadim
 */

#include "GiNaCAngleDerivates.h"

#include "../Utils.h"
#include "AngleFuncParams.h"
#include "GiNaCTypesDataParams.h"
#include "LegAnglesDataParams.h"

GiNaCAngleDerivates::GiNaCAngleDerivates()
{
}

std::vector<double> GiNaCAngleDerivates::evaluate() const
{
	std::vector<double> errors( size() );
	auto errorIter = std::begin( errors );
	for( const auto diff : *this )
	{
		(*errorIter) = diff->evaluate().front();

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
		const auto & obj = static_cast<const AngleFuncParams&>( data );
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
		obj.getAngleSymbol( m_ginacTargetAngle );
		m_ginacXYoZAngles = std::move( obj.getXYSymbols() );
		m_ginacXZoYAngles = std::move( obj.getXZSymbols() );
	}
}
