/*
 * DistanceDerivates.h
 *
 *  Created on: 19 мар. 2018 г.
 *      Author: vadim
 */

#ifndef GINACANGLEDERIVATES_H_
#define GINACANGLEDERIVATES_H_

#include "IReceivingDerivative.h"
#include <stdint.h>
#include <vector>
#include <ginac.h>

class GiNaCAngleDerivates: public IReceivingFunction, public std::vector<IFuncSh>
{
public:
	GiNaCAngleDerivates();
	~GiNaCAngleDerivates() = default;
private:

	std::vector<double> evaluate() const override;
	IFuncSh diff( const IFuncDiffParams & params ) override;
	void onReceive( const IFuncParams & data ) override;

	double m_Angle{0.0};
	std::vector<double> m_legsAngles;

	std::vector<std::shared_ptr<GiNaC::symbol>> 		m_ginacXYoZAngles;
	std::vector<std::shared_ptr<GiNaC::symbol>> 		m_ginacXZoYAngles;
	std::shared_ptr<GiNaC::symbol>               		m_ginacTargetAngle;

	uint32_t m_anglesPerLeg{2};
};

#endif /* GINACANGLEDERIVATES_H_ */
