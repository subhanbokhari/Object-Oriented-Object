#include <iostream>
#include <math.h>
using namespace std;
class Complex
{
    private:
    double real;
    double imaginary;
    double r2;
    double i2;
    public:
    Complex(double real=0.0, double imaginary=0.0)
    {
        this->real=real;
        this->imaginary=imaginary;
    }
    Complex add(Complex r1, Complex i1)
    {
        r2=r1.real+i1.real;
        i2=r1.imaginary+i1.imaginary;
        return Complex(r2,i2);
    }
    Complex subtract(Complex r1, Complex i1)
    {
        r2=r1.real-i1.real;
        i2=r1.imaginary-i1.imaginary;
        return Complex(r2,i2);
    }    

    void print() {
        cout << "(" << r2 << ", " << i2 << "i)" << endl;
    }
};
int main()
{
    // create two complex numbers
    Complex c1(2.0, 3.0);
    Complex c2(4.0, 5.0);

    // add two complex numbers
    Complex c3 = c3.add(c1,c2);
    c3.print();  // output: (6.000000, 8.000000i)

    // subtract two complex numbers
    Complex c4 = c4.subtract(c1,c2);
    c4.print();  // output: (-2.000000, -2.000000i)

 return 0;
}