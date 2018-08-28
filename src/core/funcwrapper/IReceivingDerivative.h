/*
 * IReceivingDerivative.h
 *
 *  Created on: Mar 20, 2018
 *      Author: vadym_ostanin
 */

#ifndef CORE_IRECEIVINGDERIVATIVE_H_
#define CORE_IRECEIVINGDERIVATIVE_H_

#include "IDataReceiver.h"
#include "IFunction.h"

class IReceivingFunction: public IFunction, public IDataReceiver
{
};

typedef std::shared_ptr<IReceivingFunction> IRecFuncSh;

#endif /* CORE_IRECEIVINGDERIVATIVE_H_ */
