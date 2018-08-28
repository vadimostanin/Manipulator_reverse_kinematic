/*
 * PerpendicularAngleDerivate.cpp
 *
 *  Created on: 19 мар. 2018 г.
 *      Author: vadim
 */

#include "PerpendicularAngleDerivate.h"
#include "AngleDataChunk.h"
#include "LegAnglesDataParams.h"

PerpendicularAngleDerivate::PerpendicularAngleDerivate()
{
}

std::vector<double> PerpendicularAngleDerivate::evaluate() const
{
	return std::vector<double>();
}

void PerpendicularAngleDerivate::onReceive( const IFuncParams & data )
{
	if( IFuncParams::eParamType::eAngle == data.type() )
	{
		const auto & obj = static_cast<const AngleDataChunk&>( data );
		m_Angle = obj.getAngle();
	}
	else if( IFuncParams::eParamType::eLegsAngles == data.type() )
	{
		const auto & obj = static_cast<const LegAnglesDataParams&>( data );
		m_legsAngles = std::move( obj.getLegsAngles() );
	}
}
