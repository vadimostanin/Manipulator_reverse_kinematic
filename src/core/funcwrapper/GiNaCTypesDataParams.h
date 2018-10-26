/*
 * GiNaCSymbolsChunk.h
 *
 *  Created on: Mar 20, 2018
 *      Author: vadym_ostanin
 */

#ifndef CORE_GINACTYPESDATAPARAMS_H_
#define CORE_GINACTYPESDATAPARAMS_H_

#include "IFuncParams.h"
#include <ginac.h>

class GiNaCTypesDataParams: public IFuncParams
{
public:
	GiNaCTypesDataParams();
	virtual ~GiNaCTypesDataParams();

	void setCurrentXYSymbols( std::vector<std::shared_ptr<GiNaC::symbol>> currentXYSymbols );
	std::vector<std::shared_ptr<GiNaC::symbol>> getCurrentXYSymbols() const;

	void setCurrentXZSymbols( std::vector<std::shared_ptr<GiNaC::symbol>> currentXZSymbols );
	std::vector<std::shared_ptr<GiNaC::symbol>> getCurrentXZSymbols() const;

	void setInitialXYSymbols( std::vector<std::shared_ptr<GiNaC::symbol>> xyInitialSymbols );
	std::vector<std::shared_ptr<GiNaC::symbol>> getInitialXYSymbols() const;

	void setInitialXZSymbols( std::vector<std::shared_ptr<GiNaC::symbol>> xzInitialSymbols );
	std::vector<std::shared_ptr<GiNaC::symbol>> getInitialXZSymbols() const;

	void setTargetSymbols( std::shared_ptr<GiNaC::symbol> targetX, std::shared_ptr<GiNaC::symbol> targetY, std::shared_ptr<GiNaC::symbol> targetZ );
	void getTargetSymbols( std::shared_ptr<GiNaC::symbol> & targetX, std::shared_ptr<GiNaC::symbol> & targetY, std::shared_ptr<GiNaC::symbol> & targetZ ) const;

	void setAngleSymbol( std::shared_ptr<GiNaC::symbol> targetAngle );
	void getAngleSymbol( std::shared_ptr<GiNaC::symbol> & targetAngle ) const;

private:
	std::vector<std::shared_ptr<GiNaC::symbol>> m_initialXYSymbols;
	std::vector<std::shared_ptr<GiNaC::symbol>> m_initialXZSymbols;

	std::vector<std::shared_ptr<GiNaC::symbol>> m_currentXYSymbols;
	std::vector<std::shared_ptr<GiNaC::symbol>> m_currentXZSymbols;

	std::shared_ptr<GiNaC::symbol>               m_ginacTargetX;
	std::shared_ptr<GiNaC::symbol>               m_ginacTargetY;
	std::shared_ptr<GiNaC::symbol>               m_ginacTargetZ;

	std::shared_ptr<GiNaC::symbol>               m_ginacTargetAngle;
};

#endif /* CORE_GINACTYPESDATAPARAMS_H_ */
