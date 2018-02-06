/*
 * ManipulatorUniConverter.h
 *
 *  Created on: Jan 25, 2018
 *      Author: vadym_ostanin
 */

#ifndef CORE_MANIPULATORUNICONVERTER_H_
#define CORE_MANIPULATORUNICONVERTER_H_

#include <vector>
#include "LegManipulator.h"

class ManipulatorUniConverter
{
public:

	static std::vector<double> getFormatedAngles( ShLegManipulator manipulator );

	static void setAnglesToManipualtor( ShLegManipulator manipulator, const std::vector<double> & vars );
};

#endif /* CORE_MANIPULATORUNICONVERTER_H_ */
