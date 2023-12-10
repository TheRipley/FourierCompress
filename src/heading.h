#include <complex>
#include <array>
#include <iostream>
#include <algorithm>
#include <fstream>

const int input_size=100;

using Z = std::complex<double>;
using complexList = std::array<Z,input_size>;


complexList ditfft(complexList, int);
void Print(complexList, int);
void Manipulate(complexList&, int);
void NullifyLowValues(complexList&, int, int);
void writeFile(complexList, int);
complexList readFile(std::string);

