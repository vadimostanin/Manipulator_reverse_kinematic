/*
 * DerivativeFuncsStorage.h
 *
 *  Created on: Dec 15, 2017
 *      Author: user
 */

#ifndef DERIVATIVEFUNCSSTORAGE_H_
#define DERIVATIVEFUNCSSTORAGE_H_

#include <vector>
#include <functional>

#include "funcwrapper/Types.h"

class DerivativeFuncsStorage
{
public:
	DerivativeFuncsStorage();
	~DerivativeFuncsStorage();

	void getFuncs( int legsCount, std::vector<ErrorFuncType> & funcs );
};

#endif /* DERIVATIVEFUNCSSTORAGE_H_ */
