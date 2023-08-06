#include <iostream>

class Animal {
private:
    std::string* name;

public:
    // Constructor
    Animal(const std::string& animalName) {
        name = new std::string(animalName);
    }

    // Copy constructor
    Animal(const Animal& other) {
        name = new std::string(*other.name);
    }

    // Destructor
    ~Animal() {
        delete name;
    }

    // Getter method
    std::string getName() const {
        return *name;
    }
};

int main() {
    // Create an object using the constructor
    Animal cat("Tom");

    // Create a new object using the copy constructor
    Animal dog = cat;

    // Print the names of both animals
    std::cout << "Cat's name: " << cat.getName() << std::endl;
    std::cout << "Dog's name: " << dog.getName() << std::endl;

    return 0;
}