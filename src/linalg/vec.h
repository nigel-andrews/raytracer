#pragma once

#include <array>

namespace raytracer::linalg
{
    template <typename T, unsigned N>
    struct vec
    {
        static_assert(N > 1);
        std::array<T, N> data;
    };

    using vec2 = vec<double, 2>;
    using vec3 = vec<double, 3>;
    using vec4 = vec<double, 4>;

    using vec2ld = vec<long double, 2>;
    using vec3ld = vec<long double, 3>;
    using vec4ld = vec<long double, 4>;

    using vec2f = vec<float, 2>;
    using vec3f = vec<float, 3>;
    using vec4f = vec<float, 4>;

    using vec2i = vec<int, 2>;
    using vec3i = vec<int, 3>;
    using vec4i = vec<int, 4>;

    using vec2u = vec<unsigned int, 2>;
    using vec3u = vec<unsigned int, 3>;
    using vec4u = vec<unsigned int, 4>;

    using vec2ul = vec<unsigned long, 2>;
    using vec3ul = vec<unsigned long, 3>;
    using vec4ul = vec<unsigned long, 4>;

    template <typename T>
    struct vec<T, 4>
    {
        union
        {
            std::array<T, 4> data;
            struct
            {
                T x;
                T y;
                T z;
                T w;
            };
            struct
            {
                T r;
                T g;
                T b;
                T a;
            };
        };
    };

    template <typename T>
    struct vec<T, 3>
    {
        union
        {
            std::array<T, 3> data;
            struct
            {
                T x;
                T y;
                T z;
            };
            struct
            {
                T r;
                T g;
                T b;
            };
        };
    };

    template <typename T>
    struct vec<T, 2>
    {
        union
        {
            std::array<T, 2> data;
            struct
            {
                T x;
                T y;
            };
            struct
            {
                T u;
                T v;
            };
        };
    };
} // namespace raytracer::linalg
