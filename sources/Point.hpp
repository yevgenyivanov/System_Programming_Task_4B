#pragma once
#include <string>
class Point
{
private:
    double _x_coordinate;
    double _y_coordinate;

public:
    // constructor
    Point(double _x_recv = 0, double _y_recv = 0);
    // copy constructor
    Point(Point &) = default;
    // copy assignment operator
    Point &operator=(const Point &) = default;
    // move constructor
    Point(Point &&) = default;
    // move assignment operator
    Point &operator=(Point &&) = default;
    // destructor
    virtual ~Point() = default;
    //
    //funcs
    double distance(const Point &) const;
    std::string print();
    static Point moveTowards(Point &, Point &, double);
    // helper funcs
    double get_x();
    double get_y();
};

namespace ariel
{
};