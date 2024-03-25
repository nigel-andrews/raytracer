#pragma once

#include "geometry/vector.h"

struct Ray
{
    Ray(const Vec3& origin, const Vec3& direction)
        : origin(origin)
        , direction(direction)
    {}

    Vec3 operator[](float t) const
    {
        return origin + (direction * t);
    }

    Vec3 origin;
    Vec3 direction;
};
