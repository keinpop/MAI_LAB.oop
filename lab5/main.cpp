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
    // std::map<int, int, std::less<int>, Allocator<std::pair<const int, int>>> test;
    // for (size_t i = 0; i < 10; ++i) {
    //     test[i] = fact(i);
    // }

    // for (const auto &p : test) {
    //     std::cout << "Key: " << p.first << " Value: " << p.second << '\n';
    // }

    // Forward_List<int> l;
    // l.pushFront(3);
    // l.pushFront(2);
    // l.pushFront(1);
    // l.pushFront(0);
    // l.popFront();

    // std::cout << l << std::endl;
    Forward_List<int> l1;

    l1.emplaceFront(1, 2, 3, 4, 5);
    l1.popFront();                  
    l1.popFront();                 
    l1.popFront();                  
    l1.popFront();                  
    l1.pushFront(1);                
    l1.popFront();                  
    l1.emplaceFront(1, 1, 1, 1, 1); 
    l1.popFront();                  
    l1.popFront();                  
    l1.popFront();                  
    l1.popFront();                  
    l1.popFront();                  

    std::cout << "l1.size() = " << l1.size() << std::endl;
    std::cout << l1 << std::endl; 
}