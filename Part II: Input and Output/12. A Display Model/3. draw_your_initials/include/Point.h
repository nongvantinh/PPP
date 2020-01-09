
//
// This is a GUI support code to the chapters 12-16 of the book
// "Programming -- Principles and Practice Using C++" by Bjarne Stroustrup
//

#ifndef POINT_GUARD
#define POINT_GUARD

namespace Graph_lib
{
//------------------------------------------------------------------------------

struct Point
{
    int x, y;
    Point(int xx, int yy) : x(xx), y(yy) {}
    Point() : x(0), y(0) {}
    //
    Point &operator+=(Point d)
    {
        x += d.x;
        y += d.y;
        return *this;
    }
    Point &operator+(int pixels)
    {
        x += pixels;
        y += pixels;
        return *this;
    }

    Point &operator+(Point pixels)
    {
        x += pixels.x;
        y += pixels.y;
        return *this;
    }
};

//------------------------------------------------------------------------------

inline bool operator==(Point a, Point b) { return a.x == b.x && a.y == b.y; }

//------------------------------------------------------------------------------

inline bool operator!=(Point a, Point b) { return !(a == b); }

//------------------------------------------------------------------------------

} // namespace Graph_lib
#endif // POINT_GUARD
