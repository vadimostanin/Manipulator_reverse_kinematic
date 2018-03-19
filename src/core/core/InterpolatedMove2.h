/*
 * InterpolatedMove.h
 *
 *  Created on: Jan 23, 2018
 *      Author: vadym_ostanin
 */

#ifndef CORE_INTERPOLATEDMOVE2_H_
#define CORE_INTERPOLATEDMOVE2_H_

#include "InterpolationBase.h"
#include <vector>
#include <memory>
#include <chrono>
#include <queue>

class InterpolatedMove2
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
	static std::shared_ptr<InterpolatedMove2> m_instance;
	static void init( uint32_t vars_count );
	static InterpolatedMove2 & get();
	InterpolatedMove2( uint32_t vars_count );

	void setVars( const std::vector<double> & vars );
	void getVars( std::vector<double> & vars );
	bool update( const std::chrono::milliseconds & milliseconds );
private:
//	std::vector<double> m_prevVars;
	std::vector<double> m_currentVars;

	std::shared_ptr<InterpolationBase> m_interpolationStandart;
	std::shared_ptr<InterpolationBase> m_interpolationStopStart;
	std::shared_ptr<InterpolationBase> m_interpolationCurrent;

	std::queue<VarTimeMoveInfo> m_queueRanges;

	const uint32_t m_moveTimeConstant{10*1000};// ten seconds

	std::vector<std::vector<double>> m_vVars;

	double m_currentA;

	void mergeVars();
	double findSameASlopeStraightDirection();
	double findSameASlopeOppositeDirection();
};

#endif /* CORE_INTERPOLATEDMOVE2_H_ */
