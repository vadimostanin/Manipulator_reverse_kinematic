/*
 * LegsMgr.cpp
 *
 *  Created on: 9 дек. 2017 г.
 *      Author: vadim
 */

#include "LegsMgr.h"
#include <algorithm>
#include <iterator>
#include <cassert>

LegsMgr & LegsMgr::get()
{
	static LegsMgr instance;
	return instance;
}

LegsMgr::LegsMgr()
{
	m_currentManipulator = std::make_shared<LegManipulator>();
}

LegsMgr::~LegsMgr()
{
}

ShLegManipulator LegsMgr::getManipulator()
{
	return m_currentManipulator;
}

//void LegsMgr::setManipulator( ShLegManipulator manipulator )
//{
//	m_currentManipulator = manipulator;
//}
