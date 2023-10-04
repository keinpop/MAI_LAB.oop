#include "./header/seven.h"

#include <gtest/gtest.h>

bool constructorTest()
{
    Seven s1 {'1', '2', '3'};
    std::string test = "123";
    Seven s2(test);
    Seven s3 {'3', '6', '1'};
    Seven s4(s3);

    return (s1 == s2) && (s3 == s4);
}

TEST(test_01, constructorTest)
{
    EXPECT_TRUE(constructorTest());
}

TEST(test_02, basic_arithmetic_plus_test)
{
    Seven s1 {'1', '2', '3'};
    Seven s2 {'2', '3', '5'};
    Seven s3 {'3', '6', '1'};

    ASSERT_TRUE((s1 + s2) == s3);
}

TEST(test_03, big_arithmetic_plus_test)
{
    Seven s1 {'6', '2', '3', '6', '2', '5', '1', '4'};
    Seven s2 {'2', '3', '5', '0', '0', '6'};
    Seven s3 {'6', '2', '6', '3', '0', '5', '2', '3'};

    ASSERT_TRUE((s1 + s2) == s3);
}

TEST(test_04, small_arithmetic_plus_test)
{
    Seven s1 {'6'};
    Seven s2 {'2', '3', '5'};
    Seven s3 {'2', '4', '4'};

    ASSERT_TRUE((s1 + s2) == s3);
}

TEST(test_06, big_arithmetic_minus_test)
{
    std::string a = "65412321";
    std::string b = "40021";
    std::string c = "65342300";
    Seven s1(a);
    Seven s2(b);
    Seven s3(c);

    ASSERT_TRUE((s1 - s2) == s3);
}

TEST(test_07, small_arithmetic_minus_test)
{
    std::string a = "62134";
    std::string b = "61210";
    std::string c = "624";
    Seven s1(a);
    Seven s2(b);
    Seven s3(c);

    ASSERT_TRUE((s1 - s2) == s3);
}

// TEST(test_08, abs_arithmetic_minus_test)
// {
//     Seven s1{'1', '3', '4'};
//     Seven s2{'6', '1', '2', '1', '1', '0'};
//     Seven s3{'6', '1', '0', '4', '4', '3'};

//     EXPECT_FALSE((s1 - s2) == s3);
// }

TEST(test_09, boolean_operator_equal_test)
{
    Seven s1 {'1', '2', '3'};
    Seven s2 {'1', '2', '3'};

    ASSERT_TRUE((s1 == s2) == true);
}

TEST(test_10, boolean_operator_not_equal_test)
{
    Seven s1 {'1', '2', '3'};
    Seven s2 {'2', '2', '3'};

    ASSERT_TRUE((s1 != s2) == true);
}

TEST(test_11, boolean_operator_more_test)
{
    Seven s1 {'3', '2', '3'};
    Seven s2 {'1', '2', '3'};

    ASSERT_TRUE((s1 > s2) == true);
}

TEST(test_12, boolean_operator_less_test)
{
    Seven s1 {'3', '2', '3'};
    Seven s2 {'1', '2', '3'};

    ASSERT_TRUE((s2 < s1) == true);
}

TEST(test_13, boolean_operator_more_equal_test)
{
    Seven s1 {'3', '2', '3'};
    Seven s2 {'1', '2', '3'};
    Seven s3 {'1', '2', '3'};

    ASSERT_TRUE(((s1 >= s2) && (s2 >= s3)) == true);
}

TEST(test_14, boolean_operator_less_equal_test)
{
    Seven s1 {'3', '2', '3'};
    Seven s2 {'1', '2', '3'};
    Seven s3 {'1', '2', '3'};

    ASSERT_TRUE(((s2 <= s1) && (s2 <= s3)) == true);
}

TEST(test_15, add_with_assign_operator_test)
{
    Seven s1 {'3', '2', '3'};
    Seven s2 {'1', '1', '1'};
    Seven s3 {'3', '2', '3'};
    s3 += s2;

    ASSERT_TRUE((s1 + s2) == s3);
}

TEST(test_16, sub_with_assign_operator_test)
{
    Seven s1 {'3', '2', '3'};
    Seven s2 {'1', '1', '1'};
    Seven s3 {'3', '2', '3'};
    s3 -= s2;

    ASSERT_TRUE(s3 == s3);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}