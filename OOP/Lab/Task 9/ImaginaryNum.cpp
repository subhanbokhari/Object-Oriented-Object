#include <iostream>
using namespace std;

class Complex {
private:
    int real;
    int imag;
public:
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
    friend class Operations;
};

class Operations {
public:
    static Complex addComplex(Complex c1, Complex c2) {
        Complex result;
        result.real = c1.real + c2.real;
        result.imag = c1.imag + c2.imag;
        return result;
    }
    static Complex subtractComplex(Complex c1, Complex c2) {
        Complex result;
        result.real = c1.real - c2.real;
        result.imag = c1.imag - c2.imag;
        return result;
    }
};

int main() {
    Complex c1(2, 3);
    Complex c2(4, -5);

    Complex sum = Operations::addComplex(c1, c2);
    Complex diff = Operations::subtractComplex(c1, c2);

    cout << "Sum: ";
    sum.display();
    cout << "Difference: ";
    diff.display();

    return 0;
}