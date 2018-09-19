/*
 * NativeFuncDiffParam.cpp
 *
 *  Created on: Sep 19, 2018
 *      Author: vadym_ostanin
 */

#include "NativeFuncDiffParam.h"

NativeFuncDiffParam::NativeFuncDiffParam( const std::vector<double> & params ):
		IFuncParams(eParamType::NativeFuncParams), m_funcParams( params )
{
}

NativeFuncDiffParam::~NativeFuncDiffParam()
{
}

const std::vector<double> & NativeFuncDiffParam::getParams() const
{
	return m_funcParams;
}
