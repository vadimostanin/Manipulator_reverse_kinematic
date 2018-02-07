/*
 * DrawGL3DLeg.cpp
 *
 *  Created on: 2 янв. 2018 г.
 *      Author: vadim
 */

#include "DrawGL3DLeg.h"
#include "core/Utils.h"
#include "GL/gl.h"
#include <GL/glut.h>
#include <iostream>

DrawGL3DLeg::DrawGL3DLeg( ShLeg shLeg )
{
	m_Leg = shLeg;
}

DrawGL3DLeg::~DrawGL3DLeg()
{
}

ShLeg DrawGL3DLeg::getLeg() const
{
	return m_Leg;
}

void DrawGL3DLeg::drawLeg( int x, int y, int z, int width, int thickness, int height ) const
{
	glTranslatef( x, y, z );
	glScaled( width, thickness, height );
	glutSolidCube( 1 );
}

void DrawGL3DLeg::render() const
{
	{
		double initialX = 0, initialY = 0, initialZ = 0,
			   finalX = 0, finalY = 0, finalZ = 0;
		m_Leg->getInitialPosition( initialX, initialY, initialZ );
		m_Leg->getCalulatedFinalPosition( finalX, finalY, finalZ );
//		glPushMatrix();
////			int x = initialX, y = initialY, z = initialZ;
//			glTranslatef( initialX, initialY, initialZ );
////			std::cout << "parentAngleXY_" << m_Leg->getLevel() << "=" << m_Leg->getAccumulativeParentAngleXY()
////			          << ", angleXY_" << m_Leg->getLevel() << "=" << m_Leg->getAngleXY() << std::endl;
//			std::cout << "initialZ=" << initialZ << std::endl;
//			glRotated( m_Leg->getAccumulativeParentAngleXY() + m_Leg->getAngleXY(), 0, 0, 1 );
//			glRotated( ( -1 ) * ( m_Leg->getAcuumulativeParentAngleZX() + m_Leg->getAngleZX() ), 0, 1, 0 );
//
//
//			glTranslatef( m_Leg->getLength() / 2, 0, 0 );
//			drawLeg( 0, 0, 0, m_Leg->getLength(), 10, 10 );
//		glPopMatrix();
		glPushMatrix();
			glTranslatef( initialX, initialY, initialZ );
			glutSolidSphere( 5, 32, 32 );
		glPopMatrix();
		glPushMatrix();
			glTranslatef( finalX, finalY, finalZ );
			glutSolidSphere( 5, 32, 32 );
		glPopMatrix();

//		std::cout << "distance=" << Utils::distance( initialX, initialY, initialZ, finalX, finalY, finalZ ) << std::endl;
	}
}

