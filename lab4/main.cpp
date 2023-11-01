#include "./header/figure.h"
#include "./header/square.h"
#include "./header/triangle.h"

int main()
{
    //SQUARE
    // Coord s1 = {4, 4};
    // Coord s2 = {0, 4};
    // Coord s3 = {0, 0};
    // Coord s4 = {4, 0};

    //TRIANGLE
    // Coord t1 = {0, 1};
    // Coord t2 = {1, 0};
    // Coord t3 = {0.5, 2};

    //OCTAGON
    // Coord oc1 = {4, 3};
    // Coord oc2 = {3, 4};
    // Coord oc3 = {1, 4};
    // Coord oc4 = {0, 3};
    // Coord oc5 = {0, 1};
    // Coord oc6 = {1, 0};
    // Coord oc7 = {3, 0};
    // Coord oc8 = {4, 1};

    // DArray<std::pair<double, double>> a{ {1, 1}, {2, 1}, {2, 2}, {1, 2} };
    // DArray<std::pair<double, double>> b(std::move(a));
    
    // Square<double> sq1(std::move(b));
    
    // std::cout << (sq2 == sq) ? true : false;
    // std::cout << a.getSize()<< std::endl;

    Triangle<double> tr1;
    Triangle<double> tr2 {{0, 1}, {1, 0}, {0.5, 2}};
    DArray<std::pair<double, double>> a{ {0, 1}, {1, 0}, {0.5, 2} };
    Triangle<double> tr3(a);

    std::cout << tr2.calculateGeomCentr().first << ' ' << tr2.calculateGeomCentr().second 
        << '\n' << tr2.calculateLengthOfSide() << '\n'
        << double(tr2) << std::endl;
}