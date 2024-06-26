#include "camera.h"

#include <format>
#include <iostream>

#include "geometry/ray.h"

Camera::Camera(float near, float fov, const Vec3& position,
               const Vec3& view_direction, const Vec3& up)
    : near_(near)
    , fov_(fov)
    , position_(position)
    , view_direction_(view_direction)
    , up_(up)
{}

void Camera::shoot_rays(int width, int height,
                        const std::vector<Sphere>& objects) const
{
    std::cout << std::format("P3\n{} {}\n255\n", width, height);

    auto viewport_width = (this->near_ * std::tan(this->fov_ / 2)) * 2;
    // TODO: compute this with tangent of next fov
    auto viewport_height = viewport_width
        * (static_cast<float>(height) / static_cast<float>(width));
    const Vec3 viewport_x{ viewport_width, 0.f, 0.f };
    const Vec3 viewport_y{ 0.f, -viewport_height, 0.f };

    Vec3 delta_x = viewport_x / width;
    Vec3 delta_y = viewport_y / height;
    // TODO: Offset to test middle of chunk
    Vec3 start = this->position_ - Vec3{ 0.f, 0.f, this->near_ }
        - (viewport_x / 2) - (viewport_y / 2);

    // TODO: Remove double loop by single loop + parallelize.
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            auto target = start + delta_x * x + delta_y * y;
            auto ray_direction = (target - this->position_).normalize();
            Ray current{ this->position_, ray_direction };

            auto a = 0.5 * (target.normalize().y() + 1.0);

            Vec3 color = Vec3(1.0) * (1.0 - a) + Vec3(0.5, 0.7, 1.0) * a;
            std::optional<std::string> line;

            float closest = -INFINITY;

            for (auto&& object : objects)
            {
                auto color = object.cast_ray(current).and_then(
                    [&object, &current, &closest](float t) {
                        if (closest != -INFINITY && t > closest)
                            return std::optional<std::string>{};

                        closest = t;

                        auto normal = object.normal_get(current[t]);

                        normal = normal / 2.f;
                        normal += { 0.5f, 0.5f, 0.5f };
                        normal *= 255.99f;

                        auto fmt = std::format("{} {} {}\n",
                                               static_cast<int>(normal.x()),
                                               static_cast<int>(normal.y()),
                                               static_cast<int>(normal.z()));

                        return std::make_optional<std::string>(fmt);
                    });

                if (!color)
                    continue;

                line = color;
            }

            std::cout << line.value_or(
                std::format("{} {} {}\n", static_cast<int>(255.999 * color.x()),
                            static_cast<int>(255.999 * color.y()),
                            static_cast<int>(255.999 * color.z())));
        }
    }
}

inline void Camera::look_at(const Vec3& target)
{
    this->view_direction_ = target.normalize();
}
