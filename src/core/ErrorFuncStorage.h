/*
 * ErrorFuncStorage.h
 *
 *  Created on: Feb 7, 2018
 *      Author: vadym_ostanin
 */

#ifndef CORE_ERRORFUNCSTORAGE_H_
#define CORE_ERRORFUNCSTORAGE_H_

#include "funcwrapper/Types.h"
#include <vector>
#include <functional>

class ErrorFuncStorage
{
public:
	ErrorFuncStorage();
	virtual ~ErrorFuncStorage();

	void getFunc( int32_t legsCount, ErrorFuncType & funcs );
};

#endif /* CORE_ERRORFUNCSTORAGE_H_ */
