/*
 * HelloWorld.cpp
 *
 *  Created on: 9 дек. 2017 г.
 *      Author: vadim
 */

#include "LegsMgr.h"
#include "HelloWorld.h"
#include "core/Utils.h"
#include "core/ManipulatorUniConverter.h"
#include "core/InterpolatedMove.h"
#include "core/InterpolatedMove2.h"

#include <iostream>
#include <sigc++/functors/ptr_fun.h>
#include <sigc++/functors/mem_fun.h>

void onOptimize( HelloWorld * lpHelloWorld )
{
//	std::cout << "Optimize by: x=" << lpHelloWorld->m_XYoZArea.getX() << ", y=" << lpHelloWorld->m_XYoZArea.getY() << std::endl;
	double epsilonChangeError = 0.1;
//	std::cout << "before solve" << std::endl;
//	LegsMgr::get().print();

	lpHelloWorld->m_solver.solveFromCurrent( lpHelloWorld->m_desirablePoint.getX(), lpHelloWorld->m_desirablePoint.getY(), lpHelloWorld->m_desirablePoint.getZ(), epsilonChangeError, 1000,
			[&lpHelloWorld]( const std::vector<double> & error )
			{
				lpHelloWorld->redraw();
			}
	);

//	std::cout << "after solve" << std::endl;
//	LegsMgr::get().print();
	TypePrecision finalX, finalY, finalZ;
	lpHelloWorld->m_solver.getCurrentManipulator()->getLastLeg()->getCalulatedFinalPosition( finalX, finalY, finalZ );
	double distance = lpHelloWorld->m_solver.getErrorFunctionValue( lpHelloWorld->m_desirablePoint.getX(), lpHelloWorld->m_desirablePoint.getY(), lpHelloWorld->m_desirablePoint.getZ() );
//	Utils::distance( finalX, finalY, finalZ, lpHelloWorld->m_XYoZArea.getX(), lpHelloWorld->m_desirablePoint.getY(), lpHelloWorld->m_desirablePoint.getZ() );
//	std::cout << "Distance=" << distance << ", error=" << lpHelloWorld->m_solver.getErrorFunctionValue() << std::endl;
	lpHelloWorld->m_solver.getCurrentManipulator()->print();
	if( distance > 1.0 )
	{
		std::cout << "Distance=" << distance << std::endl;

		std::cout << "From: ";
		lpHelloWorld->m_prevDesirablePoint.print();
		std::cout << "To: ";
		lpHelloWorld->m_desirablePoint.print();
	}
	lpHelloWorld->m_prevDesirablePoint = lpHelloWorld->m_desirablePoint;
}

void onPerpendicularSolve( HelloWorld * lpHelloWorld )
{
	double epsilonChangeError = 0.0001;
//	std::cout << "before solve" << std::endl;
//	LegsMgr::get().print();
//	double flippedY = lpHelloWorld->m_XYoZArea.getY();//Utils::flipY( lpHelloWorld->m_XYoZArea.getY(), lpHelloWorld->m_XYoZArea.get_allocated_height() );
//	lpHelloWorld->m_solver.solvePerpendicular( lpHelloWorld->m_XYoZArea.getX(), flippedY, lpHelloWorld->m_XYoZArea.getAngle(), epsilonChangeError, 1000,
//			[&lpHelloWorld]( std::vector<double> error )
//			{
//				lpHelloWorld->redraw();
//			}
//	);
	lpHelloWorld->m_solver.solvePerpendicular( lpHelloWorld->m_desirablePoint.getX(), lpHelloWorld->m_desirablePoint.getY(), lpHelloWorld->m_desirablePoint.getZ(), lpHelloWorld->m_XYoZArea.getAngle(), epsilonChangeError, 1000,
			[&lpHelloWorld]( const std::vector<double> & error )
			{
				lpHelloWorld->redraw();
			}
	);
//	std::cout << "after solve" << std::endl;
//	LegsMgr::get().print();
//	TypePrecision finalX, finalY, finalZ;
//	LegsMgr::get().getLastLeg()->getCalulatedFinalPosition( finalX, finalY, finalZ );
//	double distance = Utils::distance( finalX, finalY, lpHelloWorld->m_desirablePoint.getX(), lpHelloWorld->m_desirablePoint.getY() );
//	std::cout << "Distance=" << distance << std::endl;
}

