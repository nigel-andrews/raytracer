#include "camera.h"

#include <format>
#include <iostream>

#include "geometry/ray.h"

constexpr float inv_aspect_ratio = 9.f / 16.f;

Camera::Camera(float near, float fov, const Vec3& position,
               const Vec3& view_direction, const Vec3& up)
    : near_(near)
    , fov_(fov)
    , position_(position)
    , view_direction_(view_direction)
    , up_(up)
{}

void Camera::shoot_rays(int width, int height,
                        const std::vector<Sphere>& objects)
{
    std::cout << std::format("P3\n{} {}\n255\n", width, height);

    auto viewport_width = (this->near_ * std::tan(this->fov_ / 2)) * 2;
    auto viewport_height = viewport_width * inv_aspect_ratio;
    const Vec3 viewport_x{ viewport_width, 0.f, 0.f };
    const Vec3 viewport_y{ 0.f, -viewport_height, 0.f };

    Vec3 delta_x = viewport_x / width;
    Vec3 delta_y = viewport_y / height;
    // TODO: Offset to test middle of chunk
    Vec3 start = this->position_ + Vec3{ 0.f, 0.f, this->near_ }
        - (viewport_x / 2) - (viewport_y / 2);

    std::string str;
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            auto target = start + delta_x * x + delta_y * y;
            auto ray_direction = (target - this->position_).normalize();
            Ray current{ this->position_, ray_direction };

            auto a = 0.5 * (target.normalize().y() + 1.0);

            Vec3 color = Vec3(1.0) * (1.0 - a) + Vec3(0.5, 0.7, 1.0) * a;
            str =
                std::format("{} {} {}\n", static_cast<int>(255.999 * color.x()),
                            static_cast<int>(255.999 * color.y()),
                            static_cast<int>(255.999 * color.z()));

            for (const Sphere& object : objects)
                if (object.is_intersecting(current))
                    str = std::format("{} {} {}\n", 255, 255, 255);

            std::cout << str;
        }
    }
}

void Camera::look_at(const Vec3& target)
{
    this->view_direction_ = target.normalize();
}
