/*
 * InterpolationFade.cpp
 *
 *  Created on: Jan 5, 2018
 *      Author: user
 */

#include "InterpolationFade.h"
#include "Utils.h"

InterpolationFade::InterpolationFade() {
	// TODO Auto-generated constructor stub

}

InterpolationFade::~InterpolationFade() {
	// TODO Auto-generated destructor stub
}

double InterpolationFade::apply( double a ) const
{
    return Utils::clamp( a * a * a * (a * (a * 6 - 15) + 10), 0, 1 );
}
