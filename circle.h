#pragma once
#include "point.h"
// kör típusa, minden amit hazsnlok a point.h ban le van írva
class Circle
{
    private:
        Point _c;
        double  _r;
    public:
        Circle(){}
        Circle(const Point &p, double d) : _c(p), _r(d) {}
        bool in(const Point &p) const {
            return _c.distance(p) <= _r;
        }
};
