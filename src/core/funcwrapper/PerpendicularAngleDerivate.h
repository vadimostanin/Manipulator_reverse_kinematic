/*
 * PerpendicularAngleDerivate.h
 *
 *  Created on: 19 мар. 2018 г.
 *      Author: vadim
 */

#ifndef CORE_PERPENDICULARANGLEDERIVATE_H_
#define CORE_PERPENDICULARANGLEDERIVATE_H_

#include "IDataReceiver.h"
#include "IFunction.h"

class PerpendicularAngleDerivate: public IFunction, public IDataReceiver
{
public:
	PerpendicularAngleDerivate();
private:
	std::vector<double> evaluate() const override;
	void onReceive( const IFuncParams & data ) override;

	double m_Angle{0.0};
	std::vector<double> m_legsAngles;
};

#endif /* CORE_PERPENDICULARANGLEDERIVATE_H_ */
