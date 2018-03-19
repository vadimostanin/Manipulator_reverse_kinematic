/*
 * InterpolationExp.cpp
 *
 *  Created on: Jan 5, 2018
 *      Author: user
 */

#include "InterpolationExp.h"
#include <cmath>

InterpolationExp::InterpolationExp( float value, float power )
{
	m_value = value;
	m_power = power;
	m_min = ( double )std::pow( value, - power );
	m_scale = 1.0 / ( 1.0 - m_min );
}

InterpolationExp::~InterpolationExp()
{
}

double InterpolationExp::apply( double a ) const
{
	if( a <= 0.5f )
	{
		return ( ( double ) std::pow( m_value, m_power * ( a * 2.0 - 1.0 ) ) - m_min ) * m_scale / 2;
	}
	return( 2.0 - ( ( double ) std::pow( m_value, - m_power * ( a * 2.0 - 1.0 ) ) - m_min ) * m_scale ) / 2;
}
