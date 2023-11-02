#include "./header/figure.h"
#include "./header/square.h"
#include "./header/triangle.h"
#include "./header/octagon.h"
#include "./header/functionDArray.h"

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

    DArray<std::pair<double, double>> a{ {1, 1}, {2, 1}, {2, 2}, {1, 2} };
    // DArray<std::pair<double, double>> b(std::move(a));
    
    Square<double> sq1(a);
    
    // std::cout << (sq2 == sq) ? true : false;
    // std::cout << a.getSize()<< std::endl;

    // Triangle<double> tr1;
    // Triangle<double> tr2 {{0, 1}, {1, 0}, {0.5, 2}};
    DArray<std::pair<double, double>> b{ {0, 1}, {1, 0}, {0.5, 2} };
    Triangle<double> tr3(b);

    // std::cout << tr2.calculateGeomCentr().first << ' ' << tr2.calculateGeomCentr().second 
    //     << '\n' << tr2.calculateLengthOfSide() << '\n'
    //     << double(tr2) << std::endl;

    // DArray<std::pair<double, double>> a {{4, 3}, {3, 4}, {1, 4}, {0, 3}, {0, 1}, {1, 0}, {3, 0}, {4, 1}};
    // Octagon<double> oc1;
    Octagon<double> oc2 { {4, 3}, {3, 4}, {1, 4}, {0, 3}, {0, 1}, {1, 0}, {3, 0}, {4, 1} };
    // Octagon<double> oc3(a);
    
    // std::cout << oc2.calculateGeomCentr().first << ' ' << oc2.calculateGeomCentr().second 
    //     << '\n' << oc2.calculateLengthOfSide() << '\n'
    //     << double(oc2) << std::endl;

    // std::cout << (oc2 == oc3) ? true : false;

    DArray<Figure<double>> array;
    array.pushBack(sq1);
    array.pushBack(tr3);
    array.pushBack(oc2);

    std::cout << array[0] << "\n" << array[1] << "\n" << array[2] << std::endl;
    std::cout << calcualteAllArea(array) << std::endl;
    

    return 0;
}