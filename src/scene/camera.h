#pragma once

#include "vector.h"

class Camera
{
public:
    Camera() = default;
    Camera(float near, float fov_x, float fov_y, const Vec3& position,
           const Vec3& view_direction, const Vec3& up);

    void look_at(const Vec3& target);
    void shoot_rays(int width, int height);

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
    float fov_x_;
    float fov_y_;

    Vec3 position_;
    Vec3 view_direction_;
    Vec3 up_;
};
