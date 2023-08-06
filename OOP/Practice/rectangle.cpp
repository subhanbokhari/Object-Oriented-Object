#include <iostream>

using namespace std;

class Rectangle {
    private:
        double length;
        double width;
    public:
        Rectangle() {
            length = 0;
            width = 0;
        }

        void setLength(double l) {
            length = l;
        }

        double getLength() {
            return length;
        }

        void setWidth(double w) {
            width = w;
        }

        double getWidth() {
            return width;
        }

        double calculateArea() {
            return length * width;
        }
};

int main ()
{

Rectangle r;
r.setLength(5);
r.setWidth(3);
double area = r.calculateArea();
cout << "Area of rectangle: " << area << endl;

return 0;
}