void onOneStep( HelloWorld * lpHelloWorld )
{
	double epsilonChangeError = 0.001;
	std::cout << "before solve" << std::endl;
	static bool temp = false;
	if( false == temp )
	{
		lpHelloWorld->m_solver.solvePerpendicular( lpHelloWorld->m_desirablePoint.getX(), lpHelloWorld->m_desirablePoint.getY(), lpHelloWorld->m_desirablePoint.getZ(), lpHelloWorld->m_XYoZArea.getAngle(), epsilonChangeError, 1,
				[&lpHelloWorld]( const std::vector<double> & error )
				{

				}
		);
		temp = true;
	}
	else
	{
		lpHelloWorld->m_solver.oneStepV2( lpHelloWorld->m_desirablePoint.getX(), lpHelloWorld->m_desirablePoint.getY(), lpHelloWorld->m_desirablePoint.getZ() );
	}
	lpHelloWorld->redraw();
	std::cout << "after solve" << std::endl;
//	LegsMgr::get().print();
//	TypePrecision finalX, finalY, finalZ;
//	LegsMgr::get().getLastLeg()->getCalulatedFinalPosition( finalX, finalY, finalZ );
//	double flippedFinalY = finalY;
//	double distance = Utils::distance( finalX, flippedFinalY, lpHelloWorld->m_XYoZArea.getX(), lpHelloWorld->m_XYoZArea.getY() );
//	std::cout << "Distance=" << distance << std::endl;
}

bool onAngleChangeValue( Gtk::ScrollType type, double value, HelloWorld * lpHelloWorld )
{
  lpHelloWorld->m_XYoZArea.setAngle( value );
//  onOptimize( lpHelloWorld );
  onPerpendicularSolve( lpHelloWorld );
  return true;
}

void onShuffledSolve( HelloWorld * lpHelloWorld)
{
//	LegsMgr::get().print();
	double epsilonChangeError = 0.0001;
	std::cout << "before solve" << std::endl;
//	LegsMgr::get().print();
	lpHelloWorld->m_solver.solveContiniouslyShuffling( lpHelloWorld->m_desirablePoint.getX(), lpHelloWorld->m_desirablePoint.getY(), lpHelloWorld->m_desirablePoint.getZ(), epsilonChangeError, 1000, 10,
			[&lpHelloWorld]( const std::vector<double> & error )
			{
				lpHelloWorld->redraw();
			}
	);
	std::cout << "after solve" << std::endl;
//	LegsMgr::get().print();
//	double flippedY = lpHelloWorld->m_XYoZArea.getY();
//	TypePrecision finalX, finalY, finalZ;
//	LegsMgr::get().getLastLeg()->getCalulatedFinalPosition( finalX, finalY, finalZ );
//	double flippedFinalY = finalY;
//	double distance = Utils::distance( finalX, flippedFinalY, lpHelloWorld->m_XYoZArea.getX(), flippedY );
	std::cout << "error=" << lpHelloWorld->m_solver.getErrorFunctionValue( lpHelloWorld->m_desirablePoint.getX(), lpHelloWorld->m_desirablePoint.getY(), lpHelloWorld->m_desirablePoint.getZ() ) << std::endl;
}

ShLegManipulator global_clonedLegs;
ShLegManipulator global_originalLegs;
void onOptimizeClone( HelloWorld * lpHelloWorld )
{
	global_originalLegs = LegsMgr::get().getManipulator()->clone();
	global_clonedLegs = LegsMgr::get().getManipulator()->clone();
	Solver solver( global_clonedLegs );
	double epsilonChangeError = 0.1;
	solver.solveFromCurrent( lpHelloWorld->m_desirablePoint.getX(), lpHelloWorld->m_desirablePoint.getY(), lpHelloWorld->m_desirablePoint.getZ(), epsilonChangeError, 1000,
			[&lpHelloWorld]( const std::vector<double> & error )
			{
				lpHelloWorld->redraw();
			}
	);

//	std::cout << "after solve" << std::endl;
//	LegsMgr::get().print();
}

