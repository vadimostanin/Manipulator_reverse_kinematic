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

	ShLeg add( int length );
	ShLeg getLeg( int level ) const;
	const Legs & getLegs() const;

	ShLeg getFirstLeg() const;
	ShLeg getLastLeg() const;
	ShLeg getPreLastLeg() const;

	void pair( ShLeg parent, ShLeg child ) const;
	void pair( const Legs & legs ) const;
	void pair() const;

	void print() const;

	ShLegManipulator clone();
	const LegManipulator & deepAssign( const LegManipulator & src ) const;
	const LegManipulator & deepAssign( const ShLegManipulator & src ) const;
private:

};

#endif /* CORE_LEGMANIPULATOR_H_ */
