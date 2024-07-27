#pragma once

#include "linalg/vec_fwd.h"

namespace raytracer::object
{
    // TODO: replace this with compile-time polymorphism to see
    // if perf ?
    //
    // template <typename T>
    // concept Intersectable = ...;
    //
    // template <Intersectable... Shapes>
    // struct shape
    // {
    //    // Do stuff ...
    //
    //    std::variant<Shapes...> object;
    // }
    //
    //
    struct shape
    {
        virtual rgb intersect() = 0;
    };
} // namespace raytracer::object
