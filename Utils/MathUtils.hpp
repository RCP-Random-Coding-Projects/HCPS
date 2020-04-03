#pragma once

#include <cmath>

namespace MathUtils
{
    class Vector
    {
    public:
        double x, y;
        Vector();
        Vector(double x, double y);
        double mag();
        Vector normalize();
    };

    Vector operator+(const Vector & u, const Vector & v);
    Vector operator-(const Vector & u, const Vector & v);
    Vector operator*(const Vector & u, const double & a);
    Vector operator*(const double & a, const Vector & u);
    double operator*(const Vector & u, const Vector & v);
    Vector operator/(const Vector & u, const double & a);
    Vector operator>>(Vector & u, Vector & v);

    double vectorMag(Vector v);
    Vector vectorAdd(Vector v1, Vector v2);
    Vector vectorSub(Vector v1, Vector v2);
    Vector normalize(Vector v);
    Vector vectorScale(Vector v, double a);
    double vectorDot(Vector v1, Vector v2);
    Vector vectorProj(Vector v1, Vector v2);
    Vector intersect(Vector p1, Vector v1, Vector p2, Vector v2);

}
