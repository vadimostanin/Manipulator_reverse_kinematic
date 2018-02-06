/*
 * DrawLegXYoZ.cpp
 *
 *  Created on: 10 дек. 2017 г.
 *      Author: vadim
 */

#include "DrawLegXYoZ.h"
#include "LegsMgr.h"

#include "core/Utils.h"

DrawLegXYoZ::DrawLegXYoZ( ShLeg leg ) : m_Leg( leg )
{
	m_colorR = ( std::rand() % 10 ) / 10.0;
	m_colorG = ( std::rand() % 10 ) / 10.0;
	m_colorB = ( std::rand() % 10 ) / 10.0;
}

DrawLegXYoZ::~DrawLegXYoZ()
{
}

void DrawLegXYoZ::render( const Cairo::RefPtr<Cairo::Context>& cr ) const
{
	double oldLineWidth = cr->get_line_width();
	cr->set_line_width( 10.0 );

	TypePrecision initialX, initialY, initialZ;
	m_Leg->getInitialPosition( initialX, initialY, initialZ );

	TypePrecision finalX, finalY, finalZ;
	m_Leg->getCalulatedFinalPosition( finalX, finalY, finalZ );


//	double x1, y1, x2, y2;
//	cr->get_clip_extents( x1, y1, x2, y2 );
//	double height = y2 - y1;


cr->save();
	cr->set_source_rgb( m_colorR, m_colorG, m_colorB );
//	cr->move_to( initialX, Utils::flipY( initialY, height ) );
//	cr->line_to( finalX, Utils::flipY( finalY, height ) );
	cr->move_to( initialX, initialY );
	cr->line_to( finalX, finalY );
	cr->stroke();

	cr->arc( initialX, initialY, 5, 0, 2 * M_PI);//-MPI, M_PI
//	cr->arc( initialX, Utils::flipY( initialY, height ), 5, 0, 2 * M_PI);//-MPI, M_PI
	cr->stroke();

	cr->set_line_width( oldLineWidth );


	cr->restore();
}

