#include "./header/square.h"
#include "./header/triangle.h"
#include "./header/octagon.h"

int main()
{
    std::vector<Coord> vec;
    Coord t1 = {0, 0};
    Coord t2 = {2, 0};
    Coord t3 = {3.414, 1.414};
    Coord t4 = {3.414, 3.414};
    Coord t5 = {2, 4.828};
    Coord t6 = {0, 4.828};
    Coord t7 = {-1.414, 3.414};
    Coord t8 = {-1.414, 1.414};
    
    vec.push_back(t1);
    vec.push_back(t2);
    vec.push_back(t3);
    vec.push_back(t4);
    vec.push_back(t5);
    vec.push_back(t6);
    vec.push_back(t7);
    vec.push_back(t8);
    Octagon c(vec);

    std::cout << c;
    
    // std::vector<Coord> vec1;
    // Coord s1 = {1, 1};
    // Coord s2 = {3, 1};
    // Coord s3 = {3, 3};
    // Coord s4 = {1, 3};

    // vec1.push_back(s1);
    // vec1.push_back(s2);
    // vec1.push_back(s3);
    // vec1.push_back(s4);
    // Square s(vec1);
    // double area = (double) c;
    // std::cout << area << std::endl;

    // Square s(vec);
    // Square s1(std::move(s));
    // std::cout << "S1"<< s1 << std::endl;
    return 0;
}