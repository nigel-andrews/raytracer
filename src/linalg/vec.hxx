#pragma once

#include "vec.h"

namespace
{
    using namespace raytracer::linalg;

    template <typename T, unsigned N, typename BinOp>
    constexpr inline vector_storage<T, N>
    compwise_binop(const vector_storage<T, N>& lhs,
                   const vector_storage<T, N>& rhs, BinOp op)
    {
        vector_storage<T, N> result;

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
    constexpr inline vector_storage<T, N>
    vector_storage<T, N>::operator+(const vector_storage& rhs)
    {
        return compwise_binop(*this, rhs,
                              [](T a, T b) mutable { return a + b; });
    }

    template <typename T, unsigned N>
    constexpr inline vector_storage<T, N>
    vector_storage<T, N>::operator-(const vector_storage& rhs)
    {
        return compwise_binop(*this, rhs, [](T a, T b) { return a - b; });
    }

    template <typename T, unsigned N>
    constexpr inline vector_storage<T, N>
    vector_storage<T, N>::operator*(const vector_storage& rhs)
    {
        return compwise_binop(*this, rhs, [](T a, T b) { return a * b; });
    }

    template <typename T, unsigned N>
    constexpr inline vector_storage<T, N>
    vector_storage<T, N>::operator*(float scalar)
    {
        vector_storage<T, N> result = *this;
        for (std::size_t i = 0; i < N; ++i)
        {
            result.storage[i] *= scalar;
        }

        return result;
    }

    template <typename T, unsigned N>
    constexpr inline vector_storage<T, N>
    vector_storage<T, N>::operator/(const vector_storage& rhs)
    {
        return compwise_binop(*this, rhs, [](T a, T b) { return a / b; });
    }

    template <typename T, unsigned N>
    constexpr inline vector_storage<T, N>&
    vector_storage<T, N>::operator+=(const vector_storage& rhs)
    {
        for (std::size_t i = 0; i < N; ++i)
        {
            storage[i] += rhs.storage[i];
        }

        return *this;
    }

    template <typename T, unsigned N>
    constexpr inline vector_storage<T, N>&
    vector_storage<T, N>::operator-=(const vector_storage& rhs)
    {
        for (std::size_t i = 0; i < N; ++i)
        {
            storage[i] -= rhs.storage[i];
        }

        return *this;
    }

    template <typename T, unsigned N>
    constexpr inline vector_storage<T, N>&
    vector_storage<T, N>::operator*=(const vector_storage& rhs)
    {
        for (std::size_t i = 0; i < N; ++i)
        {
            storage[i] *= rhs.storage[i];
        }

        return *this;
    }

    template <typename T, unsigned N>
    constexpr inline vector_storage<T, N>&
    vector_storage<T, N>::operator/=(const vector_storage& rhs)
    {
        for (std::size_t i = 0; i < N; ++i)
        {
            storage[i] /= rhs.storage[i];
        }

        return *this;
    }

    template <typename T, unsigned N>
    constexpr inline vector_storage<T, N>&
    vector_storage<T, N>::operator*=(float scalar)
    {
        for (std::size_t i = 0; i < N; ++i)
        {
            storage[i] *= scalar;
        }

        return *this;
    }

    template <typename T, unsigned N>
    constexpr T& vector_storage<T, N>::operator[](unsigned long index)
    {
        return storage[index];
    }

    template <typename T, unsigned N>
    constexpr const T&
    vector_storage<T, N>::operator[](unsigned long index) const
    {
        return storage[index];
    }
} // namespace raytracer::linalg
