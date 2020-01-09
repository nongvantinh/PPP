#include "Simple_window.h"
#include "Graph.h"

vector<Color> init_color();
int main()
{
  using namespace Graph_lib; //our graphics facilities are in Graph_lib (defined in Graph.h)

  Point top_left{500, 100}; //will be top left corner of window

  Simple_window win{top_left, 600, 400, "Canvas"};
  win.set_label("Canvas");

  vector<Color> cl(init_color());
  Vector_ref<Circle> vc;
  Point origin{200, 150};
  for (int i(0); i < 3; ++i)
  {
    Circle *c = new Circle{origin, 50};
    origin.x += 110;
    vc.push_back(c);
  }
   origin = Point{250, 200};
  for (int i(0); i < 2; ++i)
  {
    Circle *c = new Circle{origin, 50};
    origin.x += 110;
    vc.push_back(c);
  }

for(int i(0); i < vc.size(); ++i)
{
  vc[i].set_color(cl[i]);
  vc[i].set_style(Line_style(Line_style::solid,4));
  win.attach(vc[i]);
}

  win.wait_for_button(); //give control to the display engine
}

vector<Color> init_color()
{
  vector<Color> cl;
  cl.push_back(Color::blue);
  cl.push_back(Color::black);
  cl.push_back(Color::red);
  cl.push_back(Color::yellow);
  cl.push_back(Color::green);
  return cl;
}
