#pragma once

#include "linalg/vec_fwd.h"

namespace raytracer
{
    struct ray
    {
        point3f origin;
        vec3f direction;
    };
}; // namespace raytracer
