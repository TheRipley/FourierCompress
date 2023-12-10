#include "heading.h"

//print the complexList
void Print(complexList list, int N)
{
    for (int i=0; i<N; i++)
	{
		std::cout << "Real: " << list[i].real() << 
					", Imaginary: " << list[i].imag() << std::endl;
	}
}

//The FFT outputs a list in reversed order and the last value should be placed first: This solves this problem
void Manipulate(complexList& list, int input_size)
{
	std::reverse(list.begin(), list.end());
	std::rotate(list.begin(), list.end() - 1, list.end());
	const double scaler = 1.0/input_size;
	std::transform(list.rbegin(), list.rend(),
               list.rbegin(), [scaler](Z element)
               { return element * scaler; });	
}