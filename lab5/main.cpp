#include "./include/allocator.h"

int main()
{
    Allocator<int> a;
    a.allocate(5);

    return 0;
}