#pragma once

#include "vec3.h"
#include <iostream>


// class Color : vec3
// {
// public:
//     // getters
//     double r() const { return elems_[0]; }
//     double g() const { return elems_[1]; }
//     double b() const { return elems_[2]; }
// };

using color=vec3;

inline void writeColor(std::ostream& out, color pixelColor)
{
    auto r = pixelColor.x();
    auto g = pixelColor.y();
    auto b = pixelColor.z();

    int r_int = r*255;
    int g_int = g*255;
    int b_int = b*255;

    out << r_int << ' ' << g_int << ' ' << b_int << "\n";

}

