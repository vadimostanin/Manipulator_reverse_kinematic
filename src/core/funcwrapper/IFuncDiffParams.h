/*
 * IDataChunk.h
 *
 *  Created on: 19 мар. 2018 г.
 *      Author: vadim
 */

#ifndef CORE_IFUNCDIFFPARAMS_H_
#define CORE_IFUNCDIFFPARAMS_H_

class IFuncDiffParams
{
public:

	enum class eParamType
	{
		Normal = 0,
		eGiNaCTypes
	};

	IFuncDiffParams( eParamType type ) : m_Type( type ){}

	eParamType type() const { return m_Type; }

private:
	eParamType m_Type;
};

#endif /* CORE_IFUNCDIFFPARAMS_H_ */
