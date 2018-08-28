/*
 * GiNaCFuncDiffParams.h
 *
 *  Created on: Aug 28, 2018
 *      Author: vadym_ostanin
 */

#ifndef CORE_FUNCWRAPPER_GINACFUNCDIFFPARAMS_H_
#define CORE_FUNCWRAPPER_GINACFUNCDIFFPARAMS_H_

#include "IFuncDiffParams.h"
#include <symbol.h>

class GiNaCFuncDiffParams: public IFuncDiffParams
{
public:
	GiNaCFuncDiffParams( std::shared_ptr<GiNaC::symbol> symbol, uint32_t derrivativeDepth );
	virtual ~GiNaCFuncDiffParams();

	std::shared_ptr<GiNaC::symbol> getSymbols() const { return m_Symbol; }
	uint32_t getDepth() const { return m_DerrivativeDepth; }
private:
	 std::shared_ptr<GiNaC::symbol> m_Symbol;
	 uint32_t m_DerrivativeDepth;
};

#endif /* CORE_FUNCWRAPPER_GINACFUNCDIFFPARAMS_H_ */
