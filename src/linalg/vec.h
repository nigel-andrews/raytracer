#pragma once

#include <array>

namespace raytracer::linalg
{
    template <typename T>
    concept Number = std::is_floating_point_v<T> || std::is_integral_v<T>;

    template <typename T, unsigned N>
    struct vec
    {
        static_assert(N > 1);
        std::array<T, N> data;
    };

    template <Number T>
    struct typed_vec2
    {
        union
        {
            vec<T, 2> data;
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

        static_assert(sizeof(data) == sizeof(T) * 2);
    };

    template <Number T>
    struct typed_vec3
    {
        union
        {
            vec<T, 3> data;
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

        static_assert(sizeof(data) == sizeof(T) * 3);
    };

    template <Number T>
    struct typed_vec4
    {
        union
        {
            vec<T, 4> data;
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

        static_assert(sizeof(data) == sizeof(T) * 4);
    };
} // namespace raytracer::linalg
