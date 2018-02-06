/*
 * Utils.h
 *
 *  Created on: Dec 11, 2017
 *      Author: user
 */

#ifndef UTILS_H_
#define UTILS_H_

#include <cstdint>

class Utils
{
	static double Utils_Tmp;
public:
	static double rad2Deg( double rad );
	static double deg2Rad( double angle );
	static double limitValue( double value, double minValue, double maxValue );
	static double distance( double x1, double y1, double x2, double y2 );
	static double distance( double x1, double y1, double z1, double x2, double y2, double z2 );
	static double distanceByTriangle( double , double, double, double & x = Utils_Tmp );
	static double clamp( double value, double min, double max );
	static bool   isPerpendicularBelongToSegment( double segmentX1, double segmentY1, double segmentZ1, double segmentX2, double segmentY2, double segmentZ2, double pointX, double pointY, double pointZ, double & perpLength );
	static bool   isCrossingLines( double segment1X1, double segment1Y1, double segment1Z1, double segment1X2, double segment1Y2, double segment1Z2,
            					   double segment2X1, double segment2Y1, double segment2Z1, double segment2X2, double segment2Y2, double segment2Z2 );
	static uint8_t getQouterByAngle( double angle );

	static double getDegAngle( double katetY, double hyphotenuse );
//	static double angleRand();
//	static int flipY( int y, int height );
};

#endif /* UTILS_H_ */
