// 4. Draw a 3-by-3 tic-tac-toe board of alternating white and red squares.
#include "Simple_window.h"
#include "Graph.h"

int increase(int, int);
int main()
{
  using namespace Graph_lib; //our graphics facilities are in Graph_lib (defined in Graph.h)

  Point top_left{500, 100}; //will be top left corner of window

  Simple_window win{top_left, 600, 400, "Canvas"};
  win.set_label("Canvas");

  Point origin{0, 0};
  int board(9);
  int max(150);
  Vector_ref<Rectangle> vr;
  for (int i(0); i < 9; ++i)
  {
    Rectangle *r = new Rectangle{origin, 50, 50};
    origin.x = increase(origin.x, 50);

    if (origin.x == max)
    {
      origin.x = 0;
      origin.y = increase(origin.y, 50);
    }
    vr.push_back(r);
    if (i % 2)
    {
      vr[i].set_color(Color::red);
      vr[i].set_fill_color(Color::red);
    }
    else
    {
      vr[i].set_color(Color::white);
      vr[i].set_fill_color(Color::white);
    }
    
    win.attach(vr[i]);
  }

  win.wait_for_button(); //give control to the display engine
}
int increase(int origin, int amounts)
{
  if (amounts <= 0)
    throw std::runtime_error("negative argument. Expect 0 < amounts");

  return origin + amounts;
}
