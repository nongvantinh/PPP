// 9. Display an image on the screen, e.g., a photo of a friend. Label the image both with a title on the window and with a
// caption in the window.
#include "Simple_window.h"
#include "Graph.h"

int main()
{
  using namespace Graph_lib; //our graphics facilities are in Graph_lib (defined in Graph.h)

  Point top_left{500, 100}; //will be top left corner of window

  Simple_window win{top_left, 600, 400, "Canvas"};
  win.set_label("Snow Cpp");
  Image i {Point{100,100}, "images/snow_cpp.gif"};
  Text caption{Point{240, 375}, "Snow CPP"};

  win.attach(caption);

  win.attach(i);

  win.wait_for_button(); //give control to the display engine
}
