#include "Simple_window.h"
#include "Graph.h"

int main()
{
  using namespace Graph_lib; //our graphics facilities are in Graph_lib (defined in Graph.h)

  Point top_left{500, 100}; //will be top left corner of window

  Simple_window win{top_left, x_max()+1000, y_max()+ 1000, "Canvas"}; // A window doesn't fit the screen.
  win.set_label("Canvas");

  win.wait_for_button(); //give control to the display engine
}
