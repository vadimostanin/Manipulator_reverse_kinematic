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

	enum class eParamType
	{
		eDistance,
		eAngle,
		eLegsAngles,
		eGiNaCTypes,
		NativeFuncParams,
	};

	IFuncParams( eParamType type ) : m_Type( type ){}

	eParamType type() const { return m_Type; }

private:
	eParamType m_Type;
};

#endif /* CORE_IFUNCPARAMS_H_ */
