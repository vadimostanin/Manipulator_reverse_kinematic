//============================================================================
// Name        : GtkMM_Test.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "HelloWorld.h"
#include <gtkmm/application.h>

using namespace std;

#include "LegsMgr.h"
#include "core/Utils.h"
#include <cmath>

#include <ginac.h>
#include <symbol.h>

#include "core/InterpolatedMove.h"
#include "core/InterpolatedMove2.h"
#include "core/ManipulatorUniConverter.h"

#include "FailedBehaviours.h"
#include "tests/Tests.h"

void onGenerate( HelloWorld * lpHelloWorld )
{
	std::string sFunction = lpHelloWorld->m_solver.generateErroFunctionDerivatives();
	std::cout << "sFunction" << sFunction << std::endl;
	abort();
}

int main( int argc, char ** argv)
{

//	return 0;
	std::srand( time( nullptr ) );
//	{
//	    FailedBehaviours failedBehaviours;
//	    failedBehaviours.runBehaviours();
//
//	    return 0;
//	}

//	{
//	    Tests tests;
////	    tests.run1();
//	    tests.run2();
//
//	    return 0;
//  }

	auto app = Gtk::Application::create("org.gtkmm.example");

//	{
//		LegsMgr::get().getManipulator()->add( 100 );
//		LegsMgr::get().getManipulator()->add( 80 );
//		LegsMgr::get().getManipulator()->add( 75 );
//		LegsMgr::get().getManipulator()->add( 70 );
//		LegsMgr::get().getManipulator()->add( 65 );
//		LegsMgr::get().getManipulator()->add( 60 );
//		LegsMgr::get().getManipulator()->add( 55 );
//		LegsMgr::get().getManipulator()->add( 40 );
//		LegsMgr::get().getManipulator()->add( 35 );
//		LegsMgr::get().getManipulator()->add( 30 );
//	}
	{
		LegsMgr::get().getManipulator()->add( 100 );
		LegsMgr::get().getManipulator()->add( 80 );
		LegsMgr::get().getManipulator()->add( 60 );
		LegsMgr::get().getManipulator()->add( 40 );
//		LegsMgr::get().getManipulator()->add( 20 );
	}
//	LegsMgr::get().add( 100 );
//	LegsMgr::get().add( 100 );
//	LegsMgr::get().add( 100 );
//	LegsMgr::get().add( 100 );
//	LegsMgr::get().add( 100 );
//	LegsMgr::get().add( 100 );
	LegsMgr::get().getManipulator()->pair();

	LegsMgr::get().getManipulator()->getLeg( 0 )->setAngleXYLimits( -18000, 18000 ).setAngleXZLimits( -180, 180 )
			                  .setAngleXZEnable( true ).setInitialPosition( 100, 100, 100 );
	LegsMgr::get().getManipulator()->getLeg( 1 )->setAngleXYLimits( -18000, 18000 ).setAngleXZLimits( -180, 180 )
				                  .setAngleXZEnable( true ).setAngleXZ( 1 );
	LegsMgr::get().getManipulator()->getLeg( 2 )->setAngleXYLimits( -18000, 18000 ).setAngleXZLimits( -180, 180 )
				                  .setAngleXZEnable( true ).setAngleXZ( 1 );
	LegsMgr::get().getManipulator()->getLeg( 3 )->setAngleXYLimits( -18000, 18000 ).setAngleXZLimits( -180, 180 )
				                  .setAngleXZEnable( true ).setAngleXZ( 1 );
//	LegsMgr::get().getManipulator()->getLeg( 1 )->setAngleXYLimits( - 180 + 30, 180 - 30 ).setAngleXZLimits( 0, 0 );
//	LegsMgr::get().getManipulator()->getLeg( 2 )->setAngleXYLimits( - 180 + 30, 180 - 30 ).setAngleXZLimits( 0, 0 );
//	LegsMgr::get().getManipulator()->getLeg( 3 )->setAngleXYLimits( - 180 + 60, 180 - 60 ).setAngleXZLimits( 0, 0 );
//	LegsMgr::get().getManipulator()->getLeg( 4 )->setAngleXYLimits( - 180 + 30, 180 - 30 ).setAngleXZLimits( 0, 0 );

//	LegsMgr::get().getManipulator()->getLeg( 1 )->setInitialOffsets( 0.0, 0.0, 20.0 );

	std::vector<double> varAngles = ManipulatorUniConverter::getFormatedAngles( LegsMgr::get().getManipulator() );
	InterpolatedMove2::init( varAngles.size() );
	InterpolatedMove::init( varAngles.size() );

	HelloWorld helloworld;
//	onGenerate( &helloworld );// call it to fill the generate error and derivative function at DerivativeFunctions and ErrorFunctions
	try
	{
	  //Shows the window and returns when it is closed.
		return app->run(helloworld, argc, argv);
	}
	catch( ... )
	{
		int a = 0;
		a++;
	}
	return 0;
}
