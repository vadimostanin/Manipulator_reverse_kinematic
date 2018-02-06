/*
 * DerivativeFunctions.cpp
 *
 *  Created on: Dec 15, 2017
 *      Author: user
 */

#include "DerivativeFunctions.h"
#include <cassert>
#include <cmath>

//static double operator ^ ( double value, double power )
//{
//	return pow( value, power );
//}

double DerivativeFunctions::derivative_XY_1_Legs_0( std::vector<double> & params )
{
	assert( params.size() == 13 );

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

	double result = -pow( pow( cos(angleXY_0)*cos(angleXZ_0)*length_0+initialOffsetX+initialX-targetX,2.0)+pow( targetZ-cos(angleXY_0)*length_0*sin(angleXZ_0)-initialOffsetZ-initialZ,2.0)+pow( initialOffsetY+initialY-targetY+sin(angleXY_0)*length_0,2.0),-(1.0/2.0))*( cos(angleXZ_0)*( cos(angleXY_0)*cos(angleXZ_0)*length_0+initialOffsetX+initialX-targetX)*sin(angleXY_0)*length_0-cos(angleXY_0)*( initialOffsetY+initialY-targetY+sin(angleXY_0)*length_0)*length_0-( targetZ-cos(angleXY_0)*length_0*sin(angleXZ_0)-initialOffsetZ-initialZ)*sin(angleXY_0)*length_0*sin(angleXZ_0));

	return result;
}

double DerivativeFunctions::derivative_XZ_1_Legs_0( std::vector<double> & params )
{
	assert( params.size() == 13 );

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

	double result = -( cos(angleXY_0)*cos(angleXZ_0)*( targetZ-cos(angleXY_0)*length_0*sin(angleXZ_0)-initialOffsetZ-initialZ)*length_0+cos(angleXY_0)*( cos(angleXY_0)*cos(angleXZ_0)*length_0+initialOffsetX+initialX-targetX)*length_0*sin(angleXZ_0))*pow( pow( cos(angleXY_0)*cos(angleXZ_0)*length_0+initialOffsetX+initialX-targetX,2.0)+pow( targetZ-cos(angleXY_0)*length_0*sin(angleXZ_0)-initialOffsetZ-initialZ,2.0)+pow( initialOffsetY+initialY-targetY+sin(angleXY_0)*length_0,2.0),-(1.0/2.0));

	return result;
}

double DerivativeFunctions::derivative_XY_2_Legs_0( std::vector<double> & params )
{
	assert( params.size() == 17 );

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

	double result = -pow( pow( 2.0*initialOffsetX+initialX-targetX+cos( angleXY_0+angleXY_1)*cos( angleXZ_1+angleXZ_0)*length_1+cos(angleXY_0)*length_0*cos(angleXZ_0),2.0)+pow( length_1*sin( angleXY_0+angleXY_1)+2.0*initialOffsetY+length_0*sin(angleXY_0)+initialY-targetY,2.0)+pow( targetZ-sin( angleXZ_1+angleXZ_0)*cos( angleXY_0+angleXY_1)*length_1+-2.0*initialOffsetZ-cos(angleXY_0)*sin(angleXZ_0)*length_0-initialZ,2.0),-(1.0/2.0))*( ( 2.0*initialOffsetX+initialX-targetX+cos( angleXY_0+angleXY_1)*cos( angleXZ_1+angleXZ_0)*length_1+cos(angleXY_0)*length_0*cos(angleXZ_0))*( length_0*sin(angleXY_0)*cos(angleXZ_0)+cos( angleXZ_1+angleXZ_0)*length_1*sin( angleXY_0+angleXY_1))-( 0.0+cos( angleXY_0+angleXY_1)*length_1+cos(angleXY_0)*length_0)*( length_1*sin( angleXY_0+angleXY_1)+2.0*initialOffsetY+length_0*sin(angleXY_0)+initialY-targetY)-( sin(angleXZ_0)*length_0*sin(angleXY_0)+sin( angleXZ_1+angleXZ_0)*length_1*sin( angleXY_0+angleXY_1))*( targetZ-sin( angleXZ_1+angleXZ_0)*cos( angleXY_0+angleXY_1)*length_1+-2.0*initialOffsetZ-cos(angleXY_0)*sin(angleXZ_0)*length_0-initialZ));

	return result;
}

double DerivativeFunctions::derivative_XY_2_Legs_1( std::vector<double> & params )
{
	assert( params.size() == 17 );

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

	double result = -pow( pow( 2.0*initialOffsetX+initialX-targetX+cos( angleXY_0+angleXY_1)*cos( angleXZ_1+angleXZ_0)*length_1+cos(angleXY_0)*length_0*cos(angleXZ_0),2.0)+pow( length_1*sin( angleXY_0+angleXY_1)+2.0*initialOffsetY+length_0*sin(angleXY_0)+initialY-targetY,2.0)+pow( targetZ-sin( angleXZ_1+angleXZ_0)*cos( angleXY_0+angleXY_1)*length_1+-2.0*initialOffsetZ-cos(angleXY_0)*sin(angleXZ_0)*length_0-initialZ,2.0),-(1.0/2.0))*( ( 2.0*initialOffsetX+initialX-targetX+cos( angleXY_0+angleXY_1)*cos( angleXZ_1+angleXZ_0)*length_1+cos(angleXY_0)*length_0*cos(angleXZ_0))*cos( angleXZ_1+angleXZ_0)*length_1*sin( angleXY_0+angleXY_1)-( 0.0+cos( angleXY_0+angleXY_1)*length_1)*( length_1*sin( angleXY_0+angleXY_1)+2.0*initialOffsetY+length_0*sin(angleXY_0)+initialY-targetY)-sin( angleXZ_1+angleXZ_0)*length_1*sin( angleXY_0+angleXY_1)*( targetZ-sin( angleXZ_1+angleXZ_0)*cos( angleXY_0+angleXY_1)*length_1+-2.0*initialOffsetZ-cos(angleXY_0)*sin(angleXZ_0)*length_0-initialZ));

	return result;
}

double DerivativeFunctions::derivative_XZ_2_Legs_0( std::vector<double> & params )
{
	assert( params.size() == 17 );

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

	double result = -pow( pow( 2.0*initialOffsetX+initialX-targetX+cos( angleXY_0+angleXY_1)*cos( angleXZ_1+angleXZ_0)*length_1+cos(angleXY_0)*length_0*cos(angleXZ_0),2.0)+pow( length_1*sin( angleXY_0+angleXY_1)+2.0*initialOffsetY+length_0*sin(angleXY_0)+initialY-targetY,2.0)+pow( targetZ-sin( angleXZ_1+angleXZ_0)*cos( angleXY_0+angleXY_1)*length_1+-2.0*initialOffsetZ-cos(angleXY_0)*sin(angleXZ_0)*length_0-initialZ,2.0),-(1.0/2.0))*( ( cos( angleXY_0+angleXY_1)*cos( angleXZ_1+angleXZ_0)*length_1+cos(angleXY_0)*length_0*cos(angleXZ_0))*( targetZ-sin( angleXZ_1+angleXZ_0)*cos( angleXY_0+angleXY_1)*length_1+-2.0*initialOffsetZ-cos(angleXY_0)*sin(angleXZ_0)*length_0-initialZ)+( 2.0*initialOffsetX+initialX-targetX+cos( angleXY_0+angleXY_1)*cos( angleXZ_1+angleXZ_0)*length_1+cos(angleXY_0)*length_0*cos(angleXZ_0))*( sin( angleXZ_1+angleXZ_0)*cos( angleXY_0+angleXY_1)*length_1+cos(angleXY_0)*sin(angleXZ_0)*length_0));

	return result;
}

