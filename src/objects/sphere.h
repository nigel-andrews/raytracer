#pragma once

#include "geometry/vector.h"

// TODO: Make this a subclass of object
class Sphere
{
    Sphere(const Vec3& position, float radius = 1.f)
        : position_(position)
        , radius_(radius)
    {}

    bool intersect(const Vec3& ray) const;
    Vec3 normal_get(const Vec3& point) const;

    // TODO: object materials

private:
    Vec3 position_;
    float radius_;
};