void onShuffledLessErrorSolve( HelloWorld * lpHelloWorld)
{
//	LegsMgr::get().print();
	double epsilonChangeError = 0.0001;
	std::cout << "before solve" << std::endl;
//	LegsMgr::get().print();
	lpHelloWorld->m_solver.solveContiniouslyShufflingLessError( lpHelloWorld->m_desirablePoint.getX(), lpHelloWorld->m_desirablePoint.getY(), lpHelloWorld->m_desirablePoint.getZ(), epsilonChangeError, 1000, 10,
			[&lpHelloWorld]( const std::vector<double> & error )
			{
				lpHelloWorld->redraw();
			}
	);
	std::cout << "after solve" << std::endl;
	std::cout << "error=" << lpHelloWorld->m_solver.getErrorFunctionValue( lpHelloWorld->m_desirablePoint.getX(), lpHelloWorld->m_desirablePoint.getY(), lpHelloWorld->m_desirablePoint.getZ() ) << std::endl;
}

void onShuffledLessAngleSolve( HelloWorld * lpHelloWorld)
{
//	LegsMgr::get().print();
	double epsilonChangeError = 0.0001;
	std::cout << "before solve" << std::endl;
//	LegsMgr::get().print();
	lpHelloWorld->m_solver.solveContiniouslyShufflingLessAngle( lpHelloWorld->m_desirablePoint.getX(), lpHelloWorld->m_desirablePoint.getY(), lpHelloWorld->m_desirablePoint.getZ(), epsilonChangeError, 1000, 5,
			[&lpHelloWorld]( const std::vector<double> & error )
			{
				lpHelloWorld->redraw();
			}
	);
	std::cout << "after solve" << std::endl;
	std::cout << "error=" << lpHelloWorld->m_solver.getErrorFunctionValue( lpHelloWorld->m_desirablePoint.getX(), lpHelloWorld->m_desirablePoint.getY(), lpHelloWorld->m_desirablePoint.getZ() ) << std::endl;
}

void onContIterShuffledLessAngleSolve( HelloWorld * lpHelloWorld)
{
//	LegsMgr::get().print();
	double epsilonChangeError = 0.0001;
	std::cout << "before solve" << std::endl;
//	LegsMgr::get().print();
	lpHelloWorld->m_solver.solveContIterShufLessAngle( lpHelloWorld->m_desirablePoint.getX(), lpHelloWorld->m_desirablePoint.getY(), lpHelloWorld->m_desirablePoint.getZ(), epsilonChangeError, 1000,
			[&lpHelloWorld]( const std::vector<double> & error )
			{
				lpHelloWorld->redraw();
			}
	);
	std::cout << "after solve" << std::endl;
	std::cout << "error=" << lpHelloWorld->m_solver.getErrorFunctionValue( lpHelloWorld->m_desirablePoint.getX(), lpHelloWorld->m_desirablePoint.getY(), lpHelloWorld->m_desirablePoint.getZ() ) << std::endl;
}

void onContIterShuffledSolve( HelloWorld * lpHelloWorld)
{
//	LegsMgr::get().print();
	double epsilonChangeError = 0.0001;
	std::cout << "before solve" << std::endl;
//	LegsMgr::get().print();
	lpHelloWorld->m_solver.solveContIterShuf( lpHelloWorld->m_desirablePoint.getX(), lpHelloWorld->m_desirablePoint.getY(), lpHelloWorld->m_desirablePoint.getZ(), epsilonChangeError, 1000,
			[&lpHelloWorld]( const std::vector<double> & error )
			{
				lpHelloWorld->redraw();
			}
	);
	std::cout << "after solve" << std::endl;
	std::cout << "error=" << lpHelloWorld->m_solver.getErrorFunctionValue( lpHelloWorld->m_desirablePoint.getX(), lpHelloWorld->m_desirablePoint.getY(), lpHelloWorld->m_desirablePoint.getZ() ) << std::endl;
}


bool startInterpolate = false;
std::chrono::time_point<std::chrono::system_clock> interpolationStartTime;
void onInterpolateExp5( HelloWorld * lpHelloWorld)
{
	interpolationStartTime = std::chrono::system_clock::now();
	startInterpolate = true;
}

