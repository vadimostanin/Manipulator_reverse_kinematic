/*
 * InterpolationFade.h
 *
 *  Created on: Jan 5, 2018
 *      Author: user
 */

#ifndef CORE_INTERPOLATIONFADE_H_
#define CORE_INTERPOLATIONFADE_H_

#include "InterpolationBase.h"

class InterpolationFade: public InterpolationBase
{
public:
	InterpolationFade();
	virtual ~InterpolationFade();

	double apply ( double a ) const override;
};

#endif /* CORE_INTERPOLATIONFADE_H_ */
