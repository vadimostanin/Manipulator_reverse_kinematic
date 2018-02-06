/*
 * InterpolateMove.cpp
 *
 *  Created on: Jan 23, 2018
 *      Author: vadym_ostanin
 */

#include "InterpolatedMove.h"
#include "InterpolationExp5.h"
#include "InterpolationFade.h"
#include "InterpolationSine.h"
#include "InterpolatedStopStartSine.h"
#include <cassert>
#include <iostream>
#include <sstream>
#include <iterator>
#include <cmath>
#include <algorithm>

std::shared_ptr<InterpolatedMove> InterpolatedMove::m_instance;
InterpolatedMove::InterpolatedMove( uint32_t vars_count ) : m_prevVars( vars_count ), m_currentVars( vars_count )
{
	m_interpolation = std::make_shared<InterpolationSine>();
//	m_interpolation = std::make_shared<InterpolatedStopStartSine>();
}

void InterpolatedMove::init( uint32_t vars_count )
{
	m_instance = std::make_shared<InterpolatedMove>( vars_count );
}

InterpolatedMove & InterpolatedMove::get()
{
	return *m_instance;
}

void InterpolatedMove::setVars( const std::vector<double> & newVars )
{
	assert( m_prevVars.size() == newVars.size() );

//	if( true == m_queueRanges.empty() )
//	{
//		setInitialVars( newVars );
//		return;
//	}

	double maxVarDiff = 0.0;
	{
		auto newVarIter = std::begin( newVars );
		const auto endIter = std::end( newVars );

		auto prevVarIter = std::begin( m_prevVars );


		for( ; newVarIter != endIter ; newVarIter++, prevVarIter++ )
		{
			double newVar = *newVarIter;
			double prevVar = *prevVarIter;
			if( maxVarDiff < ( newVar - prevVar ) )
			{
				maxVarDiff = std::abs( newVar - prevVar );
			}
		}
	}
	auto newVarIter = std::begin( newVars );
	const auto endIter = std::end( newVars );

	auto prevVarIter = std::begin( m_prevVars );

	VarTimeMoveInfo vTMInfo;
	for( ; newVarIter != endIter ; newVarIter++, prevVarIter++ )
	{
		double newVar = *newVarIter;
		double prevVar = *prevVarIter;
		VarMoveInfo varMoveInfo;
		varMoveInfo.range.beginVar = prevVar;
		varMoveInfo.range.endVar = newVar;
		varMoveInfo.varRateRatio = ( newVar - prevVar ) / maxVarDiff;

		vTMInfo.varMoveInfo.push_back( varMoveInfo );
	}

	vTMInfo.timeRange.beginTime = std::chrono::milliseconds::zero();
	vTMInfo.timeRange.endTime = vTMInfo.timeRange.beginTime + std::chrono::seconds( m_moveTimeConstant );

	vTMInfo.elapsed = std::chrono::milliseconds::zero();

	m_queueRanges.push( vTMInfo );

	m_prevVars = newVars;
}

void InterpolatedMove::getVars( std::vector<double> & vars )
{
	vars = m_currentVars;

//	std::stringstream ioss;
//	copy(vars.begin(), vars.end(),
//		 std::ostream_iterator<double>(ioss,","));
//	std::cout << ioss.str() << std::endl;

}

bool InterpolatedMove::update( const std::chrono::milliseconds & delta )
{
	if( true == m_queueRanges.empty() )
	{
		return false;
	}

//	currTMInfo.
	VarTimeMoveInfo & currTMInfo = m_queueRanges.front();

	assert( m_currentVars.size() == currTMInfo.varMoveInfo.size() );

	currTMInfo.elapsed += delta;
	auto varInfoIter = std::begin( currTMInfo.varMoveInfo );
	auto varInfoEndIter = std::end( currTMInfo.varMoveInfo );
	auto currVarIter = std::begin( m_currentVars );
	bool percentageFinished = false;
	const double timePercentage = ( ( currTMInfo.timeRange.beginTime.count() + currTMInfo.elapsed.count() ) / ( ( double )( currTMInfo.timeRange.endTime.count() - currTMInfo.timeRange.beginTime.count() ) ) );
	if( 1.0 >= timePercentage )
	{
		for( ; varInfoIter != varInfoEndIter ; varInfoIter++, currVarIter++ )
		{
			const auto & varInfo = ( *varInfoIter );

			const double ratio = timePercentage;// * varInfo.varRateRatio;
	//		std::cout << "ratio=" << ratio << ", timePercentage=" << timePercentage << std::endl;
			(* currVarIter ) = m_interpolation->apply3( varInfo.range.beginVar, varInfo.range.endVar, ratio );
		}
	}
	else
	{
		percentageFinished = true;
	}

	if( true == percentageFinished )
	{
		m_queueRanges.pop();
	}
	return true;
}

void InterpolatedMove::setInitialVars( const std::vector<double> & vars )
{
	std::queue<VarTimeMoveInfo> empty;
	std::swap( m_queueRanges, empty );

	m_prevVars = vars;

	m_currentVars.resize( vars.size() );
}
