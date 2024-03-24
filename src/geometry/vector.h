#pragma once

#include <cmath>
#include <ostream>
#ifdef __cpp_lib_print
#    include <print>
#else
#    include <format>
#endif // ! __cpp_lib_print

class Vec3
{
public:
    Vec3() = default;

    explicit constexpr Vec3(float value)
        : x_(value)
        , y_(value)
        , z_(value)
    {}

    constexpr Vec3(float x, float y, float z)
        : x_(x)
        , y_(y)
        , z_(z)
    {}

    static Vec3 unit(const Vec3& v)
    {
        return v / v.norm();
    }

    float norm() const
    {
        return std::sqrt(this->x_ * this->x_ + this->y_ * this->y_
                         + this->z_ * this->z_);
    }

    Vec3 normalize() const
    {
        float len = this->norm();

        return { this->x_ / len, this->y_ / len, this->z_ / len };
    }

    Vec3 operator+(const Vec3& rhs) const
    {
        return { this->x_ + rhs.x_, this->y_ + rhs.y_, this->z_ + rhs.z_ };
    }

    Vec3 operator-() const
    {
        return { -this->x_, -this->y_, -this->z_ };
    }

    Vec3 operator-(const Vec3& rhs) const
    {
        return *this + -rhs;
    }

    Vec3& operator+=(const Vec3& rhs)
    {
        this->x_ += rhs.x_;
        this->y_ += rhs.y_;
        this->z_ += rhs.z_;

        return *this;
    }

    Vec3& operator-=(const Vec3& rhs)
    {
        *this += -rhs;

        return *this;
    }

    float operator*(const Vec3& rhs) const
    {
        return this->x_ * rhs.x_ + this->y_ * rhs.y_ + this->z_ * rhs.z_;
    }

    Vec3 operator*(float l) const
    {
        return { this->x_ * l, this->y_ * l, this->z_ * l };
    }

    Vec3 operator/(float l) const
    {
        return *this * (1.f / l);
    }

    Vec3& operator*=(float l)
    {
        this->x_ *= l;
        this->y_ *= l;
        this->z_ *= l;

        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Vec3& rhs)
    {
#ifdef __cpp_lib_print
        std::print(os,
#else // ! __cpp_lib_print
        os << std::format(
#endif // __cpp_lib_print
                   "({}, {}, {})", rhs.x_, rhs.y_, rhs.z_);

        return os;
    }

    float x() const
    {
        return this->x_;
    }

    float y() const
    {
        return this->y_;
    }

    float z() const
    {
        return this->z_;
    }

private:
    float x_;
    float y_;
    float z_;
};
