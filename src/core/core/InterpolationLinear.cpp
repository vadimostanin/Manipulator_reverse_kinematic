/*
 * InterpolationLinear.cpp
 *
 *  Created on: Jan 5, 2018
 *      Author: user
 */

#include "InterpolationLinear.h"

InterpolationLinear::InterpolationLinear()
{
}

InterpolationLinear::~InterpolationLinear()
{
}

double InterpolationLinear::apply( double a ) const
{
	return a;
}

double InterpolationLinear::diff( double a ) const
{
	return 1.0;
}
