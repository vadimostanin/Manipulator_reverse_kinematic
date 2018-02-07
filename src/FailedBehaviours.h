/*
 * FailedBehaviours.h
 *
 *  Created on: Feb 7, 2018
 *      Author: vadym_ostanin
 */

#ifndef FAILEDBEHAVIOURS_H_
#define FAILEDBEHAVIOURS_H_

#include "core/LegManipulator.h"

class FailedBehaviours
{
	struct BehaviourInfo
	{
		ShLegManipulator manipulatorFrom;
		ShLegManipulator manipulatorTo;
		TypePrecision x, y, z;
	};
public:
	FailedBehaviours();
	virtual ~FailedBehaviours();

	void fillFailedBehaviours();
	void runBehaviours();

	std::vector<BehaviourInfo> m_failedBehaviours;
};

#endif /* FAILEDBEHAVIOURS_H_ */
