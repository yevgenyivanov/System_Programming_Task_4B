#include "Point.hpp"
#include <iostream>
#include <string>
#include <cmath>
constexpr int one = 1;
Point::Point(double _recv_x, double _recv_y) : _x_coordinate(_recv_x), _y_coordinate(_recv_y){}
double Point::distance(const Point &other) const
{
    double delta_x = (this->_x_coordinate - other._x_coordinate);
    double delta_y = (this->_y_coordinate - other._y_coordinate);
    return std::sqrt((delta_x * delta_x) + (delta_y * delta_y));
}
std::string Point::print()
{
    // std::cout<< '(' <<this->_x_coordinate << ',' << this->_y_coordinate << ')' << std::endl;
    return "(" + std::to_string(this->_x_coordinate) + ", " + std::to_string(this->_y_coordinate) + ")";
}
// pain in the ass
Point Point::moveTowards(Point &_source, Point &_dest, double _dist)
{
    if (_dist < 0)
        throw std::invalid_argument("Distance cannot be negative.");
    // taken from: https://math.stackexchange.com/questions/175896/finding-a-point-along-a-line-a-certain-distance-away-from-another-point
    double slope = (_dest.get_y() - _source.get_y()) / (_dest.get_x() - _source.get_x()),
           _distRatio = _dist / _source.distance(_dest);
    double _x_res = (one - _distRatio) * _source._x_coordinate + _distRatio * _dest._x_coordinate,
           _y_res = (one - _distRatio) * _source._y_coordinate + _distRatio * _dest._y_coordinate;
    return Point(_x_res, _y_res);
}

double Point::get_x()
{
    return this->_x_coordinate;
}

double Point::get_y()
{
    return this->_y_coordinate;
}