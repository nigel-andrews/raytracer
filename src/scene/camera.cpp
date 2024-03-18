#include "camera.h"

#include <format>
#include <iostream>

constexpr float inv_aspect_ratio = 9.f / 16.f;

Camera::Camera(float near, float fov, const Vec3& position,
               const Vec3& view_direction, const Vec3& up)
    : near_(near)
    , fov_(fov)
    , position_(position)
    , view_direction_(view_direction)
    , up_(up)
{}

void Camera::shoot_rays(int width, int height)
{
    std::cout << std::format("P3\n{} {}\n255\n", width, height);
    // Compute near plane top left

    // FIXME: this can (and probably should) be pre-computed
    auto right = Vec3{ static_cast<float>(width), 0.f, 0.f }.normalize();

    auto gx = this->near_ * std::tan(this->fov_ / 2);
    auto gy = gx * (inv_aspect_ratio);

    auto dx = right * (2 * gx / width);
    auto dy = this->up_.normalize() * (2 * gy / height);
    auto top_left = (this->view_direction_.normalize() * this->near_)
        - (right * gx) + (this->up_.normalize() * gy);

    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            auto pij = top_left + dx * x - dy * y;
            auto a = 0.5 * (pij.normalize().y() + 1.0);

            Vec3 color = Vec3(1.0) * (1.0 - a) + Vec3(0.5, 0.7, 1.0) * a;
            std::cout << static_cast<int>(255.999 * color.x()) << ' '
                      << static_cast<int>(255.999 * color.y()) << ' '
                      << static_cast<int>(255.999 * color.z()) << '\n';
        }
    }
}

void Camera::look_at(const Vec3& target)
{
    this->view_direction_ = target.normalize();
}
