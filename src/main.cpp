#include "heading.h"
//#include <opencv2/opencv.hpp>


int main()
{
	complexList input;
	for (int i=0; i<input_size; i++)
	{
		input[i] = Z(i, std::pow(i,2));
	}
	std::cout << "Original list:\n" << std::endl;
	//Print(input, input_size);

	std::cout << "Fourier trannsformed:\n" << std::endl;
	complexList output = ditfft(input, input_size);
	//Print(output, input_size);	
	
	std::cout << "Low values erased:\n" << std::endl;	
	NullifyLowValues(output, input_size, std::pow(input_size, 2)/2);
	//Print(output, input_size);
	writeFile(output, input_size);



	std::cout << "Now the inverse of the Fourier:\n" <<std::endl;
	complexList readList;
	readList = readFile("compressed_file.txt");
	complexList reversed_output;
	reversed_output = ditfft(readList, input_size);

	Manipulate(reversed_output, input_size);

	Print(reversed_output, input_size);	

	return 0;
}
