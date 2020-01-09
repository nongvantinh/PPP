#include "Simple_window.h"
#include "Graph.h"

int main()
{
  using namespace Graph_lib; //our graphics facilities are in Graph_lib (defined in Graph.h)

  Point top_left{500, 100}; //will be top left corner of window

  Simple_window win{top_left, 600, 400, "Canvas"};
  win.set_label("Canvas");

  Rectangle r{Point(), 1000, 1000}; // make it unfit with the window.
  r.set_fill_color(Color::red);
  win.attach(r);
  win.wait_for_button(); //give control to the display engine
}
