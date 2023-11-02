#include "../header/functionDArray.h"

template <class T>
double calcualteAllArea(const DArray<Figure<T>> & arrayFig)
{
    double result = 0;
    
    for (size_t i = 0; i < arrayFig.getSize(); ++i) {
        result += (double) arrayFig[i];
    }

    return result;
}