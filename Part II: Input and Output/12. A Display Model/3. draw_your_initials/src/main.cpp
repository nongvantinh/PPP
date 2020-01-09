// 3. Draw your initials 150 pixels high. Use a thick line. Draw each initial in a different color.
#include "Simple_window.h"
#include "Graph.h"

int main()
{
  using namespace Graph_lib; //our graphics facilities are in Graph_lib (defined in Graph.h)

  Point top_left{500, 100}; //will be top left corner of window

  Simple_window win{top_left, 600, 400, "Canvas"};
  win.set_label("Canvas #2");
  int x_margin{150};
  Point origin{x_margin, win.y_max() / 2};
  Text t1{origin, "N"};
  t1.set_style(Line_style(Line_style::solid, 4));
  t1.set_color(Color::red);
  t1.set_font_size(150);
  Text t2{origin + Point{100, 0}, "V"};
  t2.set_style(Line_style(Line_style::solid, 4));
  t2.set_color(Color::green);
  t2.set_font_size(150);

  Text t3{origin + Point{100, 0}, "T"};
  t3.set_style(Line_style(Line_style::solid, 4));
  t3.set_color(Color::blue);
  t3.set_font_size(150);

  win.attach(t1);
  win.attach(t2);
  win.attach(t3);

  win.wait_for_button(); //give control to the display engine
}
