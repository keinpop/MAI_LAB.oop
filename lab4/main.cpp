#include "./header/figure.h"


int main()
{
    Figure<double> a {{1, 2}, {3, 4}, {5, 6}};
    
    std::cout << a;

    return 0;
}