#!/bin/bash

# Compile the C++ code, including the path to LZ77.cpp
g++ -o main main.cpp LZ-77-Class/LZ77.cpp

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    # Run the executable
    ./main
else
    echo "Compilation failed."
fi
