/*
 * HelloWorld.h
 *
 *  Created on: 9 дек. 2017 г.
 *      Author: vadim
 */

#ifndef HELLOWORLD_H_
#define HELLOWORLD_H_

#include "core/Solver.h"
#include "Leg3DDrawWindow.h"
#include <gtkmm/button.h>
#include <gtkmm/togglebutton.h>
#include <gtkmm/window.h>
#include <gtkmm/drawingarea.h>
#include <gtkmm/box.h>
#include <gtkmm/fixed.h>
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/scale.h>
#include "XYoZArea.h"
#include "XZoYArea.h"
#include "Point3.h"

class HelloWorld : public Gtk::Window
{
public:
  HelloWorld();
  ~HelloWorld() override;

  void redraw();

  XYoZArea m_XYoZArea;
  XZoYArea m_XZoYArea;
  Solver m_solver;
  Point3 m_prevDesirablePoint;
  Point3 m_desirablePoint;
  Gtk::ToggleButton m_moveBaseButton;
protected:
  //Signal handlers:
  void on_button_clicked( Glib::ustring& s);

  //Member widgets:
  Gtk::Button m_buttonOneStep;
  Gtk::Box m_HBox;
  Gtk::Box m_VBox;
  Gtk::Box m_VBoxButtons;
  Gtk::Scale m_AngleScale;
  Gtk::Button m_solveButton;
  Gtk::Button m_solveShuffledButton;
  Gtk::Button m_solvePerpButton;
  Gtk::Button m_optimizeCloneButton;
  Gtk::Button m_interpolateButton;


  Gtk::ScrolledWindow m_scrolledXYoZArea;
  Gtk::ScrolledWindow m_scrolledXZoYArea;
  Gtk::Fixed m_widgetFixed;
  Leg3DDrawWindow m_gl3DLegsDrawWindow;
};

#endif /* HELLOWORLD_H_ */
