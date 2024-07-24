#include <catch2/catch_test_macros.hpp>

#include "linalg/functions.h"
#include "linalg/vec_fwd.h"

TEST_CASE("Basic vector instantiation", "[vec]")
{
    using namespace raytracer::linalg;

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

    REQUIRE(two.data.storage.size() == 2);
    REQUIRE(three.data.storage.size() == 3);
    REQUIRE(four.data.storage.size() == 4);

    REQUIRE(sizeof(two) == sizeof(double) * 2);
    REQUIRE(sizeof(three) == sizeof(double) * 3);
    REQUIRE(sizeof(four) == sizeof(double) * 4);
}

TEST_CASE("Anonymous union access", "[vec]")
{
    using namespace raytracer::linalg;

    vec3f v{ 1.f, 2.f, 3.f };

    REQUIRE(v.x == v.r);
    REQUIRE(v.y == v.g);
    REQUIRE(v.z == v.b);
}

TEST_CASE("Generic vector", "[vec]")
{
    vector_storage<float, 5> wow{ 1.f, 2.f, 3.f, 4.f, 5.f };
    REQUIRE(wow.storage.size() == 5);
    REQUIRE(wow[4] == 5.f);
}

TEST_CASE("BinOp", "[vec]")
{
    vec3f one{ 1.f };
    vec3f two{ 2.f };

    vec3f three = one + two;

    REQUIRE(three.x == 3.f);
    REQUIRE(three.y == 3.f);
    REQUIRE(three.z == 3.f);
}

TEST_CASE("BinOp-equal", "[vec]")
{
    vec3f one{ 1.f };
    vec3f two{ 2.f };

    one /= two;

    REQUIRE(one.r == 0.5f);
    REQUIRE(one.g == 0.5f);
    REQUIRE(one.b == 0.5f);
}

TEST_CASE("Scale factor", "[vec]")
{
    vec4i two{ 2 };

    vec4i four = two * 2;

    REQUIRE(four[0] == 4);
    REQUIRE(four[1] == 4);
    REQUIRE(four[2] == 4);
    REQUIRE(four[3] == 4);
}

TEST_CASE("Modify value in place", "[vec]")
{
    vec3 test;
    test[0] = 1.f;
    test[1] = 0.f;
    test[2] = -1.f;

    // This test just needs to compile
    REQUIRE(test[0] == 1.f);
    REQUIRE(test[1] == 0.f);
    REQUIRE(test[2] == -1.f);
}

TEST_CASE("Dot product", "[functions]")
{
    vec3f a{ 1.f, 2.f, 3.f };
    vec3f b{ 4.f, 0.f, 7.f };
}
