/*
 * ConstraintPerpendicular.h
 *
 *  Created on: Mar 13, 2018
 *      Author: vadym_ostanin
 */

#ifndef CORE_CONSTRAINTPERPENDICULAR_H_
#define CORE_CONSTRAINTPERPENDICULAR_H_

#include "ISolveConstraints.h"

class ConstraintPerpendicular: public ISolveConstraints
{
public:
	ConstraintPerpendicular();
	virtual ~ConstraintPerpendicular();

	bool is( ShLegManipulator manipulator ) override;
};

#endif /* CORE_CONSTRAINTPERPENDICULAR_H_ */
