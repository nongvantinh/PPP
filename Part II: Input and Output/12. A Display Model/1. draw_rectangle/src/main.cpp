// 1. Draw a rectangle as a Rectangle and as a Polygon. Make the lines of the Polygon red and the lines of the Rectangle
// blue.
#include "Simple_window.h"
#include "Graph.h"

int main()
{
  using namespace Graph_lib; //our graphics facilities are in Graph_lib (defined in Graph.h)

  Point top_left{500, 100}; //will be top left corner of window

  Simple_window win{top_left, 600, 400, "Canvas"};
  win.set_label("Canvas");
  Rectangle r{Point{100, 100},Point{300, 200}};
  r.set_color(Color::blue);
  Polygon poly;
  poly.add(Point{200, 200});
  poly.add(Point{400, 200});
  poly.add(Point{400, 300});
  poly.add(Point{200, 300});
  poly.set_color(Color::red);
  win.attach(poly);
  win.attach(r);

  win.wait_for_button(); //give control to the display engine
}
