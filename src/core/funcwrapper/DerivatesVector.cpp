/*
 * DerivatesVector.cpp
 *
 *  Created on: Mar 20, 2018
 *      Author: vadym_ostanin
 */

#include "DerivatesVector.h"

std::vector<double> DerivatesVector::evaluate()
{
	std::vector<double> result;
	for( auto & func : *this )
	{
		std::vector<double> tmp = func->evaluate();
		std::copy( tmp.begin(), tmp.end(), std::back_inserter( result ) );
	}
	return result;
}

void DerivatesVector::onReceive( const IFuncParams & data )
{
	for( auto & func : *this )
	{
		func->onReceive( data );
	}
}
