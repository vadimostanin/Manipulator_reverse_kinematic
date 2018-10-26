/*
 * LegManipulator.cpp
 *
 *  Created on: Jan 16, 2018
 *      Author: vadym_ostanin
 */

#include "LegManipulator.h"
#include <algorithm>
#include <cassert>

LegManipulator::LegManipulator()
{
}

LegManipulator::LegManipulator( Legs::iterator begin, Legs::iterator end ) : Legs( begin, end )
{
	;
}

LegManipulator::~LegManipulator()
{
}

ShLeg LegManipulator::add( int length )
{
	const int count = size();
	const int level = count;
	auto leg = std::make_shared<Leg>( level );
	leg->setLength( length );
	emplace_back( leg );
	return leg;
}

void LegManipulator::pair( ShLeg parent, ShLeg child )
{
	parent->setChild( child );
}

ShLeg LegManipulator::getLeg( int level )
{
	auto it = std::find_if( std::begin( *this ), std::end( *this ),
			[&level]( const ShLeg & leg ) -> bool
			{
				return leg->getLevel() == level;
			}
	);
	if( std::end( *this ) == it )
	{
		assert( false );
	}
	return *it;
}

ShLeg LegManipulator::getFirstLeg()
{
	return front();
}

ShLeg LegManipulator::getLastLeg()
{
	return back();
}

ShLeg LegManipulator::getPreLastLeg()
{
	return *(this->rbegin()--);
}

void LegManipulator::pair()
{
	std::adjacent_find( std::begin( *this ), std::end( *this ),
				[this]( const ShLeg & legLeft, const ShLeg & legRigth ) -> bool
				{
					this->pair( legLeft, legRigth );
					return false;
				}
		);
}

void LegManipulator::pair( const Legs & legs )
{
	std::adjacent_find( std::begin( legs ), std::end( legs ),
					[this]( const ShLeg & legLeft, const ShLeg & legRigth ) -> bool
					{
						this->pair( legLeft, legRigth );
						return false;
					}
			);
}

Legs & LegManipulator::getLegs()
{
	return *this;
}

void LegManipulator::print()
{
	for( const auto & leg : *this )
	{
		leg->print();
	}
}

//Legs LegManipulator::clone()
//{
//	Legs newLegs;
//	for( const auto & leg : *this )
//	{
////		const auto newLeg = std::make_shared<Leg>( *leg );
//		Leg newLegObj = *leg;
//		const auto newLeg = std::shared_ptr<Leg>( new Leg( newLegObj ));
//		newLegs.push_back( newLeg );
//	}
//	pair( newLegs );
//	return std::move( newLegs );
//}

ShLegManipulator LegManipulator::clone()
{
	ShLegManipulator clonedManipulator = std::make_shared<LegManipulator>();
	for( const auto & leg : *this )
	{
//		const auto newLeg = std::make_shared<Leg>( *leg );
		const auto & newLegObj = *leg;
		const auto newLeg = std::make_shared<Leg>( newLegObj );
		clonedManipulator->push_back( newLeg );
	}
	clonedManipulator->pair();
	return std::move( clonedManipulator );
}

LegManipulator & LegManipulator::deepAssign( LegManipulator & src )
{
	assert( size() == src.size() );

	for( const auto & leg : *this )
	{
		(*leg) = src.getLeg( leg->getLevel() );
		leg->setAngleXY( (*leg).getAngleXY() );
		leg->setAngleXZ( (*leg).getAngleXZ() );
		leg->setAngleZY( (*leg).getAngleZY() );
	}
	pair();

	return *this;
}

LegManipulator & LegManipulator::deepAssign( ShLegManipulator & src )
{
	return deepAssign( *src );
}
