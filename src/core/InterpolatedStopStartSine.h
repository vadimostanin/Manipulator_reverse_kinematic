/*
 * InterpolatedStopStartSine.h
 *
 *  Created on: Jan 31, 2018
 *      Author: vadym_ostanin
 */

#ifndef CORE_INTERPOLATEDSTOPSTARTSINE_H_
#define CORE_INTERPOLATEDSTOPSTARTSINE_H_

#include "InterpolationBase.h"

class InterpolatedStopStartSine: public InterpolationBase
{
public:
	InterpolatedStopStartSine();
	virtual ~InterpolatedStopStartSine();

	double apply( double a ) const override;
};

#endif /* CORE_INTERPOLATEDSTOPSTARTSINE_H_ */
