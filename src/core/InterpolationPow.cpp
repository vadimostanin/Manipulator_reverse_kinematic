/*
 * InterpolationPow.cpp
 *
 *  Created on: Jan 5, 2018
 *      Author: user
 */

#include "InterpolationPow.h"
#include <cmath>

InterpolationPow::InterpolationPow( double power ): m_power( power )
{
}

InterpolationPow::~InterpolationPow()
{
}

double InterpolationPow::apply( double a ) const
{
	if( a <= 0.5f )
	{
		return ( double ) std::pow( a * 2, m_power ) / 2.0;
	}
	return ( double ) std::pow( ( a - 1 ) * 2, m_power ) / ( ( ( int )m_power) % 2 == 0 ? -2 : 2 ) + 1;
}
