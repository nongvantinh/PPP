#include "Simple_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;
    Point tl{100, 100};
    Simple_window win {tl,600,400,"My Window"};
    win.wait_for_button();
}