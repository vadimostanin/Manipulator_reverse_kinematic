/*
 * InterpolationSine.cpp
 *
 *  Created on: Jan 9, 2018
 *      Author: user
 */

#include "InterpolationSine.h"
#include <cmath>

InterpolationSine::InterpolationSine()
{
}

InterpolationSine::~InterpolationSine()
{
}

double InterpolationSine::apply( double a ) const
{
	double value = ( 1.0 - std::cos( a * M_PI ) ) / 2.0;
	return value;
}

double InterpolationSine::diff( double a ) const
{
	double diff = ( 1.0 / 2.0 ) * M_PI * std::sin( a * M_PI );
	return diff;
}
