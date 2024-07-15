// padding.cpp
#include "padding.h"
#include <iostream>
#include <vector>

std::string Pad(const std::string &input, int block_size, int padding_type)
{

    if (padding_type == 0)
    {
        // return ZeroPad(input, block_size);

        // size_t input_length = input.size();
        // size_t padding_needed = block_size - (input_length % block_size);
        // if (padding_needed == block_size)
        // {
        //     padding_needed = 0; // No padding needed if already a multiple of block_size
        // }

        // std::string padding(padding_needed - 1, '\0');      // All padding bytes are zero except the last one
        // char last_char = static_cast<char>(padding_needed); // Last padding byte indicates the number of padding bytes

        // return input + padding + last_char;
        return "";
    }
    else if (padding_type == 1)
    {
            size_t input_length = input.size();
            size_t padding_needed = block_size - (input_length % block_size);
            std::cout <<"Input lenght :' "<<input_length << "'"<<std::endl;
            std::cout <<"Padding :' "<<padding_needed << "'"<<std::endl;

            // Calculate the total size needed (input size + padding size)
            size_t total_size = input_length + padding_needed;

            // Create a buffer for the padded input
            std::vector<char> padded(total_size, '\0');

            // Copy the input to the padded buffer
            std::copy(input.begin(), input.end(), padded.begin());

            // Add padding at the end
            for (size_t i = input_length; i < total_size; ++i) {
                padded[i] = static_cast<char>(padding_needed);
            }

            return std::string(padded.begin(), padded.end());
    }
    else
    {
        std::cerr << "Invalid padding type" << std::endl;
        return "";
    }
}

std::string Unpad(const std::string &padded, int padding_type)
{
    if (padding_type == 0)
    {
        // // return ZeroUnpad(padded);
        // if (padded.empty())
        //     return padded;

        // size_t last_byte = static_cast<unsigned char>(padded.back()); // Get the value of the last byte
        // if (last_byte > padded.size())
        // {
        //     std::cerr << "Padding is corrupt" << std::endl;
        //     return "";
        // }
        // return padded.substr(0, padded.size() - last_byte);
        return "";
    }
    else if (padding_type == 1)
    {
            if (padded.empty()) return padded;

            size_t padded_size = padded.size();
            size_t padding_size = static_cast<unsigned char>(padded.back());

            if (padding_size > padded_size) {
                std::cerr << "Padding is corrupt" << std::endl;
                return "";
            }

            return padded.substr(0, padded_size - padding_size);
    }
    else
    {
        std::cerr << "Invalid padding type" << std::endl;
        return "";
    }
}
