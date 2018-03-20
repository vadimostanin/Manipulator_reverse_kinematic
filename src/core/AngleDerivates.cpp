/*
 * DistanceDerivates.cpp
 *
 *  Created on: 19 мар. 2018 г.
 *      Author: vadim
 */

#include "AngleDerivates.h"
#include "AngleDataChunk.h"
#include "LegAnglesDataChuck.h"

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
	auto legsAngleIter = std::begin( m_legsAngles );
	auto legsAnglesIterEnd = std::end( m_legsAngles );
	for(  ; legsAngleIter != legsAnglesIterEnd ; legsAngleIter += m_anglesPerLeg )
	{
		{
			const double angle = (*legIter)->getAngleXY();
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

void AngleDerivates::onReceive( const IDataChunk & data )
{
	if( IDataChunk::eDataChunkType::eAngle == data.type() )
	{
		const auto & obj = static_cast<const AngleDataChunk&>( data );
		m_Angle = obj.getAngle();
	}
	else if( IDataChunk::eDataChunkType::eLegsAngles == data.type() )
	{
		const auto & obj = static_cast<const LegAnglesDataChuck&>( data );
		m_legsAngles = std::move( obj.getLegsAngles() );
	}
}
