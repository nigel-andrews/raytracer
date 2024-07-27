#pragma once

#include "linalg/vec_fwd.h"

namespace raytracer
{
    struct camera
    {
        vec3f position;
        float fov;
        point3f target;
    };
} // namespace raytracer
