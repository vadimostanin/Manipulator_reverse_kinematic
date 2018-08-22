/*
 * LegAnglesDataChuck.cpp
 *
 *  Created on: 19 мар. 2018 г.
 *      Author: vadim
 */

#include "LegAnglesDataChuck.h"

LegAnglesDataChuck::LegAnglesDataChuck( const std::vector<double> & legsAngles ): IFuncParams( IFuncParams::eDataChunkType::eLegsAngles ),
m_legsAngles( legsAngles )
{
}

