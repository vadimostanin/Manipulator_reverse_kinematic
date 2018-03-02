/*
 * ErrorFunctions.cpp
 *
 *  Created on: Feb 7, 2018
 *      Author: vadym_ostanin
 */

#include "ErrorFunctions.h"
#include <cassert>
#include <cmath>

double ErrorFunctions::error_Legs_5( std::vector<double> & params )
{
	assert( params.size() == 29 );

	double initialX       = params[ 0 ];
	double initialY       = params[ 1 ];
	double initialZ       = params[ 2 ];
	double initialOffsetX = params[ 3 ];
	double initialOffsetY = params[ 4 ];
	double initialOffsetZ = params[ 5 ];
	double targetX        = params[ 6 ];
	double targetY        = params[ 7 ];
	double targetZ        = params[ 8 ];
	double length_0 = params[ 9 + 0 ];
	double angleXY_0 = params[ 9 + 1 ];
	double angleXZ_0 = params[ 9 + 2 ];
	double angleZY_0 = params[ 9 + 3 ];
	double length_1 = params[ 9 + 4 ];
	double angleXY_1 = params[ 9 + 5 ];
	double angleXZ_1 = params[ 9 + 6 ];
	double angleZY_1 = params[ 9 + 7 ];
	double length_2 = params[ 9 + 8 ];
	double angleXY_2 = params[ 9 + 9 ];
	double angleXZ_2 = params[ 9 + 10 ];
	double angleZY_2 = params[ 9 + 11 ];
	double length_3 = params[ 9 + 12 ];
	double angleXY_3 = params[ 9 + 13 ];
	double angleXZ_3 = params[ 9 + 14 ];
	double angleZY_3 = params[ 9 + 15 ];
	double length_4 = params[ 9 + 16 ];
	double angleXY_4 = params[ 9 + 17 ];
	double angleXZ_4 = params[ 9 + 18 ];
	double angleZY_4 = params[ 9 + 19 ];

	double result = sqrt(pow(cos(angleXZ_0+angleXZ_2+angleXZ_1+angleXZ_3)*length_3*cos(angleXY_1+angleXY_3+angleXY_0+angleXY_2)+cos(angleXZ_0)*length_0*cos(angleXY_0)+length_4*cos(angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*cos(angleXZ_0+angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3)+length_1*cos(angleXY_1+angleXY_0)*cos(angleXZ_0+angleXZ_1)+5*initialOffsetX+initialX+cos(angleXY_1+angleXY_0+angleXY_2)*length_2*cos(angleXZ_0+angleXZ_2+angleXZ_1)-targetX, 2)+pow(sin(angleXZ_0+angleXZ_2+angleXZ_1+angleXZ_3)*length_3*cos(angleXY_1+angleXY_3+angleXY_0+angleXY_2)+length_4*sin(angleXZ_0+angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3)*cos(angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)+sin(angleXZ_0+angleXZ_2+angleXZ_1)*cos(angleXY_1+angleXY_0+angleXY_2)*length_2+length_1*sin(angleXZ_0+angleXZ_1)*cos(angleXY_1+angleXY_0)+sin(angleXZ_0)*length_0*cos(angleXY_0)+5*initialOffsetZ+initialZ-targetZ, 2)+pow(sin(angleXY_0)*length_0+5*initialOffsetY+initialY-targetY+length_2*sin(angleXY_1+angleXY_0+angleXY_2)+sin(angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3+length_1*sin(angleXY_1+angleXY_0)+length_4*sin(angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2), 2));

	return result;
}

double ErrorFunctions::error_Legs_10( std::vector<double> & params )
{
	assert( params.size() == 49 );

	double initialX       = params[ 0 ];
	double initialY       = params[ 1 ];
	double initialZ       = params[ 2 ];
	double initialOffsetX = params[ 3 ];
	double initialOffsetY = params[ 4 ];
	double initialOffsetZ = params[ 5 ];
	double targetX        = params[ 6 ];
	double targetY        = params[ 7 ];
	double targetZ        = params[ 8 ];
	double length_0 = params[ 9 + 0 ];
	double angleXY_0 = params[ 9 + 1 ];
	double angleXZ_0 = params[ 9 + 2 ];
	double angleZY_0 = params[ 9 + 3 ];
	double length_1 = params[ 9 + 4 ];
	double angleXY_1 = params[ 9 + 5 ];
	double angleXZ_1 = params[ 9 + 6 ];
	double angleZY_1 = params[ 9 + 7 ];
	double length_2 = params[ 9 + 8 ];
	double angleXY_2 = params[ 9 + 9 ];
	double angleXZ_2 = params[ 9 + 10 ];
	double angleZY_2 = params[ 9 + 11 ];
	double length_3 = params[ 9 + 12 ];
	double angleXY_3 = params[ 9 + 13 ];
	double angleXZ_3 = params[ 9 + 14 ];
	double angleZY_3 = params[ 9 + 15 ];
	double length_4 = params[ 9 + 16 ];
	double angleXY_4 = params[ 9 + 17 ];
	double angleXZ_4 = params[ 9 + 18 ];
	double angleZY_4 = params[ 9 + 19 ];
	double length_5 = params[ 9 + 20 ];
	double angleXY_5 = params[ 9 + 21 ];
	double angleXZ_5 = params[ 9 + 22 ];
	double angleZY_5 = params[ 9 + 23 ];
	double length_6 = params[ 9 + 24 ];
	double angleXY_6 = params[ 9 + 25 ];
	double angleXZ_6 = params[ 9 + 26 ];
	double angleZY_6 = params[ 9 + 27 ];
	double length_7 = params[ 9 + 28 ];
	double angleXY_7 = params[ 9 + 29 ];
	double angleXZ_7 = params[ 9 + 30 ];
	double angleZY_7 = params[ 9 + 31 ];
	double length_8 = params[ 9 + 32 ];
	double angleXY_8 = params[ 9 + 33 ];
	double angleXZ_8 = params[ 9 + 34 ];
	double angleZY_8 = params[ 9 + 35 ];
	double length_9 = params[ 9 + 36 ];
	double angleXY_9 = params[ 9 + 37 ];
	double angleXZ_9 = params[ 9 + 38 ];
	double angleZY_9 = params[ 9 + 39 ];

	double result = pow( pow( length_5*sin( angleXY_0+angleXY_5+angleXY_2+angleXY_4+angleXY_1+angleXY_3)+sin( angleXY_0+angleXY_2+angleXY_4+angleXY_1+angleXY_3)*length_4+length_1*sin( angleXY_0+angleXY_1)+sin( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*length_3+length_0*sin(angleXY_0)+length_9*sin( angleXY_8+angleXY_0+angleXY_5+angleXY_2+angleXY_7+angleXY_4+angleXY_9+angleXY_1+angleXY_6+angleXY_3)+10.0*initialOffsetY+sin( angleXY_8+angleXY_0+angleXY_5+angleXY_2+angleXY_7+angleXY_4+angleXY_1+angleXY_6+angleXY_3)*length_8+initialY-targetY+length_2*sin( angleXY_0+angleXY_2+angleXY_1)+sin( angleXY_0+angleXY_5+angleXY_2+angleXY_4+angleXY_1+angleXY_6+angleXY_3)*length_6+sin( angleXY_0+angleXY_5+angleXY_2+angleXY_7+angleXY_4+angleXY_1+angleXY_6+angleXY_3)*length_7,2.0)+pow( cos( angleXY_8+angleXY_0+angleXY_5+angleXY_2+angleXY_7+angleXY_4+angleXY_9+angleXY_1+angleXY_6+angleXY_3)*cos( angleXZ_1+angleXZ_6+angleXZ_3+angleXZ_8+angleXZ_0+angleXZ_5+angleXZ_2+angleXZ_7+angleXZ_4+angleXZ_9)*length_9+cos(angleXY_0)*length_0*cos(angleXZ_0)+length_2*cos( angleXY_0+angleXY_2+angleXY_1)*cos( angleXZ_1+angleXZ_0+angleXZ_2)+length_5*cos( angleXY_0+angleXY_5+angleXY_2+angleXY_4+angleXY_1+angleXY_3)*cos( angleXZ_1+angleXZ_3+angleXZ_0+angleXZ_5+angleXZ_2+angleXZ_4)+10.0*initialOffsetX+cos( angleXY_0+angleXY_2+angleXY_4+angleXY_1+angleXY_3)*cos( angleXZ_1+angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_4)*length_4+initialX-targetX+cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*length_3*cos( angleXZ_1+angleXZ_3+angleXZ_0+angleXZ_2)+length_6*cos( angleXY_0+angleXY_5+angleXY_2+angleXY_4+angleXY_1+angleXY_6+angleXY_3)*cos( angleXZ_1+angleXZ_6+angleXZ_3+angleXZ_0+angleXZ_5+angleXZ_2+angleXZ_4)+cos( angleXZ_1+angleXZ_0)*length_1*cos( angleXY_0+angleXY_1)+cos( angleXY_8+angleXY_0+angleXY_5+angleXY_2+angleXY_7+angleXY_4+angleXY_1+angleXY_6+angleXY_3)*cos( angleXZ_1+angleXZ_6+angleXZ_3+angleXZ_8+angleXZ_0+angleXZ_5+angleXZ_2+angleXZ_7+angleXZ_4)*length_8+cos( angleXZ_1+angleXZ_6+angleXZ_3+angleXZ_0+angleXZ_5+angleXZ_2+angleXZ_7+angleXZ_4)*length_7*cos( angleXY_0+angleXY_5+angleXY_2+angleXY_7+angleXY_4+angleXY_1+angleXY_6+angleXY_3),2.0)+pow( sin( angleXZ_1+angleXZ_3+angleXZ_0+angleXZ_5+angleXZ_2+angleXZ_4)*length_5*cos( angleXY_0+angleXY_5+angleXY_2+angleXY_4+angleXY_1+angleXY_3)+length_2*sin( angleXZ_1+angleXZ_0+angleXZ_2)*cos( angleXY_0+angleXY_2+angleXY_1)+cos( angleXY_8+angleXY_0+angleXY_5+angleXY_2+angleXY_7+angleXY_4+angleXY_9+angleXY_1+angleXY_6+angleXY_3)*sin( angleXZ_1+angleXZ_6+angleXZ_3+angleXZ_8+angleXZ_0+angleXZ_5+angleXZ_2+angleXZ_7+angleXZ_4+angleXZ_9)*length_9+sin( angleXZ_1+angleXZ_0)*length_1*cos( angleXY_0+angleXY_1)+sin( angleXZ_1+angleXZ_6+angleXZ_3+angleXZ_8+angleXZ_0+angleXZ_5+angleXZ_2+angleXZ_7+angleXZ_4)*cos( angleXY_8+angleXY_0+angleXY_5+angleXY_2+angleXY_7+angleXY_4+angleXY_1+angleXY_6+angleXY_3)*length_8+cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*length_3*sin( angleXZ_1+angleXZ_3+angleXZ_0+angleXZ_2)+sin( angleXZ_1+angleXZ_6+angleXZ_3+angleXZ_0+angleXZ_5+angleXZ_2+angleXZ_7+angleXZ_4)*length_7*cos( angleXY_0+angleXY_5+angleXY_2+angleXY_7+angleXY_4+angleXY_1+angleXY_6+angleXY_3)+sin(angleXZ_0)*cos(angleXY_0)*length_0+cos( angleXY_0+angleXY_2+angleXY_4+angleXY_1+angleXY_3)*sin( angleXZ_1+angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_4)*length_4+sin( angleXZ_1+angleXZ_6+angleXZ_3+angleXZ_0+angleXZ_5+angleXZ_2+angleXZ_4)*length_6*cos( angleXY_0+angleXY_5+angleXY_2+angleXY_4+angleXY_1+angleXY_6+angleXY_3)+10.0*initialOffsetZ+initialZ-targetZ,2.0),(1.0/2.0));

	return result;
}
