/*
 * PlatformMovable.cpp
 *
 *  Created on: Feb 19, 2018
 *      Author: vadym_ostanin
 */

#include "PlatformMovable.h"

PlatformMovable::PlatformMovable()
{
}

PlatformMovable::~PlatformMovable()
{
}

uint32_t PlatformMovable::getWidth() const
{
	return m_width;
}

uint32_t PlatformMovable::getLength() const
{
	return m_length;
}

uint32_t PlatformMovable::getHeight() const
{
	return m_height;
}

uint32_t PlatformMovable::getX() const
{
	return m_x;
}

uint32_t PlatformMovable::getY() const
{
	return m_y;
}

uint32_t PlatformMovable::getZ() const
{
	return m_z;
}

PlatformMovable & PlatformMovable::setWidth( uint32_t width )
{
	m_width = width;
	return *this;
}

PlatformMovable & PlatformMovable::setLength( uint32_t length )
{
	m_length = length;
	return *this;
}

PlatformMovable & PlatformMovable::setHeight( uint32_t height )
{
	m_height = height;
	return *this;
}

PlatformMovable & PlatformMovable::setX( uint32_t x )
{
	m_x = x;
	return *this;
}

PlatformMovable & PlatformMovable::setY( uint32_t y )
{
	m_y = y;
	return *this;
}

PlatformMovable & PlatformMovable::setZ( uint32_t z )
{
	m_z = z;
	return *this;
}

