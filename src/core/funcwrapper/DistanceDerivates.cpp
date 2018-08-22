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
			const double radian = *legAngleIter;

//			std::cout << "(**angleXYSymbolIter)=" << (**angleXYSymbolIter) << std::endl;

			functionVars.append( (**angleXYSymbolIter) == radian );
		}
		legAngleIter++;
		{
			const double radian = *legAngleIter;

			functionVars.append( (**angleXZSymbolIter) == radian );
		}
	}

	functionVars.append( *m_ginacTargetX == m_X );
	functionVars.append( *m_ginacTargetY == m_Y );
	functionVars.append( *m_ginacTargetZ == m_Z );


	std::vector<double> errors( m_legsAngles.size() );
	GiNaC::ex perLegAngleLength;
	auto errorIter = std::begin( errors );
	auto derivativeIter = std::begin( m_Funcs );
	for( ; derivativeIter != std::end( m_Funcs ) ; derivativeIter++, errorIter++ )
	{
		GiNaC::ex f = GiNaC::evalf( (*derivativeIter).subs( functionVars ) );
//		std::cout << "(*derivativeIter)=" << (*derivativeIter) << std::endl;
//		std::cout << "f=" << f << std::endl;

		if (GiNaC::is_a<GiNaC::numeric>(f))
		{
			(*errorIter) = GiNaC::ex_to<GiNaC::numeric>(f).to_double();
//			std::cout << "errorIter=" << (*errorIter) << std::endl;
		}
	}
	return std::move(errors);
}

void DistanceDerivates::onReceive( const IFuncParams & data )
{
	if( IFuncParams::eDataChunkType::eDistance == data.type() )
	{
		const auto & obj = static_cast<const DistanceDataChunk&>( data );
		m_X = obj.getX();
		m_Y = obj.getY();
		m_Z = obj.getZ();
	}
	else if( IFuncParams::eDataChunkType::eLegsAngles == data.type() )
	{
		const auto & obj = static_cast<const LegAnglesDataChuck&>( data );
		m_legsAngles = std::move( obj.getLegsAngles() );
	}
	else if( IFuncParams::eDataChunkType::eGiNaCTypes == data.type() )
	{
		const auto & obj = static_cast<const GiNaCTypesChunk&>( data );
		obj.getTargetSymbols( m_ginacTargetX, m_ginacTargetY, m_ginacTargetZ );
		m_ginacXYoZAngles = std::move( obj.getXYSymbols() );
		m_ginacXZoYAngles = std::move( obj.getXZSymbols() );
	}
}
