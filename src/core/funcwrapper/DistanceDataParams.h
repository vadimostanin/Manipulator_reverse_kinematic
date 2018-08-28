/*
 * DistanceDataChunk.h
 *
 *  Created on: 19 мар. 2018 г.
 *      Author: vadim
 */

#ifndef CORE_DISTANCEDATACHUNK_H_
#define CORE_DISTANCEDATACHUNK_H_

#include <stdint.h>
#include "IFuncParams.h"

class DistanceDataParams: public IFuncParams
{
public:
	DistanceDataParams( int32_t x, int32_t y, int32_t z );
	virtual ~DistanceDataParams();

	int32_t getX() const { return m_X; }
	int32_t getY() const { return m_Y; }
	int32_t getZ() const { return m_Z; }
private:
	int32_t m_X;
	int32_t m_Y;
	int32_t m_Z;
};

#endif /* CORE_DISTANCEDATACHUNK_H_ */
