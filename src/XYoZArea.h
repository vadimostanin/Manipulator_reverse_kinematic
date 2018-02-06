/*
 * MyArea.h
 *
 *  Created on: 9 дек. 2017 г.
 *      Author: vadim
 */

#ifndef XYOZAREA_H_
#define XYOZAREA_H_

#include "DrawLegXYoZ.h"
#include <gtkmm/drawingarea.h>

class XYoZArea : public Gtk::DrawingArea
{
public:
  XYoZArea();
  virtual ~XYoZArea();

  void setX( int x ){ m_X = x; }
  void setY( int y ){ m_Y = y; }
  void setAngle( int angle ){ m_angle = angle; }

  double getX(){ return m_X; }
  double getY(){ return m_Y; }
  int getAngle(){ return m_angle; }

  void updateDrawLegs( Legs legs );

protected:
  //Override default signal handler:
  bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr) override;
private:
  DrawLegsXYoZ m_drawLegs;
  int m_X;
  int m_Y;

  int m_angle;

  cairo_matrix_t m_flipYMatrix;
  Cairo::RefPtr<Cairo::ToyFontFace> m_font;
};

#endif /* XYOZAREA_H_ */
