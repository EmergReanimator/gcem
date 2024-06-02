/**
 * @file            test_sqrt.hpp
 *
 * @author          agum
 *
 * @date            2024-Jun-02, 11:06
 *
 * @brief           TODO: Add file description here
 *
 * @copyright       Bruker Optik GmbH & Co. KG 2024 - All rights reserved
 */


#if !defined(TESTS_GTESTS_TEST_SQRT_HPP_)
#define TESTS_GTESTS_TEST_SQRT_HPP_


#include "tests/gtests/googletest/include/gtest/gtest.h"
#include "tests/gtests/googlemock/include/gmock/gmock.h"
#include "include/gcem.hpp"


class test_sqrt : public ::testing::Test {
    protected:
        virtual void SetUp()
        {
            return;
        }

        virtual void TearDown()
        {
            return;
        }
};


#endif /* TESTS_GTESTS_TEST_SQRT_HPP_ */
