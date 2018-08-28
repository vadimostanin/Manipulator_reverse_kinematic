/*
 * AngleDataChunk.cpp
 *
 *  Created on: 19 мар. 2018 г.
 *      Author: vadim
 */

#include "AngleFuncParams.h"

AngleFuncParams::AngleFuncParams( double angle ) : IFuncParams( IFuncParams::eParamType::eAngle ), m_Angle( angle )
{
}

AngleFuncParams::~AngleFuncParams()
{
}

