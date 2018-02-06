/*
 * DrawLegXZoY.h
 *
 *  Created on: 10 дек. 2017 г.
 *      Author: vadim
 */

#ifndef DrawLegXZoY_H_
#define DrawLegXZoY_H_

#include "core/Leg.h"
#include <memory>
#include <vector>
#include <cairomm/refptr.h>
#include <cairomm/context.h>

class DrawLegXZoY;
typedef std::shared_ptr<DrawLegXZoY> ShDrawLegXZoY;
typedef std::vector<ShDrawLegXZoY> DrawLegsXZoY;

class DrawLegXZoY
{
public:
	DrawLegXZoY( ShLeg leg );
	virtual ~DrawLegXZoY();

	void render( const Cairo::RefPtr<Cairo::Context>& cr ) const;
	ShLeg getLeg(){ return m_Leg; }
private:
	ShLeg m_Leg;

	double m_colorR;
	double m_colorG;
	double m_colorB;
};

#endif /* DrawLegXZoY_H_ */
