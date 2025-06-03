#pragma once
#include <cmath>
#include <iostream>

class vec3
{

public:

    // constructors
    vec3() : elems_{0,0,0} {};
    vec3(double elem0, double elem1, double elem2) : elems_{elem0,elem1,elem2} {};

    // getters
    double x() const { return elems_[0]; }
    double y() const { return elems_[1]; }
    double z() const { return elems_[2]; }

    vec3 operator-() const { return vec3(-elems_[0], -elems_[1], -elems_[2]); }
    double operator[](int indx) const { return elems_[indx]; }
    double& operator[](int indx) { return elems_[indx]; }

    vec3& operator+=(const vec3& v)
    {
        elems_[0]+=v[0];
        elems_[1]+=v[1];
        elems_[2]+=v[2];
        return *this;
    }

    vec3& operator*=(double t)
    {
        elems_[0]*=t;
        elems_[1]*=t;
        elems_[2]*=t;
        return *this;
    }

    vec3& operator/=(double t)
    {
        return *this *= 1/t;
    }

    double lengthSquared() const
    {
        return elems_[0]*elems_[0] + elems_[1]*elems_[1] + elems_[2]*elems_[2];
    }

    double length() const
    {
        return std::sqrt(lengthSquared());
    }



protected:
    // internal elements
    double elems_[3];

};

using point3 = vec3;

// utility functions
inline std::ostream& operator<<(std::ostream& out, const vec3& v)
{
    return out << v[0] << ' ' << v[1] << ' ' << v[2];
}

inline vec3 operator+(vec3 u, vec3 v)
{
    return vec3(
        u[0]+v[0],
        u[1]+v[1],
        u[2]+v[2]
    );
}

inline vec3 operator-(vec3 u, vec3 v)
{
    return vec3(
        u[0]-v[0],
        u[1]-v[1],
        u[2]-v[2]
    );
}

inline vec3 operator*(vec3 v, double t)
{
    return vec3(
        v[0]*t,
        v[1]*t,
        v[2]*t
    );
}

inline vec3 operator*(double t, vec3 v)
{
    return v*t;
}

inline vec3 operator/(vec3 v, double t)
{
    return v * (1/t);
}

inline double dot(vec3 u, vec3 v)
{
    return
    (
        u[0]*v[0]+
        u[1]*v[1]+
        u[2]*v[2]
    );
}

inline vec3 cross(const vec3& u, const vec3& v)
{
    return vec3
    (
        u[1] * v[2] - u[2] * v[1],
        u[2] * v[0] - u[0] * v[2],
        u[0] * v[1] - u[1] * v[0]
    );
}

inline vec3 normalized(const vec3& v)
{
    return v/v.length();
}




