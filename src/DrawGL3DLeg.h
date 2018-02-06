/*
 * DrawGL3DLeg.h
 *
 *  Created on: 2 янв. 2018 г.
 *      Author: vadim
 */

#ifndef DRAWGL3DLEG_H_
#define DRAWGL3DLEG_H_

#include "core/Leg.h"
#include <memory>
#include <vector>

class DrawGL3DLeg;
typedef std::shared_ptr<DrawGL3DLeg> ShDrawGL3DLeg;
typedef std::vector<ShDrawGL3DLeg> DrawGL3DLegs;

class DrawGL3DLeg
{
public:
	DrawGL3DLeg( ShLeg shLeg );
	virtual ~DrawGL3DLeg();
	void render() const;
private:
	void drawLeg( int x, int y, int z, int width, int thickness, int height ) const;

	ShLeg m_Leg;
};

#endif /* DRAWGL3DLEG_H_ */
