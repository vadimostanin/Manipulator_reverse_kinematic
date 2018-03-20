/*
 * IDataChunk.h
 *
 *  Created on: 19 мар. 2018 г.
 *      Author: vadim
 */

#ifndef CORE_IDATACHUNK_H_
#define CORE_IDATACHUNK_H_

class IDataChunk
{
public:

	enum class eDataChunkType
	{
		eDistance,
		eAngle,
		eLegsAngles,
		eGiNaCTypes
	};

	IDataChunk( eDataChunkType type ) : m_Type( type ){}

	eDataChunkType type() const { return m_Type; }

private:
	eDataChunkType m_Type;
};

#endif /* CORE_IDATACHUNK_H_ */
