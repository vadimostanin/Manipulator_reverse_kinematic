/*
 * DistanceDerivates.h
 *
 *  Created on: 19 мар. 2018 г.
 *      Author: vadim
 */

#ifndef WRAPPERERRORFUNCTION_H_
#define WRAPPERERRORFUNCTION_H_

#include "IReceivingDerivative.h"
#include <stdint.h>
#include <vector>
#include <ginac.h>

class GiNaCErrorFunction: public IReceivingFunction
{
public:
	GiNaCErrorFunction( std::shared_ptr<GiNaC::ex> ex );
	~GiNaCErrorFunction() = default;

	IFuncSh diff( const IFuncDiffParams & params ) override;
private:

	std::vector<double> evaluate() const override;

	void onReceive( const IFuncParams & data ) override;

	int32_t m_X{0};
	int32_t m_Y{0};
	int32_t m_Z{0};

	std::shared_ptr<GiNaC::symbol> m_ginacTargetX;
	std::shared_ptr<GiNaC::symbol> m_ginacTargetY;
	std::shared_ptr<GiNaC::symbol> m_ginacTargetZ;

	std::vector<std::shared_ptr<GiNaC::symbol>> 		m_ginacXYoZAngles;
	std::vector<std::shared_ptr<GiNaC::symbol>> 		m_ginacXZoYAngles;
	std::shared_ptr<GiNaC::symbol> 						m_ginacAngleDegree;

	std::vector<double> m_legsAngles;
	std::shared_ptr<GiNaC::ex> m_Ex;

	double m_AngleDegree{0};
	bool m_IsAngled{false};
};

#endif /* WRAPPERERRORFUNCTION_H_ */
