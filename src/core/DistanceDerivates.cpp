/*
 * DistanceDerivates.cpp
 *
 *  Created on: 19 мар. 2018 г.
 *      Author: vadim
 */

#include "DistanceDerivates.h"
#include "DistanceDataChunk.h"
#include "LegAnglesDataChuck.h"

DistanceDerivates::DistanceDerivates()
{
}

double DistanceDerivates::evaluate()
{
	return 0.0;
}

void DistanceDerivates::onReceive( const IDataChunk & data )
{
	if( IDataChunk::eDataChunkType::eDistance == data.type() )
	{
		const auto & obj = static_cast<const DistanceDataChunk&>( data );
		m_X = obj.getX();
		m_Y = obj.getY();
		m_Z = obj.getZ();
	}
	else if( IDataChunk::eDataChunkType::eLegsAngles == data.type() )
	{
		const auto & obj = static_cast<const LegAnglesDataChuck&>( data );
		m_legsAngles = std::move( obj.getLegsAngles() );
	}
}
