#pragma once

#include <optional>

#include "geometry/ray.h"

class IObject
{
public:
    virtual std::optional<float> cast_ray(const Ray& ray) const = 0;
    virtual Vec3 normal_get(const Vec3& point) const = 0;
};
