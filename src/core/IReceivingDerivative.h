/*
 * IReceivingDerivative.h
 *
 *  Created on: Mar 20, 2018
 *      Author: vadym_ostanin
 */

#ifndef CORE_IRECEIVINGDERIVATIVE_H_
#define CORE_IRECEIVINGDERIVATIVE_H_

#include "IDataReceiver.h"
#include "IDerivative.h"

class IReceivingFunction: public IFunction, public IDataReceiver
{
};

#endif /* CORE_IRECEIVINGDERIVATIVE_H_ */
