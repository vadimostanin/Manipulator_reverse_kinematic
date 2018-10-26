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

class LegAnglesDataParams: public IFuncParams
{
public:
	LegAnglesDataParams();

	void setLegsCurrentAngles( std::vector<double> legsCurrentAngles) { m_legsCurrentAngles = std::move( legsCurrentAngles ); }
	void setLegsInitialAngles( std::vector<double> legsInitialAngles ) { m_legsInitialAngles = std::move( legsInitialAngles ); }

	std::vector<double> getLegsCurrentAngles() const { return m_legsCurrentAngles; }
	std::vector<double> getLegsInitialAngles() const { return m_legsInitialAngles; }
private:
	std::vector<double> m_legsCurrentAngles;
	std::vector<double> m_legsInitialAngles;
};

#endif /* CORE_LEGANGLESDATACHUCK_H_ */
