/*
 * DistanceDerivates.h
 *
 *  Created on: 19 мар. 2018 г.
 *      Author: vadim
 */

#ifndef ANGLEDERIVATES_H_
#define ANGLEDERIVATES_H_

#include "IReceivingDerivative.h"
#include <stdint.h>
#include <vector>
#include <ginac.h>

class AngleDerivates: public IReceivingFunction
{
public:
	AngleDerivates();
	~AngleDerivates() = default;

	void add( const GiNaC::ex & func );
private:

	std::vector<double> evaluate() override;
	void onReceive( const IFuncParams & data ) override;

	double m_Angle{0.0};
	std::vector<double> m_legsAngles;

	std::vector<std::shared_ptr<GiNaC::symbol>> 		m_ginacXYoZAngles;
	std::vector<std::shared_ptr<GiNaC::symbol>> 		m_ginacXZoYAngles;
	std::shared_ptr<GiNaC::symbol>               		m_ginacTargetAngle;

	std::vector<GiNaC::ex> m_Funcs;

	uint32_t m_anglesPerLeg{2};
};

#endif /* ANGLEDERIVATES_H_ */
