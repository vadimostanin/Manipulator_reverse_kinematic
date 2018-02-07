/*
 * ErrorFuncStorage.h
 *
 *  Created on: Feb 7, 2018
 *      Author: vadym_ostanin
 */

#ifndef CORE_ERRORFUNCSTORAGE_H_
#define CORE_ERRORFUNCSTORAGE_H_

#include <vector>
#include <functional>

typedef std::function<double( std::vector<double> & )> ErroFuncType;

class ErrorFuncStorage
{
public:
	ErrorFuncStorage();
	virtual ~ErrorFuncStorage();

	void getFunc( int legsCount, std::vector<ErroFuncType> & funcs );
};

#endif /* CORE_ERRORFUNCSTORAGE_H_ */
