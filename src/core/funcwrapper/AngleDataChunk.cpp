/*
 * AngleDataChunk.cpp
 *
 *  Created on: 19 мар. 2018 г.
 *      Author: vadim
 */

#include "AngleDataChunk.h"

AngleDataChunk::AngleDataChunk( double angle ) : IFuncParams( IFuncParams::eDataChunkType::eAngle ), m_Angle( angle )
{
}

AngleDataChunk::~AngleDataChunk()
{
}

