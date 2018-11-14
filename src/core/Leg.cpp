/*
 * Leg.cpp
 *
 *  Created on: 9 дек. 2017 г.
 *      Author: vadim
 */

#include "Leg.h"
#include "Utils.h"
#include <cmath>
#include <utility>
#include <iostream>

Leg::Leg( int level ): m_length( 0 ), m_width1( 10 ), m_width2( 10 ), m_angleXY( 0 ), m_angleXYMax( 360 ), m_angleXYMin( -360 ), m_angleXYEnabled( true ), m_accumulativeParentAngleXY( 0 ),
					   m_angleXZ( 0 ), m_angleXZMax( 360 ), m_angleXZMin( -360 ), m_angleXZEnabled( false ), m_accumulativeParentAngleZX( 0 ),
					   m_angleZY( 0 ), m_angleZYMax( 360 ), m_angleZYMin( -360 ), m_angleZYEnabled( false ), m_accumulativeParentAngleZY( 0 ),
					   m_level( level ), m_child( nullptr ), m_initialX( 0 ), m_initialY( 0 ), m_initialZ( 0 ),
					   m_offsetInitialX( 0 ), m_offsetInitialY( 0 ), m_offsetInitialZ( 0 )
{}

Leg::~Leg()
{}

Leg& Leg::operator=( const ShLeg leg )
{
	operator =( *leg );
	setAngleXY(leg->getAngleXY());
	setAngleXZ(leg->getAngleXZ());
	setAngleZY(leg->getAngleZY());
	return *this;
}

void Leg::setChild( ShLeg child )
{
	m_child = child;
}

int Leg::getLength() const
{
	return m_length;
}

Leg& Leg::setLength( int length )
{
	m_length = length;
	return *this;
}

double Leg::getWidth1() const
{
	return m_width1;
}

Leg& Leg::setWidth1( double w1 )
{
	m_width1 = w1;
	return *this;
}

//double Leg::getWidth2() const
//{
//	return m_width2;
//}
//
//Leg& Leg::setWindth2( double w2 )
//{
//	m_width2 = w2;
//	return *this;
//}

Leg& Leg::setInitialOffsets( double offsetX, double offsetY, double offsetZ )
{
	m_offsetInitialX = offsetX;
	m_offsetInitialY = offsetY;
	m_offsetInitialZ = offsetZ;
	if( nullptr != m_child.get() )
	{
		TypePrecision currentFinalPositionX, currentFinalPositionY, currentFinalPositionZ;
		getCalulatedFinalPosition( currentFinalPositionX, currentFinalPositionY, currentFinalPositionZ );
		m_child->setInitialPosition( currentFinalPositionX, currentFinalPositionY, currentFinalPositionZ );
	}
	return *this;
}

Leg& Leg::getInitialOffsets( double & offsetX, double & offsetY, double & offsetZ )
{
	offsetX = m_offsetInitialX;
	offsetY = m_offsetInitialY;
	offsetZ = m_offsetInitialZ;
	return *this;
}

double Leg::getAngleXY() const
{
	return m_angleXY;
}

Leg& Leg::setAngleXY( double angle )
{
	if( false == m_angleXYEnabled )
	{
		return *this;
	}
	double normalizedAngle = ( ( ( angle / 360.0 ) - ( ( int )( angle / 360.0 ) ) ) * 360 );
	if( normalizedAngle < m_angleXYMin || normalizedAngle > m_angleXYMax )
	{
		return *this;
	}
	m_angleXY = normalizedAngle;
	if( nullptr != m_child.get() )
	{
		double degreeXY = m_angleXY + m_accumulativeParentAngleXY;
		TypePrecision currentFinalPositionX, currentFinalPositionY, currentFinalPositionZ;
		getCalulatedFinalPosition( currentFinalPositionX, currentFinalPositionY, currentFinalPositionZ );
		m_child->setAccumulativeParentAngleXY( degreeXY );
		m_child->setInitialPosition( currentFinalPositionX, currentFinalPositionY, currentFinalPositionZ );
	}
	return *this;
}

Leg& Leg::setAngleXYLimits( double min, double max )
{
	m_angleXYMin = min;
	m_angleXYMax = max;
	return *this;
}

Leg& Leg::getAngleXYLimits( double & min, double & max )
{
	min = m_angleXYMin;
	max = m_angleXYMax;
	return *this;
}

Leg& Leg::setAngleXYEnable( bool enable )
{
	m_angleXYEnabled = enable;
	return *this;
}

bool Leg::getAngleXYEnabled() const
{
	return m_angleXYEnabled;
}

Leg& Leg::setAngleXZLimits( double min, double max )
{
	m_angleXZMin = min;
	m_angleXZMax = max;
	return *this;
}

Leg& Leg::getAngleXZLimits( double & min, double & max )
{
	min = m_angleXZMin;
	max = m_angleXZMax;
	return *this;
}

double Leg::getAngleXZ() const
{
	return m_angleXZ;
}

