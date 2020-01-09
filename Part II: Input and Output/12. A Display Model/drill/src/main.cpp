#include "Simple_window.h"
#include "Graph.h"

int main()
{
  using namespace Graph_lib; //our graphics facilities are in Graph_lib (defined in Graph.h)

  Point top_left{500, 100}; //will be top left corner of window

  Simple_window win{top_left, 600, 400, "Canvas"};
  win.set_label("Canvas");

  Axis xa{Axis::x, Point{20, 300}, 280, 10, "x axis"};
  win.set_label("Canbas #2");
  win.attach(xa);

  Axis ya{Axis::y, Point{20, 300}, 280, 10, "y axis"};
  ya.set_color(Color::red);
  ya.label.set_color(Color::cyan);
  win.attach(ya);
  win.set_label("Canvas #3");

  Function sine{sin, 0, 100, Point{20, 150}, 1000, 50, 50};
  win.attach(sine);
  win.set_label("Canvas #4");

  Polygon poly; //make a shape a polygon
  //add some points, set color of poly
  poly.add(Point{300, 200});
  poly.add(Point{350, 100});
  poly.add(Point{400, 200});
  poly.set_color(Color::red);
  poly.set_style(Line_style(Line_style::dash, 4));
  win.attach(poly); //attach poly to window
  win.set_label("Canvas #5");

  Rectangle r{Point{200, 200}, 100, 50};
  r.set_fill_color(Color::yellow);
  win.attach(r);
  win.set_label("Canvas #6");

  Closed_polyline poly_rect;
  poly_rect.add(Point{100, 50});
  poly_rect.add(Point{200, 50});
  poly_rect.add(Point{200, 100});
  poly_rect.add(Point{100, 100});
  poly_rect.set_style(Line_style(Line_style::dash, 2));
  poly_rect.set_fill_color(Color::green);
  win.attach(poly_rect);
  win.set_label("Canvas #7");
  poly_rect.add(Point{50, 75});

  Text t{Point{150, 150}, "Hello, graphical world!"};
  win.attach(t);
  win.set_label("Canvas #8");
  t.set_font(Graph_lib::Font::times_bold);
  t.set_font_size(20);
  win.set_label("Canvas #9");

  Image ii{Point{100, 50}, "images/image.jpg"};
  win.attach(ii);
  win.set_label("Canvas #10");
  ii.move(100, 200);
  win.set_label("Canvas #11");

  Circle c{Point{100, 200}, 50};
  Ellipse e{Point{100, 200}, 75, 25};
  e.set_color(Color::dark_red);
  Mark m{Point{100, 200}, 'x'};

  ostringstream oss;
  oss << "screen size: " << x_max() << y_max()
      << "; window size: " << win.x_max() << "*" << win.y_max();
  Text sizes{Point{100, 20}, oss.str()};
  sizes.set_style(Line_style::dashdotdot);
  Image cal{Point{225, 225}, "images/snow_cpp.gif"};
  cal.set_mask(Point{40, 40}, 200, 150);
  sizes.set_color(Color::magenta);
  
  win.attach(c);
  win.attach(m);
  win.attach(e);
  win.attach(sizes);
  win.attach(cal);
  win.set_label("Canvas #12");
  win.wait_for_button(); //give control to the display engine
}
