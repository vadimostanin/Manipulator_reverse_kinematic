/*
 * GiNaCSymbolsChunk.cpp
 *
 *  Created on: Mar 20, 2018
 *      Author: vadym_ostanin
 */

#include "GiNaCTypesChunk.h"

GiNaCTypesChunk::GiNaCTypesChunk() : IDataChunk( IDataChunk::eDataChunkType::eGiNaCTypes )
{
}

GiNaCTypesChunk::~GiNaCTypesChunk()
{
}

void GiNaCTypesChunk::setXYSymbols( const std::vector<std::shared_ptr<GiNaC::symbol>> & xySymbols )
{
	m_xySymbols = xySymbols;
}

std::vector<std::shared_ptr<GiNaC::symbol>> GiNaCTypesChunk::getXYSymbols() const
{
	return m_xySymbols;
}

void GiNaCTypesChunk::setXZSymbols( const std::vector<std::shared_ptr<GiNaC::symbol>> & xzSymbols )
{
	m_xzSymbols = xzSymbols;
}

std::vector<std::shared_ptr<GiNaC::symbol>> GiNaCTypesChunk::getXZSymbols() const
{
	return m_xzSymbols;
}

void GiNaCTypesChunk::setTargetSymbols( std::shared_ptr<GiNaC::symbol> targetX, std::shared_ptr<GiNaC::symbol> targetY, std::shared_ptr<GiNaC::symbol> targetZ )
{
	m_ginacTargetX = std::move( targetX );
	m_ginacTargetY = std::move( targetY );
	m_ginacTargetZ = std::move( targetZ );
}

void GiNaCTypesChunk::getTargetSymbols( std::shared_ptr<GiNaC::symbol> & targetX, std::shared_ptr<GiNaC::symbol> & targetY, std::shared_ptr<GiNaC::symbol> & targetZ ) const
{
	targetX = m_ginacTargetX;
	targetY = m_ginacTargetY;
	targetZ = m_ginacTargetZ;
}

void GiNaCTypesChunk::setAngleSymbol( std::shared_ptr<GiNaC::symbol> targetAngle )
{
	m_ginacTargetAngle = targetAngle;
}

void GiNaCTypesChunk::getAngleAngle( std::shared_ptr<GiNaC::symbol> & targetAngle ) const
{
	targetAngle = m_ginacTargetAngle;
}
