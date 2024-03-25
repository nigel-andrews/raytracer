#include "sphere.h"

#include <cmath>

std::optional<float> Sphere::cast_ray(const Ray& ray) const
{
    Vec3 oc = ray.origin - this->position_;

    float a = std::pow(ray.direction.norm(), 2);
    float b = 2.f * (oc * ray.direction);
    float c = std::pow(oc.norm(), 2) - std::pow(this->radius_, 2);

    float discriminant = b * b - 4.f * a * c;

    if (discriminant < 0.f)
        return std::nullopt;

    auto t1 = (-b - std::sqrt(discriminant)) / (2.f * a);
    auto t2 = (-b + std::sqrt(discriminant)) / (2.f * a);

    return t1 < t2 ? t1 : t2;
}

inline Vec3 Sphere::normal_get(const Vec3& point) const
{
    return Vec3::unit(point - this->position_);
}