bool onXYoZButtonPressed(GdkEventButton* event, HelloWorld * lpHelloWorld)
{
	try
	{
//		std::cout << "on_my_button_press_event" << std::endl;
//		event->x = 106;
//		event->y = 332;
		lpHelloWorld->m_XYoZArea.setX( event->x );//106, 332
		lpHelloWorld->m_XYoZArea.setY( event->y );

		lpHelloWorld->m_XZoYArea.setX( event->x );

		lpHelloWorld->m_desirablePoint.setX( event->x );
		lpHelloWorld->m_desirablePoint.setY( event->y );

		Leg3DDrawWindow::solveForX = event->x;
		Leg3DDrawWindow::solveForY = event->y;

//		ShLegManipulator initiatedManipulatorClone = lpHelloWorld->m_solver.getCurrentManipulator()->clone();
//		initiatedManipulatorClone->print();

//		{
//			std::vector<double> varAngles = ManipulatorUniConverter::getFormatedAngles( lpHelloWorld->m_solver.getCurrentManipulator() );
//			InterpolatedMove::get().setInitialVars( varAngles );
//		}
//		onOptimize( lpHelloWorld );
//		onOptimizeClone( lpHelloWorld );
//		onShuffledSolve( lpHelloWorld );
//		onShuffledLessErrorSolve( lpHelloWorld );
//		onShuffledLessAngleSolve( lpHelloWorld );
//		onContIterShuffledLessAngleSolve( lpHelloWorld );
//		onContIterShuffledSolve( lpHelloWorld );
		onPerpendicularSolve( lpHelloWorld );
		{
//			std::vector<double> varAngles = ManipulatorUniConverter::getFormatedAngles( lpHelloWorld->m_solver.getCurrentManipulator() );
//			InterpolatedMove2::get().setVars( varAngles );
		}

//		lpHelloWorld->m_solver.getCurrentManipulator()->print();
//		LegsMgr::get().getManipulator()->deepAssign( initiatedManipulatorClone );

		lpHelloWorld->redraw();
	}
	catch( std::exception & ex )
	{
		std::cout << "Exception catched" << std::endl;
		int a = 0;
		a++;
	}

	return true;
}

bool onXYoZButtonMove(GdkEventMotion* event, HelloWorld * lpHelloWorld)
{
	try
	{
//		event->x = 106;
//		event->y = 332;
//		std::cout << "on_my_button_press_event" << std::endl;
		lpHelloWorld->m_XYoZArea.setX( event->x );
		lpHelloWorld->m_XYoZArea.setY( event->y );

		lpHelloWorld->m_XZoYArea.setX( event->x );

		lpHelloWorld->m_desirablePoint.setX( event->x );
		lpHelloWorld->m_desirablePoint.setY( event->y );

		Leg3DDrawWindow::solveForX = event->x;
		Leg3DDrawWindow::solveForY = event->y;

//		onOptimize( lpHelloWorld );
//		onOptimizeClone( lpHelloWorld );
//		onShuffledSolve( lpHelloWorld );
//		onShuffledLessErrorSolve( lpHelloWorld );
//		onShuffledLessAngleSolve( lpHelloWorld );
//		onPerpendicularSolve( lpHelloWorld );
//		onContIterShuffledLessAngleSolve( lpHelloWorld );
		lpHelloWorld->redraw();
	}
	catch( std::exception & ex )
	{
		std::cout << "Exception catched" << std::endl;
		int a = 0;
		a++;
	}

	return true;
}

bool onXZoYButtonPressed(GdkEventButton* event, HelloWorld * lpHelloWorld)
{
//	std::cout << "on_my_button_press_event" << std::endl;
	lpHelloWorld->m_XZoYArea.setX( event->x );
	lpHelloWorld->m_XZoYArea.setZ( event->y );

	lpHelloWorld->m_XYoZArea.setX( event->x );

	lpHelloWorld->m_desirablePoint.setX( event->x );
	lpHelloWorld->m_desirablePoint.setZ( event->y );

	Leg3DDrawWindow::solveForX = event->x;
	Leg3DDrawWindow::solveForZ = event->y;

//	onOptimize( lpHelloWorld );
//	onOptimizeClone( lpHelloWorld );
//	onShuffledSolve( lpHelloWorld );
//	onShuffledLessErrorSolve( lpHelloWorld );
//	onShuffledLessAngleSolve( lpHelloWorld );
//	onContIterShuffledLessAngleSolve( lpHelloWorld );
	onContIterShuffledSolve( lpHelloWorld );
//	onPerpendicularSolve( lpHelloWorld );

	std::vector<double>varAngles = ManipulatorUniConverter::getFormatedAngles( lpHelloWorld->m_solver.getCurrentManipulator() );
	InterpolatedMove2::get().setVars( varAngles );

	lpHelloWorld->redraw();

	return true;
}

