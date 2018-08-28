/*
 * GiNaCSymbolsChunk.cpp
 *
 *  Created on: Mar 20, 2018
 *      Author: vadym_ostanin
 */

#include "GiNaCTypesDataParams.h"

GiNaCTypesDataParams::GiNaCTypesDataParams() : IFuncParams( IFuncParams::eParamType::eGiNaCTypes )
{
}

GiNaCTypesDataParams::~GiNaCTypesDataParams()
{
}

void GiNaCTypesDataParams::setXYSymbols( const std::vector<std::shared_ptr<GiNaC::symbol>> & xySymbols )
{
	m_xySymbols = xySymbols;
}

std::vector<std::shared_ptr<GiNaC::symbol>> GiNaCTypesDataParams::getXYSymbols() const
{
	return m_xySymbols;
}

void GiNaCTypesDataParams::setXZSymbols( const std::vector<std::shared_ptr<GiNaC::symbol>> & xzSymbols )
{
	m_xzSymbols = xzSymbols;
}

std::vector<std::shared_ptr<GiNaC::symbol>> GiNaCTypesDataParams::getXZSymbols() const
{
	return m_xzSymbols;
}

void GiNaCTypesDataParams::setTargetSymbols( std::shared_ptr<GiNaC::symbol> targetX, std::shared_ptr<GiNaC::symbol> targetY, std::shared_ptr<GiNaC::symbol> targetZ )
{
	m_ginacTargetX = std::move( targetX );
	m_ginacTargetY = std::move( targetY );
	m_ginacTargetZ = std::move( targetZ );
}

void GiNaCTypesDataParams::getTargetSymbols( std::shared_ptr<GiNaC::symbol> & targetX, std::shared_ptr<GiNaC::symbol> & targetY, std::shared_ptr<GiNaC::symbol> & targetZ ) const
{
	targetX = m_ginacTargetX;
	targetY = m_ginacTargetY;
	targetZ = m_ginacTargetZ;
}

void GiNaCTypesDataParams::setAngleSymbol( std::shared_ptr<GiNaC::symbol> targetAngle )
{
	m_ginacTargetAngle = targetAngle;
}

void GiNaCTypesDataParams::getAngleSymbol( std::shared_ptr<GiNaC::symbol> & targetAngle ) const
{
	targetAngle = m_ginacTargetAngle;
}
