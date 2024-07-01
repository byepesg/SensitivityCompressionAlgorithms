#include "LZ-77-Class/ExampleClass.h"

int main() {
    // Create an object of ExampleClass
    ExampleClass example("InitialName", 10);

    // Display the initial state
    example.display();

    // Change the name using setName
    example.setName("NewName");

    // Display the updated state
    example.display();

    return 0;
}
