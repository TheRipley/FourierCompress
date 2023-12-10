#include "heading.h"
//#include <opencv2/opencv.hpp>


int main(int argc, char *argv[])
{
	// Create the initial list of complex values 
	complexList input;
	for (int i=0; i<input_size; i++)
	{
		input[i] = Z(i, i);
	}
	
	//Perform a FT on the input and then set to (0.0, 0.0) small values.
	complexList output = ditfft(input, input_size);
	NullifyLowValues(output, input_size, input_size*2);

	//Compress this list in an array of pairs in the form (Z, int consecutive_repetitions_of_Z)
	//And then write into a file named "compressed_file.txt"
	std::vector<std::pair<Z, int>> compressedData = compress(output, output.size());
	writeFile(compressedData, input_size);

	//Make a new array of pairs to assign the values of the "compressed_file.txt"
	std::vector<std::pair<Z, int>> new_output;
	new_output = readFile("compressed_file.txt");

	complexList decompressData = decompress(new_output);
	
	complexList reversed_output = ditfft(decompressData, input_size);
	Manipulate(reversed_output, input_size);
	Print(reversed_output, input_size);
	

	return 0;
}
