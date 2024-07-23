#include <catch2/catch_test_macros.hpp>

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
    vec<float, 5> wow{ 1.f, 2.f, 3.f, 4.f, 5.f };
    REQUIRE(wow.storage.size() == 5);
    REQUIRE(wow[4] == 5.f);
}
