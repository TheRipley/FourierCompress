#include "heading.h"

//Perform the Fast Fourier Transform on the complexList x to obtain a new list X
complexList ditfft(complexList x, int N)
{
    complexList X;

    Z temp;
    const Z i(0.0, 1.0);

    for (int k=0; k<N; k++)
    {
        temp={0.0, 0.0};
        for (int n=0; n<N; n++)
        {
            temp += x[n]
                        * std::exp(-i * Z(2.0, 0.0)  
                                        * M_PI * Z(k, 0.0) 
                                        * Z(n, 0.0) 
                                        / Z(N, 0.0));
        }
        X[k] = temp;
    }
    return X;
}