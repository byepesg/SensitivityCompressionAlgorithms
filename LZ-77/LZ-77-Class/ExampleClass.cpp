#include "ExampleClass.h"
#include <iostream>

// Constructor implementation
ExampleClass::ExampleClass(std::string initName, int initValue) : name(initName), value(initValue) {}

// Function to set the name
void ExampleClass::setName(std::string newName) {
    name = newName;
}

// Function to get the name
std::string ExampleClass::getName() const {
    return name;
}

// Function to display the current state of the object
void ExampleClass::display() const {
    std::cout << "Name: " << name << ", Value: " << value << std::endl;
}
