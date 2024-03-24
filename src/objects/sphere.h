#pragma once

#include "objects/object.h"

// TODO: Make this a subclass of object
class Sphere : public IObject
{
public:
    virtual ~Sphere() = default;
    Sphere(const Vec3& position, float radius = 1.f)
        : position_(position)
        , radius_(radius)
    {}

    std::optional<float> cast_ray(const Ray& ray) const final;
    Vec3 normal_get(const Vec3& /* point */) const final
    {
        return {};
    }

    // TODO: object materials

private:
    Vec3 position_;
    float radius_;
};
