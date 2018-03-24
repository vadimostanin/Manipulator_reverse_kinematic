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
#include "ErrorFuncStorage.h"
#include "ContrainsTooClose.h"
#include "DerivatesVector.h"

#include <symbol.h>

static void empty( const std::vector<double> & ){}
typedef std::function<void( const std::vector<double> & )> SolveEndCb;

typedef std::shared_ptr<GiNaC::symbol> ShSymbol;

class Solver
{
	enum class ErrorFunctionType
	{
		eDistance,
		eAngle,
	};
	struct ErrorFunctionTyped
	{
		ErrorFunctionType 			type;
		std::vector<GiNaC::ex> 		errorDerivativeFunctions;
		GiNaC::ex 					errorFunction;
	};
public:
	Solver( const ShLegManipulator & legs );
	virtual ~Solver();

	std::vector<double> getError();

	void solveFromCurrent( int32_t x, int32_t y, int32_t z, double epsilon = 0.01, uint32_t maxSteps = 1000, SolveEndCb cbPerStep = empty );
	void solveFromCurrentAngled( int32_t x, int32_t y, int32_t z, double angleDegree, double epsilon = 0.01, uint32_t maxSteps = 1000, SolveEndCb cbPerStep = empty );
	void solveFromCurrentAngledStochastic( int32_t x, int32_t y, int32_t z, double angleDegree, double epsilon, uint32_t maxSteps, SolveEndCb cbPerStep );
	void solveContiniouslyShuffling( int32_t x, int32_t y, int32_t z, double epsilon = 0.01, uint32_t maxStepsPerSolving = 1000, uint32_t maxSolvingCount = 10, SolveEndCb cbPerStep = empty );

	void solvePerpendicular( int32_t x, int32_t y, int32_t z, double angleDegree, double epsilon = 0.01, uint32_t maxSteps = 1000, SolveEndCb cbPerStep = empty );
	void solvePerpendicularNative( int32_t x, int32_t y, int32_t z, double angleDegree, double epsilon = 0.01, uint32_t maxSteps = 1000, SolveEndCb cbPerStep = empty );
	void solvePerpendicularNativeStochastic( int32_t x, int32_t y, int32_t z, double angleDegree, double epsilon = 0.01, uint32_t maxSteps = 1000, SolveEndCb cbPerStep = empty );

	void solvePerpendicularShuffling( int32_t x, int32_t y, int32_t z, double angleDegree, double epsilon = 0.01, uint32_t maxStepsPerSolving = 1000, uint32_t maxSolvingCount = 10, SolveEndCb cbPerStep = empty );
	void solvePerpendicularNativeShuffling( int32_t x, int32_t y, int32_t z, double angleDegree, double epsilon = 0.01, uint32_t maxStepsPerSolving = 1000, uint32_t maxSolvingCount = 10, SolveEndCb cbPerStep = empty );

	void solveContiniouslyShufflingLessError( int32_t x, int32_t y, int32_t z, double epsilon = 0.01, uint32_t maxStepsPerSolving = 1000, uint32_t maxSolvingCount = 10, SolveEndCb cbPerStep = empty );
	void solveContiniouslyShufflingLessAngle( int32_t x, int32_t y, int32_t z, double epsilon = 0.01, uint32_t maxStepsPerSolving = 1000, uint32_t maxSolvingCount = 10, SolveEndCb cbPerStep = empty );

	void solveContIterShuf( int32_t x, int32_t y, int32_t z, double epsilon = 0.01, int32_t maxStepsPerSolving = 1000, SolveEndCb cbPerStep = empty );
	void solveContIterShufLessAngle( int32_t x, int32_t y, int32_t z, double epsilon = 0.01, int32_t maxStepsPerSolving = 1000, SolveEndCb cbPerStep = empty );

	std::string generateErroFunctionDerivatives();

	double getErrorFunctionValue( TypePrecision targetX, TypePrecision targetY, TypePrecision targetZ, bool angled = false, double angleDegree = 0.0 );
	double getErrorFunctionValue( ShLegManipulator manipulator, TypePrecision targetX, TypePrecision targetY, TypePrecision targetZ, bool angled = false, double angleDegree = 0.0 );