Leg& Leg::setAngleXZ( double angle )
{
	if( false == m_angleXZEnabled )
	{
		return *this;
	}
	double normalizedAngle = ( ( ( angle / 360.0 ) - ( ( int )( angle / 360.0 ) ) ) * 360 );
	if( normalizedAngle < m_angleXZMin || normalizedAngle > m_angleXZMax )
	{
		return *this;
	}
	m_angleXZ = normalizedAngle;
	if( nullptr != m_child.get() )
	{
		double degreeZX = m_angleXZ + m_accumulativeParentAngleZX;
		TypePrecision currentFinalPositionX, currentFinalPositionY, currentFinalPositionZ;
		getCalulatedFinalPosition( currentFinalPositionX, currentFinalPositionY, currentFinalPositionZ );
		m_child->setAcummulativeParentAngleXZ( degreeZX );
		m_child->setInitialPosition( currentFinalPositionX, currentFinalPositionY, currentFinalPositionZ );
	}
	return *this;
}

Leg& Leg::setAngleXZEnable( bool enable )
{
	m_angleXZEnabled = enable;
	return *this;
}

bool Leg::getAngleXZEnabled() const
{
	return m_angleXZEnabled;
}

double Leg::getAngleZY() const
{
	return m_angleZY;
}

Leg& Leg::setAngleZY( double angle )
{
	if( false == m_angleZYEnabled )
	{
		return *this;
	}
	double normalizedAngle = ( ( ( angle / 360.0 ) - ( ( int )( angle / 360.0 ) ) ) * 360 );
	if( normalizedAngle < m_angleZYMin || normalizedAngle > m_angleZYMax )
	{
		return *this;
	}
	m_angleZY = normalizedAngle;
	if( nullptr != m_child.get() )
	{
		double degreeZY = m_angleZY + m_accumulativeParentAngleZY;
		TypePrecision currentFinalPositionX, currentFinalPositionY, currentFinalPositionZ;
		getCalulatedFinalPosition( currentFinalPositionX, currentFinalPositionY, currentFinalPositionZ );
		m_child->setAcummulativeParentAngleZY( degreeZY );
		m_child->setInitialPosition( currentFinalPositionX, currentFinalPositionY, currentFinalPositionZ );
	}
	return *this;
}

Leg& Leg::setAngleZYLimits( double min, double max )
{
	m_angleZYMin = min;
	m_angleZYMax = max;
	return *this;
}

Leg& Leg::getAngleZYLimits( double & min, double & max )
{
	min = m_angleZYMin;
	max = m_angleZYMax;
	return *this;
}

Leg& Leg::setAngleZYEnable( bool enable )
{
	m_angleZYEnabled = enable;
	return *this;
}

bool Leg::getAngleZYEnabled() const
{
	return m_angleZYEnabled;
}

Leg& Leg::setAcummulativeParentAngleZY( double accumulativeParentsAngle )
{
	m_accumulativeParentAngleZY = accumulativeParentsAngle;
	return *this;
}

double Leg::getAcummulativeParentAngleZY()
{
	return m_accumulativeParentAngleZY;
}

Leg& Leg::setInitialPosition( TypePrecision x, TypePrecision y, TypePrecision z )
{
	m_initialX = x;
	m_initialY = y;
	m_initialZ = z;

	if( nullptr != m_child.get() )
	{
		TypePrecision currentFinalPositionX, currentFinalPositionY, currentFinalPositionZ;
		getCalulatedFinalPosition( currentFinalPositionX, currentFinalPositionY, currentFinalPositionZ );
		m_child->setInitialPosition( currentFinalPositionX, currentFinalPositionY, currentFinalPositionZ );
	}
	return *this;
}

const Leg& Leg::getInitialPosition( TypePrecision & x, TypePrecision & y, TypePrecision & z ) const
{
	x = m_initialX + m_offsetInitialX;
	y = m_initialY + m_offsetInitialY;
	z = m_initialZ + m_offsetInitialZ;
	return *this;
}

//const Leg& Leg::getCalulatedFinalPosition( TypePrecision & x, TypePrecision & y, TypePrecision & z ) const
//{
//	double degreeXY = m_angleXY + m_accumulativeParentAngleXY;
//	double degreeZX = m_angleZX + m_accumulativeParentAngleZX;
//
//	double radiansXY = Utils::deg2Rad( degreeXY );
//	double radiansZX = Utils::deg2Rad( degreeZX );
//
//	//around Y
//	x = 0;
//	y = 0;
//	z = 0;
//	x = m_length * std::cos( radiansZX );
//	z = m_length * std::sin( radiansZX );
//
//
//	double tempX = x;
//
//	//around Z
//	x = tempX * std::cos( radiansXY );
//	y = tempX * std::sin( radiansXY );
//
//	x += m_initialX;
//	y += m_initialY;
//	z += m_initialZ;
//
//	return *this;
//}


const Leg& Leg::getCalulatedFinalPosition( double & x, double & y, double & z ) const
{
	double degreeXY = m_angleXY + m_accumulativeParentAngleXY;
	double degreeZX = m_angleXZ + m_accumulativeParentAngleZX;

	double radiansXY = Utils::deg2Rad( degreeXY );
	double radiansZX = Utils::deg2Rad( degreeZX );

	//around Z
	x = m_length * std::cos( radiansXY );
	y = m_length * std::sin( radiansXY );
	z = 0;

	//around Y
	double tempX = x;
	x = tempX * std::cos( radiansZX );
	z = tempX * std::sin( radiansZX );

	x += m_initialX + m_offsetInitialX;
	y += m_initialY + m_offsetInitialY;
	z += m_initialZ + m_offsetInitialZ;

	return *this;
}


