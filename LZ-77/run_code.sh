#!/bin/bash

# Compile the C++ code
g++ -o main main.cpp

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    # Run the executable
    ./main
else
    echo "Compilation failed."
fi
