
#include <catch2/catch_template_test_macros.hpp>
#include <catch2/catch_approx.hpp>

#include "attitude_propagation.hpp"

using namespace Catch;
using namespace ahrs;
using mathtypes = std::tuple<float, double>;


TEMPLATE_LIST_TEST_CASE( "Attitude is propaged", "[ahrs]", mathtypes ) 
{
    Quaternion<TestType> q{1.0, 0.0, 0.0};
    Vector<TestType, 3> omega{0.1, 0.0, 0.0};

    propagate_attitude(q, omega, static_cast<TestType>(0.1));

    REQUIRE( q.w == Approx(0.99997500) );
    REQUIRE( q.x == Approx(0.00499988) );
    REQUIRE( q.y == Approx(0.0) );
    REQUIRE( q.z == Approx(0.0) );
}