double DerivativeFunctions::derivative_XZ_2_Legs_1( std::vector<double> & params )
{
	assert( params.size() == 17 );

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

	double result = -pow( pow( 2.0*initialOffsetX+initialX-targetX+cos( angleXY_0+angleXY_1)*cos( angleXZ_1+angleXZ_0)*length_1+cos(angleXY_0)*length_0*cos(angleXZ_0),2.0)+pow( length_1*sin( angleXY_0+angleXY_1)+2.0*initialOffsetY+length_0*sin(angleXY_0)+initialY-targetY,2.0)+pow( targetZ-sin( angleXZ_1+angleXZ_0)*cos( angleXY_0+angleXY_1)*length_1+-2.0*initialOffsetZ-cos(angleXY_0)*sin(angleXZ_0)*length_0-initialZ,2.0),-(1.0/2.0))*( cos( angleXY_0+angleXY_1)*cos( angleXZ_1+angleXZ_0)*length_1*( targetZ-sin( angleXZ_1+angleXZ_0)*cos( angleXY_0+angleXY_1)*length_1+-2.0*initialOffsetZ-cos(angleXY_0)*sin(angleXZ_0)*length_0-initialZ)+sin( angleXZ_1+angleXZ_0)*cos( angleXY_0+angleXY_1)*( 2.0*initialOffsetX+initialX-targetX+cos( angleXY_0+angleXY_1)*cos( angleXZ_1+angleXZ_0)*length_1+cos(angleXY_0)*length_0*cos(angleXZ_0))*length_1);

	return result;
}

double DerivativeFunctions::derivative_XY_3_Legs_0( std::vector<double> & params )
{
	assert( params.size() == 21 );

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

	double result = -( ( 3.0*initialOffsetZ+initialZ-targetZ+length_0*sin(angleXZ_0)*cos(angleXY_0)+cos( angleXY_1+angleXY_0)*sin( angleXZ_1+angleXZ_0)*length_1+length_2*sin( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2))*( length_2*sin( angleXZ_2+angleXZ_1+angleXZ_0)*sin( angleXY_1+angleXY_0+angleXY_2)+sin( angleXY_1+angleXY_0)*sin( angleXZ_1+angleXZ_0)*length_1+length_0*sin(angleXZ_0)*sin(angleXY_0))+( length_0*cos(angleXY_0)*cos(angleXZ_0)+cos( angleXY_1+angleXY_0)*length_1*cos( angleXZ_1+angleXZ_0)+length_2*cos( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2)+3.0*initialOffsetX+initialX-targetX)*( sin( angleXY_1+angleXY_0)*length_1*cos( angleXZ_1+angleXZ_0)+length_0*sin(angleXY_0)*cos(angleXZ_0)+length_2*cos( angleXZ_2+angleXZ_1+angleXZ_0)*sin( angleXY_1+angleXY_0+angleXY_2))-( 3.0*initialOffsetY+initialY-targetY+length_0*sin(angleXY_0)+length_2*sin( angleXY_1+angleXY_0+angleXY_2)+sin( angleXY_1+angleXY_0)*length_1)*( cos( angleXY_1+angleXY_0)*length_1+length_2*cos( angleXY_1+angleXY_0+angleXY_2)+length_0*cos(angleXY_0)))*pow( pow( length_0*cos(angleXY_0)*cos(angleXZ_0)+cos( angleXY_1+angleXY_0)*length_1*cos( angleXZ_1+angleXZ_0)+length_2*cos( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2)+3.0*initialOffsetX+initialX-targetX,2.0)+pow( 3.0*initialOffsetY+initialY-targetY+length_0*sin(angleXY_0)+length_2*sin( angleXY_1+angleXY_0+angleXY_2)+sin( angleXY_1+angleXY_0)*length_1,2.0)+pow( 3.0*initialOffsetZ+initialZ-targetZ+length_0*sin(angleXZ_0)*cos(angleXY_0)+cos( angleXY_1+angleXY_0)*sin( angleXZ_1+angleXZ_0)*length_1+length_2*sin( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2),2.0),-(1.0/2.0));

	return result;
}

double DerivativeFunctions::derivative_XY_3_Legs_1( std::vector<double> & params )
{
	assert( params.size() == 21 );

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

	double result = pow( pow( length_0*cos(angleXY_0)*cos(angleXZ_0)+cos( angleXY_1+angleXY_0)*length_1*cos( angleXZ_1+angleXZ_0)+length_2*cos( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2)+3.0*initialOffsetX+initialX-targetX,2.0)+pow( 3.0*initialOffsetY+initialY-targetY+length_0*sin(angleXY_0)+length_2*sin( angleXY_1+angleXY_0+angleXY_2)+sin( angleXY_1+angleXY_0)*length_1,2.0)+pow( 3.0*initialOffsetZ+initialZ-targetZ+length_0*sin(angleXZ_0)*cos(angleXY_0)+cos( angleXY_1+angleXY_0)*sin( angleXZ_1+angleXZ_0)*length_1+length_2*sin( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2),2.0),-(1.0/2.0))*( ( cos( angleXY_1+angleXY_0)*length_1+length_2*cos( angleXY_1+angleXY_0+angleXY_2))*( 3.0*initialOffsetY+initialY-targetY+length_0*sin(angleXY_0)+length_2*sin( angleXY_1+angleXY_0+angleXY_2)+sin( angleXY_1+angleXY_0)*length_1)-( length_0*cos(angleXY_0)*cos(angleXZ_0)+cos( angleXY_1+angleXY_0)*length_1*cos( angleXZ_1+angleXZ_0)+length_2*cos( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2)+3.0*initialOffsetX+initialX-targetX)*( sin( angleXY_1+angleXY_0)*length_1*cos( angleXZ_1+angleXZ_0)+length_2*cos( angleXZ_2+angleXZ_1+angleXZ_0)*sin( angleXY_1+angleXY_0+angleXY_2))-( 3.0*initialOffsetZ+initialZ-targetZ+length_0*sin(angleXZ_0)*cos(angleXY_0)+cos( angleXY_1+angleXY_0)*sin( angleXZ_1+angleXZ_0)*length_1+length_2*sin( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2))*( length_2*sin( angleXZ_2+angleXZ_1+angleXZ_0)*sin( angleXY_1+angleXY_0+angleXY_2)+sin( angleXY_1+angleXY_0)*sin( angleXZ_1+angleXZ_0)*length_1));

	return result;
}

double DerivativeFunctions::derivative_XY_3_Legs_2( std::vector<double> & params )
{
	assert( params.size() == 21 );

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

	double result = -pow( pow( length_0*cos(angleXY_0)*cos(angleXZ_0)+cos( angleXY_1+angleXY_0)*length_1*cos( angleXZ_1+angleXZ_0)+length_2*cos( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2)+3.0*initialOffsetX+initialX-targetX,2.0)+pow( 3.0*initialOffsetY+initialY-targetY+length_0*sin(angleXY_0)+length_2*sin( angleXY_1+angleXY_0+angleXY_2)+sin( angleXY_1+angleXY_0)*length_1,2.0)+pow( 3.0*initialOffsetZ+initialZ-targetZ+length_0*sin(angleXZ_0)*cos(angleXY_0)+cos( angleXY_1+angleXY_0)*sin( angleXZ_1+angleXZ_0)*length_1+length_2*sin( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2),2.0),-(1.0/2.0))*( length_2*( length_0*cos(angleXY_0)*cos(angleXZ_0)+cos( angleXY_1+angleXY_0)*length_1*cos( angleXZ_1+angleXZ_0)+length_2*cos( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2)+3.0*initialOffsetX+initialX-targetX)*cos( angleXZ_2+angleXZ_1+angleXZ_0)*sin( angleXY_1+angleXY_0+angleXY_2)+length_2*sin( angleXZ_2+angleXZ_1+angleXZ_0)*( 3.0*initialOffsetZ+initialZ-targetZ+length_0*sin(angleXZ_0)*cos(angleXY_0)+cos( angleXY_1+angleXY_0)*sin( angleXZ_1+angleXZ_0)*length_1+length_2*sin( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2))*sin( angleXY_1+angleXY_0+angleXY_2)-length_2*( 3.0*initialOffsetY+initialY-targetY+length_0*sin(angleXY_0)+length_2*sin( angleXY_1+angleXY_0+angleXY_2)+sin( angleXY_1+angleXY_0)*length_1)*cos( angleXY_1+angleXY_0+angleXY_2));

	return result;
}

