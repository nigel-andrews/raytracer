#pragma once

#include <vector>

#include "geometry/vector.h"
#include "objects/sphere.h"

class Camera
{
public:
    Camera() = delete;
    Camera(float near, float fov, const Vec3& position,
           const Vec3& view_direction, const Vec3& up);

    void look_at(const Vec3& target);
    void shoot_rays(int width, int height,
                    const std::vector<Sphere>& objects) const;

    float near_get() const
    {
        return this->near_;
    }

    const Vec3& position_get() const
    {
        return this->position_;
    }

    const Vec3& view_direction_get() const
    {
        return this->view_direction_;
    }

private:
    float near_;
    float fov_;

    Vec3 position_;
    Vec3 view_direction_;
    Vec3 up_;
};
