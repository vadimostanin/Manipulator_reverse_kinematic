/*
 * ErrorFuncStorage.cpp
 *
 *  Created on: Feb 7, 2018
 *      Author: vadym_ostanin
 */

#include "ErrorFuncStorage.h"
#include "ErrorFunctions.h"
#include <cassert>

ErrorFuncStorage::ErrorFuncStorage()
{
}

ErrorFuncStorage::~ErrorFuncStorage()
{
}

void ErrorFuncStorage::getFunc( int32_t legsCount, ErroFuncType & func )
{
	switch( legsCount )
	{
		case 1:
			func = ErrorFunctions::error_Legs_1;
			break;
		case 2:
			func = ErrorFunctions::error_Legs_2;
			break;
		case 3:
			func = ErrorFunctions::error_Legs_3;
			break;
		case 4:
			func = ErrorFunctions::error_Legs_4 ;
			break;
		case 5:
			func = ErrorFunctions::error_Legs_5 ;
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
			func = ErrorFunctions::error_Legs_10 ;
			break;
		default:
			assert( false );
	}
}

