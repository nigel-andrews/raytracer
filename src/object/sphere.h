#pragma once

#include "shape.h"

namespace raytracer::object
{
    struct sphere : shape
    {
        point3f position;
        float radius;
    };
} // namespace raytracer::object
