/*
 * InterpolatedStopStartSine.cpp
 *
 *  Created on: Jan 31, 2018
 *      Author: vadym_ostanin
 */

#include "InterpolatedStopStartSine.h"
#include <cmath>
#include <algorithm>

InterpolatedStopStartSine::InterpolatedStopStartSine()
{
}

InterpolatedStopStartSine::~InterpolatedStopStartSine()
{
}

double InterpolatedStopStartSine::apply( double a ) const
{
	const double minA = 0;
	const double maxA = 1.0;
	a = std::max( std::min( a, maxA ), minA );
	double interpValue = 0.0;
	if( a <= 0.25 )
	{
		interpValue = 0.2 + ( 0.8 * ( 1.0 - std::cos( 1.3 * a * M_PI ) - 1 ) ) / 2.0;
	}
	else
	{
		interpValue = -0.2 + ( 0.8 * ( 1.0 - std::cos( 1.3 * a * M_PI ) - 1.05 ) ) / 2.0;
	}
	return interpValue;
}
