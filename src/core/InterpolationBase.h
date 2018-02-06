/*
 * InterpolationBase.h
 *
 *  Created on: Jan 5, 2018
 *      Author: user
 */

#ifndef CORE_INTERPOLATIONBASE_H_
#define CORE_INTERPOLATIONBASE_H_

/** Takes a linear value in the range of 0-1 and outputs a (usually) non-linear, interpolated value.
 * @author Nathan Sweet */

class InterpolationBase
{
public:
	InterpolationBase();
	virtual ~InterpolationBase();

	/** @param a Alpha value between 0 and 1. */
public:
	virtual double apply( double a ) const = 0;

	virtual double diff( double a ) const = 0;

	double apply3( double start, double end, double a ) const;

	double getStart( double middle, double end, double middleA ) const;
	double getEnd( double start, double middle, double middleA ) const;
};

#endif /* CORE_INTERPOLATIONBASE_H_ */
