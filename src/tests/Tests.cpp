/*
 * Tests.cpp
 *
 *  Created on: Mar 1, 2018
 *      Author: vadym_ostanin
 */

#include "Tests.h"
#include "../core/LegManipulator.h"
#include "../core/Solver.h"

Tests::Tests(){
	// TODO Auto-generated constructor stub

}

Tests::~Tests() {
	// TODO Auto-generated destructor stub
}

void Tests::run1()
{
	auto legMan = std::make_shared<LegManipulator>();
	legMan->add( 100 );
	legMan->add( 75 );
	legMan->add( 50 );
	legMan->add( 30 );
	legMan->add( 20 );
	legMan->pair();
	Solver solver( legMan );
	double epsilonChangeError = 0.1;
	std::cout << "error=" << solver.getErrorFunctionValue( 100, 100, 0 ) << std::endl;
	solver.solveFromCurrent( 100, 100, 0, epsilonChangeError, 1000 );
	std::cout << "error=" << solver.getErrorFunctionValue( 100, 100, 0 ) << std::endl;
}

void Tests::run2()
{
	auto legMan = std::make_shared<LegManipulator>();
	legMan->add( 100 );
	legMan->add( 80 );
	legMan->add( 75 );
	legMan->add( 70 );
	legMan->add( 65 );
	legMan->add( 60 );
	legMan->add( 55 );
	legMan->add( 40 );
	legMan->add( 35 );
	legMan->add( 30 );
	legMan->pair();
	Solver solver( legMan );
	double epsilonChangeError = 0.1;
	std::cout << "error=" << solver.getErrorFunctionValue( 106, 332, 0 ) << std::endl;
	solver.solveFromCurrent( 106, 332, 0, epsilonChangeError, 1000 );
	std::cout << "error=" << solver.getErrorFunctionValue( 106, 332, 0 ) << std::endl;
}
