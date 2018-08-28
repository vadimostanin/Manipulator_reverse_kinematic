/*
 * DerivatesVector.cpp
 *
 *  Created on: Mar 20, 2018
 *      Author: vadym_ostanin
 */

#include "DerivatesVector.h"
#include "GiNaCFuncDiffParams.h"

std::vector<double> DerivatesVector::evaluate() const
{
	std::vector<double> result;
	for( const auto & func : *this )
	{
		std::vector<double> tmp = func->evaluate();
		std::copy( tmp.begin(), tmp.end(), std::back_inserter( result ) );
	}
	return result;
}

IFuncSh DerivatesVector::diff( const IFuncDiffParams & iParams )
{
    auto cloned = std::make_shared<DerivatesVector>();
    for( const auto func : *this )
    {
    	cloned->push_back( func->diff( iParams ) );
    }
    return cloned;
}

void DerivatesVector::onReceive( const IFuncParams & data )
{
	for( auto & func : *this )
	{
		func->onReceive( data );
	}
}
