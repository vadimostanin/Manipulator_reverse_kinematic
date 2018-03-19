/*
 * LegManipulator.h
 *
 *  Created on: Jan 16, 2018
 *      Author: vadym_ostanin
 */

#ifndef CORE_LEGMANIPULATOR_H_
#define CORE_LEGMANIPULATOR_H_

#include "Leg.h"

class LegManipulator;
typedef std::shared_ptr<LegManipulator> ShLegManipulator;

class LegManipulator : public Legs
{
public:
	LegManipulator();
	LegManipulator( Legs::iterator begin, Legs::iterator end );
	virtual ~LegManipulator();

	void add( int length );
	ShLeg getLeg( int level );
	Legs & getLegs();

	ShLeg getFirstLeg();
	ShLeg getLastLeg();
	ShLeg getPreLastLeg();

	void pair( ShLeg parent, ShLeg child );
	void pair( const Legs & legs );
	void pair();

	void print();

	ShLegManipulator clone();
	LegManipulator & deepAssign( LegManipulator & src );
	LegManipulator & deepAssign( ShLegManipulator & src );
private:

};

#endif /* CORE_LEGMANIPULATOR_H_ */
