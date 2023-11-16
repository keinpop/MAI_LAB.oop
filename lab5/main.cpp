#include "./include/allocator.h"
#include "./include/forward_list.h"

int main()
{
    Forward_List<int> a{1, 2, 3};
    a.emplaceFront(0);
    // a.emplaceFront(-2);
    std::cout << a << std::endl;
    std::cout << "OK" << std::endl;
}