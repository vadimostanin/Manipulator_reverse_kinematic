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

typedef std::function<double( std::vector<double> & )> DerivFuncType;

class DerivativeFuncsStorage
{
public:
	DerivativeFuncsStorage();
	~DerivativeFuncsStorage();

	void getFunc( int legsCount, std::vector<DerivFuncType> & funcs );
};

#endif /* DERIVATIVEFUNCSSTORAGE_H_ */
