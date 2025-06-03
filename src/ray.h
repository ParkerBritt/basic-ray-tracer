#pragma once

#include "vec3.h"

class ray
{
public:
    ray() {}
    ray(const vec3& origin, const vec3& direction) : orig_{origin}, dir_{direction} {}

    const vec3& origin() const { return orig_; }
    const vec3& direction() const { return dir_; }

    point3 at(double t) const
    {
        return orig_ + dir_*t;
    }

private:
    vec3 orig_;
    vec3 dir_;
};
