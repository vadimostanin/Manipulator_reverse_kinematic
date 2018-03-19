/*
 * IDerivative.h
 *
 *  Created on: Mar 19, 2018
 *      Author: vadym_ostanin
 */

#ifndef CORE_IDERIVATIVE_H_
#define CORE_IDERIVATIVE_H_

#include <vector>

class IDerivative
{
public:
	double evaluate( const std::vector<double> &  );
};

#endif /* CORE_IDERIVATIVE_H_ */
