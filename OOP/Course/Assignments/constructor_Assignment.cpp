#include <iostream>
using namespace std;

class MyClass {
private:
    int intValue;
    float floatValue;
public:
    MyClass() : intValue(0), floatValue(0.0f) {
        cout << "Default constructor called." << endl;
    }

    MyClass(int i) : intValue(i), floatValue(0.0f) {
        cout << "One-argument constructor called." << endl;
    }

    MyClass(int i, float f) : intValue(i), floatValue(f) {
        cout << "Two-argument constructor called." << endl;
    }

    MyClass(int i, float f, bool b) : intValue(i), floatValue(f) {
        if (b) {
            cout << "Three-argument constructor called with bool parameter set to true." << endl;
        }
        else {
            cout << "Three-argument constructor called with bool parameter set to false." << endl;
        }
    }

    void printValues() {
        cout << "Integer value: " << intValue << endl;
        cout << "Float value: " << floatValue << endl;
    }

    void myMethod(int a, int b) {
        cout << "Method with two integer arguments called." << endl;
        cout << "a: " << a << ", b: " << b << endl;
    }

    void myMethod(float a, float b) {
        cout << "Method with two float arguments called." << endl;
        cout << "a: " << a << ", b: " << b << endl;
    }
};

int main() {
    MyClass obj1;
    obj1.printValues();

    MyClass obj2(10);
    obj2.printValues();

    MyClass obj3(20, 30.5f);
    obj3.printValues();

    MyClass obj4(40, 50.5f, true);
    obj4.printValues();

    MyClass obj5 = MyClass(60, 70.5f, false);
    obj5.printValues();

    obj1.myMethod(5, 10);
    obj1.myMethod(3.14f, 2.71f);

    return 0;
}