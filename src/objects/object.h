#pragma once

#include "geometry/ray.h"

class IObject
{
public:
    virtual bool is_intersecting(const Ray& ray) const = 0;
    virtual Vec3 normal_get(const Vec3& point) const = 0;
};
