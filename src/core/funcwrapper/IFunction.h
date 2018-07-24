/*
 * IDerivative.h
 *
 *  Created on: Mar 19, 2018
 *      Author: vadym_ostanin
 */

#ifndef CORE_IFUNCTION_H_
#define CORE_IFUNCTION_H_

#include "IDataReceiver.h"
#include <vector>

class IFunction
{
public:
	virtual std::vector<double> evaluate() = 0;
	virtual ~IFunction(){};
};

#endif /* CORE_IFUNCTION_H_ */
