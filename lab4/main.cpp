#include "./header/figure.h"
#include "./header/square.h"

int main()
{
    DArray<std::pair<int, int>> a{ {1, 1}, {2, 1}, {2, 2}, {1, 2} };
    Square<int> sq{ {1, 1}, {2, 1}, {2, 2}, {1, 2} };
    Square<int> b(std::move(sq));
    std::cout << b.getNameFigure() << '\n';
}