Leg& Leg::setAccumulativeParentAngleXY( double accumulativeParentsAngle )
{
	m_accumulativeParentAngleXY = accumulativeParentsAngle;
	if( nullptr != m_child.get() )
	{
		m_child->setAccumulativeParentAngleXY( m_accumulativeParentAngleXY + m_angleXY );
	}
	return *this;
}

double Leg::getAccumulativeParentAngleXY()
{
	return m_accumulativeParentAngleXY;
}

Leg& Leg::setAcummulativeParentAngleXZ( double accumulativeParentsAngle )
{
	m_accumulativeParentAngleZX = accumulativeParentsAngle;
	if( nullptr != m_child.get() )
	{
		m_child->setAcummulativeParentAngleXZ( m_accumulativeParentAngleZX + m_angleXZ );
	}
	return *this;
}

double Leg::getAcummulativeParentAngleXZ()
{
	return m_accumulativeParentAngleZX;
}

int Leg::getLevel() const
{
	return m_level;
}

struct pt {
	TypePrecision x, y;
};


inline int area (pt a, pt b, pt c) {
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

inline bool intersect_1 (int a, int b, int c, int d) {
	if (a > b)  std::swap ( a, b );
	if (c > d)  std::swap ( c, d );
	return std::max( a, c ) <= std::min( b, d );
}

//bool Leg::isCrossing( const Leg & leg )
//{
//	pt a, b, c, d, tmp;
//	leg.getInitialPosition( a.x, a.y, tmp.x );
//	leg.getCalulatedFinalPosition( b.x, b.y, tmp.x );
//	getInitialPosition( c.x, c.y, tmp.x );
//	getCalulatedFinalPosition( d.x, d.y, tmp.x );
//
//	bool croossCandidate = intersect_1 (a.x, b.x, c.x, d.x)
//	&& intersect_1 (a.y, b.y, c.y, d.y)
//	&& area(a,b,c) * area(a,b,d) <= 0
//	&& area(c,d,a) * area(c,d,b) <= 0;
//
//	bool isBeginEndTouch = ( a.x == d.x && a.y == d.y ) || ( b.x == c.x && b.y == c.y );
//
//	bool crossed = croossCandidate && ( false == isBeginEndTouch );
//
//	return crossed;
//}
#include "HardFire.h"
bool Leg::isCrossing( const Leg & leg )
{
	point a, b, c, d, tmp;
	leg.getInitialPosition( a.x, a.y, tmp.x );
	leg.getCalulatedFinalPosition( b.x, b.y, tmp.x );
	getInitialPosition( c.x, c.y, tmp.x );
	getCalulatedFinalPosition( d.x, d.y, tmp.x );

	bool croossCandidate = cross_segment( a, b, c, d, tmp );
	bool isBeginEndTouch = ( a.x == d.x && a.y == d.y ) || ( b.x == c.x && b.y == c.y );

	bool crossed = croossCandidate && ( false == isBeginEndTouch );

	return crossed;
}

//bool Leg::isCrossing( const Leg & leg )
//{
//	TypePrecision originInitialX, originInitialY, originInitialZ;
//	TypePrecision originFinalX, originFinalY, originFinalZ;
//	TypePrecision srcInitialX, srcInitialY, srcInitialZ;
//	TypePrecision srcFinalX, srcFinalY, srcFinalZ;
//	leg.getInitialPosition( srcInitialX, srcInitialY, srcInitialZ );
//	leg.getCalulatedFinalPosition( srcFinalX, srcFinalY, srcFinalZ );
//	getInitialPosition( originInitialX, originInitialY, originInitialZ );
//	getCalulatedFinalPosition( originFinalX, originFinalY, originFinalZ );
//
//	bool croossCandidate = Utils::isCrossingLines( originInitialX, originInitialY, originInitialZ, originFinalX, originFinalY, originFinalZ,
//												   srcInitialX, srcInitialY, srcInitialZ, srcFinalX, srcFinalY, srcFinalZ );
//
//	bool isBeginEndTouch = ( srcInitialX == originFinalX && srcInitialY == originFinalY ) || ( srcFinalX == originInitialX && srcFinalY == originInitialY );
//
//	bool crossed = croossCandidate && ( false == isBeginEndTouch );
//
//	return crossed;
//}

void Leg::print()
{
	TypePrecision finalX, finalY, finalZ;
	this->getCalulatedFinalPosition( finalX, finalY, finalZ );
	std::cout << "level=" << m_level << ", angleXY=" << m_angleXY << ", m_angleXZ=" << m_angleXZ << ", initial=( " << m_initialX << ", " << m_initialY << " ), final=( " << finalX << ", " << finalY << ", " << finalZ << "" << " )" << std::endl;
}
