#include "eub.h"

#include <gtest/gtest.h>

TEST(test_01, basic_test_set)
{
    ASSERT_TRUE(eliminateUnsetBits("11101")==15);
}

TEST(test_02, big_empty_enter)
{
    ASSERT_TRUE(eliminateUnsetBits("   ")==-1);
}

TEST(test_03, many_zero_some_one)
{
    ASSERT_TRUE(eliminateUnsetBits("10000001")==3);
}

TEST(test_04, basic_test_out_of_bounds)
{
    ASSERT_TRUE(eliminateUnsetBits("1010101011101001010101010")==-1);
}

TEST(test_05, zero_enter)
{
    ASSERT_TRUE(eliminateUnsetBits("000")==0);
}

TEST(test_06, one_enter)
{
    ASSERT_TRUE(eliminateUnsetBits("1")==1);
}

TEST(test_07, zero_start_to_number)
{
    ASSERT_TRUE(eliminateUnsetBits("000000000000111")==7);
}

TEST(test_08, null_enter)
{
    ASSERT_TRUE(eliminateUnsetBits("")==-1);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}