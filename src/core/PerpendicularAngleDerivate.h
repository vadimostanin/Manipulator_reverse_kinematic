/*
 * PerpendicularAngleDerivate.h
 *
 *  Created on: 19 мар. 2018 г.
 *      Author: vadim
 */

#ifndef CORE_PERPENDICULARANGLEDERIVATE_H_
#define CORE_PERPENDICULARANGLEDERIVATE_H_

#include "IDataReceiver.h"
#include "IDerivative.h"

class PerpendicularAngleDerivate: public IDerivative, public IDataReceiver
{
public:
	PerpendicularAngleDerivate();
private:
	std::vector<double> evaluate() override;
	void onReceive( const IDataChunk & data ) override;

	double m_Angle{0.0};
	std::vector<double> m_legsAngles;
};

#endif /* CORE_PERPENDICULARANGLEDERIVATE_H_ */
