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
}
