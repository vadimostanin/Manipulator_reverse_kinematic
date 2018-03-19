/*
 * InterpolatedMove.h
 *
 *  Created on: Jan 23, 2018
 *      Author: vadym_ostanin
 */

#ifndef CORE_INTERPOLATEDMOVE_H_
#define CORE_INTERPOLATEDMOVE_H_

#include "InterpolationBase.h"
#include <vector>
#include <memory>
#include <chrono>
#include <queue>

class InterpolatedMove
{
private:
	struct TimeRange
	{
		std::chrono::milliseconds beginTime;
		std::chrono::milliseconds endTime;
	};

	struct VarRange
	{
		double beginVar;
		double endVar;
	};

	struct VarMoveInfo
	{
		double varRateRatio;
		VarRange range;
	};

	struct VarTimeMoveInfo
	{
		std::chrono::milliseconds elapsed;
		TimeRange timeRange;
		std::vector<VarMoveInfo> varMoveInfo;
	};
	using ShVarTimeMoveInfo = std::shared_ptr<VarTimeMoveInfo>;
public:
	static std::shared_ptr<InterpolatedMove> m_instance;
	static void init( uint32_t vars_count );
	static InterpolatedMove & get();
	InterpolatedMove( uint32_t vars_count );

	void setVars( const std::vector<double> & vars );
	void getVars( std::vector<double> & vars );
	bool update( const std::chrono::milliseconds & milliseconds );
	void setInitialVars( const std::vector<double> & vars );
private:
	std::vector<double> m_prevVars;
	std::vector<double> m_currentVars;

	std::shared_ptr<InterpolationBase> m_interpolation;

	std::queue<VarTimeMoveInfo> m_queueRanges;

//	const double m_etalonVarRate{100};//mean ratio hundred degrees to one
	const uint8_t m_moveTimeConstant{10};// ten seconds

};

#endif /* CORE_INTERPOLATEDMOVE_H_ */
