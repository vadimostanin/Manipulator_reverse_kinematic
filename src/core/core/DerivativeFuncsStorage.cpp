/*
 * DerivativeFuncsStorage.cpp
 *
 *  Created on: Dec 15, 2017
 *      Author: user
 */

#include "DerivativeFuncsStorage.h"
#include "DerivativeFunctions.h"
#include <cassert>

DerivativeFuncsStorage::DerivativeFuncsStorage()
{
}

DerivativeFuncsStorage::~DerivativeFuncsStorage()
{
}

void DerivativeFuncsStorage::getFunc( int legsCount, std::vector<DerivFuncType> & funcs )
{
	funcs.clear();
	switch( legsCount )
	{
		case 1:
			funcs.push_back( DerivativeFunctions::derivative_XY_1_Legs_0 );
			funcs.push_back( DerivativeFunctions::derivative_XZ_1_Legs_0 );
			break;
		case 2:
			funcs.push_back( DerivativeFunctions::derivative_XY_2_Legs_0 );
			funcs.push_back( DerivativeFunctions::derivative_XZ_2_Legs_0 );
			funcs.push_back( DerivativeFunctions::derivative_XY_2_Legs_1 );
			funcs.push_back( DerivativeFunctions::derivative_XZ_2_Legs_1 );
			break;
		case 3:
			funcs.push_back( DerivativeFunctions::derivative_XY_3_Legs_0 );
			funcs.push_back( DerivativeFunctions::derivative_XZ_3_Legs_0 );
			funcs.push_back( DerivativeFunctions::derivative_XY_3_Legs_1 );
			funcs.push_back( DerivativeFunctions::derivative_XZ_3_Legs_1 );
			funcs.push_back( DerivativeFunctions::derivative_XY_3_Legs_2 );
			funcs.push_back( DerivativeFunctions::derivative_XZ_3_Legs_2 );
			break;
		case 4:
			funcs.push_back( DerivativeFunctions::derivative_XY_4_Legs_0 );
			funcs.push_back( DerivativeFunctions::derivative_XZ_4_Legs_0 );
			funcs.push_back( DerivativeFunctions::derivative_XY_4_Legs_1 );
			funcs.push_back( DerivativeFunctions::derivative_XZ_4_Legs_1 );
			funcs.push_back( DerivativeFunctions::derivative_XY_4_Legs_2 );
			funcs.push_back( DerivativeFunctions::derivative_XZ_4_Legs_2 );
			funcs.push_back( DerivativeFunctions::derivative_XY_4_Legs_3 );
			funcs.push_back( DerivativeFunctions::derivative_XZ_4_Legs_3 );
			break;
		case 5:
			funcs.push_back( DerivativeFunctions::derivative_XY_5_Legs_0 );
			funcs.push_back( DerivativeFunctions::derivative_XZ_5_Legs_0 );
			funcs.push_back( DerivativeFunctions::derivative_XY_5_Legs_1 );
			funcs.push_back( DerivativeFunctions::derivative_XZ_5_Legs_1 );
			funcs.push_back( DerivativeFunctions::derivative_XY_5_Legs_2 );
			funcs.push_back( DerivativeFunctions::derivative_XZ_5_Legs_2 );
			funcs.push_back( DerivativeFunctions::derivative_XY_5_Legs_3 );
			funcs.push_back( DerivativeFunctions::derivative_XZ_5_Legs_3 );
			funcs.push_back( DerivativeFunctions::derivative_XY_5_Legs_4 );
			funcs.push_back( DerivativeFunctions::derivative_XZ_5_Legs_4 );
			break;
		case 6:
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			funcs.push_back( DerivativeFunctions::derivative_XY_10_Legs_0 );
			funcs.push_back( DerivativeFunctions::derivative_XZ_10_Legs_0 );
			funcs.push_back( DerivativeFunctions::derivative_XY_10_Legs_1 );
			funcs.push_back( DerivativeFunctions::derivative_XZ_10_Legs_1 );
			funcs.push_back( DerivativeFunctions::derivative_XY_10_Legs_2 );
			funcs.push_back( DerivativeFunctions::derivative_XZ_10_Legs_2 );
			funcs.push_back( DerivativeFunctions::derivative_XY_10_Legs_3 );
			funcs.push_back( DerivativeFunctions::derivative_XZ_10_Legs_3 );
			funcs.push_back( DerivativeFunctions::derivative_XY_10_Legs_4 );
			funcs.push_back( DerivativeFunctions::derivative_XZ_10_Legs_4 );
			funcs.push_back( DerivativeFunctions::derivative_XY_10_Legs_5 );
			funcs.push_back( DerivativeFunctions::derivative_XZ_10_Legs_5 );
			funcs.push_back( DerivativeFunctions::derivative_XY_10_Legs_6 );
			funcs.push_back( DerivativeFunctions::derivative_XZ_10_Legs_6 );
			funcs.push_back( DerivativeFunctions::derivative_XY_10_Legs_7 );
			funcs.push_back( DerivativeFunctions::derivative_XZ_10_Legs_7 );
			funcs.push_back( DerivativeFunctions::derivative_XY_10_Legs_8 );
			funcs.push_back( DerivativeFunctions::derivative_XZ_10_Legs_8 );
			funcs.push_back( DerivativeFunctions::derivative_XY_10_Legs_9 );
			funcs.push_back( DerivativeFunctions::derivative_XZ_10_Legs_9 );
			break;
		default:
			assert( false );
	}
}
