#include "sphere.h"

#include <cmath>

std::optional<float> Sphere::cast_ray(const Ray& ray) const
{
    Vec3 oc = ray.origin - this->position_;
    const auto& ray_direction = ray.direction;
    float a = ray_direction * ray_direction;
    float b = 2.f * (oc * ray.direction);
    float c = oc * oc - (this->radius_ * this->radius_);
    float determinant = b * b - 4 * a * c;

    if (determinant < 0.f)
        return std::nullopt;

    return (-b - std::sqrt(determinant)) / (2.f * a);
}
