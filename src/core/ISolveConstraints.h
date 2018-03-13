/*
 * ISolveConstraints.h
 *
 *  Created on: Mar 13, 2018
 *      Author: vadym_ostanin
 */

#ifndef CORE_ISOLVECONSTRAINTS_H_
#define CORE_ISOLVECONSTRAINTS_H_

#include "LegManipulator.h"

class ISolveConstraints
{
public:
	virtual bool is( ShLegManipulator manipulator ) = 0;
	virtual ~ISolveConstraints(){}
};

#endif /* CORE_ISOLVECONSTRAINTS_H_ */
