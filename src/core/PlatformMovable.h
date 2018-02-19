/*
 * PlatformMovable.h
 *
 *  Created on: Feb 19, 2018
 *      Author: vadym_ostanin
 */

#ifndef CORE_PLATFORMMOVABLE_H_
#define CORE_PLATFORMMOVABLE_H_

#include <cinttypes>

class PlatformMovable
{
public:
	PlatformMovable();
	virtual ~PlatformMovable();
private:
	uint32_t m_width{0};
	uint32_t m_length{0};
	uint32_t m_height{0};
	uint32_t m_x{0};
	uint32_t m_y{0};
	uint32_t m_z{0};

	uint32_t getWidth() const;
	uint32_t getLength() const;
	uint32_t getHeight() const;
	uint32_t getX() const;
	uint32_t getY() const;
	uint32_t getZ() const;

	PlatformMovable & setWidth( uint32_t width );
	PlatformMovable & setLength( uint32_t length );
	PlatformMovable & setHeight( uint32_t height );
	PlatformMovable & setX( uint32_t x );
	PlatformMovable & setY( uint32_t y );
	PlatformMovable & setZ( uint32_t z );
};

#endif /* CORE_PLATFORMMOVABLE_H_ */
