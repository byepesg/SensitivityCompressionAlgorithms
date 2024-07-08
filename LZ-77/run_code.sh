#!/bin/bash

# Compile the C++ code, including the path to LZ77.cpp
# g++ -o main main.cpp LZ-77-Class/LZ77.cpp

# # Check if the compilation was successful
# if [ $? -eq 0 ]; then
#     # Run the executable
#     ./main
# else
#     echo "Compilation failed."
# fi
#!/bin/bash

EXECUTABLE="main"

# Define source files
MAIN_SOURCE="main.cpp"
LZ77_SOURCE="LZ-77-Class/LZ77.cpp"

# Compile the C++ code using C++11 standard
g++ -std=c++11 -o $EXECUTABLE $MAIN_SOURCE $LZ77_SOURCE

# Check if the compilation was successful
if [ $? -eq 0 ]; then
    echo "Compilation successful. Running the program..."
    # Run the executable
    ./$EXECUTABLE
else
    echo "Compilation failed."
fi