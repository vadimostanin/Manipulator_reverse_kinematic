/*
 * DistanceDerivates.h
 *
 *  Created on: 19 мар. 2018 г.
 *      Author: vadim
 */

#ifndef DISTANCEDERIVATES_H_
#define DISTANCEDERIVATES_H_

#include "IReceivingDerivative.h"
#include <stdint.h>
#include <vector>
#include <ginac.h>

class WrapperErrorFunction: public IReceivingFunction
{
public:
	WrapperErrorFunction();
	~WrapperErrorFunction() = default;

	void add( const GiNaC::ex & func );
private:

	std::vector<double> evaluate() override;
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

	std::vector<GiNaC::ex> m_Funcs;
};

#endif /* DISTANCEDERIVATES_H_ */
