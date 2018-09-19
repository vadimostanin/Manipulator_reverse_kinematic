/*
 * NativeErrorFunction.h
 *
 *  Created on: Sep 19, 2018
 *      Author: vadym_ostanin
 */

#ifndef CORE_FUNCWRAPPER_NATIVEERRORFUNCTION_H_
#define CORE_FUNCWRAPPER_NATIVEERRORFUNCTION_H_

#include "IReceivingDerivative.h"
#include "Types.h"
#include <vector>

class NativeErrorFunction: public IReceivingFunction
{
public:
	NativeErrorFunction( ErrorFuncType func );
	virtual ~NativeErrorFunction();
private:
	IFuncSh diff( const IFuncParams & params ) override;
	std::vector<double> evaluate() const override;
	void onReceive( const IFuncParams & data ) override;

	ErrorFuncType m_Func;
	std::vector<double> m_funcParams;
};

#endif /* CORE_FUNCWRAPPER_NATIVEERRORFUNCTION_H_ */
