/*
 * InterpolationLinear.h
 *
 *  Created on: Jan 5, 2018
 *      Author: user
 */

#ifndef CORE_INTERPOLATIONLINEAR_H_
#define CORE_INTERPOLATIONLINEAR_H_

#include "InterpolationBase.h"

class InterpolationLinear : public InterpolationBase
{
public:
	InterpolationLinear();
	virtual ~InterpolationLinear();

	double diff( double a ) const override;
	double apply( double a ) const override;
};

#endif /* CORE_INTERPOLATIONLINEAR_H_ */
