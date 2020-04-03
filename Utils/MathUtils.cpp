#include "MathUtils.hpp"
#include <math.h>

namespace MathUtils
{
    double vectorMag(Vector v)
    {
        return std::sqrt(v.x*v.x + v.y*v.y);
    }

    Vector vectorAdd(Vector v1, Vector v2)
    {
        Vector newVector;
        newVector.x = v1.x + v2.x;
        newVector.y = v1.y + v2.y;
        return newVector;
    }

    Vector vectorSub(Vector v1, Vector v2)
    {
        Vector newVector;
        newVector.x = v1.x - v2.x;
        newVector.y = v1.y - v2.y;
        return newVector;

    }

    Vector normalize(Vector v)
    {   
        double mag = vectorMag(v);
        v.x /= mag;
        v.y /= mag;
        return v;
    }

    Vector vectorScale(Vector v, double a)
    {
        v.x *= a;
        v.y *= a;
        return v;
    }

    double vectorDot(Vector v1, Vector v2)
    {
        return v1.x*v2.x + v1.y*v2.y;
    }

    Vector vectorProj(Vector v1, Vector v2)
    {
        return vectorScale(normalize(v2),vectorDot(v1,v2)/vectorMag(v2));
    }

    Vector intersect(Vector p1, Vector v1, Vector p2, Vector v2)
    {
        Vector p;
        p.x  = (p2.y - p1.y + v1.y/v1.x*p1.x - v2.y/v2.x*p2.x) / (v1.y/v1.x - v2.y/v2.x);
        p.y = p1.y/p1.x * (p.x - p1.x) + p1.y;
        return p;
    }

    // Vector's constructors
    Vector::Vector(): x{0}, y{0} {}
    Vector::Vector(double x, double y): x{x}, y{y} {}

    double Vector::mag(){
        return sqrt((this->x)*(this->x)+(this->y)*(this->y));
    }

    Vector Vector::normalize(){
        return Vector(this->x, this->y)/this->mag();
    }

    Vector operator+(const Vector & u, const Vector & v)
    {
        return Vector(u.x+v.x, u.y+v.y);
    }
    
    Vector operator-(const Vector & u, const Vector & v)
    {
        return Vector(u.x-v.x, u.y-v.y);
    }

    Vector operator*(const double & a, const Vector & u)
    {
        return Vector(a*u.x, a*u.y);
    }

    Vector operator*(const Vector & u, const double & a)
    {
        return Vector(a*u.x, a*u.y);
    }

    double operator*(const Vector & u, const Vector & v)
    {
        return u.x*v.x+u.y*v.y;
    }

    Vector operator/(const Vector & u, const double & a){
        return Vector(u.x/a, u.y/a);
    }
    
    Vector operator>>(Vector & u, Vector & v){
        return v.normalize()*(u*v)/v.mag();
    }

}