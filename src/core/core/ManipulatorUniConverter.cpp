/*
 * ManipulatorUniConverter.cpp
 *
 *  Created on: Jan 25, 2018
 *      Author: vadym_ostanin
 */

#include "ManipulatorUniConverter.h"
#include <cassert>

std::vector<double> ManipulatorUniConverter::getFormatedAngles( ShLegManipulator manipulator )
{
	std::vector<double> result;
	for( const auto & leg : *manipulator )
	{
		result.push_back( leg->getAngleXY() );
		result.push_back( leg->getAngleXZ() );
		result.push_back( leg->getAngleZY() );
	}
	return std::move( result );
}

void ManipulatorUniConverter::setAnglesToManipualtor( ShLegManipulator manipulator, const std::vector<double> & vars )
{
	const uint8_t anglesPerLegCount = 3u;
	assert( manipulator->size() * anglesPerLegCount == vars.size() );

	auto varIter = std::begin( vars );
	auto legIter = std::begin( *manipulator );
	auto legEndIter = std::end( *manipulator );

	for( ; legIter != legEndIter ; legIter++, varIter++ )
	{
		auto & leg = ( *legIter );
		leg->setAngleXY( *( varIter ) );
		++varIter;
		leg->setAngleXZ( *( varIter ) );
		++varIter;
		leg->setAngleZY( *( varIter) );
	}
}
