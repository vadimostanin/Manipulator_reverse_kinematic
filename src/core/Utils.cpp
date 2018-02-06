/*
 * Utils.cpp
 *
 *  Created on: Dec 11, 2017
 *      Author: user
 */

#include "Utils.h"
#include "HardFire.h"
#include <cmath>

double Utils::Utils_Tmp;

double Utils::deg2Rad( double angle )
{
	double rad = angle / 180 * M_PI;
	return rad;
}

double Utils::rad2Deg( double rad )
{
	double degree = rad / M_PI * 180 ;
	return degree;
}

double Utils::limitValue( double value, double minValue, double maxValue )
{
	value = value < minValue ? minValue : value;
	value = value > maxValue ? maxValue : value;

	return value;
}

double Utils::distance( double x1, double y1, double x2, double y2 )
{
	double deltaX = x1 - x2;
	double deltaY = y1 - y2;
	return std::sqrt( deltaX * deltaX + deltaY * deltaY );
}

double Utils::distance( double x1, double y1, double z1, double x2, double y2, double z2 )
{
	const double deltaX = x1 - x2;
	const double deltaY = y1 - y2;
	const double deltaZ = z1 - z2;
	return std::sqrt( deltaX * deltaX + deltaY * deltaY + deltaZ * deltaZ );
}

double Utils::distanceByTriangle( double a, double b, double c, double & x )
{
	x = ( b * b + c * c - a * a ) / ( 2 * c );
	return std::sqrt( b * b - x * x );
}

double Utils::clamp( double value, double min, double max )
{
	if (value < min) return min;
	if (value > max) return max;
	return value;
}

double VDot( const point & v1, const point & v2 )
{
  return ( v1.x * v2.x + v1.y * v2.y + v1.z * v2.z );
}

point VMul( const point & v1, double A )
{
  point result;
  result.x = v1.x * A;
  result.y = v1.y * A;
  result.z = v1.z * A;
  return result;
}

point VSub( const point & v1, const point & v2 )
{
  point result;
  result.x = v1.x - v2.x;
  result.y = v1.y - v2.y;
  result.z = v1.z - v2.z;
  return result;
}

point VNorm( const point & V )
{
  double vl = dist( point(), V );
  point result;
  result.x = V.x / vl;
  result.y = V.y / vl;
  result.z = V.z / vl;
  return result;
}

point VProject( const point & A, const point & B )
{
  point Anorm = VNorm( A );
  point result;
  result = VMul( Anorm, VDot( Anorm, B ) );
  return result;
}

point Perpendicular( const point & A, const point & B, const point & C )
{
  point CA = VSub( C, A );
  point result = VSub( VProject( VSub( B, A ), CA ), CA );
  return result;
}

bool Utils::isPerpendicularBelongToSegment( double segmentX1, double segmentY1, double segmentZ1, double segmentX2, double segmentY2, double segmentZ2, double pointX, double pointY, double pointZ, double & perpLength )
{
	point p( pointX, pointY, pointZ ),
		  p1( segmentX1, segmentY1, segmentZ1 ),
		  p2( segmentX2, segmentY2, segmentZ2 );

	point perpPoint = Perpendicular( p1, p2, p );
	bool isPerp = point_in_segment( perpPoint, p1, p2 );
	if( true == isPerp )
	{
		perpLength = dist( perpPoint, p );
	}

	return isPerp;
}

//bool Utils::isPerpendicularBelongToSegment( double segmentX1, double segmentY1, double segmentZ1, double segmentX2, double segmentY2, double segmentZ2, double pointX, double pointY, double pointZ, double & perpLength )
//{
//	gpoint p( pointX, pointY, pointZ ),
//		  p1( segmentX1, segmentY1, segmentZ1 ),
//		  p2( segmentX2, segmentY2, segmentZ2 );
//
//	gline segmentLine( p1, p2 );
//	gpoint perpPoint = closest_point( segmentLine, p );
//	bool isPerp = segmentLine.in_line( perpPoint );
//	perpLength = 0;
//	if( true == isPerp )
//	{
//		perpLength = dist( perpPoint, p );
//	}
//
//	return isPerp;
//}

bool Utils::isCrossingLines( double segment1X1, double segment1Y1, double segment1Z1, double segment1X2, double segment1Y2, double segment1Z2,
		                     double segment2X1, double segment2Y1, double segment2Z1, double segment2X2, double segment2Y2, double segment2Z2 )
{
	gpoint p11( segment1X1, segment1Y1, segment1Z1 );
	gpoint p12( segment1X2, segment1Y2, segment1Z2 );

	gpoint p21( segment2X1, segment2Y1, segment2Z1 );
	gpoint p22( segment2X2, segment2Y2, segment2Z2 );
	gline l1( p11, p12 );
	gline l2( p21, p22 );
	gpoint l1l2;
	bool crossed = cross_lines( l1, l2, l1l2 ) && l1.in_line( l1l2 ) && l2.in_line( l1l2 );
	return crossed;
}

uint8_t Utils::getQouterByAngle( double angle )
{
	uint8_t quoter = 0;
	if( angle >= 0 && angle <= 90 )
	{
		quoter = 1;
	}
	else if( angle > 90 && angle <= 180 )
	{
		quoter = 2;
	}
	else if( angle > 180 && angle <= 270 )
	{
		quoter = 3;
	}
	else if( angle > 270 && angle <= 360 )
	{
		quoter = 4;
	}
	return quoter;
}

double Utils::getDegAngle( double katetY, double hypothenuse )
{
	double angle = Utils::rad2Deg( std::asin( katetY / hypothenuse ) );
	return angle;
}

//int Utils::flipY( int y, int height )
//{
//	return y;//height - y;
//}
