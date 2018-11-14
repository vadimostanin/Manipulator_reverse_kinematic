/*
 * Leg.h
 *
 *  Created on: 9 дек. 2017 г.
 *      Author: vadim
 */

#ifndef LEG_H_
#define LEG_H_

#include <memory>
#include <vector>

class Leg;
typedef std::shared_ptr<Leg> ShLeg;
typedef std::vector<ShLeg> Legs;

typedef double TypePrecision;

class Leg
{
public:
	Leg( int level );
	virtual ~Leg();

	Leg( const Leg & ) = default;
	Leg& operator=( const Leg & leg ) = default;
	Leg& operator=( const ShLeg leg );

	void setChild( ShLeg child );

	int getLength() const;
	Leg& setLength( int length );

	double getWidth1() const;
	Leg& setWidth1( double w1 );

//	double getWidth2() const;
//	Leg& setWindth2( double w2 );

	Leg& setInitialOffsets( double offsetX, double offsetY, double offsetZ );
	Leg& getInitialOffsets( double & offsetX, double & offsetY, double & offsetZ );

	double getAngleXY() const;
	Leg& setAngleXY( double angle );
	Leg& setAngleXYLimits( double min, double max );
	Leg& getAngleXYLimits( double & min, double & max );
	Leg& setAngleXYEnable( bool enable );
	bool getAngleXYEnabled() const;
	Leg& setAccumulativeParentAngleXY( double accumulativeParentsAngle );
	double getAccumulativeParentAngleXY();

	double getAngleXZ() const;
	Leg& setAngleXZ( double angle );
	Leg& setAngleXZLimits( double min, double max );
	Leg& getAngleXZLimits( double & min, double & max );
	Leg& setAngleXZEnable( bool enable );
	bool getAngleXZEnabled() const;
	Leg& setAcummulativeParentAngleXZ( double accumulativeParentsAngle );
	double getAcummulativeParentAngleXZ();

	double getAngleZY() const;
	Leg& setAngleZY( double angle );
	Leg& setAngleZYLimits( double min, double max );
	Leg& getAngleZYLimits( double & min, double & max );
	Leg& setAngleZYEnable( bool enable );
	bool getAngleZYEnabled() const;
	Leg& setAcummulativeParentAngleZY( double accumulativeParentsAngle );
	double getAcummulativeParentAngleZY();

	int getLevel() const;

	Leg& setInitialPosition( TypePrecision x, TypePrecision y, TypePrecision z );
	const Leg& getInitialPosition( TypePrecision & x, TypePrecision & y, TypePrecision & z ) const;

	const Leg& getCalulatedFinalPosition( TypePrecision & x, TypePrecision & y, TypePrecision & z ) const;

	bool isCrossing( const Leg& leg );

	void print();
private:
	double m_length;
	double m_width1;
	double m_width2;
	double m_angleXY;
	double m_angleXYMax;
	double m_angleXYMin;
	bool   m_angleXYEnabled;
	double m_accumulativeParentAngleXY;
	double m_angleXZ;
	double m_angleXZMax;
	double m_angleXZMin;
	bool   m_angleXZEnabled;
	double m_accumulativeParentAngleZX;
	double m_angleZY;
	double m_angleZYMax;
	double m_angleZYMin;
	bool   m_angleZYEnabled;
	double m_accumulativeParentAngleZY;
	int m_level;
	ShLeg m_child;
	TypePrecision m_initialX;
	TypePrecision m_initialY;
	TypePrecision m_initialZ;

	TypePrecision m_offsetInitialX;
	TypePrecision m_offsetInitialY;
	TypePrecision m_offsetInitialZ;
};

#endif /* LEG_H_ */
