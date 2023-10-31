#include "./header/figure.h"
#include "./header/square.h"

int main()
{
    DArray<std::pair<double, double>> test1 {{1, 1}, {2, 1}, {2, 2}, {1, 2}};
    Square<double> sq(test1);

    return 0;
}