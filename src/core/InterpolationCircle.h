/*
 * InterpolationCircle.h
 *
 *  Created on: Jan 9, 2018
 *      Author: user
 */

#ifndef CORE_INTERPOLATIONCIRCLE_H_
#define CORE_INTERPOLATIONCIRCLE_H_

#include "InterpolationBase.h"

class InterpolationCircle: public InterpolationBase
{
public:
	InterpolationCircle();
	virtual ~InterpolationCircle();

	double apply( double a ) const override;
};

#endif /* CORE_INTERPOLATIONCIRCLE_H_ */
