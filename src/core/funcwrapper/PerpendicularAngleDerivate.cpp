/*
 * PerpendicularAngleDerivate.cpp
 *
 *  Created on: 19 мар. 2018 г.
 *      Author: vadim
 */

#include "PerpendicularAngleDerivate.h"
#include "LegAnglesDataChuck.h"
#include "AngleDataChunk.h"

PerpendicularAngleDerivate::PerpendicularAngleDerivate()
{
}

std::vector<double> PerpendicularAngleDerivate::evaluate()
{
	return std::vector<double>();
}

void PerpendicularAngleDerivate::onReceive( const IDataChunk & data )
{
	if( IDataChunk::eDataChunkType::eAngle == data.type() )
	{
		const auto & obj = static_cast<const AngleDataChunk&>( data );
		m_Angle = obj.getAngle();
	}
	else if( IDataChunk::eDataChunkType::eLegsAngles == data.type() )
	{
		const auto & obj = static_cast<const LegAnglesDataChuck&>( data );
		m_legsAngles = std::move( obj.getLegsAngles() );
	}
}
