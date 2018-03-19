/*
 * InterpolationSine.h
 *
 *  Created on: Jan 9, 2018
 *      Author: user
 */

#ifndef CORE_INTERPOLATIONSINE_H_
#define CORE_INTERPOLATIONSINE_H_

#include "InterpolationBase.h"

class InterpolationSine: public InterpolationBase
{
public:
	InterpolationSine();
	virtual ~InterpolationSine();

	double diff( double a ) const override;
	double apply( double a ) const override;
};

#endif /* CORE_INTERPOLATIONSINE_H_ */
