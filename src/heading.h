#include <complex>
#include <array>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

const int input_size=100;

using Z = std::complex<double>;
using complexList = std::array<Z,input_size>;


complexList ditfft(complexList, int);
void Print(complexList, int);
void Manipulate(complexList&, int);
void NullifyLowValues(complexList&, int, int);

void writeFile(const std::vector<std::pair<Z, int>>&, int );
std::vector<std::pair<Z, int>> readFile(const std::string&);
complexList decompress(const std::vector<std::pair<Z, int>>&);
std::vector<std::pair<Z, int>> compress(const complexList&, int);

