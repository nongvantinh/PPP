#include "Simple_window.h" // get access to our window library
#include "Graph.h"
// get access to our graphics library facilities
int main()
{
    using namespace Graph_lib;
    Point tl{100, 100};
    // our graphics facilities are in Graph_lib
    // to become top left corner of window
    Simple_window win{tl, 600, 400, "Canvas"};
    Polygon poly;
    // make a simple window
    // make a shape (a polygon)
    poly.add(Point{300, 200});
    poly.add(Point{350, 100});
    poly.add(Point{400, 200}); // add a point
    // add another point
    // add a third point
    poly.set_color(Color::red); // adjust properties of poly
    win.attach(poly);           // connect poly to the window
    win.wait_for_button();
    // give control to the display engine
}