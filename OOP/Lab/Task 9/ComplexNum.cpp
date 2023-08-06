#include <iostream>
using namespace std;

class Complex {
private:
    int real;
    int imag;
public:
    Complex(int r = 0, int i = 0) : real(r), imag(i) {}
    friend Complex addComplex(Complex c1, Complex c2);
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

Complex addComplex(Complex c1, Complex c2) {
    Complex result;
    result.real = c1.real + c2.real;
    result.imag = c1.imag + c2.imag;
    return result;
}

int main() {
    Complex c1(2, 3);
    Complex c2(4, -5);

    Complex sum = addComplex(c1, c2);
    sum.display();

    return 0;
}