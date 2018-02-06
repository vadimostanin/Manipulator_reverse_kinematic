/*
 * MyArea.cpp
 *
 *  Created on: 9 дек. 2017 г.
 *      Author: vadim
 */

#include "XYoZArea.h"

#include "LegsMgr.h"
#include "core/Utils.h"

#include <iostream>
#include <cairomm/context.h>

#include "core/InterpolationExp5.h"
#include "core/InterpolationFade.h"
#include "core/InterpolationPow2.h"
#include "core/InterpolationLinear.h"

#include "core/InterpolatedMove.h"
#include "core/InterpolatedMove2.h"
#include "core/ManipulatorUniConverter.h"

#include <chrono>

XYoZArea::XYoZArea() : m_X( 0 ), m_Y( 0 ), m_angle( 0 )
{
	cairo_matrix_init( &m_flipYMatrix, 1, 0, 0, -1, 0, 0 );

	m_font = Cairo::ToyFontFace::create("Bitstream Charter",
								   Cairo::FONT_SLANT_ITALIC,
								   Cairo::FONT_WEIGHT_BOLD);

}

XYoZArea::~XYoZArea()
{

}
const float interploationSecondsMax = 5.0;

extern bool startInterpolate;
extern Legs global_clonedLegs;
extern Legs global_originalLegs;
extern std::chrono::time_point<std::chrono::system_clock> interpolationStartTime;

bool XYoZArea::on_draw(const Cairo::RefPtr<Cairo::Context>& cr)
{
  Gtk::Allocation allocation = get_allocation();
  const int width = allocation.get_width();
//  const int height = allocation.get_height();

  cr->save();
//  cr->restore();
//  cr->set_matrix( m_flipYMatrix );

//	cr->scale( 1, -1 );
//	cairo_matrix_t matrix;
//  cr->get_matrix( matrix );
//  ::cairo_matrix_scale( &matrix, 1, 0.5 );
//  if( 0 == memcmp( &m_flipYMatrix, &matrix, sizeof( matrix ) ) )
//  {
//	  int a = 0;
//	  a++;
//  }
//
//  cr->set_matrix( matrix );

//	cairo_matrix_t x_reflection_matrix;
//	cairo_matrix_init_identity( &x_reflection_matrix ); // could not find a oneliner
//	/* reflection through the x axis equals the identity matrix with the bottom
//	left value negated  */
//	x_reflection_matrix.yy = -1.0;
//	cr->set_matrix( x_reflection_matrix );
//	// This would result in your drawing being done on top of the destination
//	// surface, so we translate the surface down the full height
//	cr->translate( 0, 600 ); // replace SURFACE_HEIGHT

  if( true == InterpolatedMove2::get().update( std::chrono::milliseconds( 50 ) ) )
  {
    std::vector<double> newAngles;
    InterpolatedMove2::get().getVars( newAngles );
//  LegsMgr::get().getManipulator()->print();
    ManipulatorUniConverter::setAnglesToManipualtor( LegsMgr::get().getManipulator(), newAngles );
//  LegsMgr::get().getManipulator()->print();
  }

  if( true == startInterpolate )
  {
	  auto now = std::chrono::system_clock::now();
	  std::chrono::duration<double> diff = now - interpolationStartTime;
	  double percentage = diff.count() / interploationSecondsMax;
	  if( 1.0 <= percentage )
	  {
		  startInterpolate = false;
	  }

	  for( const auto & originLeg : global_originalLegs )
	  {
		  const auto & clonedLeg = global_clonedLegs[ originLeg->getLevel() ];

		  InterpolationLinear interpolation;
		  const double interpolatedAngleXY = interpolation.apply3( originLeg->getAngleXY(), clonedLeg->getAngleXY(), percentage );

		  LegsMgr::get().getManipulator()->getLeg( originLeg->getLevel() )->setAngleXY( interpolatedAngleXY );
	  }

	  cr->set_source_rgb(0.8, 0.2, 0.2);
	  cr->set_font_face( m_font );
	  cr->set_font_size( 14 );
	  cr->move_to( width - 150, 30 );
	  cr->show_text( std::string( "Interpolating: " ) + std::to_string( percentage ) );
  }

  for( const auto & drawLeg : m_drawLegs )
  {
	  drawLeg->render( cr );
//	  drawLeg->getLeg()->print();
  }

	int vectorX = getX() + 50 * std::cos( Utils::deg2Rad( m_angle ) );
	int vectorY = getY() + 50 * std::sin( Utils::deg2Rad( m_angle ) );

	const auto & lastLeg = LegsMgr::get().getManipulator()->getLastLeg();
	int lastLegLength = lastLeg->getLength();
	int perpendilularLastLegInitialExpectedX = getX() + lastLegLength * std::cos( Utils::deg2Rad( m_angle - 90 ) );
//	int perpendicularLastLegInitialExpectedY = Utils::flipY( getY(), height ) + lastLegLength * std::sin( Utils::deg2Rad( m_angle - 90 ) );
	int perpendicularLastLegInitialExpectedY = getY() + lastLegLength * std::sin( Utils::deg2Rad( m_angle - 90 ) );

//	int flippedPerpLastLegInitialExpectedY = Utils::flipY( perpendicularLastLegInitialExpectedY, height );

//    const int lesser = MIN(width, height);

  // first draw a simple unclosed arc
//    cr->save();
    cr->arc( m_X, m_Y, 2, 0, 2 * M_PI);//-MPI, M_PI
//    cr->close_path();   // line back to start point
    cr->set_source_rgb(0.0, 0.8, 0.0);
    cr->fill_preserve();
//    cr->restore();  // back to opaque black
    cr->stroke();   // outline it

    cr->set_line_width(1.0);
    cr->set_source_rgb(0.0, 0.0, 0.5);
    cr->move_to( m_X, m_Y );
    cr->line_to( vectorX, vectorY );
    cr->stroke();

    cr->set_line_width(10.0);
    cr->arc( perpendilularLastLegInitialExpectedX, perpendicularLastLegInitialExpectedY, 2, 0, 2 * M_PI);//-MPI, M_PI
//    cr->close_path();   // line back to start point
	cr->set_source_rgb(0.5, 0.0, 0.0);
	cr->fill_preserve();
	cr->stroke();   // outline it

	cr->restore();

	cr->set_source_rgb(0.8, 0.2, 0.2);
	cr->set_font_face( m_font );
	cr->set_font_size( 14 );
	cr->move_to( width - 100, 10 );
	cr->show_text( "XYoZ axis" );

	this->queue_draw();

  return true;
}

void XYoZArea::updateDrawLegs( Legs legs )
{
	m_drawLegs.clear();
	for( const auto & leg : legs )
	{
		m_drawLegs.emplace_back( std::make_shared<DrawLegXYoZ>( leg ) );
	}
}
