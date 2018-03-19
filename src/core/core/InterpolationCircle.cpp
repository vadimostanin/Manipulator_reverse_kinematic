/*
 * InterpolationCircle.cpp
 *
 *  Created on: Jan 9, 2018
 *      Author: user
 */

#include "InterpolationCircle.h"
#include <cmath>

InterpolationCircle::InterpolationCircle()
{
}

InterpolationCircle::~InterpolationCircle()
{
}

double InterpolationCircle::apply( double a ) const
{
	if( a <= 0.5f )
	{
		a *= 2;
		return ( 1.0 - std::sqrt( 1.0 - a * a ) ) / 2.0;
	}
	a--;
	a *= 2;
	return ( std::sqrt( 1.0 - a * a ) + 1.0 ) / 2.0;
}
