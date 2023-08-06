#include <iostream>
#include <string>

using namespace std;

class Animal {
protected:
    string name;
    string color;
public:
    Animal(const string& n, const string& c) : name(n), color(c) {}
    virtual ~Animal() {}
    virtual void display() = 0;
};

class Deer : public Animal {
private:
    bool hasAntlers;
public:
    Deer(const string& n, const string& c, bool antlers) : Animal(n, c), hasAntlers(antlers) {}
    void display() override {
        cout << "Name: " << name << ", Color: " << color << ", Has Antlers: " << (hasAntlers ? "Yes" : "No") << endl;
    }
};

class Zebra : public Animal {
private:
    string stripe_pattern;
public:
    Zebra(const string& n, const string& c, const string& pattern) : Animal(n, c), stripe_pattern(pattern) {}
    void display() override {
        cout << "Name: " << name << ", Color: " << color << ", Stripe Pattern: " << stripe_pattern << endl;
    }
};

void displayAll(Animal** animals, int count) {
    for (int i = 0; i < count; i++) {
        animals[i]->display();
    }
}

int main() {
    Animal* animals[2];
    animals[0] = new Deer("Bambi", "Brown", true);
    animals[1] = new Zebra("Marty", "Black and White", "Vertical");

    displayAll(animals, 2);

    delete animals[0];
    delete animals[1];

    return 0;
}