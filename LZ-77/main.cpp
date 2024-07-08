#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "LZ-77-Class/LZ77.h"

std::string Pad(const std::string& input, int padLength) {
    std::string padding(padLength, '\0'); // Using null characters for padding
    std::ostringstream oss;
    oss << input << "|" << padding << std::setw(2) << std::setfill('0') << padLength;
    return oss.str();
}

std::string Unpad(const std::string& padded) {
    auto pos = padded.rfind('|');
    if (pos != std::string::npos) {
        int padLength = std::stoi(padded.substr(pos + 1 + padded.substr(pos + 1).find_first_not_of('\0'), 2));
        return padded.substr(0, pos - padLength);
    }
    return padded; // return original if no padding info found
}

int main() {
    std::ifstream inputFile("Input/input1.txt");
    if (!inputFile) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::string input((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    inputFile.close();

    int padLength = 10; // Example padding length
    std::string paddedInput = Pad(input, padLength);

    LZ77 lz77;
    int searchBufferSize = 100;
    int lookAheadBufferSize = 100;

    std::vector<LZ77::Match> compressed = lz77.compress(paddedInput, searchBufferSize, lookAheadBufferSize);

    std::cout << "Compressed data:" << std::endl;
    for (const auto& match : compressed) {
        std::cout << "(" << match.offset << ", " << match.length << ", '" << match.nextChar << "')" << std::endl;
    }

    std::string decompressed = lz77.decompress(compressed);
    std::string original = Unpad(decompressed);
    std::cout << "Original text after decompression and unpadding: " << original << std::endl;

    return 0;
}