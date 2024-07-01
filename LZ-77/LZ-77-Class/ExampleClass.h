#ifndef EXAMPLECLASS_H
#define EXAMPLECLASS_H

#include <string>

class ExampleClass {
private:
    std::string name;
    int value;

public:
    // Constructor
    ExampleClass(std::string initName, int initValue);

    // Function to set the name
    void setName(std::string newName);

    // Function to get the name
    std::string getName() const;

    // Function to display the current state of the object
    void display() const;
};

#endif // EXAMPLECLASS_H
