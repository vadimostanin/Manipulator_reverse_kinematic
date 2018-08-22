/*
 * AngleDataChunk.h
 *
 *  Created on: 19 мар. 2018 г.
 *      Author: vadim
 */

#ifndef CORE_ANGLEDATACHUNK_H_
#define CORE_ANGLEDATACHUNK_H_

#include "IFuncParams.h"

class AngleDataChunk: public IFuncParams
{
public:
	AngleDataChunk( double angle );
	virtual ~AngleDataChunk();

	double getAngle() const { return m_Angle; }
private:

	double m_Angle;
};

#endif /* CORE_ANGLEDATACHUNK_H_ */
