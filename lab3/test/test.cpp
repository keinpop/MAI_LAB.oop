#include "../header/square.h"
#include "../header/triangle.h"
#include "../header/octagon.h"
#include "../header/arrayFig.h"
#include "../header/figure.h"

#include <gtest/gtest.h>

TEST(test_00, SquareConstructorTest)
{
    std::vector<Coord> test1;
    Coord s1 = {6, 2};
    Coord s2 = {2, 6};
    Coord s3 = {-2, 2};
    Coord s4 = {2, -2};
    test1.push_back(s1);
    test1.push_back(s2);
    test1.push_back(s3);
    test1.push_back(s4);
    Square sq(test1);
    Square sq1(test1);
    ASSERT_TRUE(sq == sq1);
}

TEST(test_01, TriangleConstructorTest)
{
    std::vector<Coord> test1;
    Coord t1 = {0, 0};
    Coord t2 = {1, 0};
    Coord t3 = {0.5, sqrt(3)/2};
    test1.push_back(t1);
    test1.push_back(t2);
    test1.push_back(t3);
    Triangle tr(test1);
    Square tr1(test1);
    ASSERT_TRUE(tr == tr1);
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}