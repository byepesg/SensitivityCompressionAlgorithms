// padding.h
#ifndef PADDING_H
#define PADDING_H

#include <string>

std::string Pad(const std::string& input, int block_size,int padding_type);
std::string Unpad(const std::string& padded,int padding_type);

#endif // PADDING_H
