/*
 * DistanceDerivates.cpp
 *
 *  Created on: 19 мар. 2018 г.
 *      Author: vadim
 */

#include "AngleDerivates.h"
#include "AngleDataChunk.h"
#include "LegAnglesDataChuck.h"
#include "GiNaCTypesChunk.h"
#include "Utils.h"

AngleDerivates::AngleDerivates()
{
}

void AngleDerivates::add( const GiNaC::ex & func )
{
	m_Funcs.emplace_back( func );
}

std::vector<double> AngleDerivates::evaluate()
{
	GiNaC::lst functionVars;
	auto legAngleIter = std::begin( m_legsAngles );
	auto legsAnglesIterEnd = std::end( m_legsAngles );
	auto angleXYSymbolIter = std::begin( m_ginacXYoZAngles );
	auto angleXZSymbolIter = std::begin( m_ginacXZoYAngles );
	for(  ; legAngleIter != legsAnglesIterEnd ; legAngleIter ++, angleXYSymbolIter++, angleXZSymbolIter++ )
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
	functionVars.append( ( *m_ginacTargetAngle) == m_Angle );
	std::vector<double> errors( m_legsAngles.size() );
	GiNaC::ex perLegAngleLength;
	auto errorIter = std::begin( errors );
	auto derivativeIter = std::begin( m_Funcs );
	for( ; derivativeIter != std::end( m_Funcs ) ; derivativeIter++, errorIter++ )
	{
		GiNaC::ex f = GiNaC::evalf( (*derivativeIter).subs( functionVars ) );
		std::cout << "(*derivativeIter)=" << (*derivativeIter) << std::endl;
//		std::cout << "f=" << f << std::endl;

		if (GiNaC::is_a<GiNaC::numeric>(f))
		{
			(*errorIter) = GiNaC::ex_to<GiNaC::numeric>(f).to_double();
//			std::cout << "errorIter=" << (*errorIter) << std::endl;
		}
	}
	return std::move(errors);
}

void AngleDerivates::onReceive( const IDataChunk & data )
{
	if( IDataChunk::eDataChunkType::eAngle == data.type() )
	{
		const auto & obj = static_cast<const AngleDataChunk&>( data );
		m_Angle = Utils::deg2Rad( obj.getAngle() );
	}
	else if( IDataChunk::eDataChunkType::eLegsAngles == data.type() )
	{
		const auto & obj = static_cast<const LegAnglesDataChuck&>( data );
		m_legsAngles = std::move( obj.getLegsAngles() );
	}
	else if( IDataChunk::eDataChunkType::eGiNaCTypes == data.type() )
	{
		const auto & obj = static_cast<const GiNaCTypesChunk&>( data );
		obj.getAngleAngle( m_ginacTargetAngle );
		m_ginacXYoZAngles = std::move( obj.getXYSymbols() );
		m_ginacXZoYAngles = std::move( obj.getXZSymbols() );
	}
}
