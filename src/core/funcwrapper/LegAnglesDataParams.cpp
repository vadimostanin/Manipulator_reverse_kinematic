/*
 * LegAnglesDataChuck.cpp
 *
 *  Created on: 19 мар. 2018 г.
 *      Author: vadim
 */

#include "LegAnglesDataParams.h"

LegAnglesDataParams::LegAnglesDataParams( const std::vector<double> & legsAngles ): IFuncParams( IFuncParams::eParamType::eLegsAngles ),
m_legsAngles( legsAngles )
{
}

