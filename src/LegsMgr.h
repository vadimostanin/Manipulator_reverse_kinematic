/*
 * LegsMgr.h
 *
 *  Created on: 9 дек. 2017 г.
 *      Author: vadim
 */

#ifndef LEGSMGR_H_
#define LEGSMGR_H_

#include "core/LegManipulator.h"
#include "DrawGL3DLeg.h"

class LegsMgr
{
	LegsMgr();
	virtual ~LegsMgr();
public:
	static LegsMgr & get();
	ShLegManipulator getManipulator();
//	void setManipulator( ShLegManipulator manipulator );

private:
	ShLegManipulator m_currentManipulator;
};

#endif /* LEGSMGR_H_ */
