/*
 * IDerivative.h
 *
 *  Created on: Mar 19, 2018
 *      Author: vadym_ostanin
 */

#ifndef CORE_IDERIVATIVE_H_
#define CORE_IDERIVATIVE_H_

#include "IDataReceiver.h"
#include "IFuncDiffParams.h"
#include <vector>
#include <memory>

class IFunction;
typedef std::shared_ptr<IFunction> IFuncSh;

class IFunction
{
public:
	virtual std::vector<double> evaluate() const = 0;
	virtual IFuncSh diff( const IFuncDiffParams & params ) = 0;
	virtual void onReceive( const IFuncParams & data ) = 0;
	virtual ~IFunction(){};
};

typedef std::shared_ptr<IFunction> IFuncSh;

#endif /* CORE_IDERIVATIVE_H_ */
