/*
 * ErrorFunctions.h
 *
 *  Created on: Feb 7, 2018
 *      Author: vadym_ostanin
 */

#ifndef CORE_ERRORFUNCTIONS_H_
#define CORE_ERRORFUNCTIONS_H_

#include <vector>

class ErrorFunctions
{
public:
	static double error_Legs_5( std::vector<double> & params );
};

#endif /* CORE_ERRORFUNCTIONS_H_ */