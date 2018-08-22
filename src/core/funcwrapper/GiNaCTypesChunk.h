/*
 * GiNaCSymbolsChunk.h
 *
 *  Created on: Mar 20, 2018
 *      Author: vadym_ostanin
 */

#ifndef CORE_GINACTYPESCHUNK_H_
#define CORE_GINACTYPESCHUNK_H_

#include "IFuncParams.h"
#include <ginac.h>

class GiNaCTypesChunk: public IFuncParams
{
public:
	GiNaCTypesChunk();
	virtual ~GiNaCTypesChunk();

	void setXYSymbols( const std::vector<std::shared_ptr<GiNaC::symbol>> & xySymbols );
	std::vector<std::shared_ptr<GiNaC::symbol>> getXYSymbols() const;

	void setXZSymbols( const std::vector<std::shared_ptr<GiNaC::symbol>> & xzSymbols );
	std::vector<std::shared_ptr<GiNaC::symbol>> getXZSymbols() const;

	void setTargetSymbols( std::shared_ptr<GiNaC::symbol> targetX, std::shared_ptr<GiNaC::symbol> targetY, std::shared_ptr<GiNaC::symbol> targetZ );
	void getTargetSymbols( std::shared_ptr<GiNaC::symbol> & targetX, std::shared_ptr<GiNaC::symbol> & targetY, std::shared_ptr<GiNaC::symbol> & targetZ ) const;

	void setAngleSymbol( std::shared_ptr<GiNaC::symbol> targetAngle );
	void getAngleAngle( std::shared_ptr<GiNaC::symbol> & targetAngle ) const;

private:
	std::vector<std::shared_ptr<GiNaC::symbol>> m_xySymbols;
	std::vector<std::shared_ptr<GiNaC::symbol>> m_xzSymbols;

	std::shared_ptr<GiNaC::symbol>               m_ginacTargetX;
	std::shared_ptr<GiNaC::symbol>               m_ginacTargetY;
	std::shared_ptr<GiNaC::symbol>               m_ginacTargetZ;

	std::shared_ptr<GiNaC::symbol>               m_ginacTargetAngle;
};

#endif /* CORE_GINACTYPESCHUNK_H_ */
