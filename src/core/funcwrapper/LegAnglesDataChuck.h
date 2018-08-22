/*
 * LegAnglesDataChuck.h
 *
 *  Created on: 19 мар. 2018 г.
 *      Author: vadim
 */

#ifndef CORE_LEGANGLESDATACHUCK_H_
#define CORE_LEGANGLESDATACHUCK_H_

#include "IFuncParams.h"
#include <vector>

class LegAnglesDataChuck: public IFuncParams
{
public:
	LegAnglesDataChuck( const std::vector<double> & legsAngles );

	const std::vector<double> getLegsAngles() const { return m_legsAngles; }
private:
	std::vector<double> m_legsAngles;
};

#endif /* CORE_LEGANGLESDATACHUCK_H_ */
