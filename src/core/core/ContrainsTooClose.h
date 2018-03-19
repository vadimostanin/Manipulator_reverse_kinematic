/*
 * ContrainsTooClose.h
 *
 *  Created on: Mar 13, 2018
 *      Author: vadym_ostanin
 */

#ifndef CORE_CONTRAINSTOOCLOSE_H_
#define CORE_CONTRAINSTOOCLOSE_H_

#include "ISolveConstraints.h"

class ContrainsTooClose: public ISolveConstraints
{
public:
	ContrainsTooClose();
	virtual ~ContrainsTooClose();

	virtual bool is( ShLegManipulator manipulator ) override;

	bool isFinalTooClose( ShLegManipulator manipulator, const int32_t minDistance );
private:
	double m_minClosestDistance{15};
};
#endif /* CORE_CONTRAINSTOOCLOSE_H_ */
