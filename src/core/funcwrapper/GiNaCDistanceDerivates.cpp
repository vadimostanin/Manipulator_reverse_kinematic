/*
 * DistanceDerivates.cpp
 *
 *  Created on: 19 мар. 2018 г.
 *      Author: vadim
 */

#include "DistanceDataParams.h"
#include "GiNaCDistanceDerivates.h"
#include "GiNaCTypesDataParams.h"
#include "LegAnglesDataParams.h"

GiNaCDistanceDerivates::GiNaCDistanceDerivates()
{
}

std::vector<double> GiNaCDistanceDerivates::evaluate() const
{
	std::vector<double> errors( size() );
	auto errorIter = std::begin( errors );
	for( const auto diff : *this )
	{
		(*errorIter) = diff->evaluate().front();

		errorIter++;
	}
	return std::move(errors);
}

IFuncSh GiNaCDistanceDerivates::diff( const IFuncDiffParams & params )
{
	throw std::exception();
//    auto cloned = std::make_shared<GiNaCDistanceDerivates>();
//    return cloned;
}

void GiNaCDistanceDerivates::onReceive( const IFuncParams & data )
{
	for( const auto diff : *this )
	{
		diff->onReceive( data );
	}
}
