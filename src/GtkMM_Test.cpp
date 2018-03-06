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
//	{
//		GiNaC::symbol x("x"), y("y"), z("z");
//		GiNaC::ex P = GiNaC::pow(x + y, 2) + y;
//
//		GiNaC::ex Pderivative = P.diff( x, 1 );
//
//		std::cout << "Pderivative=" << Pderivative << std::endl;
//
//		GiNaC::ex Pderivative2 = P.diff( GiNaC::symbol( "x" ), 1 );
//		std::cout << "Pderivative2=" << Pderivative2 << std::endl;
//		{
//			GiNaC::lst container;
//			container.append( GiNaC::symbol("x") == 1 ).append( y == 2 );
//			GiNaC::ex f = GiNaC::evalf( Pderivative.subs( container ) );
//
//			std::cout << "f=" << f << std::endl;
//
//			if (GiNaC::is_a<GiNaC::numeric>(f))
//			{
//				double d = GiNaC::ex_to<GiNaC::numeric>(f).to_double();
//				cout << d << endl;
//				 // -> 0.0318256
//			}
//		}
//		{
//			GiNaC::lst container;
//			container.append( x == 1 ).append( y == 2 );
//			GiNaC::ex f = GiNaC::evalf( Pderivative.subs( container ) );
//
//			std::cout << "f=" << f << std::endl;
//
//			if (GiNaC::is_a<GiNaC::numeric>(f))
//			{
//				double d = GiNaC::ex_to<GiNaC::numeric>(f).to_double();
//				cout << d << endl;
//				 // -> 0.0318256
//			}
//		}
//	}
//	return 0;
//	{
//		GiNaC::symbol angle("a");
//		int length = 100;
//		int x0 = 258;
//		int y0 = 279;
//		GiNaC::ex P = GiNaC::sqrt( GiNaC::pow( length * GiNaC::cos( angle ) + 200 - x0, 2 ) + GiNaC::pow( length * GiNaC::sin( angle ) + 200 - y0, 2 ) );
//		std::cout << P << std::endl;
//		GiNaC::ex Pderivative = P.diff( angle, 1 );
//		std::cout << Pderivative << std::endl;
//
//		GiNaC::ex f = GiNaC::evalf( Pderivative.subs( angle == Utils::deg2Rad( 10 ) ) );
//
//		if (GiNaC::is_a<GiNaC::numeric>(f))
//		{
//			double d = GiNaC::ex_to<GiNaC::numeric>(f).to_double();
//			cout << d << endl;
//			 // -> 0.0318256
//		}
//	}

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
		LegsMgr::get().getManipulator()->add( 20 );
	}
//	LegsMgr::get().add( 100 );
//	LegsMgr::get().add( 100 );
//	LegsMgr::get().add( 100 );
//	LegsMgr::get().add( 100 );
//	LegsMgr::get().add( 100 );
//	LegsMgr::get().add( 100 );
	LegsMgr::get().getManipulator()->pair();

//	LegsMgr::get().getManipulator()->getLeg( 0 )->setAngleXYLimits( - 180 + 60, 180 - 60 ).setAngleXZLimits( -360, 360 ).setAngleXZEnable( true );
	LegsMgr::get().getManipulator()->getLeg( 0 )->setAngleXYLimits( 0, 180 ).setAngleXZLimits( -360, 360 )
			                  .setAngleXZEnable( true ).setAngleXY( 0.0 ).setInitialPosition( 200, 0, 0 );
	LegsMgr::get().getManipulator()->getLeg( 1 )->setAngleXYLimits( - 180 + 30, 180 - 30 ).setAngleXZLimits( 0, 0 );
	LegsMgr::get().getManipulator()->getLeg( 2 )->setAngleXYLimits( - 180 + 60, 180 - 60 ).setAngleXZLimits( 0, 0 );
	LegsMgr::get().getManipulator()->getLeg( 3 )->setAngleXYLimits( - 180 + 60, 180 - 60 ).setAngleXZLimits( 0, 0 );
	LegsMgr::get().getManipulator()->getLeg( 4 )->setAngleXYLimits( - 180 + 60, 180 - 60 ).setAngleXZLimits( 0, 0 );

//	LegsMgr::get().getManipulator()->getLeg( 1 )->setInitialOffsets( 0.0, 0.0, 20.0 );

	std::vector<double> varAngles = ManipulatorUniConverter::getFormatedAngles( LegsMgr::get().getManipulator() );
	InterpolatedMove2::init( varAngles.size() );
	InterpolatedMove::init( varAngles.size() );

	HelloWorld helloworld;
//	onGenerate( &helloworld );// call it to fill the generate error and deraivative function at DerivativeFunctions and ErrorFunctions
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
