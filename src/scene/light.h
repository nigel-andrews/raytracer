#pragma once

#include <optional>

#include "vector.h"

struct Light
{
    Light() = delete;
    Light(const Vec3& position);
    Light(const Vec3& position, const Vec3& direction);

    Vec3 position;
    // Either a point light or a ray
    std::optional<Vec3> direction;
};
