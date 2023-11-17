#include "../include/allocator.h"
#include "../include/forward_list.h"
#include "../include/iterator_FL.h"

#include <gtest/gtest.h>
#include <map>
#include <vector>

TEST(test_00, testAllocatorBase)
{
    Allocator<int> test;
    int* ptr = test.allocate(25);
    test.deallocate(ptr, 24);
    test.allocate(1);
    test.free();

    ASSERT_TRUE(1);
}

TEST(test_01, testAllocatorManyAlloc)
{
    Allocator<double> test;
    double* ptr = test.allocate(450);
    test.allocate(300); test.allocate(300); test.allocate(300);
    test.allocate(300); test.allocate(300); test.allocate(300);
    test.allocate(300); test.allocate(300); test.allocate(300);
    test.allocate(300); test.allocate(300); test.allocate(300);
    test.allocate(300); test.allocate(300); test.allocate(300);
    test.allocate(300); test.allocate(300); test.allocate(300);
    test.free();

    ASSERT_TRUE(1);
}

TEST(test_02, testAllocatorCheckDestroy)
{
    Allocator<char> test;
    char* ptr = test.allocate(25);
    test.allocate(1); test.allocate(1); test.allocate(1);
    test.allocate(1); test.allocate(1); test.allocate(1);
    test.allocate(1); test.allocate(1); test.allocate(1);
    test.allocate(1); test.allocate(1); test.allocate(1);
    test.allocate(1); test.allocate(1); test.allocate(1);
    test.allocate(1); test.allocate(1); test.allocate(1);
    test.allocate(1); test.allocate(1); test.allocate(1);
    test.allocate(1); test.allocate(1); test.allocate(1);
    test.allocate(1); test.allocate(1); test.allocate(1);
    test.allocate(1); test.allocate(1); test.allocate(1);
    test.allocate(1); test.allocate(1); test.allocate(1);
    test.allocate(1); test.allocate(1); test.allocate(1);
    test.allocate(1); test.allocate(1); test.allocate(1);
    test.allocate(1); test.allocate(1); test.allocate(1);
    test.destroy(ptr);

    ASSERT_TRUE(1);
}

TEST(test_03, testAllocatorCheckDestructor)
{
    Allocator<char> test;
    char* ptr = test.allocate(25);
    test.allocate(1); test.allocate(1); test.allocate(1);
    test.allocate(1); test.allocate(1); test.allocate(1);
    test.allocate(1); test.allocate(1); test.allocate(1);
    test.allocate(1); test.allocate(1); test.allocate(1);
    test.allocate(1); test.allocate(1); test.allocate(1);
    test.allocate(1); test.allocate(1); test.allocate(1);
    test.allocate(1); test.allocate(1); test.allocate(1);
    test.allocate(1); test.allocate(1); test.allocate(1);
    test.allocate(1); test.allocate(1); test.allocate(1);
    test.allocate(1); test.allocate(1); test.allocate(1);
    test.allocate(1); test.allocate(1); test.allocate(1);
    test.allocate(1); test.allocate(1); test.allocate(1);
    test.allocate(1); test.allocate(1); test.allocate(1);
    test.allocate(1); test.allocate(1); test.allocate(1);
    
    ASSERT_TRUE(1);
}

TEST(test_04, testAllocatorCheck)
{
    Allocator<size_t> test;
    size_t* ptr = test.allocate(25);
    test.allocate(300); test.allocate(300); test.allocate(300);
    test.allocate(300); test.allocate(300); test.allocate(300);
    test.allocate(300); test.allocate(300); test.allocate(300);
    test.allocate(300); test.allocate(300); test.allocate(300);
    test.allocate(300); test.allocate(300); test.allocate(300);
    test.allocate(300); test.allocate(300); test.allocate(300);
    test.allocate(300); test.allocate(300); test.allocate(300);
    test.allocate(300); test.allocate(300); test.allocate(300);

    test.deallocate(ptr, 24);
    
    ASSERT_TRUE(1);
}

TEST(test_05, testAllocatorCheckToMap)
{
    std::map<int, uint64_t, std::less<uint64_t>, Allocator<std::pair<const int, uint64_t>>> test;
    for (size_t i = 0; i < 1000; ++i) {
        test[i] = i + 1;
    }

    ASSERT_TRUE(1);
}

