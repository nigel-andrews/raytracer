#include "sphere.h"

bool Sphere::is_intersecting(const Ray& ray) const
{
    Vec3 oc = ray.origin - this->position_;
    const auto& ray_direction = ray.direction;
    float a = ray_direction * ray_direction;
    float b = 2.f * (oc * ray.direction);
    float c = oc * oc - (this->radius_ * this->radius_);

    return b * b - 4 * a * c >= 0;
}