bool onXZoYButtonMove(GdkEventMotion* event, HelloWorld * lpHelloWorld)
{
//	std::cout << "on_my_button_motion_event" << std::endl;
	lpHelloWorld->m_XZoYArea.setX( event->x );
	lpHelloWorld->m_XZoYArea.setZ( event->y );

	lpHelloWorld->m_XYoZArea.setX( event->x );

	lpHelloWorld->m_desirablePoint.setX( event->x );
	lpHelloWorld->m_desirablePoint.setZ( event->y );

	Leg3DDrawWindow::solveForX = event->x;
	Leg3DDrawWindow::solveForZ = event->y;

	onOptimize( lpHelloWorld );
//	onOptimizeClone( lpHelloWorld );
//	onShuffledSolve( lpHelloWorld );
//	onShuffledLessErrorSolve( lpHelloWorld );
//	onShuffledLessAngleSolve( lpHelloWorld );
//	onPerpendicularSolve( lpHelloWorld );

	lpHelloWorld->redraw();

	return true;
}

HelloWorld::HelloWorld()
: m_solver( LegsMgr::get().getManipulator() ),
  m_HBox(Gtk::ORIENTATION_HORIZONTAL, 6),
  m_VBox(Gtk::ORIENTATION_VERTICAL, 6),
  m_VBoxButtons(Gtk::ORIENTATION_VERTICAL, 6),
  m_AngleScale( Gtk::Orientation::ORIENTATION_VERTICAL)
{
	m_XYoZArea.updateDrawLegs( *LegsMgr::get().getManipulator() );
	m_XZoYArea.updateDrawLegs( *LegsMgr::get().getManipulator() );
	m_gl3DLegsDrawWindow.updateDrawLegs( *LegsMgr::get().getManipulator() );

	std::vector<double> varAngles = ManipulatorUniConverter::getFormatedAngles( m_solver.getCurrentManipulator() );
	InterpolatedMove2::get().setVars( varAngles );

  // Sets the margin around the button.
//  m_button.set_margin(10);
//	m_button.set_margin_bottom( 10 );
//	m_button.set_margin_left( 10 );
//	m_button.set_margin_right( 10 );
//	m_button.set_margin_top( 10 );
  // When the button receives the "clicked" signal, it will call the
  // on_button_clicked() method defined below.
//  m_button.signal_clicked().connect(sigc::mem_fun(*this,
//              &HelloWorld::on_button_clicked));
//  m_button.show();
  // This packs the button into the Window (a container).
//  add(m_button);
  m_XYoZArea.add_events( Gdk::BUTTON_PRESS_MASK );
  m_XYoZArea.add_events( Gdk::BUTTON_MOTION_MASK );
  m_XYoZArea.show();
  m_XYoZArea.queue_draw();

  m_XZoYArea.add_events( Gdk::BUTTON_PRESS_MASK );
  m_XZoYArea.add_events( Gdk::BUTTON_MOTION_MASK );
  m_XZoYArea.show();
  m_XZoYArea.queue_draw();

  m_AngleScale.set_digits( 0 );
  m_AngleScale.set_draw_value( true );
  m_AngleScale.Range::set_range( -135, 135 );
  m_AngleScale.show();
  m_AngleScale.signal_change_value().connect( sigc::bind<HelloWorld*>( sigc::ptr_fun( &onAngleChangeValue ), this ) );

  m_VBox.show();
  m_HBox.show();
  m_scrolledXYoZArea.show();
  m_scrolledXZoYArea.show();
  m_solveButton.show();
  m_solveShuffledButton.show();
  m_buttonOneStep.show();
  m_solvePerpButton.show();
  m_interpolateButton.show();
  m_optimizeCloneButton.show();
  m_VBoxButtons.show();
//  add(m_XYoZArea);

//  m_widgetBox.pack_start(m_XYoZArea, true, true);
  add(m_VBox);
//  add( m_ScrolledWindowCanvas );
//  add( m_ScrolledWindowCanvasAnglePoint );


  m_buttonOneStep.set_label( "OneStep" );
  m_buttonOneStep.signal_clicked().connect( sigc::bind<HelloWorld*>( sigc::ptr_fun( &onOneStep ), this ) );

  m_solveButton.set_label( "Current Solve" );
  m_solveButton.signal_clicked().connect( sigc::bind<HelloWorld*>( sigc::ptr_fun( &onOptimize ), this ) );

  m_solvePerpButton.set_label( "Perpendicular Solve" );
  m_solvePerpButton.signal_clicked().connect( sigc::bind<HelloWorld*>( sigc::ptr_fun( &onPerpendicularSolve ), this ) );

  m_solveShuffledButton.set_label( "Shuffled Solve" );
  m_solveShuffledButton.signal_clicked().connect( sigc::bind<HelloWorld*>( sigc::ptr_fun( &onShuffledSolve ), this ) );

  m_optimizeCloneButton.set_label( "Optimize Clone" );
  m_optimizeCloneButton.signal_clicked().connect( sigc::bind<HelloWorld*>( sigc::ptr_fun( &onOptimizeClone ), this ) );

  m_interpolateButton.set_label( "Interpolate Exp5" );
  m_interpolateButton.signal_clicked().connect( sigc::bind<HelloWorld*>( sigc::ptr_fun( &onInterpolateExp5 ), this ) );

  m_XYoZArea.signal_button_press_event().connect( sigc::bind<HelloWorld*>( sigc::ptr_fun( &onXYoZButtonPressed ), this ) );
//  m_XYoZArea.signal_motion_notify_event().connect( sigc::bind<HelloWorld*>( sigc::ptr_fun( &onXYoZButtonMove ), this ) );

  m_XZoYArea.signal_button_press_event().connect( sigc::bind<HelloWorld*>( sigc::ptr_fun( &onXZoYButtonPressed ), this ) );
  m_XZoYArea.signal_motion_notify_event().connect( sigc::bind<HelloWorld*>( sigc::ptr_fun( &onXZoYButtonMove ), this ) );


  this->set_size_request( 1000, 600 );


  m_scrolledXYoZArea.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_ALWAYS);
  m_scrolledXYoZArea.set_border_width(6);
  m_scrolledXYoZArea.add( m_XYoZArea );
  m_scrolledXYoZArea.set_size_request(400, -1);

  m_scrolledXZoYArea.set_policy(Gtk::POLICY_AUTOMATIC, Gtk::POLICY_ALWAYS);
  m_scrolledXZoYArea.set_border_width(6);
  m_scrolledXZoYArea.add( m_XZoYArea );
  m_scrolledXZoYArea.set_size_request(400, -1);


  m_HBox.pack_start( m_scrolledXYoZArea );
  m_HBox.pack_start( m_scrolledXZoYArea );
  m_HBox.pack_start(m_AngleScale);
  m_VBox.pack_start(m_HBox, Gtk::PACK_EXPAND_WIDGET);
  m_VBoxButtons.pack_start( m_solveButton, Gtk::PACK_SHRINK );
  m_VBoxButtons.pack_start( m_solveShuffledButton, Gtk::PACK_SHRINK );
  m_VBoxButtons.pack_start( m_buttonOneStep, Gtk::PACK_SHRINK );
  m_VBoxButtons.pack_start( m_solvePerpButton, Gtk::PACK_SHRINK );
  m_VBoxButtons.pack_start( m_interpolateButton, Gtk::PACK_SHRINK );
  m_VBoxButtons.pack_start( m_optimizeCloneButton, Gtk::PACK_SHRINK );
  m_HBox.pack_start( m_VBoxButtons, Gtk::PACK_SHRINK );
}

HelloWorld::~HelloWorld()
{
}

void HelloWorld::redraw()
{
	m_XYoZArea.queue_draw();
}

void HelloWorld::on_button_clicked( Glib::ustring& s)
{
  std::cout << "Hello World" << std::endl;
}



