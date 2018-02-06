/*
 * MyArea.h
 *
 *  Created on: 9 дек. 2017 г.
 *      Author: vadim
 */

#ifndef XZoYArea_H_
#define XZoYArea_H_

#include "DrawLegXZoY.h"
#include <gtkmm/drawingarea.h>

class XZoYArea : public Gtk::DrawingArea
{
public:
  XZoYArea();
  virtual ~XZoYArea();

  void setX( int x ){ m_X = x; }
  void setZ( int z ){ m_Z = z; }
  void setAngle( int angle ){ m_angle = angle; }

  double getX(){ return m_X; }
  double getZ(){ return m_Z; }
  int getAngle(){ return m_angle; }

  void updateDrawLegs( Legs legs );

protected:
  //Override default signal handler:
  bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
private:
  DrawLegsXZoY m_drawLegs;
  int m_X;
  int m_Z;

  int m_angle;

  cairo_matrix_t m_flipYMatrix;
  Cairo::RefPtr<Cairo::ToyFontFace> m_font;
};

#endif /* XZoYArea_H_ */