double DerivativeFunctions::derivative_XZ_3_Legs_0( std::vector<double> & params )
{
	assert( params.size() == 21 );

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

	double result = -( ( length_0*cos(angleXY_0)*cos(angleXZ_0)+cos( angleXY_1+angleXY_0)*length_1*cos( angleXZ_1+angleXZ_0)+length_2*cos( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2)+3.0*initialOffsetX+initialX-targetX)*( length_0*sin(angleXZ_0)*cos(angleXY_0)+cos( angleXY_1+angleXY_0)*sin( angleXZ_1+angleXZ_0)*length_1+length_2*sin( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2))-( 3.0*initialOffsetZ+initialZ-targetZ+length_0*sin(angleXZ_0)*cos(angleXY_0)+cos( angleXY_1+angleXY_0)*sin( angleXZ_1+angleXZ_0)*length_1+length_2*sin( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2))*( length_0*cos(angleXY_0)*cos(angleXZ_0)+cos( angleXY_1+angleXY_0)*length_1*cos( angleXZ_1+angleXZ_0)+length_2*cos( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2)))*pow( pow( length_0*cos(angleXY_0)*cos(angleXZ_0)+cos( angleXY_1+angleXY_0)*length_1*cos( angleXZ_1+angleXZ_0)+length_2*cos( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2)+3.0*initialOffsetX+initialX-targetX,2.0)+pow( 3.0*initialOffsetY+initialY-targetY+length_0*sin(angleXY_0)+length_2*sin( angleXY_1+angleXY_0+angleXY_2)+sin( angleXY_1+angleXY_0)*length_1,2.0)+pow( 3.0*initialOffsetZ+initialZ-targetZ+length_0*sin(angleXZ_0)*cos(angleXY_0)+cos( angleXY_1+angleXY_0)*sin( angleXZ_1+angleXZ_0)*length_1+length_2*sin( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2),2.0),-(1.0/2.0));

	return result;
}

double DerivativeFunctions::derivative_XZ_3_Legs_1( std::vector<double> & params )
{
	assert( params.size() == 21 );

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

	double result = -( ( length_0*cos(angleXY_0)*cos(angleXZ_0)+cos( angleXY_1+angleXY_0)*length_1*cos( angleXZ_1+angleXZ_0)+length_2*cos( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2)+3.0*initialOffsetX+initialX-targetX)*( cos( angleXY_1+angleXY_0)*sin( angleXZ_1+angleXZ_0)*length_1+length_2*sin( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2))-( 3.0*initialOffsetZ+initialZ-targetZ+length_0*sin(angleXZ_0)*cos(angleXY_0)+cos( angleXY_1+angleXY_0)*sin( angleXZ_1+angleXZ_0)*length_1+length_2*sin( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2))*( cos( angleXY_1+angleXY_0)*length_1*cos( angleXZ_1+angleXZ_0)+length_2*cos( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2)))*pow( pow( length_0*cos(angleXY_0)*cos(angleXZ_0)+cos( angleXY_1+angleXY_0)*length_1*cos( angleXZ_1+angleXZ_0)+length_2*cos( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2)+3.0*initialOffsetX+initialX-targetX,2.0)+pow( 3.0*initialOffsetY+initialY-targetY+length_0*sin(angleXY_0)+length_2*sin( angleXY_1+angleXY_0+angleXY_2)+sin( angleXY_1+angleXY_0)*length_1,2.0)+pow( 3.0*initialOffsetZ+initialZ-targetZ+length_0*sin(angleXZ_0)*cos(angleXY_0)+cos( angleXY_1+angleXY_0)*sin( angleXZ_1+angleXZ_0)*length_1+length_2*sin( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2),2.0),-(1.0/2.0));

	return result;
}

double DerivativeFunctions::derivative_XZ_3_Legs_2( std::vector<double> & params )
{
	assert( params.size() == 21 );

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

	double result = -( length_2*( length_0*cos(angleXY_0)*cos(angleXZ_0)+cos( angleXY_1+angleXY_0)*length_1*cos( angleXZ_1+angleXZ_0)+length_2*cos( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2)+3.0*initialOffsetX+initialX-targetX)*sin( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2)-length_2*cos( angleXZ_2+angleXZ_1+angleXZ_0)*( 3.0*initialOffsetZ+initialZ-targetZ+length_0*sin(angleXZ_0)*cos(angleXY_0)+cos( angleXY_1+angleXY_0)*sin( angleXZ_1+angleXZ_0)*length_1+length_2*sin( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2))*cos( angleXY_1+angleXY_0+angleXY_2))*pow( pow( length_0*cos(angleXY_0)*cos(angleXZ_0)+cos( angleXY_1+angleXY_0)*length_1*cos( angleXZ_1+angleXZ_0)+length_2*cos( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2)+3.0*initialOffsetX+initialX-targetX,2.0)+pow( 3.0*initialOffsetY+initialY-targetY+length_0*sin(angleXY_0)+length_2*sin( angleXY_1+angleXY_0+angleXY_2)+sin( angleXY_1+angleXY_0)*length_1,2.0)+pow( 3.0*initialOffsetZ+initialZ-targetZ+length_0*sin(angleXZ_0)*cos(angleXY_0)+cos( angleXY_1+angleXY_0)*sin( angleXZ_1+angleXZ_0)*length_1+length_2*sin( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2),2.0),-(1.0/2.0));

	return result;
}

