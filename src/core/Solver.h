/*
 * Solver.h
 *
 *  Created on: Dec 11, 2017
 *      Author: user
 */

#ifndef SOLVER_H_
#define SOLVER_H_

#include "LegManipulator.h"
#include "DerivativeFuncsStorage.h"
#include <ginac.h>
#include <symbol.h>

static void empty( const std::vector<double> & ){}
typedef std::function<void( const std::vector<double> & )> SolveEndCb;

typedef std::shared_ptr<GiNaC::symbol> ShSymbol;

class Solver
{
public:
	Solver( const ShLegManipulator & legs );
	virtual ~Solver();

	std::vector<double> getError();

	void solveFromCurrent( int32_t x, int32_t y, int32_t z, double epsilon = 0.01, uint32_t maxSteps = 1000, SolveEndCb cbPerStep = empty );
	void solveContiniouslyShuffling( int32_t x, int32_t y, int32_t z, double epsilon = 0.01, uint32_t maxStepsPerSolving = 1000, uint32_t maxSolvingCount = 10, SolveEndCb cbPerStep = empty );

	void solvePerpendicular( int32_t x, int32_t y, int32_t z, double angle, double epsilon = 0.01, uint32_t maxSteps = 1000, SolveEndCb cbPerStep = empty );
	void solvePerpendicularShuffling( int32_t x, int32_t y, int32_t z, double angle, double epsilon = 0.01, uint32_t maxStepsPerSolving = 1000, uint32_t maxSolvingCount = 10, SolveEndCb cbPerStep = empty );

	void solveContiniouslyShufflingLessError( int32_t x, int32_t y, int32_t z, double epsilon = 0.01, uint32_t maxStepsPerSolving = 1000, uint32_t maxSolvingCount = 10, SolveEndCb cbPerStep = empty );
	void solveContiniouslyShufflingLessAngle( int32_t x, int32_t y, int32_t z, double epsilon = 0.01, uint32_t maxStepsPerSolving = 1000, uint32_t maxSolvingCount = 10, SolveEndCb cbPerStep = empty );

	void solveContIterShuf( int32_t x, int32_t y, int32_t z, double epsilon = 0.01, int32_t maxStepsPerSolving = 1000, SolveEndCb cbPerStep = empty );
	void solveContIterShufLessAngle( int32_t x, int32_t y, int32_t z, double epsilon = 0.01, int32_t maxStepsPerSolving = 1000, SolveEndCb cbPerStep = empty );

	std::string generateErroFunctionDerivatives();

	double getErrorFunctionValue();
	double getErrorFunctionValue( ShLegManipulator manipulator );

	ShLegManipulator getCurrentManipulator() const;
private:
	void fillPredefinedDerErrorFunctions();
	std::vector<double> oneStep( int32_t x, int32_t y, int32_t z );
	void updateLearningRate( const std::vector<double> & angleErrors );
	void initPreSolv( int32_t x, int32_t y, int32_t z );
	void fillParams( int32_t targetX, int32_t targetY, int32_t targetZ, std::vector<double> & params );
	std::vector<double> forwardv3( int32_t expectedX, int32_t expectedY, int32_t expectedZ );
	std::vector<double> forwardv2( int32_t expectedX, int32_t expectedY, int32_t expectedZ );
	std::vector<double> forwardv1( int32_t x, int32_t y );
	void backward( const std::vector<double> & error );
	void initGiNaCVars();
	void initGiNaCErrorFunction( int32_t targetX, int32_t targetY, int32_t targetZ );

	bool isCrossingLegsFound( const ShLeg& leg, uint32_t legIndex );
	bool isFinalTooClose( const int32_t minDistance );
	bool isFinalTooClose( ShLegManipulator manipulator, const int32_t minDistance );
	bool isAccumulativeAngleTooBig( const double maxAngle );

	void printLearningRates();

	void shuffleLegs();
	void shuffleLeg( const ShLeg & leg );
	void shuffleReverseIncrementLegs( uint32_t legsCount );

	void setCurrentManipulator( ShLegManipulator manipulator );

	bool isPathPossble( ShLegManipulator manipulatorFrom, ShLegManipulator manipulatorTo );

	std::vector<double> 		m_errors;
	std::vector<double> 		m_learningRates;
	ShLegManipulator 			m_manipulator;
	std::vector<ShSymbol> 		m_ginacXYoZAngles;
	std::vector<ShSymbol> 		m_ginacXZoYAngles;
	std::vector<GiNaC::ex> 		m_errorDerivativeFunctions;
	GiNaC::ex 					m_errorFunction;
	std::vector<DerivFuncType> 	m_preDefinedDerivativeFunctions;

	double m_minEcceptableDistance{1.0};
	double m_minClosestDistance{15};
};

#endif /* SOLVER_H_ */
