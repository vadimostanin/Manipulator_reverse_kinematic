/*
 * GiNaCFuncDiffParams.cpp
 *
 *  Created on: Aug 28, 2018
 *      Author: vadym_ostanin
 */

#include "GiNaCFuncDiffParams.h"

GiNaCFuncDiffParams::GiNaCFuncDiffParams( std::shared_ptr<GiNaC::symbol> symbol, uint32_t derrivativeDepth ):
    IFuncDiffParams(eParamType::eGiNaCTypes), m_Symbol( symbol ), m_DerrivativeDepth( derrivativeDepth )
{
}

GiNaCFuncDiffParams::~GiNaCFuncDiffParams()
{
}