double DerivativeFunctions::derivative_XY_4_Legs_0( std::vector<double> & params )
{
	assert( params.size() == 25 );

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

	double result = -pow( pow( length_3*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*cos( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)+4.0*initialOffsetX+initialX-targetX+cos( angleXY_0+angleXY_1)*cos( angleXZ_0+angleXZ_1)*length_1+length_0*cos(angleXZ_0)*cos(angleXY_0)+length_2*cos( angleXY_0+angleXY_2+angleXY_1)*cos( angleXZ_0+angleXZ_2+angleXZ_1),2.0)+pow( sin( angleXY_0+angleXY_1)*length_1+length_2*sin( angleXY_0+angleXY_2+angleXY_1)+4.0*initialOffsetY+initialY-targetY+sin(angleXY_0)*length_0+sin( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*length_3,2.0)+pow( sin(angleXZ_0)*length_0*cos(angleXY_0)+length_2*sin( angleXZ_0+angleXZ_2+angleXZ_1)*cos( angleXY_0+angleXY_2+angleXY_1)+sin( angleXZ_0+angleXZ_1)*cos( angleXY_0+angleXY_1)*length_1+sin( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)*length_3*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3)+4.0*initialOffsetZ+initialZ-targetZ,2.0),-(1.0/2.0))*( ( sin( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*length_3*cos( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)+length_2*sin( angleXY_0+angleXY_2+angleXY_1)*cos( angleXZ_0+angleXZ_2+angleXZ_1)+sin(angleXY_0)*length_0*cos(angleXZ_0)+sin( angleXY_0+angleXY_1)*cos( angleXZ_0+angleXZ_1)*length_1)*( length_3*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*cos( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)+4.0*initialOffsetX+initialX-targetX+cos( angleXY_0+angleXY_1)*cos( angleXZ_0+angleXZ_1)*length_1+length_0*cos(angleXZ_0)*cos(angleXY_0)+length_2*cos( angleXY_0+angleXY_2+angleXY_1)*cos( angleXZ_0+angleXZ_2+angleXZ_1))+( length_2*sin( angleXY_0+angleXY_2+angleXY_1)*sin( angleXZ_0+angleXZ_2+angleXZ_1)+sin( angleXY_0+angleXY_1)*sin( angleXZ_0+angleXZ_1)*length_1+sin( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)*sin( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*length_3+sin(angleXZ_0)*sin(angleXY_0)*length_0)*( sin(angleXZ_0)*length_0*cos(angleXY_0)+length_2*sin( angleXZ_0+angleXZ_2+angleXZ_1)*cos( angleXY_0+angleXY_2+angleXY_1)+sin( angleXZ_0+angleXZ_1)*cos( angleXY_0+angleXY_1)*length_1+sin( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)*length_3*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3)+4.0*initialOffsetZ+initialZ-targetZ)-( sin( angleXY_0+angleXY_1)*length_1+length_2*sin( angleXY_0+angleXY_2+angleXY_1)+4.0*initialOffsetY+initialY-targetY+sin(angleXY_0)*length_0+sin( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*length_3)*( length_2*cos( angleXY_0+angleXY_2+angleXY_1)+length_0*cos(angleXY_0)+cos( angleXY_0+angleXY_1)*length_1+length_3*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3)));;

	return result;
}

double DerivativeFunctions::derivative_XY_4_Legs_1( std::vector<double> & params )
{
	assert( params.size() == 25 );

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

	double result = -( ( length_3*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*cos( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)+4.0*initialOffsetX+initialX-targetX+cos( angleXY_0+angleXY_1)*cos( angleXZ_0+angleXZ_1)*length_1+length_0*cos(angleXZ_0)*cos(angleXY_0)+length_2*cos( angleXY_0+angleXY_2+angleXY_1)*cos( angleXZ_0+angleXZ_2+angleXZ_1))*( sin( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*length_3*cos( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)+length_2*sin( angleXY_0+angleXY_2+angleXY_1)*cos( angleXZ_0+angleXZ_2+angleXZ_1)+sin( angleXY_0+angleXY_1)*cos( angleXZ_0+angleXZ_1)*length_1)+( length_2*sin( angleXY_0+angleXY_2+angleXY_1)*sin( angleXZ_0+angleXZ_2+angleXZ_1)+sin( angleXY_0+angleXY_1)*sin( angleXZ_0+angleXZ_1)*length_1+sin( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)*sin( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*length_3)*( sin(angleXZ_0)*length_0*cos(angleXY_0)+length_2*sin( angleXZ_0+angleXZ_2+angleXZ_1)*cos( angleXY_0+angleXY_2+angleXY_1)+sin( angleXZ_0+angleXZ_1)*cos( angleXY_0+angleXY_1)*length_1+sin( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)*length_3*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3)+4.0*initialOffsetZ+initialZ-targetZ)-( length_2*cos( angleXY_0+angleXY_2+angleXY_1)+cos( angleXY_0+angleXY_1)*length_1+length_3*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3))*( sin( angleXY_0+angleXY_1)*length_1+length_2*sin( angleXY_0+angleXY_2+angleXY_1)+4.0*initialOffsetY+initialY-targetY+sin(angleXY_0)*length_0+sin( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*length_3))*pow( pow( length_3*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*cos( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)+4.0*initialOffsetX+initialX-targetX+cos( angleXY_0+angleXY_1)*cos( angleXZ_0+angleXZ_1)*length_1+length_0*cos(angleXZ_0)*cos(angleXY_0)+length_2*cos( angleXY_0+angleXY_2+angleXY_1)*cos( angleXZ_0+angleXZ_2+angleXZ_1),2.0)+pow( sin( angleXY_0+angleXY_1)*length_1+length_2*sin( angleXY_0+angleXY_2+angleXY_1)+4.0*initialOffsetY+initialY-targetY+sin(angleXY_0)*length_0+sin( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*length_3,2.0)+pow( sin(angleXZ_0)*length_0*cos(angleXY_0)+length_2*sin( angleXZ_0+angleXZ_2+angleXZ_1)*cos( angleXY_0+angleXY_2+angleXY_1)+sin( angleXZ_0+angleXZ_1)*cos( angleXY_0+angleXY_1)*length_1+sin( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)*length_3*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3)+4.0*initialOffsetZ+initialZ-targetZ,2.0),-(1.0/2.0));

	return result;
}

double DerivativeFunctions::derivative_XY_4_Legs_2( std::vector<double> & params )
{
	assert( params.size() == 25 );

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

	double result = -pow( pow( length_3*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*cos( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)+4.0*initialOffsetX+initialX-targetX+cos( angleXY_0+angleXY_1)*cos( angleXZ_0+angleXZ_1)*length_1+length_0*cos(angleXZ_0)*cos(angleXY_0)+length_2*cos( angleXY_0+angleXY_2+angleXY_1)*cos( angleXZ_0+angleXZ_2+angleXZ_1),2.0)+pow( sin( angleXY_0+angleXY_1)*length_1+length_2*sin( angleXY_0+angleXY_2+angleXY_1)+4.0*initialOffsetY+initialY-targetY+sin(angleXY_0)*length_0+sin( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*length_3,2.0)+pow( sin(angleXZ_0)*length_0*cos(angleXY_0)+length_2*sin( angleXZ_0+angleXZ_2+angleXZ_1)*cos( angleXY_0+angleXY_2+angleXY_1)+sin( angleXZ_0+angleXZ_1)*cos( angleXY_0+angleXY_1)*length_1+sin( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)*length_3*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3)+4.0*initialOffsetZ+initialZ-targetZ,2.0),-(1.0/2.0))*( ( length_3*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*cos( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)+4.0*initialOffsetX+initialX-targetX+cos( angleXY_0+angleXY_1)*cos( angleXZ_0+angleXZ_1)*length_1+length_0*cos(angleXZ_0)*cos(angleXY_0)+length_2*cos( angleXY_0+angleXY_2+angleXY_1)*cos( angleXZ_0+angleXZ_2+angleXZ_1))*( sin( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*length_3*cos( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)+length_2*sin( angleXY_0+angleXY_2+angleXY_1)*cos( angleXZ_0+angleXZ_2+angleXZ_1))-( length_2*cos( angleXY_0+angleXY_2+angleXY_1)+length_3*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3))*( sin( angleXY_0+angleXY_1)*length_1+length_2*sin( angleXY_0+angleXY_2+angleXY_1)+4.0*initialOffsetY+initialY-targetY+sin(angleXY_0)*length_0+sin( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*length_3)+( length_2*sin( angleXY_0+angleXY_2+angleXY_1)*sin( angleXZ_0+angleXZ_2+angleXZ_1)+sin( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)*sin( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*length_3)*( sin(angleXZ_0)*length_0*cos(angleXY_0)+length_2*sin( angleXZ_0+angleXZ_2+angleXZ_1)*cos( angleXY_0+angleXY_2+angleXY_1)+sin( angleXZ_0+angleXZ_1)*cos( angleXY_0+angleXY_1)*length_1+sin( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)*length_3*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3)+4.0*initialOffsetZ+initialZ-targetZ));

	return result;
}

double DerivativeFunctions::derivative_XY_4_Legs_3( std::vector<double> & params )
{
	assert( params.size() == 25 );

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

	double result = ( length_3*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*( sin( angleXY_0+angleXY_1)*length_1+length_2*sin( angleXY_0+angleXY_2+angleXY_1)+4.0*initialOffsetY+initialY-targetY+sin(angleXY_0)*length_0+sin( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*length_3)-sin( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)*sin( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*length_3*( sin(angleXZ_0)*length_0*cos(angleXY_0)+length_2*sin( angleXZ_0+angleXZ_2+angleXZ_1)*cos( angleXY_0+angleXY_2+angleXY_1)+sin( angleXZ_0+angleXZ_1)*cos( angleXY_0+angleXY_1)*length_1+sin( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)*length_3*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3)+4.0*initialOffsetZ+initialZ-targetZ)-( length_3*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*cos( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)+4.0*initialOffsetX+initialX-targetX+cos( angleXY_0+angleXY_1)*cos( angleXZ_0+angleXZ_1)*length_1+length_0*cos(angleXZ_0)*cos(angleXY_0)+length_2*cos( angleXY_0+angleXY_2+angleXY_1)*cos( angleXZ_0+angleXZ_2+angleXZ_1))*sin( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*length_3*cos( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1))*pow( pow( length_3*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*cos( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)+4.0*initialOffsetX+initialX-targetX+cos( angleXY_0+angleXY_1)*cos( angleXZ_0+angleXZ_1)*length_1+length_0*cos(angleXZ_0)*cos(angleXY_0)+length_2*cos( angleXY_0+angleXY_2+angleXY_1)*cos( angleXZ_0+angleXZ_2+angleXZ_1),2.0)+pow( sin( angleXY_0+angleXY_1)*length_1+length_2*sin( angleXY_0+angleXY_2+angleXY_1)+4.0*initialOffsetY+initialY-targetY+sin(angleXY_0)*length_0+sin( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*length_3,2.0)+pow( sin(angleXZ_0)*length_0*cos(angleXY_0)+length_2*sin( angleXZ_0+angleXZ_2+angleXZ_1)*cos( angleXY_0+angleXY_2+angleXY_1)+sin( angleXZ_0+angleXZ_1)*cos( angleXY_0+angleXY_1)*length_1+sin( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)*length_3*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3)+4.0*initialOffsetZ+initialZ-targetZ,2.0),-(1.0/2.0));

	return result;
}

double DerivativeFunctions::derivative_XZ_4_Legs_0( std::vector<double> & params )
{
	assert( params.size() == 25 );

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

	double result = ( ( length_3*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*cos( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)+cos( angleXY_0+angleXY_1)*cos( angleXZ_0+angleXZ_1)*length_1+length_0*cos(angleXZ_0)*cos(angleXY_0)+length_2*cos( angleXY_0+angleXY_2+angleXY_1)*cos( angleXZ_0+angleXZ_2+angleXZ_1))*( sin(angleXZ_0)*length_0*cos(angleXY_0)+length_2*sin( angleXZ_0+angleXZ_2+angleXZ_1)*cos( angleXY_0+angleXY_2+angleXY_1)+sin( angleXZ_0+angleXZ_1)*cos( angleXY_0+angleXY_1)*length_1+sin( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)*length_3*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3)+4.0*initialOffsetZ+initialZ-targetZ)-( length_3*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*cos( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)+4.0*initialOffsetX+initialX-targetX+cos( angleXY_0+angleXY_1)*cos( angleXZ_0+angleXZ_1)*length_1+length_0*cos(angleXZ_0)*cos(angleXY_0)+length_2*cos( angleXY_0+angleXY_2+angleXY_1)*cos( angleXZ_0+angleXZ_2+angleXZ_1))*( sin(angleXZ_0)*length_0*cos(angleXY_0)+length_2*sin( angleXZ_0+angleXZ_2+angleXZ_1)*cos( angleXY_0+angleXY_2+angleXY_1)+sin( angleXZ_0+angleXZ_1)*cos( angleXY_0+angleXY_1)*length_1+sin( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)*length_3*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3)))*pow( pow( length_3*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*cos( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)+4.0*initialOffsetX+initialX-targetX+cos( angleXY_0+angleXY_1)*cos( angleXZ_0+angleXZ_1)*length_1+length_0*cos(angleXZ_0)*cos(angleXY_0)+length_2*cos( angleXY_0+angleXY_2+angleXY_1)*cos( angleXZ_0+angleXZ_2+angleXZ_1),2.0)+pow( sin( angleXY_0+angleXY_1)*length_1+length_2*sin( angleXY_0+angleXY_2+angleXY_1)+4.0*initialOffsetY+initialY-targetY+sin(angleXY_0)*length_0+sin( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*length_3,2.0)+pow( sin(angleXZ_0)*length_0*cos(angleXY_0)+length_2*sin( angleXZ_0+angleXZ_2+angleXZ_1)*cos( angleXY_0+angleXY_2+angleXY_1)+sin( angleXZ_0+angleXZ_1)*cos( angleXY_0+angleXY_1)*length_1+sin( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)*length_3*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3)+4.0*initialOffsetZ+initialZ-targetZ,2.0),-(1.0/2.0));

	return result;
}

double DerivativeFunctions::derivative_XZ_4_Legs_1( std::vector<double> & params )
{
	assert( params.size() == 25 );

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

	double result = pow( pow( length_3*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*cos( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)+4.0*initialOffsetX+initialX-targetX+cos( angleXY_0+angleXY_1)*cos( angleXZ_0+angleXZ_1)*length_1+length_0*cos(angleXZ_0)*cos(angleXY_0)+length_2*cos( angleXY_0+angleXY_2+angleXY_1)*cos( angleXZ_0+angleXZ_2+angleXZ_1),2.0)+pow( sin( angleXY_0+angleXY_1)*length_1+length_2*sin( angleXY_0+angleXY_2+angleXY_1)+4.0*initialOffsetY+initialY-targetY+sin(angleXY_0)*length_0+sin( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*length_3,2.0)+pow( sin(angleXZ_0)*length_0*cos(angleXY_0)+length_2*sin( angleXZ_0+angleXZ_2+angleXZ_1)*cos( angleXY_0+angleXY_2+angleXY_1)+sin( angleXZ_0+angleXZ_1)*cos( angleXY_0+angleXY_1)*length_1+sin( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)*length_3*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3)+4.0*initialOffsetZ+initialZ-targetZ,2.0),-(1.0/2.0))*( ( length_3*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*cos( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)+cos( angleXY_0+angleXY_1)*cos( angleXZ_0+angleXZ_1)*length_1+length_2*cos( angleXY_0+angleXY_2+angleXY_1)*cos( angleXZ_0+angleXZ_2+angleXZ_1))*( sin(angleXZ_0)*length_0*cos(angleXY_0)+length_2*sin( angleXZ_0+angleXZ_2+angleXZ_1)*cos( angleXY_0+angleXY_2+angleXY_1)+sin( angleXZ_0+angleXZ_1)*cos( angleXY_0+angleXY_1)*length_1+sin( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)*length_3*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3)+4.0*initialOffsetZ+initialZ-targetZ)-( length_3*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*cos( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)+4.0*initialOffsetX+initialX-targetX+cos( angleXY_0+angleXY_1)*cos( angleXZ_0+angleXZ_1)*length_1+length_0*cos(angleXZ_0)*cos(angleXY_0)+length_2*cos( angleXY_0+angleXY_2+angleXY_1)*cos( angleXZ_0+angleXZ_2+angleXZ_1))*( length_2*sin( angleXZ_0+angleXZ_2+angleXZ_1)*cos( angleXY_0+angleXY_2+angleXY_1)+sin( angleXZ_0+angleXZ_1)*cos( angleXY_0+angleXY_1)*length_1+sin( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)*length_3*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3)));

	return result;
}

double DerivativeFunctions::derivative_XZ_4_Legs_2( std::vector<double> & params )
{
	assert( params.size() == 25 );

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

	double result = pow( pow( length_3*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*cos( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)+4.0*initialOffsetX+initialX-targetX+cos( angleXY_0+angleXY_1)*cos( angleXZ_0+angleXZ_1)*length_1+length_0*cos(angleXZ_0)*cos(angleXY_0)+length_2*cos( angleXY_0+angleXY_2+angleXY_1)*cos( angleXZ_0+angleXZ_2+angleXZ_1),2.0)+pow( sin( angleXY_0+angleXY_1)*length_1+length_2*sin( angleXY_0+angleXY_2+angleXY_1)+4.0*initialOffsetY+initialY-targetY+sin(angleXY_0)*length_0+sin( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*length_3,2.0)+pow( sin(angleXZ_0)*length_0*cos(angleXY_0)+length_2*sin( angleXZ_0+angleXZ_2+angleXZ_1)*cos( angleXY_0+angleXY_2+angleXY_1)+sin( angleXZ_0+angleXZ_1)*cos( angleXY_0+angleXY_1)*length_1+sin( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)*length_3*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3)+4.0*initialOffsetZ+initialZ-targetZ,2.0),-(1.0/2.0))*( ( length_3*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*cos( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)+length_2*cos( angleXY_0+angleXY_2+angleXY_1)*cos( angleXZ_0+angleXZ_2+angleXZ_1))*( sin(angleXZ_0)*length_0*cos(angleXY_0)+length_2*sin( angleXZ_0+angleXZ_2+angleXZ_1)*cos( angleXY_0+angleXY_2+angleXY_1)+sin( angleXZ_0+angleXZ_1)*cos( angleXY_0+angleXY_1)*length_1+sin( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)*length_3*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3)+4.0*initialOffsetZ+initialZ-targetZ)-( length_3*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*cos( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)+4.0*initialOffsetX+initialX-targetX+cos( angleXY_0+angleXY_1)*cos( angleXZ_0+angleXZ_1)*length_1+length_0*cos(angleXZ_0)*cos(angleXY_0)+length_2*cos( angleXY_0+angleXY_2+angleXY_1)*cos( angleXZ_0+angleXZ_2+angleXZ_1))*( length_2*sin( angleXZ_0+angleXZ_2+angleXZ_1)*cos( angleXY_0+angleXY_2+angleXY_1)+sin( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)*length_3*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3)));

	return result;
}