	double getErrorFunctionValue( std::shared_ptr<IDerivative> func );

	ShLegManipulator getCurrentManipulator() const;

	bool isPathPossble( ShLegManipulator manipulatorFrom, ShLegManipulator manipulatorTo );
	std::vector<double> oneStep( int32_t x, int32_t y, int32_t z, bool angled = false, double angleDegree = 0.0 );// temporary in public, need to be private
	std::vector<double> oneStepStochastic( int32_t x, int32_t y, int32_t z, bool angled, double angleDegree );
	std::vector<double> oneStepV2( int32_t x, int32_t y, int32_t z );
private:
	void fillPredefinedDerErrorFunctions();

	void updateLearningRate( const std::vector<double> & angleErrors );
	void initPreSolv( int32_t x, int32_t y, int32_t z, bool angled = false, double angleDegree = 0.0 );
	void initPreSolvStochastic( int32_t x, int32_t y, int32_t z, bool angled, double angleDegree );
	void fillParams( int32_t targetX, int32_t targetY, int32_t targetZ, std::vector<double> & params );
	std::vector<double> forwardLegv3( uint32_t legIndex, int32_t targetX, int32_t targetY, int32_t targetZ );
	std::vector<double> forwardv3( int32_t expectedX, int32_t expectedY, int32_t expectedZ, bool angled = false, double angleDegree = 0.0 );
	std::vector<double> forwardv2_1( std::shared_ptr<IDerivative> funcDerivatives );
	std::vector<double> forwardv2( int32_t expectedX, int32_t expectedY, int32_t expectedZ, bool angled = false, double angleDegree = 0.0 );
	std::vector<double> forwardv1( int32_t x, int32_t y );
	void backward( const std::vector<double> & angleErrors );
	void backwardLeg( uint32_t legIndex, const std::vector<double> & angleErrors );
	void initGiNaCVars();
	void initGiNaCErrorFunction( bool isAngled = false );
	void initGiNaCDistanceErrorFunction();
	void initGiNaCAngleErrorFunction();

	bool isCrossingLegsFound( const ShLeg& leg, uint32_t legIndex );
	bool isAccumulativeAngleTooBig( const double maxAngle );

	void printLearningRates();

	void shuffleLegs();
	void shuffleLeg( const ShLeg & leg );
	void shuffleReverseIncrementLegs( uint32_t legsCount );

	void setCurrentManipulator( ShLegManipulator manipulator );

	void fillErrorFunctionsTyped();

	std::vector<double> getLegsAngles();



	std::vector<double> 		m_errors;
	std::vector<double> 		m_learningRates;
	std::vector<std::vector<double>> 		m_learningRatesPerErrorFunction;
	ShLegManipulator 			m_manipulator;
	std::vector<ShSymbol> 		m_ginacXYoZAngles;
	std::vector<ShSymbol> 		m_ginacXZoYAngles;
	ShSymbol                    m_ginacTargetX{std::make_shared<GiNaC::symbol>("targetX")};
	ShSymbol                    m_ginacTargetY{std::make_shared<GiNaC::symbol>("targetY")};
	ShSymbol                    m_ginacTargetZ{std::make_shared<GiNaC::symbol>("targetZ")};
	ShSymbol                    m_ginacAngleDegree{std::make_shared<GiNaC::symbol>("angleDegree")};
	std::vector<GiNaC::ex> 		m_errorDerivativeFunctions;
	GiNaC::ex 					m_errorFunction;
	std::vector<DerivFuncType> 	m_preDefinedDerivativeFunctions;
	ErroFuncType				m_preDefinedErrorFunction;

	std::vector<ErrorFunctionTyped> m_errorFunctionsTyped;
	DerivatesVector m_derivatesVector;

	double m_minEcceptableDistance{0.05};

	static constexpr float m_ratioRadiansPer1PixelError{0.001};// Begins angles searching with 0.5 radians = 28 degrees
														   // if distance = 100 pixels

	uint32_t m_anglesPerLeg{2};

	ContrainsTooClose m_constrinTooClose;
};

#endif /* SOLVER_H_ */
