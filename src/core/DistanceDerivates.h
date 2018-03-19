/*
 * DistanceDerivates.h
 *
 *  Created on: 19 мар. 2018 г.
 *      Author: vadim
 */

#ifndef DISTANCEDERIVATES_H_
#define DISTANCEDERIVATES_H_

#include "IDataReceiver.h"
#include "IDerivative.h"
#include <stdint.h>
#include <vector>

class DistanceDerivates: public IDerivative, public IDataReceiver
{
public:
	DistanceDerivates();
	~DistanceDerivates() = default;
private:

	double evaluate() override;
	void onReceive( const IDataChunk & data ) override;

	int32_t m_X{0};
	int32_t m_Y{0};
	int32_t m_Z{0};

	std::vector<double> m_legsAngles;
};

#endif /* DISTANCEDERIVATES_H_ */
