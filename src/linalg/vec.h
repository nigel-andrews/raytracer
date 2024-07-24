#pragma once

#include <array>

namespace raytracer::linalg
{
    template <typename T>
    concept Number = std::is_floating_point_v<T> || std::is_integral_v<T>;

    template <typename T, unsigned N>
    struct vec
    {
        typedef T value_type;

        static_assert(N > 1);
        std::array<T, N> storage;

        template <typename... Ts>
        vec(Ts... args)
            : storage({ args... })
        {}

        vec() = default;

        constexpr vec operator+(const vec& rhs);

        constexpr vec operator-(const vec& rhs);
        constexpr vec operator*(const vec& rhs);
        constexpr vec operator*(float scalar);
        constexpr vec operator/(const vec& rhs);

        constexpr vec& operator+=(const vec& rhs);
        constexpr vec& operator-=(const vec& rhs);
        constexpr vec& operator*=(const vec& rhs);
        constexpr vec& operator*=(float scalar);
        constexpr vec& operator/=(const vec& rhs);

        constexpr T& operator[](unsigned long index);
        constexpr const T& operator[](unsigned long index) const;
    };

    template <Number T>
    struct typed_vec2
    {
        typed_vec2()
            : data{}
        {}

        typed_vec2(const vec<T, 2>& rhs)
            : data{ rhs }
        {}

        typed_vec2(T val)
            : data{ val, val }
        {}

        typed_vec2(T x, T y)
            : data{ x, y }
        {}

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

        constexpr typed_vec2 operator+(const typed_vec2& rhs)
        {
            return data + rhs.data;
        }

        constexpr typed_vec2 operator-(const typed_vec2& rhs)
        {
            return data - rhs.data;
        }

        constexpr typed_vec2 operator*(const typed_vec2& rhs)
        {
            return data * rhs.data;
        }

        constexpr typed_vec2 operator*(float scalar)
        {
            return data * scalar;
        }

        constexpr typed_vec2 operator/(const typed_vec2& rhs)
        {
            return data / rhs;
        }

        constexpr typed_vec2& operator+=(const typed_vec2& rhs)
        {
            data += rhs.data;
            return *this;
        }

        constexpr typed_vec2& operator-=(const typed_vec2& rhs)
        {
            data -= rhs.data;
            return *this;
        }

        constexpr typed_vec2& operator*=(const typed_vec2& rhs)
        {
            data *= rhs.data;
            return *this;
        }

        constexpr typed_vec2& operator*=(float scalar)
        {
            data *= scalar;
            return *this;
        }

        constexpr typed_vec2& operator/=(const typed_vec2& rhs)
        {
            data /= rhs.data;
            return *this;
        }

        constexpr T& operator[](unsigned long index)
        {
            return data[index];
        }

        constexpr const T& operator[](unsigned long index) const
        {
            return data[index];
        }

        static_assert(sizeof(data) == sizeof(T) * 2);
    };

    template <Number T>
    struct typed_vec3
    {
        typed_vec3()
            : data{}
        {}

        typed_vec3(const vec<T, 3>& rhs)
            : data{ rhs }
        {}

        typed_vec3(T val)
            : data{ val, val, val }
        {}

        typed_vec3(T x, T y, T z)
            : data{ x, y, z }
        {}

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

        constexpr typed_vec3 operator+(const typed_vec3& rhs)
        {
            return data + rhs.data;
        }

        constexpr typed_vec3 operator-(const typed_vec3& rhs)
        {
            return data - rhs.data;
        }

        constexpr typed_vec3 operator*(const typed_vec3& rhs)
        {
            return data * rhs.data;
        }

        constexpr typed_vec3 operator*(float scalar)
        {
            return data * scalar;
        }

        constexpr typed_vec3 operator/(const typed_vec3& rhs)
        {
            return data / rhs;
        }

        constexpr typed_vec3& operator+=(const typed_vec3& rhs)
        {
            data += rhs.data;
            return *this;
        }

        constexpr typed_vec3& operator-=(const typed_vec3& rhs)
        {
            data -= rhs.data;
            return *this;
        }

        constexpr typed_vec3& operator*=(const typed_vec3& rhs)
        {
            data *= rhs.data;
            return *this;
        }

        constexpr typed_vec3& operator*=(float scalar)
        {
            data *= scalar;
            return *this;
        }

        constexpr typed_vec3& operator/=(const typed_vec3& rhs)
        {
            data /= rhs.data;
            return *this;
        }

        constexpr T& operator[](unsigned long index)
        {
            return data[index];
        }

        constexpr const T& operator[](unsigned long index) const
        {
            return data[index];
        }

        static_assert(sizeof(data) == sizeof(T) * 3);
    };

    template <Number T>
    struct typed_vec4
    {
        typed_vec4()
            : data{}
        {}

        typed_vec4(const vec<T, 4>& rhs)
            : data{ rhs }
        {}

        typed_vec4(T val)
            : data{ val, val, val, val }
        {}

        typed_vec4(T x, T y, T z, T w)
            : data{ x, y, z, w }
        {}

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

        constexpr typed_vec4 operator+(const typed_vec4& rhs)
        {
            return data + rhs.data;
        }

        constexpr typed_vec4 operator-(const typed_vec4& rhs)
        {
            return data - rhs.data;
        }

        constexpr typed_vec4 operator*(const typed_vec4& rhs)
        {
            return data * rhs.data;
        }

        constexpr typed_vec4 operator*(float scalar)
        {
            return data * scalar;
        }

        constexpr typed_vec4 operator/(const typed_vec4& rhs)
        {
            return data / rhs;
        }

        constexpr typed_vec4& operator+=(const typed_vec4& rhs)
        {
            data += rhs.data;
            return *this;
        }

        constexpr typed_vec4& operator-=(const typed_vec4& rhs)
        {
            data -= rhs.data;
            return *this;
        }

        constexpr typed_vec4& operator*=(const typed_vec4& rhs)
        {
            data *= rhs.data;
            return *this;
        }

        constexpr typed_vec4& operator*=(float scalar)
        {
            data *= scalar;
            return *this;
        }

        constexpr typed_vec4& operator/=(const typed_vec4& rhs)
        {
            data /= rhs.data;
            return *this;
        }

        constexpr T& operator[](unsigned long index)
        {
            return data[index];
        }

        constexpr const T& operator[](unsigned long index) const
        {
            return data[index];
        }

        static_assert(sizeof(data) == sizeof(T) * 4);
    };
} // namespace raytracer::linalg

#include "vec.hxx"
