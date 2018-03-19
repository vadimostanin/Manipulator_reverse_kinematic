/*
 * InterpolationBase.cpp
 *
 *  Created on: Jan 5, 2018
 *      Author: user
 */

#include "InterpolationBase.h"

InterpolationBase::InterpolationBase()
{
}

InterpolationBase::~InterpolationBase()
{
}

/** @param a Alpha value between 0 and 1. */
double InterpolationBase::apply3( double start, double end, double a ) const
{
	double appliedValue = apply( a );
	double value = start + ( end - start ) * appliedValue;
    return value;
}

double InterpolationBase::getStart( double middle, double end, double middleA ) const
{
	double appliedValue = apply( middleA );
	double start = ( middle - end * appliedValue ) / ( 1.0 - appliedValue );
	return start;
}

double InterpolationBase::getEnd( double start, double middle, double middleA ) const
{
	double appliedValue = apply( middleA );
	double end = ( middle - start * ( appliedValue - 1.0 ) ) / appliedValue;
	return end;
}
