#pragma once

#include <memory>
#include <vector>

#include "object/shape.h"

namespace raytracer
{
    class scene
    {
        std::vector<std::unique_ptr<object::shape>> shapes_;
    };
} // namespace raytracer
