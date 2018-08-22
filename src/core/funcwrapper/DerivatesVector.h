/*
 * DerivatesVector.h
 *
 *  Created on: Mar 20, 2018
 *      Author: vadym_ostanin
 */

#ifndef CORE_DERIVATESVECTOR_H_
#define CORE_DERIVATESVECTOR_H_

#include "IReceivingDerivative.h"
#include <vector>
#include <memory>

class DerivatesVector : public std::vector<std::shared_ptr<IReceivingFunction>>, public IReceivingFunction
{
public:
	std::vector<double> evaluate() override;
	void onReceive( const IFuncParams & data ) override;
};

#endif /* CORE_DERIVATESVECTOR_H_ */
