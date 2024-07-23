#pragma once

#include "vec.h"

namespace
{
    using namespace raytracer::linalg;

    template <typename T, unsigned N, typename BinOp>
    constexpr inline vec<T, N> compwise_binop(const vec<T, N>& lhs,
                                              const vec<T, N>& rhs, BinOp op)
    {
        vec<T, N> result;

        for (std::size_t i = 0; i < N; ++i)
        {
            result.storage[i] = op(lhs[i], rhs[i]);
        }

        return result;
    }
} // namespace

namespace raytracer::linalg
{
    template <typename T, unsigned N>
    constexpr inline vec<T, N> vec<T, N>::operator+(const vec& rhs)
    {
        return compwise_binop(*this, rhs,
                              [](T a, T b) mutable { return a + b; });
    }

    template <typename T, unsigned N>
    constexpr inline vec<T, N> vec<T, N>::operator-(const vec& rhs)
    {
        return compwise_binop(*this, rhs, [](T a, T b) { return a - b; });
    }

    template <typename T, unsigned N>
    constexpr inline vec<T, N> vec<T, N>::operator*(const vec& rhs)
    {
        return compwise_binop(*this, rhs, [](T a, T b) { return a * b; });
    }

    template <typename T, unsigned N>
    constexpr inline vec<T, N> vec<T, N>::operator*(float scalar)
    {
        vec<T, N> result = *this;
        for (std::size_t i = 0; i < N; ++i)
        {
            result.storage[i] *= scalar;
        }

        return result;
    }

    template <typename T, unsigned N>
    constexpr inline vec<T, N> vec<T, N>::operator/(const vec& rhs)
    {
        return compwise_binop(*this, rhs, [](T a, T b) { return a / b; });
    }

    template <typename T, unsigned N>
    constexpr inline vec<T, N>& vec<T, N>::operator+=(const vec& rhs)
    {
        for (std::size_t i = 0; i < N; ++i)
        {
            storage[i] += rhs.storage[i];
        }

        return *this;
    }

    template <typename T, unsigned N>
    constexpr inline vec<T, N>& vec<T, N>::operator-=(const vec& rhs)
    {
        for (std::size_t i = 0; i < N; ++i)
        {
            storage[i] -= rhs.storage[i];
        }

        return *this;
    }

    template <typename T, unsigned N>
    constexpr inline vec<T, N>& vec<T, N>::operator*=(const vec& rhs)
    {
        for (std::size_t i = 0; i < N; ++i)
        {
            storage[i] *= rhs.storage[i];
        }

        return *this;
    }

    template <typename T, unsigned N>
    constexpr inline vec<T, N>& vec<T, N>::operator/=(const vec& rhs)
    {
        for (std::size_t i = 0; i < N; ++i)
        {
            storage[i] /= rhs.storage[i];
        }

        return *this;
    }

    template <typename T, unsigned N>
    constexpr inline vec<T, N>& vec<T, N>::operator*=(float scalar)
    {
        for (std::size_t i = 0; i < N; ++i)
        {
            storage[i] *= scalar;
        }

        return *this;
    }

    template <typename T, unsigned N>
    constexpr T& vec<T, N>::operator[](unsigned long index)
    {
        return storage[index];
    }

    template <typename T, unsigned N>
    constexpr const T& vec<T, N>::operator[](unsigned long index) const
    {
        return storage[index];
    }
} // namespace raytracer::linalg
