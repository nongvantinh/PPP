#include <FL/Fl.H>
#include <FL/Fl_Box.H>
#include <Fl/Fl_Window.H>

int main()
{
    Fl_Window window(200, 200, "Window title");
    Fl_Box box(0, 0, 200, 200, "Hey, I mean, Hello, World!");
    window.show();
    // window.hide();
    Fl::redraw();
    // while (true)
        Fl::wait();
    // return Fl::run();
}