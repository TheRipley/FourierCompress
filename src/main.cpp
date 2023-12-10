#include "heading.h"
//#include <opencv2/opencv.hpp>


int main()
{
	complexList input;
	for (int i=0; i<input_size; i++)
	{
		input[i] = Z(i, i);
	}
	
	
	complexList output = ditfft(input, input_size);
	NullifyLowValues(output, input_size, std::pow(input_size, 2)/4);

	std::vector<std::pair<Z, int>> compressedData = compress(output, output.size());
	writeFile(compressedData, input_size);


	std::vector<std::pair<Z, int>> new_output;
	new_output = readFile("compressed_file.txt");

	complexList decompressData = decompress(new_output);
	Print(decompressData, decompressData.size());
	

	return 0;
}
