#include <iostream>
#include <fstream>
#include <string>
#include "LZ-77-Class/LZ77.h"

int main() {
    std::ifstream inputFile("Input/input1.txt");
    if (!inputFile) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::string input((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    inputFile.close();

    LZ77 lz77;
    int searchBufferSize = 5;
    int lookAheadBufferSize = 5;

    std::vector<LZ77::Match> compressed = lz77.compress(input, searchBufferSize, lookAheadBufferSize);
    
    std::cout << "Compressed data:" << std::endl;
    for (const auto& match : compressed) {
        std::cout << "(" << match.offset << ", " << match.length << ", " << match.nextChar << ")" << std::endl;
    }

    std::string decompressed = lz77.decompress(compressed);
    std::cout << "Decompressed string: " << decompressed << std::endl;

    return 0;
}
