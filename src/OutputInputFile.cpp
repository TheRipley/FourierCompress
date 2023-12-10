#include "heading.h"

void writeFile(complexList list, int N)
{
    std::ofstream outputFile;
    outputFile.open("compressed_file.txt");
    outputFile << N << std::endl;

    for (int i=0; i<N; i++)
    {
        outputFile << list[i] << std::endl;
    }

    outputFile.close();


}

complexList readFile(const std::string& fileName)
{
    complexList inputList;
    std::ifstream inputFile;
    inputFile.open(fileName);

    if (!inputFile)
    {
        std::cout << "Unable to open " << fileName << ". Check if the file exists or if you wrote its name correctly." << std::endl;
        exit(1);
    }

    int size;
    inputFile >> size;
    std::cout << size << std::endl;

    for (int i=0; i<size; i++)
    {
        inputFile >> inputList[i];
        std::cout << inputList[i] << std::endl;
    }

    return inputList;

}