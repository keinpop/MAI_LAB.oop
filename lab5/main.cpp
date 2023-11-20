#include "./include/allocator.h"
#include "./include/forward_list.h"
#include <map>

int fact(int dig) {
    int res = 1;
    
    for (int i = 1; i <= dig; ++i) {
        res *= i; 
    }

    return res;
}

int main()
{
    std::map<int, int, std::less<int>, Allocator<std::pair<const int, int>>> test;
    for (size_t i = 0; i < 10; ++i) {
        test[i] = fact(i);
    }

    for (const auto &p : test) {
        std::cout << "Key: " << p.first << " Value: " << p.second << '\n';
    }

    Forward_List<int> l;
    l.pushFront(3);
    l.pushFront(2);
    l.pushFront(1);
    l.pushFront(0);
    l.popFront();

    std::cout << l << std::endl;


    std::cout << "\tSTART\n";

    std::map<int, int, std::less<int>, Allocator<std::pair<const int, int>>> allocTest;
    const size_t initialSize = 10000;
    for (size_t i = 0; i < initialSize; ++i) {
        allocTest[i] = i;
    }

    std::cout << "Map size after initial insertion: " << allocTest.size() << std::endl;
    const size_t elementsToRemove = 5000;
    for (size_t i = 0; i < elementsToRemove; ++i) {
        allocTest.erase(i);
    }

    std::cout << "Map size after removal: " << allocTest.size() << std::endl;
    const size_t additionalElements = 7000;
    for (size_t i = initialSize; i < initialSize + additionalElements; ++i) {
        allocTest[i] = i;
    }

    std::cout << "Map size after additional insertion: " << allocTest.size() << std::endl;
    for (size_t i = initialSize; i < allocTest.size(); ++i) {
        allocTest.erase(i);
    }

    std::cout << "Map size after removal: " << allocTest.size() << std::endl;
    const size_t additionalElements1 = 17000;
    for (size_t i = initialSize; i < initialSize + additionalElements1; ++i) {
        allocTest[i] = i;
    }

    std::cout << "Map size after additional insertion: " << allocTest.size() << std::endl;
    for (size_t i = initialSize; i < allocTest.size() - 10000; ++i) {
        allocTest.erase(i);
    }

    std::cout << "\tEND\n";

    return 0;
}