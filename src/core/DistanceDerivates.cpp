/*
 * DistanceDerivates.cpp
 *
 *  Created on: 19 мар. 2018 г.
 *      Author: vadim
 */

#include "DistanceDerivates.h"
#include "DistanceDataChunk.h"
#include "LegAnglesDataChuck.h"
#include "GiNaCTypesChunk.h"

DistanceDerivates::DistanceDerivates()
{
}

void DistanceDerivates::add( const GiNaC::ex & func )
{
	m_Funcs.emplace_back( func );
}

std::vector<double> DistanceDerivates::evaluate()
{
	GiNaC::lst functionVars;
	auto legAngleIter = std::begin( m_legsAngles );
	auto angleXYSymbolIter = std::begin( m_ginacXYoZAngles );
	auto angleXZSymbolIter = std::begin( m_ginacXZoYAngles );
	for(  ; legAngleIter != std::end( m_legsAngles ) ; legAngleIter ++, angleXYSymbolIter++, angleXZSymbolIter++ )
	{
		{
			const double angle = *legAngleIter;
			const double radian = Utils::deg2Rad( angle );

//			std::cout << "(**angleXYSymbolIter)=" << (**angleXYSymbolIter) << std::endl;

			functionVars.append( (**angleXYSymbolIter) == radian );
		}
		{
			const double angle = (*legIter)->getAngleXZ();
			const double radian = Utils::deg2Rad( angle );

			functionVars.append( (**angleXZSymbolIter) == radian );
		}
	}
	return std::vector<double>();
}

void DistanceDerivates::onReceive( const IDataChunk & data )
{
	if( IDataChunk::eDataChunkType::eDistance == data.type() )
	{
		const auto & obj = static_cast<const DistanceDataChunk&>( data );
		m_X = obj.getX();
		m_Y = obj.getY();
		m_Z = obj.getZ();
	}
	else if( IDataChunk::eDataChunkType::eLegsAngles == data.type() )
	{
		const auto & obj = static_cast<const LegAnglesDataChuck&>( data );
		m_legsAngles = std::move( obj.getLegsAngles() );
	}
	else if( IDataChunk::eDataChunkType::eGiNaCTypes == data.type() )
	{
		const auto & obj = static_cast<const GiNaCTypesChunk&>( data );
		obj.getTargetSymbols( m_ginacTargetX, m_ginacTargetY, m_ginacTargetZ );
		m_ginacXYoZAngles = std::move( obj.getXYSymbols() );
		m_ginacXZoYAngles = std::move( obj.getXZSymbols() );
	}
}
