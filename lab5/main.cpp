#include "./include/allocator.h"
#include "./include/iterator_FL.h"

#include <map>
#include <unordered_map>

int main()
{
    std::map<int, int, std::less<int>, Allocator<std::pair<const int, int>>> a;
    a[0] = 1;
    a[1] = 2;
    for (const auto & p : a) {
        std::cout << p.first << ' ' << p.second << std::endl;
    }

    return 0;
}