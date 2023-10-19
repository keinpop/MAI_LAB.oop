#include "../src/figure.cpp"

#include <gtest/gtest.h>

bool constructorTest()
{
    Figure f1;
    std::vector<Coord> test1;
    Figure f2(test1);

    std::vector<Coord> test2;
    for (size_t i = 0; i < 5; ++i) {
        Coord test;
        test.x = i;
        test.y = i + 1;
        test2.push_back(test);
    }
    Figure f3(test2);
    Figure f33(test2);
    Figure f4(f3);
    Figure f5(std::move(f33));

    return (f1 == f2) && (f3 == f4) && (f5 == f3);
}

TEST(test_00, constructorTest)
{
    EXPECT_TRUE(constructorTest());
}

// TEST(test_10, constructorTest)
// {
    
// }

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}