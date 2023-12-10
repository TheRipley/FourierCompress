#include "heading.h"

void NullifyLowValues(complexList& list, int N, int LowerBound)
{
    for (int i=0; i<N; i++)
    {
        if (abs(list[i]) < LowerBound)
            list[i] = Z(0,0);
    }
}