/*
 * DrawLegXYoZ.h
 *
 *  Created on: 10 дек. 2017 г.
 *      Author: vadim
 */

#ifndef DRAWLEGXYOZ_H_
#define DRAWLEGXYOZ_H_

#include "core/Leg.h"
#include <memory>
#include <vector>
#include <cairomm/refptr.h>
#include <cairomm/context.h>

class DrawLegXYoZ;
typedef std::shared_ptr<DrawLegXYoZ> ShDrawLegXYoZ;
typedef std::vector<ShDrawLegXYoZ> DrawLegsXYoZ;

class DrawLegXYoZ
{
public:
	DrawLegXYoZ( ShLeg leg );
	virtual ~DrawLegXYoZ();

	void render( const Cairo::RefPtr<Cairo::Context>& cr ) const;
	ShLeg getLeg(){ return m_Leg; }
private:
	ShLeg m_Leg;

	double m_colorR;
	double m_colorG;
	double m_colorB;
};

#endif /* DRAWLEGXYOZ_H_ */
