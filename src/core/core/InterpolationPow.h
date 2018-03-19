/*
 * InterpolationPow.h
 *
 *  Created on: Jan 5, 2018
 *      Author: user
 */

#ifndef CORE_INTERPOLATIONPOW_H_
#define CORE_INTERPOLATIONPOW_H_

#include "InterpolationBase.h"

class InterpolationPow: public InterpolationBase
{
public:
	InterpolationPow( double power );
	virtual ~InterpolationPow();

	double apply( double a ) const override;
private:
	double m_power;
};

#endif /* CORE_INTERPOLATIONPOW_H_ */
