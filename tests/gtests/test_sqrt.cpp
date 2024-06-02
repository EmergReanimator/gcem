// Step 1. Include necessary header files such that the stuff your
// test logic needs is declared.
//
// Don't forget gtest.h, which declares the testing framework.


#include "tests/gtests/test_sqrt.hpp"
#include "tests/gtests/types.h"
#include "tests/gcem_tests.hpp"


using ::testing::Matcher;
using ::testing::NanSensitiveDoubleEq;


namespace {

// Step 2. Use the TEST macro to define your tests.
//
// TEST has two parameters: the test case name and the test name.
// After using the macro, you should define your test logic between a
// pair of braces.  You can use a bunch of macros to indicate the
// success or failure of a test.  EXPECT_TRUE and EXPECT_EQ are
// examples of such macros.  For a complete list, see gtest.h.
//
// <TechnicalDetails>
//
// In Google Test, tests are grouped into test cases.  This is how we
// keep test code organized.  You should put logically related tests
// into the same test case.
//
// The test case name and the test name should both be valid C++
// identifiers.  And you should not use underscore (_) in the names.
//
// Google Test guarantees that each test you define is run exactly
// once, but it makes no guarantee on the order the tests are
// executed.  Therefore, you should write your tests in such a way
// that their results don't depend on their order.
//
// </TechnicalDetails>


// Tests some method here.
TEST_F(test_sqrt, long_double_0_5)
{
    long double y = gcem::sqrt(0.5L);
    long double ref = std::sqrt(0.5L);

#if (false)
    EXPECT_LONG_DOUBLE_EQ(y, ref);
#else
    EXPECT_NEAR(y, ref, TEST_ERR_TOL);
#endif
}


TEST_F(test_sqrt, long_double_0_00199900000000000208)
{
    long double y = gcem::sqrt(0.00199900000000000208L);
    long double ref = std::sqrt(0.00199900000000000208L);

#if (false)
    EXPECT_LONG_DOUBLE_EQ(y, ref);
#else
    EXPECT_NEAR(y, ref, TEST_ERR_TOL);
#endif
}


TEST_F(test_sqrt, long_double_1_5)
{
    long double y = gcem::sqrt(1.5L);
    long double ref = std::sqrt(1.5L);

#if (false)
    EXPECT_LONG_DOUBLE_EQ(y, ref);
#else
    EXPECT_NEAR(y, ref, TEST_ERR_TOL);
#endif
}


TEST_F(test_sqrt, long_double_2_0)
{
    long double y = gcem::sqrt(2.0L);
    long double ref = std::sqrt(2.0L);

#if (false)
    EXPECT_LONG_DOUBLE_EQ(y, ref);
#else
    EXPECT_NEAR(y, ref, TEST_ERR_TOL);
#endif
}


TEST_F(test_sqrt, long_double_41_5)
{
    long double y = gcem::sqrt(41.5L);
    long double ref = std::sqrt(41.5L);

#if (false)
    EXPECT_LONG_DOUBLE_EQ(y, ref);
#else
    EXPECT_NEAR(y, ref, TEST_ERR_TOL);
#endif
}


TEST_F(test_sqrt, long_double_123456789_5)
{
    long double y = gcem::sqrt(123456789.5L);
    long double ref = std::sqrt(123456789.5L);

#if (false)
    EXPECT_LONG_DOUBLE_EQ(y, ref);
#else
    EXPECT_NEAR(y, ref, TEST_ERR_TOL);
#endif
}


TEST_F(test_sqrt, long_double_0_0)
{
    long double y = gcem::sqrt(0.0L);
    long double ref = std::sqrt(0.0L);

    EXPECT_NEAR(y, ref, TEST_ERR_TOL);
}


TEST_F(test_sqrt, long_double_neg_1_0)
{
    long double y = gcem::sqrt(-1.0L);
    long double ref = std::sqrt(-1.0L);

    typedef std::tuple<long double, long double> Tpl;
    Matcher<const Tpl&> m = NanSensitiveDoubleEq();

    EXPECT_TRUE(m.Matches(Tpl(y, ref)));
}


TEST_F(test_sqrt, long_double_1e_neg_500)
{
    long double y = gcem::sqrt(1e-500L);
    long double ref = std::sqrt(1e-500L);

#if (false)
    EXPECT_LONG_DOUBLE_EQ(y, ref);
#else
    EXPECT_NEAR(y, ref, TEST_ERR_TOL);
#endif
}


TEST_F(test_sqrt, long_double_x_0_5)
{
    const long double x = 0.5L;

    long double y = gcem::sqrt(x);
    long double ref = std::sqrt(x);

#if (false)
    EXPECT_LONG_DOUBLE_EQ(y, ref);
#else
    EXPECT_NEAR(y, ref, TEST_ERR_TOL);
#endif
}


TEST_F(test_sqrt, double_0_5)
{
    double y = gcem::sqrt(0.5);
    double ref = std::sqrt(0.5);

    EXPECT_DOUBLE_EQ(y, ref);
}


TEST_F(test_sqrt, float_0_5)
{
    float y = gcem::sqrt(0.5f);
    float ref = std::sqrt(0.5f);

    EXPECT_FLOAT_EQ(y, ref);
}


}  // namespace

// Step 3. Call RUN_ALL_TESTS() in main().
//
// We do this by linking in src/gtest_main.cc file, which consists of
// a main() function which calls RUN_ALL_TESTS() for us.
//
// This runs all the tests you've defined, prints the result, and
// returns 0 if successful, or 1 otherwise.
//
// Did you notice that we didn't register the tests?  The
// RUN_ALL_TESTS() macro magically knows about all the tests we
// defined.  Isn't this convenient?