TEST(test_06, testAllocatorCheckToVector)
{
    std::vector<int, Allocator<int>> test;
    for (size_t i = 0; i < 100; ++i) {
        test.push_back(i + 2);
    }

    ASSERT_TRUE(1);
}

TEST(test_07, testIteratorFLBegin)
{
    Forward_List<int> test{1, 2, 3, 4};
    std::begin(test);
    Iterator<int> it = test.begin();

    ASSERT_TRUE(std::begin(test) == it);
}

TEST(test_08, testIteratorFLEnd)
{
    Forward_List<int> test{1, 2, 3};
    std::end(test);
    Iterator<int> it = test.end();

    ASSERT_TRUE(std::end(test) == it);
}

TEST(test_09, testIteratorFLOperatorStars)
{
    Forward_List<int> test{1, 2, 3};
    Iterator<int> it = test.begin();
    std::begin(test);

    ASSERT_TRUE(*std::begin(test) == *it);
}

TEST(test_10, testIteratorFLOperatorPlus)
{
    Forward_List<int> test{1, 2, 3};
    Iterator<int> it = test.begin() + 2;

    ASSERT_TRUE(*(std::begin(test) + 2) == *it);
}

TEST(test_11, testIteratorFLOperatorEqual)
{
    Forward_List<int> test{1, 2, 3};
    Iterator<int> it = test.begin();
    Iterator<int> itCopy = test.begin();

    ASSERT_TRUE(itCopy == it);
}

TEST(test_12, testIteratorFLOperatorUnequal)
{
    Forward_List<int> test{1, 2, 3};
    Iterator<int> it = test.begin();
    Iterator<int> itCopy = test.begin();
    ++itCopy;

    ASSERT_TRUE(itCopy != it);
}

TEST(test_13, testConstIteratorFLBegin)
{
    Forward_List<int> test{1, 2, 3, 4};
    ConstIterator<int> it = test.CBegin();

    ASSERT_TRUE(*std::cbegin(test) == *it);
}

TEST(test_14, testConstIteratorFLEnd)
{
    Forward_List<int> test{1, 2, 3};
    ConstIterator<int> it = test.CEnd();
    ConstIterator<int> itCopy = test.CEnd();

    ASSERT_TRUE(itCopy == it);
}

TEST(test_15, testConstIteratorFLOperatorStars)
{
    Forward_List<int> test{1, 2, 3};
    ConstIterator<int> it = test.CBegin();
    std::cbegin(test);

    ASSERT_TRUE(*std::begin(test) == *it);
}

TEST(test_16, testIteratorFLOperatorPlus)
{
    Forward_List<int> test{1, 2, 3};
    ConstIterator<int> it = test.CBegin() + 2;

    ASSERT_TRUE(*(std::cbegin(test) + 2) == *it);
}

TEST(test_17, testConstIteratorFLOperatorEqual)
{
    Forward_List<int> test{1, 2, 3};
    ConstIterator<int> it = test.CBegin();
    ConstIterator<int> itCopy = test.CBegin();

    ASSERT_TRUE(itCopy == it);
}

TEST(test_18, testConstIteratorFLOperatorUnequal)
{
    Forward_List<int> test{1, 2, 3};
    ConstIterator<int> it = test.CBegin();
    ConstIterator<int> itCopy = ++test.CBegin();

    ASSERT_TRUE(itCopy != it);
}

TEST(test_19, testForwardListConstructorInt)
{
    Forward_List<int> l1;
    Forward_List<int> l11;
    Forward_List<int> l2(3, 3);
    Forward_List<int> l3{3, 3, 3};
    Forward_List<int> l4{1, 2, 3, 4 , 5};
    Forward_List<int> l5(l4);
    Forward_List<int> l6(std::move(l4));
    
    ASSERT_TRUE((l1.size() == l1.size()) &&  
                (*l2.begin() == *l3.begin()) && 
                (*l5.begin() == *l6.begin()));
}

TEST(test_20, testForwardListConstructorUChar)
{
    Forward_List<unsigned char> l1;
    Forward_List<unsigned char> l11;
    Forward_List<unsigned char> l2('1', 3);
    Forward_List<unsigned char> l3{'1', '1', '1'};
    Forward_List<unsigned char> l4{'1', '2', '3'};
    Forward_List<unsigned char> l5(l4);
    Forward_List<unsigned char> l6(std::move(l4));
    
    ASSERT_TRUE((l1.size() == l1.size()) &&  
                (*l2.begin() == *l3.begin()) && 
                (*l5.begin() == *l6.begin()));
}

