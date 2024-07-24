#include <catch2/catch_test_macros.hpp>

#include "linalg/functions.h"
#include "linalg/vec_fwd.h"

using namespace raytracer::linalg;

TEST_CASE("Basic vector instantiation", "[vec]")
{
    vec2 two;
    vec3 three;
    vec4 four;

    CHECK(two.x == 0);
    CHECK(two.y == 0);

    CHECK(three.x == 0);
    CHECK(three.y == 0);
    CHECK(three.z == 0);

    CHECK(four.x == 0);
    CHECK(four.y == 0);
    CHECK(four.z == 0);
    CHECK(four.w == 0);

    CHECK(two.data.storage.size() == 2);
    CHECK(three.data.storage.size() == 3);
    CHECK(four.data.storage.size() == 4);

    CHECK(sizeof(two) == sizeof(double) * 2);
    CHECK(sizeof(three) == sizeof(double) * 3);
    CHECK(sizeof(four) == sizeof(double) * 4);
}

TEST_CASE("Anonymous union access", "[vec]")
{
    vec3f v{ 1.f, 2.f, 3.f };

    CHECK(v.x == v.r);
    CHECK(v.y == v.g);
    CHECK(v.z == v.b);
}

TEST_CASE("Generic vector", "[vec]")
{
    vector_storage<float, 5> wow{ 1.f, 2.f, 3.f, 4.f, 5.f };
    CHECK(wow.storage.size() == 5);
    CHECK(wow[4] == 5.f);
}

TEST_CASE("BinOp", "[vec]")
{
    vec3f one{ 1.f };
    vec3f two{ 2.f };

    vec3f three = one + two;

    CHECK(three.x == 3.f);
    CHECK(three.y == 3.f);
    CHECK(three.z == 3.f);
}

TEST_CASE("BinOp-equal", "[vec]")
{
    vec3f one{ 1.f };
    vec3f two{ 2.f };

    one /= two;

    CHECK(one.r == 0.5f);
    CHECK(one.g == 0.5f);
    CHECK(one.b == 0.5f);
}

TEST_CASE("Scale factor", "[vec]")
{
    vec4i two{ 2 };

    vec4i four = two * 2;

    CHECK(four[0] == 4);
    CHECK(four[1] == 4);
    CHECK(four[2] == 4);
    CHECK(four[3] == 4);
}

TEST_CASE("Modify value in place", "[vec]")
{
    vec3 test;
    test[0] = 1.f;
    test[1] = 0.f;
    test[2] = -1.f;

    // This test just needs to compile
    CHECK(test[0] == 1.f);
    CHECK(test[1] == 0.f);
    CHECK(test[2] == -1.f);
}

TEST_CASE("Dot product", "[functions]")
{
    vec2f u{ 8.f, 9.f };
    vec2f v{ -1.f, 1.f };

    CHECK(dot(u, v) == 1.f);

    vec3f a{ 1.f, 2.f, 3.f };
    vec3f b{ 4.f, 0.f, 7.f };

    CHECK(dot(a, b) == 25.f);

    vec4f x{ 4.f, 5.f, 2.f, 2.f };
    vec4f y{ 8.f, -4.f, 8.f, -2.f };

    CHECK(dot(x, y) == 24.f);

    vector_storage<double, 6> meh{ 1.f, 1.f, 2.f, 2.f, 4.f, 5.f };
}
