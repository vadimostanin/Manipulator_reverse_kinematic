/*
 * DerivatesVector.cpp
 *
 *  Created on: Mar 20, 2018
 *      Author: vadym_ostanin
 */

#include "DerivatesVector.h"

std::vector<double> DerivatesVector::evaluate()
{
	return std::vector<double>();
}

void DerivatesVector::onReceive( const IDataChunk & data )
{
	for( auto & func : *this )
	{
		func->onReceive( data );
	}
}
