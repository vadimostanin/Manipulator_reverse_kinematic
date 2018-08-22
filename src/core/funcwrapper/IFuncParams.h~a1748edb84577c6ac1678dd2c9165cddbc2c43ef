/*
 * IDataChunk.h
 *
 *  Created on: 19 мар. 2018 г.
 *      Author: vadim
 */

#ifndef CORE_IFUNCPARAMS_H_
#define CORE_IFUNCPARAMS_H_

class IFuncParams
{
public:

	enum class eDataChunkType
	{
		eDistance,
		eAngle,
		eLegsAngles,
		eGiNaCTypes
	};

	IFuncParams( eDataChunkType type ) : m_Type( type ){}

	eDataChunkType type() const { return m_Type; }

private:
	eDataChunkType m_Type;
};

#endif /* CORE_IFUNCPARAMS_H_ */
