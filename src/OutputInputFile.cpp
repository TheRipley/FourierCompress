#include "heading.h"

std::vector<std::pair<Z, int>> compress(const complexList &list, int N)
{
    std::vector<std::pair<Z, int>> compressedData;

    int count = 1;
    for (int i=1; i<N; i++)
    {
        if (list[i] == list[i-1])
        {
            count++;
        }
        else
        {
            compressedData.push_back({list[i-1], count});
            count = 1;
        }
    }

    compressedData.push_back({list[N-1], count});

    return compressedData;
}

complexList decompress(const std::vector<std::pair<Z, int>> &compressedData)
{
    complexList decompressedData;

    int index = 0;
    for (const auto &pair : compressedData)
    {
        for (int i=0; i<pair.second; i++)
        {
            decompressedData[index++] = pair.first;
        }
    }

    return decompressedData;
}

void writeFile(const std::vector<std::pair<Z, int>> &compressedData, int N)
{
    std::ofstream outputFile;
    outputFile.open("compressed_file.txt");
    if (!outputFile.is_open())
    {
        std::cout << "Unable to open the output file." << std::endl;
        exit(1);
    }

    outputFile << N << std::endl;

    for (const auto &pair : compressedData)
    {
        outputFile << pair.first << " " << pair.second << std::endl;
    }

    outputFile.close();


}


std::vector<std::pair<Z, int>> readFile(const std::string& fileName)
{
    std::vector<std::pair<Z, int>> inputVector;

    std::ifstream inputFile;
    inputFile.open(fileName);

    if (!inputFile.is_open())
    {
        std::cout << "Unable to open " << fileName << ". Check if the file exists or if you wrote its name correctly." << std::endl;
        exit(1);
    }

    int size;
    inputFile >> size;
    std::cout << size << std::endl;

    Z complexPart;
    int count;
    while (inputFile >> complexPart >> count)
    {
        inputVector.push_back(std::make_pair(complexPart, count));
    }

    inputFile.close();

    return inputVector;

}