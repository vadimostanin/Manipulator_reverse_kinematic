/*
 * IDerivative.h
 *
 *  Created on: Mar 19, 2018
 *      Author: vadym_ostanin
 */

#ifndef CORE_IDERIVATIVE_H_
#define CORE_IDERIVATIVE_H_

#include "IDataReceiver.h"
#include <vector>

class IDerivative
{
public:
	virtual double evaluate() = 0;
	virtual ~IDerivative(){};
};

#endif /* CORE_IDERIVATIVE_H_ */
