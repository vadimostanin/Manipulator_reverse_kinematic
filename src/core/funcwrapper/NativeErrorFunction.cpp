/*
 * NativeErrorFunction.cpp
 *
 *  Created on: Sep 19, 2018
 *      Author: vadym_ostanin
 */

#include "NativeErrorFunction.h"
#include "NativeFuncDiffParam.h"

NativeErrorFunction::NativeErrorFunction( ErrorFuncType func ):
	m_Func( func )
{
}

NativeErrorFunction::~NativeErrorFunction()
{
}

std::vector<double> NativeErrorFunction::evaluate() const
{
	std::vector<double> result( 1, m_Func( m_funcParams ) );
	return result;
}

IFuncSh NativeErrorFunction::diff( const IFuncParams & iParams )
{
	return nullptr;//no derivatives expected
}

void NativeErrorFunction::onReceive( const IFuncParams & data )
{
	if( IFuncParams::eParamType::NativeFuncParams == data.type() )
	{
		const auto & obj = static_cast<const NativeFuncDiffParam&>( data );
		m_funcParams = obj.getParams();
	}
}
