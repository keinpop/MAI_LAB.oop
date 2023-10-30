#include "./header/dinamicArray.h"

int main()
{
    DArray<int> a;
    DArray<int> bc(a);
    DArray<int> c;
    DArray<int> d = std::move(bc);
    
    return 0;
}