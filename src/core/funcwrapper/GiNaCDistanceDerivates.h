/*
 * DistanceDerivates.h
 *
 *  Created on: 19 мар. 2018 г.
 *      Author: vadim
 */

#ifndef GINACDISTANCEDERIVATES_H_
#define GINACDISTANCEDERIVATES_H_

#include "IReceivingDerivative.h"
#include <stdint.h>
#include <vector>
#include <ginac.h>

class GiNaCDistanceDerivates: public IReceivingFunction, public std::vector<IFuncSh>
{
public:
	GiNaCDistanceDerivates();
	~GiNaCDistanceDerivates() = default;
private:

	std::vector<double> evaluate() const override;
	IFuncSh diff( const IFuncDiffParams & params ) override;
	void onReceive( const IFuncParams & data ) override;

	int32_t m_X{0};
	int32_t m_Y{0};
	int32_t m_Z{0};

	std::shared_ptr<GiNaC::symbol> m_ginacTargetX;
	std::shared_ptr<GiNaC::symbol> m_ginacTargetY;
	std::shared_ptr<GiNaC::symbol> m_ginacTargetZ;

	std::vector<std::shared_ptr<GiNaC::symbol>> 		m_ginacXYoZAngles;
	std::vector<std::shared_ptr<GiNaC::symbol>> 		m_ginacXZoYAngles;

	std::vector<double> m_legsAngles;
};

#endif /* GINACDISTANCEDERIVATES_H_ */
