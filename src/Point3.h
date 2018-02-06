/*
 * Point3.h
 *
 *  Created on: 2 янв. 2018 г.
 *      Author: vadim
 */

#ifndef POINT3_H_
#define POINT3_H_

class Point3
{
public:
	Point3();
	Point3( int x );
	Point3( int x, int y );
	Point3( int x, int y, int z );

	Point3( const Point3 & src ) = default;
	Point3 & operator = ( const Point3 & src ) = default;

	void setX( int x );
	void setY( int y );
	void setZ( int z );

	int getX();
	int getY();
	int getZ();

	void print();
private:
	int m_x, m_y, m_z;
};

#endif /* POINT3_H_ */
