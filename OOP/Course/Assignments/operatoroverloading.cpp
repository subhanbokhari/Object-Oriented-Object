#include <iostream>
#include <exception>
using namespace std;

class ComplexNum {
private:
    int realPart;
    int imagPart;
public:
    ComplexNum(int r = 0, int i = 0) : realPart(r), imagPart(i) {}

    ComplexNum operator*(const ComplexNum& c) {
        ComplexNum result;
        result.realPart = realPart * c.realPart - imagPart * c.imagPart;
        result.imagPart = realPart * c.imagPart + imagPart * c.realPart;
        return result;
    }

    ComplexNum operator++(int) {
        ComplexNum temp(*this);
        realPart++;
        imagPart++;
        return temp;
    }

    void operator/=(const ComplexNum& c) {
        int tempRealPart = realPart;
        realPart = (realPart * c.realPart + imagPart * c.imagPart) / (c.realPart * c.realPart + c.imagPart * c.imagPart);
        imagPart = (imagPart * c.realPart - tempRealPart * c.imagPart) / (c.realPart * c.realPart + c.imagPart * c.imagPart);
    }

    bool operator!=(const ComplexNum& c) {
        return (realPart != c.realPart) || (imagPart != c.imagPart);
    }

    bool operator||(const ComplexNum& c) {
        return (realPart || c.realPart) || (imagPart || c.imagPart);
    }

    ComplexNum operator^(const ComplexNum& c) {
        ComplexNum result;
        result.realPart = realPart ^ c.realPart;
        result.imagPart = imagPart ^ c.imagPart;
        return result;
    }

    ComplexNum operator>>(const int& n) {
        ComplexNum result;
        result.realPart = realPart >> n;
        result.imagPart = imagPart >> n;
        return result;
    }

    int operator[](const int& index) {
        if (index == 0) {
            return realPart;
        }
        else if (index == 1) {
            return imagPart;
        }
        else {
            throw invalid_argument("Invalid index!");
        }
    }

    friend istream& operator>>(istream& is, ComplexNum& c) {
        cout << "Enter real part: ";
        if (!(is >> c.realPart)) {
            throw invalid_argument("Invalid input for real part!");
        }
        cout << "Enter imaginary part: ";
        if (!(is >> c.imagPart)) {
            throw invalid_argument("Invalid input for imaginary part!");
        }
        return is;
    }

    friend ostream& operator<<(ostream& os, const ComplexNum& c) {
        os << c.realPart << " + " << c.imagPart << "i";
        return os;
    }
};

int main() {
    ComplexNum firstNum(2, 3);
    ComplexNum secondNum(4, -5);

    ComplexNum product = firstNum * secondNum;
    cout << "Product: " << product << endl;

    ComplexNum postIncrement = firstNum++;
    cout << "Post-increment: " << postIncrement << endl;

    firstNum /= secondNum;
    cout << "Division assignment: " << firstNum << endl;

    bool notEqual = firstNum != secondNum;
    cout << "Not equal to: " << notEqual << endl;

    bool logicalOr = firstNum || secondNum;
    cout << "Logical OR: " << logicalOr << endl;

    ComplexNum bitwiseXor = firstNum ^ secondNum;
    cout << "Bitwise XOR: " << bitwiseXor << endl;

    ComplexNum rightShift = firstNum >> 1;
    cout << "Right shift: " << rightShift << endl;

    int realPart = 0;
    try {
        realPart = firstNum[2];
    }
    catch (invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }
    cout << "Real part: " << realPart << endl;

    int imagPart = 0;
    try {
        imagPart = firstNum[1];
    }
    catch (invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
    }
    cout << "Imaginary part: " << imagPart << endl;

    ComplexNum userNum;
    try {
        cin >> userNum;
    }
    catch (invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    cout << "User input: " << userNum << endl;

    return 0;
}