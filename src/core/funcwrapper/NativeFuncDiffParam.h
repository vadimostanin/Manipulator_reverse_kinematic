/*
 * NativeFuncDiffParam.h
 *
 *  Created on: Sep 19, 2018
 *      Author: vadym_ostanin
 */

#ifndef CORE_FUNCWRAPPER_NATIVEFUNCDIFFPARAM_H_
#define CORE_FUNCWRAPPER_NATIVEFUNCDIFFPARAM_H_

#include "IFuncParams.h"
#include "Types.h"

class NativeFuncDiffParam: public IFuncParams
{
public:
	NativeFuncDiffParam( const std::vector<double> & params );
	virtual ~NativeFuncDiffParam();

	const std::vector<double> & getParams() const;
private:

	std::vector<double> m_funcParams;
};

#endif /* CORE_FUNCWRAPPER_NATIVEFUNCDIFFPARAM_H_ */
