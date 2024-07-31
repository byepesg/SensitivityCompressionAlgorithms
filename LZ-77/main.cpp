#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <vector>
#include "LZ-77-Class/LZ77.h"
#include "Padding/padding.h"

std::string readFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return "";
    }
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    file.close();
    return content;
}

void writeFile(const std::string& filename, const std::string& content) {
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Unable to open file: " << filename << std::endl;
        return;
    }
    file.write(content.c_str(), content.size());
    file.close();
}

// Function to serialize compressed data
std::string serializeCompressed(const std::vector<LZ77::Match>& compressed) {
    std::ostringstream oss;
    for (const auto& match : compressed) {
        oss << "["<<match.offset << "," << match.length << "," << match.nextChar << "]";
    }
    return oss.str();
}

int main() {
    std::string name;
    std::cout << "Please enter the file name: ";
    std::getline(std::cin, name);
    
    std::cout << "The file you have chosen is " << name << ". Hold on while we compress your data." << std::endl;

    std::string input = readFile("Input/" + name);
    if (input.empty()) {
        return 1;
    }

    LZ77 lz77;
    int searchBufferSize = 100;
    int lookAheadBufferSize = 100;
    std::vector<LZ77::Match> compressed = lz77.compress(input, searchBufferSize, lookAheadBufferSize);

    std::string serialized = serializeCompressed(compressed);
    int block_size = 16;
    std::string paddedInput = Pad(serialized, block_size, 1);

    std::string output_filename = "Output/" + name + ".txt";
    writeFile(output_filename, paddedInput);
    
    std::cout << "Compression and padding complete. Data saved to " << output_filename << std::endl;

    return 0;
}
