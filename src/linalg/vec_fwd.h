#pragma once

#include "vec.h"

namespace raytracer::linalg
{
#define GEN_VEC_TYPES(Type, Suffix)                                            \
    using vec2##Suffix = typed_vec2<Type>;                                     \
    using vec3##Suffix = typed_vec3<Type>;                                     \
    using vec4##Suffix = typed_vec4<Type>

    GEN_VEC_TYPES(double, );
    GEN_VEC_TYPES(long double, ld);
    GEN_VEC_TYPES(float, f);
    GEN_VEC_TYPES(int, i);
    GEN_VEC_TYPES(unsigned int, u);
    GEN_VEC_TYPES(long, l);
    GEN_VEC_TYPES(unsigned long, ul);

#undef GEN_VEC_TYPES
} // namespace raytracer::linalg
