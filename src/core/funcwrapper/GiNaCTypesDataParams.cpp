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

void GiNaCTypesDataParams::setCurrentXYSymbols( std::vector<std::shared_ptr<GiNaC::symbol>> currentXYSymbols )
{
	m_currentXYSymbols = std::move( currentXYSymbols );
}

std::vector<std::shared_ptr<GiNaC::symbol>> GiNaCTypesDataParams::getCurrentXYSymbols() const
{
	return m_currentXYSymbols;
}

void GiNaCTypesDataParams::setCurrentXZSymbols( std::vector<std::shared_ptr<GiNaC::symbol>> currentXZSymbols )
{
	m_currentXZSymbols = std::move( currentXZSymbols );
}

std::vector<std::shared_ptr<GiNaC::symbol>> GiNaCTypesDataParams::getCurrentXZSymbols() const
{
	return m_currentXZSymbols;
}

void GiNaCTypesDataParams::setInitialXYSymbols( std::vector<std::shared_ptr<GiNaC::symbol>> xyInitialSymbols )
{
	m_initialXYSymbols = std::move( xyInitialSymbols );
}

std::vector<std::shared_ptr<GiNaC::symbol>> GiNaCTypesDataParams::getInitialXYSymbols() const
{
	return m_initialXYSymbols;
}

void GiNaCTypesDataParams::setInitialXZSymbols( std::vector<std::shared_ptr<GiNaC::symbol>> xzInitialSymbols )
{
	m_initialXZSymbols = std::move( xzInitialSymbols );
}

std::vector<std::shared_ptr<GiNaC::symbol>> GiNaCTypesDataParams::getInitialXZSymbols() const
{
	return m_initialXZSymbols;
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