TEST(test_21, testForwardListSize)
{
    Forward_List<int> l1{1, 2, 3, 4, 5};
    Forward_List<int> l2;

    ASSERT_TRUE((l1.size() == 5) && (l2.size() == 0));
}

TEST(test_22, testForwardListEmpty)
{
    Forward_List<int> l1{1, 2, 3, 4, 5};
    Forward_List<int> l2;

    ASSERT_TRUE(!(l1.empty()) && l2.empty());
}

TEST(test_23, testForwardListPushFront)
{
    Forward_List<int> l1;
    Forward_List<unsigned char> l2;

    l1.pushFront(5);
    l2.pushFront('5');
    l1.pushFront(4);
    l2.pushFront('4');
    l1.pushFront(3);
    l2.pushFront('3');

    l1.popFront(); l2.popFront();

    l1.pushFront(3); l2.pushFront('3');

    l1.popFront(); l2.popFront();

    l1.popFront(); l2.popFront();
    
    l1.pushFront(3); l2.pushFront('3');

    ASSERT_TRUE((l2.size() == 2) && (*l1.begin() == 3));
}

TEST(test_24, testForwardListEmplaceFront)
{
    Forward_List<int> l1;
    Forward_List<unsigned char> l2;

    l1.emplaceFront(1);             l2.emplaceFront('1');
    l1.emplaceFront(1, 2, 3, 4, 5); l2.emplaceFront('1', '2', '3', '4', '5');
    l1.popFront();                  l2.popFront();
    l1.emplaceFront(1, 2, 3, 4);    l2.emplaceFront('1', '2', '3', '4');
    l1.popFront();                  l2.popFront();
    l1.popFront();                  l2.popFront();
    l1.popFront();                  l2.popFront();
    l1.popFront();                  l2.popFront();
    l1.emplaceFront(1);             l2.emplaceFront('1');
    l1.pushFront(123);              l2.pushFront('0');
    l1.emplaceFront(1, 2, 3, 4, 5); l2.emplaceFront('1', '2', '3', '4', '5');
    
    ASSERT_TRUE((l1.size() == 12) && (l2.size() == 12));
}

TEST(test_25, testForwardListPopFrontException)
{
    Forward_List<int> l1;

    ASSERT_THROW(l1.popFront(), std::length_error);
}

TEST(test_26, testForwardListPopFront)
{
    Forward_List<int> l1;
    Forward_List<unsigned char> l2;

    l1.emplaceFront(1, 2, 3, 4, 5); l2.emplaceFront('1', '2', '3', '4', '5');
    l1.popFront();                  l2.popFront();
    l1.popFront();                  l2.popFront();
    l1.popFront();                  l2.popFront();
    l1.popFront();                  l2.popFront();
    l1.pushFront(1);                l2.pushFront('1');
    l1.popFront();                  l2.popFront();
    l1.emplaceFront(1, 1, 1, 1, 1); l2.emplaceFront('1', '1', '1', '1', '1');
    l1.popFront();                  l2.popFront();
    l1.popFront();                  l2.popFront();
    l1.popFront();                  l2.popFront();
    l1.popFront();                  l2.popFront();
    l1.popFront();                  l2.popFront();

    ASSERT_TRUE((l1.size() == 1) && (l2.size() == 1));
}

TEST(test_26, testForwardListClear)
{
    Forward_List<int> l1 {1, 2, 3, 4, 5};
    Forward_List<unsigned char> l2 {1, 2, 3, 4, 5};
    l1.clear();      l2.clear();
    l1.pushFront(1); l2.pushFront(1);
    l1.clear();      l2.clear();
    l1.pushFront(1); l2.pushFront(1);
    l1.pushFront(1); l2.pushFront(1);
    l1.pushFront(1); l2.pushFront(1);
    l1.popFront();   l2.popFront();
    l1.clear();      l2.clear();
    
    ASSERT_TRUE((l1.size() == 0) && (l2.size() == 0));
}

int main(int argc, char** argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}