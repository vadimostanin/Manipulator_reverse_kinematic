/*
 * InterpolationExp.h
 *
 *  Created on: Jan 5, 2018
 *      Author: user
 */

#ifndef CORE_INTERPOLATIONEXP_H_
#define CORE_INTERPOLATIONEXP_H_

#include "InterpolationBase.h"

class InterpolationExp: public InterpolationBase
{
public:
	InterpolationExp( float value, float power );
	virtual ~InterpolationExp();

	double apply( double a ) const override;

private:
	double m_value, m_power, m_min, m_scale;
};

#endif /* CORE_INTERPOLATIONEXP_H_ */
