// 2. Draw a 100-by-30 Rectangle and place the text “Howdy!” inside it.
#include "Simple_window.h"
#include "Graph.h"

int main()
{
  using namespace Graph_lib; //our graphics facilities are in Graph_lib (defined in Graph.h)

  Point top_left{500, 100}; //will be top left corner of window

  Simple_window win{top_left, 600, 400, "Canvas"};
  win.set_label("Canvas");

  Rectangle r{Point{100, 200}, 100, 30};
  Text t{Point{125, 225}, "Howdy!"};

  win.attach(r);
  win.attach(t);
  win.wait_for_button(); //give control to the display engine
}
