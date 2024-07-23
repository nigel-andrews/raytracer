#pragma once

#include "vec.h"

namespace
{
    using namespace raytracer::linalg;

    template <typename T, unsigned N, typename BinOp>
    inline vec<T, N> astract_binop(const vec<T, N>& lhs, const vec<T, N>& rhs,
                                   BinOp op)
    {
        static_assert(N > 4);
        vec<T, N> result;

        for (auto i = 0; i < N; ++i)
        {
            result.storage[i] = op(lhs[i], rhs[i]);
        }

        result;
    }
} // namespace

namespace raytracer::linalg
{
    template <typename T, unsigned N>
    inline vec<T, N> vec<T, N>::operator+(const vec& rhs)
    {
        return abstract_binop(*this, rhs, [](T a, T b) { return a + b; });
    }

    template <typename T, unsigned N>
    inline vec<T, N> vec<T, N>::operator-(const vec& rhs)
    {
        return abstract_binop(*this, rhs, [](T a, T b) { return a - b; });
    }

    template <typename T, unsigned N>
    inline float vec<T, N>::operator*(const vec& rhs)
    {
        return abstract_binop(*this, rhs, [](T a, T b) { return a * b; });
    }

    template <typename T, unsigned N>
    inline vec<T, N> vec<T, N>::operator/(const vec& rhs)
    {
        return abstract_binop(*this, rhs, [](T a, T b) { return a / b; });
    }

    template <typename T, unsigned N>
    inline vec<T, N>& vec<T, N>::operator+=(const vec& rhs)
    {
        for (auto i = 0; i < N; ++i)
        {
            storage[i] += rhs.storage[i];
        }
    }

    template <typename T, unsigned N>
    inline vec<T, N>& vec<T, N>::operator-=(const vec& rhs)
    {
        for (auto i = 0; i < N; ++i)
        {
            storage[i] -= rhs.storage[i];
        }
    }

    template <typename T, unsigned N>
    inline vec<T, N>& vec<T, N>::operator*=(const vec& rhs)
    {
        for (auto i = 0; i < N; ++i)
        {
            storage[i] *= rhs.storage[i];
        }
    }

    template <typename T, unsigned N>
    inline vec<T, N>& vec<T, N>::operator/=(const vec& rhs)
    {
        for (auto i = 0; i < N; ++i)
        {
            storage[i] /= rhs.storage[i];
        }
    }
} // namespace raytracer::linalg