double DerivativeFunctions::derivative_XZ_4_Legs_3( std::vector<double> & params )
{
	assert( params.size() == 25 );

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

	double result = ( length_3*( sin(angleXZ_0)*length_0*cos(angleXY_0)+length_2*sin( angleXZ_0+angleXZ_2+angleXZ_1)*cos( angleXY_0+angleXY_2+angleXY_1)+sin( angleXZ_0+angleXZ_1)*cos( angleXY_0+angleXY_1)*length_1+sin( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)*length_3*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3)+4.0*initialOffsetZ+initialZ-targetZ)*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*cos( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)-( length_3*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*cos( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)+4.0*initialOffsetX+initialX-targetX+cos( angleXY_0+angleXY_1)*cos( angleXZ_0+angleXZ_1)*length_1+length_0*cos(angleXZ_0)*cos(angleXY_0)+length_2*cos( angleXY_0+angleXY_2+angleXY_1)*cos( angleXZ_0+angleXZ_2+angleXZ_1))*sin( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)*length_3*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3))*pow( pow( length_3*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*cos( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)+4.0*initialOffsetX+initialX-targetX+cos( angleXY_0+angleXY_1)*cos( angleXZ_0+angleXZ_1)*length_1+length_0*cos(angleXZ_0)*cos(angleXY_0)+length_2*cos( angleXY_0+angleXY_2+angleXY_1)*cos( angleXZ_0+angleXZ_2+angleXZ_1),2.0)+pow( sin( angleXY_0+angleXY_1)*length_1+length_2*sin( angleXY_0+angleXY_2+angleXY_1)+4.0*initialOffsetY+initialY-targetY+sin(angleXY_0)*length_0+sin( angleXY_0+angleXY_2+angleXY_1+angleXY_3)*length_3,2.0)+pow( sin(angleXZ_0)*length_0*cos(angleXY_0)+length_2*sin( angleXZ_0+angleXZ_2+angleXZ_1)*cos( angleXY_0+angleXY_2+angleXY_1)+sin( angleXZ_0+angleXZ_1)*cos( angleXY_0+angleXY_1)*length_1+sin( angleXZ_3+angleXZ_0+angleXZ_2+angleXZ_1)*length_3*cos( angleXY_0+angleXY_2+angleXY_1+angleXY_3)+4.0*initialOffsetZ+initialZ-targetZ,2.0),-(1.0/2.0));

	return result;
}

