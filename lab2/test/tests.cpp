#include "./header/seven.h"

#include <gtest/gtest.h>

bool constructorTest()
{
    Seven s1 {'1', '2', '3'};
    std::string test = "123";
    Seven s2(test);
    Seven s3 {'3', '6', '1'}, s4(s3);
    Seven s5{'0', '0', '0'}, s6("000");

    return (s1 == s2) && (s3 == s4) && (s5 == s6);
}

TEST(test_00, constructorTest)
{
    EXPECT_TRUE(constructorTest());
}

TEST(test_01, thorw_constructor_test)
{
    ASSERT_THROW(Seven s1("507"), std::range_error);
}

TEST(test_02, throw_constrctor_test)
{
    
    ASSERT_THROW(Seven s1("f&k*"), std::range_error);
}

TEST(test_03, throw_constrctor_test)
{
    std::string test = "24 1";
    
    EXPECT_THROW(Seven s1(test), std::range_error);
}

TEST(test_10, basic_arithmetic_plus_test)
{
    Seven s1 {'1', '2', '3'};
    Seven s2 {'2', '3', '5'};
    Seven s3 {'3', '6', '1'};

    ASSERT_TRUE((s1 + s2) == s3);
}

TEST(test_11, big_arithmetic_plus_test)
{
    Seven s1 {'6', '2', '3', '6', '2', '5', '1', '4'};
    Seven s2 {'2', '3', '5', '0', '0', '6'};
    Seven s3 {'6', '2', '6', '3', '0', '5', '2', '3'};

    ASSERT_TRUE((s1 + s2) == s3);
}

TEST(test_12, small_arithmetic_plus_test)
{
    Seven s1 {'6'};
    Seven s2 {'2', '3', '5'};
    Seven s3 {'2', '4', '4'};

    ASSERT_TRUE((s1 + s2) == s3);
}

TEST(test_13, zero_arithmetic_plus_test)
{
    Seven s1 {'0', '0', '0', '5'};
    Seven s2 {'2', '3', '5'};
    Seven s3("243");

    ASSERT_TRUE((s1 + s2) == s3);
}

TEST(test_20, big_arithmetic_minus_test)
{
    std::string a = "65412321";
    std::string b = "40021";
    std::string c = "65342300";
    Seven s1(a);
    Seven s2(b);
    Seven s3(c);

    ASSERT_TRUE((s1 - s2) == s3);
}

TEST(test_21, small_arithmetic_minus_test)
{
    std::string a = "62134";
    std::string b = "61210";
    std::string c = "624";
    Seven s1(a);
    Seven s2(b);
    Seven s3(c);

    ASSERT_TRUE((s1 - s2) == s3);
}

TEST(test_22, big_sub_arithmetic_minus_test)
{
    Seven s1{'1', '3', '4'};
    Seven s2{'6', '1', '2', '1', '1', '0'};

    EXPECT_THROW((s1 - s2), std::range_error);
}

TEST(test_23, big_sub_arithmetic_minus_test)
{
    Seven s1{'6', '6', '1', '0', '1', '6'};
    Seven s2{'6', '1', '6', '1', '1', '0'};
    Seven s3("41606");

    ASSERT_TRUE((s1 - s2) == s3);
}

TEST(test_30, boolean_operator_equal_test)
{
    Seven s1 {'1', '2', '3'};
    Seven s2 {'1', '2', '3'};

    ASSERT_TRUE((s1 == s2) == true);
}

TEST(test_31, boolean_operator_not_equal_test)
{
    Seven s1 {'1', '2', '3'};
    Seven s2 {'2', '2', '3'};

    ASSERT_TRUE((s1 != s2) == true);
}

TEST(test_32, boolean_operator_more_test)
{
    Seven s1 {'3', '2', '3'};
    Seven s2 {'1', '2', '3'};

    ASSERT_TRUE((s1 > s2) == true);
}

TEST(test_33, boolean_operator_less_test)
{
    Seven s1 {'3', '2', '3'};
    Seven s2 {'1', '2', '3'};

    ASSERT_TRUE((s2 < s1) == true);
}

TEST(test_34, boolean_operator_more_equal_test)
{
    Seven s1 {'3', '2', '3'};
    Seven s2 {'1', '2', '3'};
    Seven s3 {'1', '2', '3'};

    ASSERT_TRUE(((s1 >= s2) && (s2 >= s3)) == true);
}

TEST(test_35, boolean_operator_less_equal_test)
{
    Seven s1 {'3', '2', '3'};
    Seven s2 {'1', '2', '3'};
    Seven s3 {'1', '2', '3'};

    ASSERT_TRUE(((s2 <= s1) && (s2 <= s3)) == true);
}

TEST(test_40, add_with_assign_operator_test)
{
    Seven s1 {'3', '2', '3'};
    Seven s2 {'1', '1', '1'};
    Seven s3 {'3', '2', '3'};
    s3 += s2;

    ASSERT_TRUE((s1 + s2) == s3);
}

TEST(test_41, sub_with_assign_operator_test)
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