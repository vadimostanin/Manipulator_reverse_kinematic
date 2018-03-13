/*
 * ContrainsTooClose.cpp
 *
 *  Created on: Mar 13, 2018
 *      Author: vadym_ostanin
 */

#include "ContrainsTooClose.h"
#include "Utils.h"

ContrainsTooClose::ContrainsTooClose() {
	// TODO Auto-generated constructor stub

}

ContrainsTooClose::~ContrainsTooClose() {
	// TODO Auto-generated destructor stub
}

bool ContrainsTooClose::is( ShLegManipulator manipulator )
{
	return isFinalTooClose( manipulator, m_minClosestDistance );
}


bool ContrainsTooClose::isFinalTooClose( ShLegManipulator manipulator, const int32_t minDistance )
{
	bool tooClose = false;
	const auto & lastLeg = manipulator->getLastLeg();
	const auto & preLastLeg = manipulator->getPreLastLeg();
	TypePrecision finalX, finalY, finalZ;
	lastLeg->getCalulatedFinalPosition( finalX, finalY, finalZ );
	finalX = (int)finalX;
	finalY = (int)finalY;
	finalZ = (int)finalZ;
	const size_t legsCount = manipulator->size();
	for( size_t leg_i = 0 ; leg_i < legsCount ; leg_i++ )//cross legs checking
	{
		const auto &legLoop = (*manipulator)[leg_i];
		if( lastLeg == legLoop || preLastLeg == legLoop )
		{
			continue;
		}
		TypePrecision legLoopInitialX, legLoopInitialY, legLoopInitialZ;
		TypePrecision legLoopFinalX, legLoopFinalY, legLoopFinalZ;
		legLoop->getInitialPosition( legLoopInitialX, legLoopInitialY, legLoopInitialZ );
		legLoop->getCalulatedFinalPosition( legLoopFinalX, legLoopFinalY, legLoopFinalZ );

		legLoopInitialX = (int)legLoopInitialX;
		legLoopInitialY = (int)legLoopInitialY;
		legLoopInitialZ = (int)legLoopInitialZ;
		legLoopFinalX = (int)legLoopFinalX;
		legLoopFinalY = (int)legLoopFinalY;
		legLoopFinalZ = (int)legLoopFinalZ;

		//a
		const double legLoopInitial_lastLegFinal_distance =
				Utils::distance( legLoopInitialX, legLoopInitialY, legLoopInitialZ, finalX, finalY, finalZ );
		//b
		const double legLoopFinal_lastLegFinal_distance =
				Utils::distance( legLoopFinalX, legLoopFinalY, legLoopFinalZ, finalX, finalY, finalZ );
		//c
		const double legLoopInitial_legLoopFinal_distance = legLoop->getLength();

		double triangleX = 0.0;
		const double distance = Utils::distanceByTriangle( legLoopInitial_lastLegFinal_distance,
				legLoopFinal_lastLegFinal_distance, legLoopInitial_legLoopFinal_distance, triangleX );

//		double legLoopInitial_lastLegFinal_angle = Utils::getDegAngle( distance, legLoopInitial_lastLegFinal_distance );
//		uint8_t legLoopInitial_lastLegFinal_quoter = Utils::getQouterByAngle( legLoopInitial_lastLegFinal_angle );

//		double legLoopFinal_lastLegFinal_angle = 90 + Utils::getDegAngle( distance, legLoopFinal_lastLegFinal_distance );
//		uint8_t legLoopFinal_lastLegFinal_quoter = Utils::getQouterByAngle( legLoopFinal_lastLegFinal_angle );
//
//		const bool isBelongToSegment = legLoopInitial_lastLegFinal_quoter != legLoopFinal_lastLegFinal_quoter;
		const bool isBelongToSegment = triangleX < legLoopInitial_legLoopFinal_distance && triangleX > 0.0;

		if( true == isBelongToSegment && distance <= minDistance )
		{
			tooClose = true;
//			std::cout << "leg " << legLoop->getLevel() << ", distance=" << distance << std::endl;
			break;
		}

	}
	return tooClose;
}
