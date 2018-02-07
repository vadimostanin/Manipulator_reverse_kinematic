/*
 * FailedBehaviours.cpp
 *
 *  Created on: Feb 7, 2018
 *      Author: vadym_ostanin
 */

#include "FailedBehaviours.h"

#include "LegsMgr.h"
#include "core/Solver.h"

FailedBehaviours::FailedBehaviours()
{
	fillFailedBehaviours();
}

FailedBehaviours::~FailedBehaviours()
{
}

void FailedBehaviours::fillFailedBehaviours()
{
	ShLegManipulator manipulatorFrom = std::make_shared<LegManipulator>();
	manipulatorFrom->add( 100 );
	manipulatorFrom->add( 75 );
	manipulatorFrom->add( 50 );
	manipulatorFrom->add( 30 );
	manipulatorFrom->add( 20 );
	manipulatorFrom->pair();

	ShLegManipulator manipulatorTo = manipulatorFrom->clone();

	manipulatorFrom->getLeg( 0 )->setAngleXY( 93.9478 ).setAngleXZ( -180 ).setInitialPosition( 200, 0, 0 );
	manipulatorFrom->getLeg( 1 )->setAngleXY( -126.053 );
	manipulatorFrom->getLeg( 2 )->setAngleXY( -92.8557 );
	manipulatorFrom->getLeg( 3 )->setAngleXY( 54.5547 );
	manipulatorFrom->getLeg( 4 )->setAngleXY( 116.203 );



	manipulatorTo->getLeg( 0 )->setAngleXY( 46.1152 ).setAngleXZ( -180 ).setInitialPosition( 200, 0, 0 );
	manipulatorTo->getLeg( 1 )->setAngleXY( -143.556 );
	manipulatorTo->getLeg( 2 )->setAngleXY( -106.824 );
	manipulatorTo->getLeg( 3 )->setAngleXY( 39.5335 );
	manipulatorTo->getLeg( 4 )->setAngleXY( -71.6123 );
	BehaviourInfo behaviourInfo = { manipulatorFrom, manipulatorTo, 226, 27, 0 };

	m_failedBehaviours.push_back( behaviourInfo );
}

void FailedBehaviours::runBehaviours()
{
	for( auto & behaviour : m_failedBehaviours )
	{
		Solver solver( behaviour.manipulatorFrom );
		bool pathPossible = solver.isPathPossble( behaviour.manipulatorFrom, behaviour.manipulatorTo );
		std::cout << "pathPossible=" << pathPossible << std::endl;
	}
}



