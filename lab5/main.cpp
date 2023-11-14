#include "./include/allocator.h"

int main()
{
    Allocator<int> a;
    int* ptr = a.allocate(5);
    int* tmp = ptr + 2 * sizeof(int);

    a.deallocate(tmp, 5);
    std::cout << '\n';
    // a.free();

    return 0;
}