double DerivativeFunctions::derivative_XY_5_Legs_0( std::vector<double> & params )
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

	double result = -( ( cos(angleXZ_0)*length_0*sin(angleXY_0)+sin( angleXY_1+angleXY_0)*cos( angleXZ_1+angleXZ_0)*length_1+sin( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*cos( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+length_3*cos( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)*sin( angleXY_1+angleXY_3+angleXY_0+angleXY_2)+length_2*sin( angleXY_1+angleXY_0+angleXY_2)*cos( angleXZ_2+angleXZ_1+angleXZ_0))*( length_2*cos( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2)+5.0*initialOffsetX+cos(angleXZ_0)*cos(angleXY_0)*length_0+initialX-targetX+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*cos( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3*cos( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)+cos( angleXY_1+angleXY_0)*cos( angleXZ_1+angleXZ_0)*length_1)+( sin(angleXZ_0)*length_0*sin(angleXY_0)+sin( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*sin( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_4+sin( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)*length_3*sin( angleXY_1+angleXY_3+angleXY_0+angleXY_2)+length_2*sin( angleXY_1+angleXY_0+angleXY_2)*sin( angleXZ_2+angleXZ_1+angleXZ_0)+sin( angleXZ_1+angleXZ_0)*sin( angleXY_1+angleXY_0)*length_1)*( 5.0*initialOffsetZ+cos( angleXY_1+angleXY_0)*sin( angleXZ_1+angleXZ_0)*length_1+initialZ-targetZ+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*sin( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos(angleXY_0)*sin(angleXZ_0)*length_0+sin( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)*cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3+length_2*sin( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2))-( cos( angleXY_1+angleXY_0)*length_1+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_4+cos(angleXY_0)*length_0+length_2*cos( angleXY_1+angleXY_0+angleXY_2)+cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3)*( initialY-targetY+sin( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_4+length_0*sin(angleXY_0)+length_3*sin( angleXY_1+angleXY_3+angleXY_0+angleXY_2)+length_2*sin( angleXY_1+angleXY_0+angleXY_2)+sin( angleXY_1+angleXY_0)*length_1+5.0*initialOffsetY))*pow( pow( length_2*cos( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2)+5.0*initialOffsetX+cos(angleXZ_0)*cos(angleXY_0)*length_0+initialX-targetX+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*cos( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3*cos( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)+cos( angleXY_1+angleXY_0)*cos( angleXZ_1+angleXZ_0)*length_1,2.0)+pow( initialY-targetY+sin( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_4+length_0*sin(angleXY_0)+length_3*sin( angleXY_1+angleXY_3+angleXY_0+angleXY_2)+length_2*sin( angleXY_1+angleXY_0+angleXY_2)+sin( angleXY_1+angleXY_0)*length_1+5.0*initialOffsetY,2.0)+pow( 5.0*initialOffsetZ+cos( angleXY_1+angleXY_0)*sin( angleXZ_1+angleXZ_0)*length_1+initialZ-targetZ+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*sin( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos(angleXY_0)*sin(angleXZ_0)*length_0+sin( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)*cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3+length_2*sin( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2),2.0),-(1.0/2.0));

	return result;
}

double DerivativeFunctions::derivative_XY_5_Legs_1( std::vector<double> & params )
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

	double result = ( ( cos( angleXY_1+angleXY_0)*length_1+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_4+length_2*cos( angleXY_1+angleXY_0+angleXY_2)+cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3)*( initialY-targetY+sin( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_4+length_0*sin(angleXY_0)+length_3*sin( angleXY_1+angleXY_3+angleXY_0+angleXY_2)+length_2*sin( angleXY_1+angleXY_0+angleXY_2)+sin( angleXY_1+angleXY_0)*length_1+5.0*initialOffsetY)-( sin( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*sin( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_4+sin( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)*length_3*sin( angleXY_1+angleXY_3+angleXY_0+angleXY_2)+length_2*sin( angleXY_1+angleXY_0+angleXY_2)*sin( angleXZ_2+angleXZ_1+angleXZ_0)+sin( angleXZ_1+angleXZ_0)*sin( angleXY_1+angleXY_0)*length_1)*( 5.0*initialOffsetZ+cos( angleXY_1+angleXY_0)*sin( angleXZ_1+angleXZ_0)*length_1+initialZ-targetZ+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*sin( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos(angleXY_0)*sin(angleXZ_0)*length_0+sin( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)*cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3+length_2*sin( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2))-( sin( angleXY_1+angleXY_0)*cos( angleXZ_1+angleXZ_0)*length_1+sin( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*cos( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+length_3*cos( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)*sin( angleXY_1+angleXY_3+angleXY_0+angleXY_2)+length_2*sin( angleXY_1+angleXY_0+angleXY_2)*cos( angleXZ_2+angleXZ_1+angleXZ_0))*( length_2*cos( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2)+5.0*initialOffsetX+cos(angleXZ_0)*cos(angleXY_0)*length_0+initialX-targetX+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*cos( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3*cos( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)+cos( angleXY_1+angleXY_0)*cos( angleXZ_1+angleXZ_0)*length_1))*pow( pow( length_2*cos( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2)+5.0*initialOffsetX+cos(angleXZ_0)*cos(angleXY_0)*length_0+initialX-targetX+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*cos( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3*cos( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)+cos( angleXY_1+angleXY_0)*cos( angleXZ_1+angleXZ_0)*length_1,2.0)+pow( initialY-targetY+sin( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_4+length_0*sin(angleXY_0)+length_3*sin( angleXY_1+angleXY_3+angleXY_0+angleXY_2)+length_2*sin( angleXY_1+angleXY_0+angleXY_2)+sin( angleXY_1+angleXY_0)*length_1+5.0*initialOffsetY,2.0)+pow( 5.0*initialOffsetZ+cos( angleXY_1+angleXY_0)*sin( angleXZ_1+angleXZ_0)*length_1+initialZ-targetZ+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*sin( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos(angleXY_0)*sin(angleXZ_0)*length_0+sin( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)*cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3+length_2*sin( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2),2.0),-(1.0/2.0));

	return result;
}

double DerivativeFunctions::derivative_XY_5_Legs_2( std::vector<double> & params )
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

	double result = -( ( 5.0*initialOffsetZ+cos( angleXY_1+angleXY_0)*sin( angleXZ_1+angleXZ_0)*length_1+initialZ-targetZ+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*sin( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos(angleXY_0)*sin(angleXZ_0)*length_0+sin( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)*cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3+length_2*sin( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2))*( sin( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*sin( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_4+sin( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)*length_3*sin( angleXY_1+angleXY_3+angleXY_0+angleXY_2)+length_2*sin( angleXY_1+angleXY_0+angleXY_2)*sin( angleXZ_2+angleXZ_1+angleXZ_0))-( initialY-targetY+sin( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_4+length_0*sin(angleXY_0)+length_3*sin( angleXY_1+angleXY_3+angleXY_0+angleXY_2)+length_2*sin( angleXY_1+angleXY_0+angleXY_2)+sin( angleXY_1+angleXY_0)*length_1+5.0*initialOffsetY)*( cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_4+length_2*cos( angleXY_1+angleXY_0+angleXY_2)+cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3)+( sin( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*cos( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+length_3*cos( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)*sin( angleXY_1+angleXY_3+angleXY_0+angleXY_2)+length_2*sin( angleXY_1+angleXY_0+angleXY_2)*cos( angleXZ_2+angleXZ_1+angleXZ_0))*( length_2*cos( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2)+5.0*initialOffsetX+cos(angleXZ_0)*cos(angleXY_0)*length_0+initialX-targetX+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*cos( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3*cos( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)+cos( angleXY_1+angleXY_0)*cos( angleXZ_1+angleXZ_0)*length_1))*pow( pow( length_2*cos( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2)+5.0*initialOffsetX+cos(angleXZ_0)*cos(angleXY_0)*length_0+initialX-targetX+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*cos( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3*cos( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)+cos( angleXY_1+angleXY_0)*cos( angleXZ_1+angleXZ_0)*length_1,2.0)+pow( initialY-targetY+sin( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_4+length_0*sin(angleXY_0)+length_3*sin( angleXY_1+angleXY_3+angleXY_0+angleXY_2)+length_2*sin( angleXY_1+angleXY_0+angleXY_2)+sin( angleXY_1+angleXY_0)*length_1+5.0*initialOffsetY,2.0)+pow( 5.0*initialOffsetZ+cos( angleXY_1+angleXY_0)*sin( angleXZ_1+angleXZ_0)*length_1+initialZ-targetZ+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*sin( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos(angleXY_0)*sin(angleXZ_0)*length_0+sin( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)*cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3+length_2*sin( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2),2.0),-(1.0/2.0));

	return result;
}

double DerivativeFunctions::derivative_XY_5_Legs_3( std::vector<double> & params )
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

	double result = ( ( cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_4+cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3)*( initialY-targetY+sin( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_4+length_0*sin(angleXY_0)+length_3*sin( angleXY_1+angleXY_3+angleXY_0+angleXY_2)+length_2*sin( angleXY_1+angleXY_0+angleXY_2)+sin( angleXY_1+angleXY_0)*length_1+5.0*initialOffsetY)-( sin( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*cos( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+length_3*cos( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)*sin( angleXY_1+angleXY_3+angleXY_0+angleXY_2))*( length_2*cos( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2)+5.0*initialOffsetX+cos(angleXZ_0)*cos(angleXY_0)*length_0+initialX-targetX+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*cos( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3*cos( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)+cos( angleXY_1+angleXY_0)*cos( angleXZ_1+angleXZ_0)*length_1)-( 5.0*initialOffsetZ+cos( angleXY_1+angleXY_0)*sin( angleXZ_1+angleXZ_0)*length_1+initialZ-targetZ+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*sin( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos(angleXY_0)*sin(angleXZ_0)*length_0+sin( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)*cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3+length_2*sin( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2))*( sin( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*sin( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_4+sin( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)*length_3*sin( angleXY_1+angleXY_3+angleXY_0+angleXY_2)))*pow( pow( length_2*cos( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2)+5.0*initialOffsetX+cos(angleXZ_0)*cos(angleXY_0)*length_0+initialX-targetX+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*cos( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3*cos( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)+cos( angleXY_1+angleXY_0)*cos( angleXZ_1+angleXZ_0)*length_1,2.0)+pow( initialY-targetY+sin( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_4+length_0*sin(angleXY_0)+length_3*sin( angleXY_1+angleXY_3+angleXY_0+angleXY_2)+length_2*sin( angleXY_1+angleXY_0+angleXY_2)+sin( angleXY_1+angleXY_0)*length_1+5.0*initialOffsetY,2.0)+pow( 5.0*initialOffsetZ+cos( angleXY_1+angleXY_0)*sin( angleXZ_1+angleXZ_0)*length_1+initialZ-targetZ+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*sin( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos(angleXY_0)*sin(angleXZ_0)*length_0+sin( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)*cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3+length_2*sin( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2),2.0),-(1.0/2.0));

	return result;
}

double DerivativeFunctions::derivative_XY_5_Legs_4( std::vector<double> & params )
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

	double result = -pow( pow( length_2*cos( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2)+5.0*initialOffsetX+cos(angleXZ_0)*cos(angleXY_0)*length_0+initialX-targetX+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*cos( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3*cos( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)+cos( angleXY_1+angleXY_0)*cos( angleXZ_1+angleXZ_0)*length_1,2.0)+pow( initialY-targetY+sin( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_4+length_0*sin(angleXY_0)+length_3*sin( angleXY_1+angleXY_3+angleXY_0+angleXY_2)+length_2*sin( angleXY_1+angleXY_0+angleXY_2)+sin( angleXY_1+angleXY_0)*length_1+5.0*initialOffsetY,2.0)+pow( 5.0*initialOffsetZ+cos( angleXY_1+angleXY_0)*sin( angleXZ_1+angleXZ_0)*length_1+initialZ-targetZ+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*sin( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos(angleXY_0)*sin(angleXZ_0)*length_0+sin( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)*cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3+length_2*sin( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2),2.0),-(1.0/2.0))*( sin( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*( length_2*cos( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2)+5.0*initialOffsetX+cos(angleXZ_0)*cos(angleXY_0)*length_0+initialX-targetX+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*cos( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3*cos( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)+cos( angleXY_1+angleXY_0)*cos( angleXZ_1+angleXZ_0)*length_1)*cos( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+( 5.0*initialOffsetZ+cos( angleXY_1+angleXY_0)*sin( angleXZ_1+angleXZ_0)*length_1+initialZ-targetZ+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*sin( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos(angleXY_0)*sin(angleXZ_0)*length_0+sin( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)*cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3+length_2*sin( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2))*sin( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*sin( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_4-cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*( initialY-targetY+sin( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_4+length_0*sin(angleXY_0)+length_3*sin( angleXY_1+angleXY_3+angleXY_0+angleXY_2)+length_2*sin( angleXY_1+angleXY_0+angleXY_2)+sin( angleXY_1+angleXY_0)*length_1+5.0*initialOffsetY)*length_4);

	return result;
}

double DerivativeFunctions::derivative_XZ_5_Legs_0( std::vector<double> & params )
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

	double result = pow( pow( length_2*cos( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2)+5.0*initialOffsetX+cos(angleXZ_0)*cos(angleXY_0)*length_0+initialX-targetX+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*cos( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3*cos( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)+cos( angleXY_1+angleXY_0)*cos( angleXZ_1+angleXZ_0)*length_1,2.0)+pow( initialY-targetY+sin( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_4+length_0*sin(angleXY_0)+length_3*sin( angleXY_1+angleXY_3+angleXY_0+angleXY_2)+length_2*sin( angleXY_1+angleXY_0+angleXY_2)+sin( angleXY_1+angleXY_0)*length_1+5.0*initialOffsetY,2.0)+pow( 5.0*initialOffsetZ+cos( angleXY_1+angleXY_0)*sin( angleXZ_1+angleXZ_0)*length_1+initialZ-targetZ+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*sin( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos(angleXY_0)*sin(angleXZ_0)*length_0+sin( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)*cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3+length_2*sin( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2),2.0),-(1.0/2.0))*( ( 5.0*initialOffsetZ+cos( angleXY_1+angleXY_0)*sin( angleXZ_1+angleXZ_0)*length_1+initialZ-targetZ+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*sin( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos(angleXY_0)*sin(angleXZ_0)*length_0+sin( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)*cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3+length_2*sin( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2))*( length_2*cos( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2)+cos(angleXZ_0)*cos(angleXY_0)*length_0+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*cos( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3*cos( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)+cos( angleXY_1+angleXY_0)*cos( angleXZ_1+angleXZ_0)*length_1)-( cos( angleXY_1+angleXY_0)*sin( angleXZ_1+angleXZ_0)*length_1+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*sin( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos(angleXY_0)*sin(angleXZ_0)*length_0+sin( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)*cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3+length_2*sin( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2))*( length_2*cos( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2)+5.0*initialOffsetX+cos(angleXZ_0)*cos(angleXY_0)*length_0+initialX-targetX+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*cos( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3*cos( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)+cos( angleXY_1+angleXY_0)*cos( angleXZ_1+angleXZ_0)*length_1));

	return result;
}

double DerivativeFunctions::derivative_XZ_5_Legs_1( std::vector<double> & params )
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

	double result = ( ( length_2*cos( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2)+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*cos( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3*cos( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)+cos( angleXY_1+angleXY_0)*cos( angleXZ_1+angleXZ_0)*length_1)*( 5.0*initialOffsetZ+cos( angleXY_1+angleXY_0)*sin( angleXZ_1+angleXZ_0)*length_1+initialZ-targetZ+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*sin( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos(angleXY_0)*sin(angleXZ_0)*length_0+sin( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)*cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3+length_2*sin( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2))-( cos( angleXY_1+angleXY_0)*sin( angleXZ_1+angleXZ_0)*length_1+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*sin( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+sin( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)*cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3+length_2*sin( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2))*( length_2*cos( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2)+5.0*initialOffsetX+cos(angleXZ_0)*cos(angleXY_0)*length_0+initialX-targetX+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*cos( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3*cos( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)+cos( angleXY_1+angleXY_0)*cos( angleXZ_1+angleXZ_0)*length_1))*pow( pow( length_2*cos( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2)+5.0*initialOffsetX+cos(angleXZ_0)*cos(angleXY_0)*length_0+initialX-targetX+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*cos( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3*cos( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)+cos( angleXY_1+angleXY_0)*cos( angleXZ_1+angleXZ_0)*length_1,2.0)+pow( initialY-targetY+sin( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_4+length_0*sin(angleXY_0)+length_3*sin( angleXY_1+angleXY_3+angleXY_0+angleXY_2)+length_2*sin( angleXY_1+angleXY_0+angleXY_2)+sin( angleXY_1+angleXY_0)*length_1+5.0*initialOffsetY,2.0)+pow( 5.0*initialOffsetZ+cos( angleXY_1+angleXY_0)*sin( angleXZ_1+angleXZ_0)*length_1+initialZ-targetZ+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*sin( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos(angleXY_0)*sin(angleXZ_0)*length_0+sin( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)*cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3+length_2*sin( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2),2.0),-(1.0/2.0));

	return result;
}

double DerivativeFunctions::derivative_XZ_5_Legs_2( std::vector<double> & params )
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

	double result = ( ( 5.0*initialOffsetZ+cos( angleXY_1+angleXY_0)*sin( angleXZ_1+angleXZ_0)*length_1+initialZ-targetZ+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*sin( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos(angleXY_0)*sin(angleXZ_0)*length_0+sin( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)*cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3+length_2*sin( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2))*( length_2*cos( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2)+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*cos( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3*cos( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0))-( cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*sin( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+sin( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)*cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3+length_2*sin( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2))*( length_2*cos( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2)+5.0*initialOffsetX+cos(angleXZ_0)*cos(angleXY_0)*length_0+initialX-targetX+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*cos( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3*cos( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)+cos( angleXY_1+angleXY_0)*cos( angleXZ_1+angleXZ_0)*length_1))*pow( pow( length_2*cos( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2)+5.0*initialOffsetX+cos(angleXZ_0)*cos(angleXY_0)*length_0+initialX-targetX+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*cos( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3*cos( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)+cos( angleXY_1+angleXY_0)*cos( angleXZ_1+angleXZ_0)*length_1,2.0)+pow( initialY-targetY+sin( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_4+length_0*sin(angleXY_0)+length_3*sin( angleXY_1+angleXY_3+angleXY_0+angleXY_2)+length_2*sin( angleXY_1+angleXY_0+angleXY_2)+sin( angleXY_1+angleXY_0)*length_1+5.0*initialOffsetY,2.0)+pow( 5.0*initialOffsetZ+cos( angleXY_1+angleXY_0)*sin( angleXZ_1+angleXZ_0)*length_1+initialZ-targetZ+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*sin( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos(angleXY_0)*sin(angleXZ_0)*length_0+sin( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)*cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3+length_2*sin( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2),2.0),-(1.0/2.0));

	return result;
}

double DerivativeFunctions::derivative_XZ_5_Legs_3( std::vector<double> & params )
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

	double result = pow( pow( length_2*cos( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2)+5.0*initialOffsetX+cos(angleXZ_0)*cos(angleXY_0)*length_0+initialX-targetX+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*cos( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3*cos( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)+cos( angleXY_1+angleXY_0)*cos( angleXZ_1+angleXZ_0)*length_1,2.0)+pow( initialY-targetY+sin( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_4+length_0*sin(angleXY_0)+length_3*sin( angleXY_1+angleXY_3+angleXY_0+angleXY_2)+length_2*sin( angleXY_1+angleXY_0+angleXY_2)+sin( angleXY_1+angleXY_0)*length_1+5.0*initialOffsetY,2.0)+pow( 5.0*initialOffsetZ+cos( angleXY_1+angleXY_0)*sin( angleXZ_1+angleXZ_0)*length_1+initialZ-targetZ+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*sin( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos(angleXY_0)*sin(angleXZ_0)*length_0+sin( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)*cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3+length_2*sin( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2),2.0),-(1.0/2.0))*( ( 5.0*initialOffsetZ+cos( angleXY_1+angleXY_0)*sin( angleXZ_1+angleXZ_0)*length_1+initialZ-targetZ+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*sin( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos(angleXY_0)*sin(angleXZ_0)*length_0+sin( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)*cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3+length_2*sin( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2))*( cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*cos( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3*cos( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0))-( cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*sin( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+sin( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)*cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3)*( length_2*cos( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2)+5.0*initialOffsetX+cos(angleXZ_0)*cos(angleXY_0)*length_0+initialX-targetX+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*cos( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3*cos( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)+cos( angleXY_1+angleXY_0)*cos( angleXZ_1+angleXZ_0)*length_1));

	return result;
}

double DerivativeFunctions::derivative_XZ_5_Legs_4( std::vector<double> & params )
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

	double result = -pow( pow( length_2*cos( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2)+5.0*initialOffsetX+cos(angleXZ_0)*cos(angleXY_0)*length_0+initialX-targetX+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*cos( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3*cos( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)+cos( angleXY_1+angleXY_0)*cos( angleXZ_1+angleXZ_0)*length_1,2.0)+pow( initialY-targetY+sin( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_4+length_0*sin(angleXY_0)+length_3*sin( angleXY_1+angleXY_3+angleXY_0+angleXY_2)+length_2*sin( angleXY_1+angleXY_0+angleXY_2)+sin( angleXY_1+angleXY_0)*length_1+5.0*initialOffsetY,2.0)+pow( 5.0*initialOffsetZ+cos( angleXY_1+angleXY_0)*sin( angleXZ_1+angleXZ_0)*length_1+initialZ-targetZ+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*sin( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos(angleXY_0)*sin(angleXZ_0)*length_0+sin( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)*cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3+length_2*sin( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2),2.0),-(1.0/2.0))*( cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*sin( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*( length_2*cos( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2)+5.0*initialOffsetX+cos(angleXZ_0)*cos(angleXY_0)*length_0+initialX-targetX+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*cos( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3*cos( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)+cos( angleXY_1+angleXY_0)*cos( angleXZ_1+angleXZ_0)*length_1)*length_4-cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*( 5.0*initialOffsetZ+cos( angleXY_1+angleXY_0)*sin( angleXZ_1+angleXZ_0)*length_1+initialZ-targetZ+cos( angleXY_4+angleXY_1+angleXY_3+angleXY_0+angleXY_2)*sin( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4+cos(angleXY_0)*sin(angleXZ_0)*length_0+sin( angleXZ_2+angleXZ_1+angleXZ_3+angleXZ_0)*cos( angleXY_1+angleXY_3+angleXY_0+angleXY_2)*length_3+length_2*sin( angleXZ_2+angleXZ_1+angleXZ_0)*cos( angleXY_1+angleXY_0+angleXY_2))*cos( angleXZ_2+angleXZ_4+angleXZ_1+angleXZ_3+angleXZ_0)*length_4);

	return result;
}

