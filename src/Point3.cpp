/*
 * Point3.cpp
 *
 *  Created on: 2 янв. 2018 г.
 *      Author: vadim
 */

#include "Point3.h"
#include <iostream>

Point3::Point3() : m_x( 0 ), m_y( 0 ), m_z( 0 )
{
}

Point3::Point3( int x ) : m_x( x ), m_y( 0 ), m_z( 0 )
{
}

Point3::Point3( int x, int y ) : m_x( x ), m_y( y ), m_z( 0 )
{
}

Point3::Point3( int x, int y, int z ) : m_x( x ), m_y( y ), m_z( z )
{
}

void Point3::setX( int x )
{
	m_x = x;
}

void Point3::setY( int y )
{
	m_y = y;
}

void Point3::setZ( int z )
{
	m_z = z;
}

int Point3::getX()
{
	return m_x;
}

int Point3::getY()
{
	return m_y;
}

int Point3::getZ()
{
	return m_z;
}

void Point3::print()
{
	std::cout << "X=" << m_x << ", Y=" << m_y << ", Z=" << m_z << std::endl;
}
