#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>
#include <string>
#include "LZ-77-Class/LZ77.h"
#include "Padding/padding.h"

// std::string Pad(const std::string& input, int block_size) {
//     size_t input_length = input.size();
//     size_t padding_needed = block_size - (input_length % block_size);
//     if (padding_needed == block_size) {
//         padding_needed = 0;  // No padding needed if already a multiple of block_size
//     }

//     std::string padding(padding_needed - 1, '\0'); // All padding bytes are zero except the last one
//     char last_char = static_cast<char>(padding_needed); // Last padding byte indicates the number of padding bytes

//     return input + padding + last_char;
// }

// std::string Unpad(const std::string& padded) {
//     if (padded.empty()) return padded;

//     size_t last_byte = static_cast<unsigned char>(padded.back()); // Get the value of the last byte
//     if (last_byte > padded.size()) {
//         std::cerr << "Padding is corrupt" << std::endl;
//         return "";
//     }
//     return padded.substr(0, padded.size() - last_byte);
// }
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


int main() {

    std::string name;

    // Prompt the user
    std::cout << "Please the file name: ";
    
    // Get the entire line as input
    std::getline(std::cin, name);
        std::string output_filename = name+".txt";
    
    // Output the name to confirm it was entered correctly
    std::cout << "The file you have choosen is, " << name << "Hold on while we compressed your data." << std::endl;

    std::ifstream inputFile("Input/"+name);
    if (!inputFile) {
        std::cerr << "Error opening file" << std::endl;
        return 1;
    }

    std::string input((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    inputFile.close();

    int block_size = 16; 
    
    std::string paddedInput = Pad(input, block_size,1);

    


    LZ77 lz77;
    int searchBufferSize = 100;
    int lookAheadBufferSize = 100;

    std::vector<LZ77::Match> compressed = lz77.compress(paddedInput, searchBufferSize, lookAheadBufferSize);
    int i = 1;
    std::cout << "Compressed data:" << std::endl;
    for (const auto& match : compressed) {
        std::cout <<"B_"<<i <<"[" << match.offset << ", " << match.length << ", '" << match.nextChar << "']" << std::endl;
        i++;
    }

    std::string decompressed = lz77.decompress(compressed);
    std::string original = Unpad(decompressed,1);
    // std::cout << "Original text after decompression and unpadding: " << original << std::endl;

    return 0;
}
