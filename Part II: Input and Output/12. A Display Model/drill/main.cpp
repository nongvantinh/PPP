#include "Simple_window.h"
#include "Graph.h"

int main()
{
  try
  {
    Point top_left{500, 100}; //will be top left corner of window

    Simple_window win{top_left, 600, 400, "My Window"};

    Axis xa{Axis::x, Point{20, 300}, 280, 10, "x axis"};
    win.attach(xa);

    Axis ya{Axis::y, Point{20, 300}, 280, 10, "y axis"};
    ya.set_color(Color::cyan);
    ya.label.set_color(Color::dark_red);

    Function sine{sin, 0, 100, Point{20, 150}, 1000, 50, 50}; // sine curve.
    sine.set_color(Color::blue);

    Polygon poly;
    poly.add(Point{300, 200});
    poly.add(Point{350, 100});
    poly.add(Point{400, 200});
    poly.set_color(Color::red);
    poly.set_style(Line_style::dash);

    Rectangle r{Point{200, 200}, 100, 50};
    r.set_fill_color(Color::yellow);
    r.set_style(Line_style(Line_style::dashdot, 4));

    Closed_polyline poly_rect;
    poly_rect.add(Point{100, 50});
    poly_rect.add(Point{200, 50});
    poly_rect.add(Point{200, 100});
    poly_rect.add(Point{100, 100});
    poly_rect.add(Point{50, 75});
    poly_rect.set_fill_color(Color::green);

    Text t{Point{150, 150}, "Hello, graphical world!"};
    t.set_font(Graph_lib::Font::times_bold);
    t.set_font_size(31);

    Image im{Point{100, 50}, "image.jpg"};
    im.move(100, 200);

    Circle c{Point{100, 200}, 50};
    Ellipse e{Point{100, 200}, 75, 25};
    e.set_color(Color::dark_blue);
    Mark m{Point{100, 200}, 'x'};

    std::ostringstream oss;
    oss << "screen size: " << x_max() << '*' << y_max()
    << "; window size: " << win.x_max() << '*' << win.y_max();
    Text size{Point{100,20}, oss.str()};
    Image cal{Point{225,225}, "snow_cpp.gif"};
    cal.set_mask(Point{40,40},200,150);

    win.attach(c);
    win.attach(m);
    win.attach(cal);
    win.attach(e);
    win.attach(size);
    win.attach(cal);
    win.attach(im);
    win.attach(t);
    win.attach(poly_rect);
    win.attach(r);
    win.attach(poly);
    win.attach(sine);
    win.attach(xa);
    win.attach(ya);
    win.set_label("Canvas #2");

    win.wait_for_button(); //give control to the display engine

    using namespace Graph_lib; //our graphics facilities are in Graph_lib (defined in Graph.h)
  }
  catch (const std::exception &e)
  {
    std::cerr << e.what() << '\n';
  }
}
