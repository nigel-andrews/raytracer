#pragma once

#include <type_traits>

#include "vec.h"

namespace raytracer::linalg
{
    template <typename T>
    concept FloatingPoint = std::is_floating_point_v<T>;

    template <FloatingPoint T, unsigned N>
    constexpr T dot(const vector_storage<T, N>& a,
                    const vector_storage<T, N>& b)
    {
        T acc = 0;

        for (std::size_t i = 0; i < N; ++i)
        {
            acc += a.storage[i] * b.storage[i];
        }

        return acc;
    }

    template <FloatingPoint T>
    constexpr T dot(const typed_vec2<T>& a, const typed_vec2<T>& b)
    {
        return a.data.storage[0] * b.data.storage[0]
            + a.data.storage[1] * b.data.storage[1];
    }

    template <FloatingPoint T>
    constexpr T dot(const typed_vec3<T>& a, const typed_vec3<T>& b)
    {
        return a.data.storage[0] * b.data.storage[0]
            + a.data.storage[1] * b.data.storage[1]
            + a.data.storage[2] * b.data.storage[2];
    }

    template <FloatingPoint T>
    constexpr T dot(const typed_vec4<T>& a, const typed_vec4<T>& b)
    {
        return a.data.storage[0] * b.data.storage[0]
            + a.data.storage[1] * b.data.storage[1]
            + a.data.storage[2] * b.data.storage[2]
            + a.data.storage[3] * b.data.storage[3];
    }
} // namespace raytracer::linalg
