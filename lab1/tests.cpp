#include "./header/eub.h"

#include <gtest/gtest.h>

TEST(test_01, basic_test_set)
{
    std::string test = "11101";
    ASSERT_TRUE(eliminateUnsetBits(test)==15);
}

TEST(test_02, big_empty_enter)
{
    std::string test = "   ";
    ASSERT_TRUE(eliminateUnsetBits(test)==-1);
}

TEST(test_03, many_zero_some_one)
{
    std::string test = "10000001";
    ASSERT_TRUE(eliminateUnsetBits(test)==3);
}

TEST(test_04, basic_test_out_of_bounds)
{
    std::string test = "111111111111111111111111111111111";
    ASSERT_TRUE(eliminateUnsetBits(test)==-1);
}

TEST(test_05, zero_enter)
{
    std::string test = "000";
    ASSERT_TRUE(eliminateUnsetBits(test)==0);
}

TEST(test_06, one_enter)
{
    std::string test = "1";
    ASSERT_TRUE(eliminateUnsetBits(test)==1);
}

TEST(test_07, zero_start_to_number)
{
    std::string test = "000000000000111";
    ASSERT_TRUE(eliminateUnsetBits(test)==7);
}

TEST(test_08, null_enter)
{
    std::string test = "";
    ASSERT_TRUE(eliminateUnsetBits(test)==-1);
}

TEST(test_09, max_number_before_out_of_bounds)
{
    std::string test = "11111111111111111111111111111111";
    ASSERT_TRUE(eliminateUnsetBits(test)==4294967295);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}