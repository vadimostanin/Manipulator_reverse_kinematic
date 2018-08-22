/*
 * IDataReciever.h
 *
 *  Created on: 19 мар. 2018 г.
 *      Author: vadim
 */

#ifndef CORE_IDATARECEIVER_H_
#define CORE_IDATARECEIVER_H_

#include "IFuncParams.h"

class IDataReceiver
{
public:
	virtual void onReceive( const IFuncParams & data ) = 0;
	virtual ~IDataReceiver(){}
};

#endif /* CORE_IDATARECEIVER_H_ */
