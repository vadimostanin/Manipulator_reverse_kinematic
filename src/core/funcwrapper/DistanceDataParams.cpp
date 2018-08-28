/*
 * DistanceDataParams.cpp
 *
 *  Created on: 19 мар. 2018 г.
 *      Author: vadim
 */

#include "DistanceDataParams.h"

DistanceDataParams::DistanceDataParams( int32_t x, int32_t y, int32_t z ) :
	IFuncParams( IFuncParams::eParamType::eDistance ),
	m_X( x ), m_Y( y ), m_Z( z )
{
}

DistanceDataParams::~DistanceDataParams()
{
}

