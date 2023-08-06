#include <iostream>
using namespace std;

class Shape
{
    public:
     virtual void draw()
    {
        cout << "Drawing a shape"<< endl;
    }
};

class Rectangle : public Shape
{
    int length;
    int width;
    public:
    void draw()
    {
        cout << "Drawing Rectangle"<< endl;
    }
};

class Circle: public Shape
{
    int radius;
    public:
    void draw()
    {
        cout << "Drawing a Circle" << endl;
    }
};


int main()
{
    Shape *ptr;
    ptr = new Circle;
    ptr->draw();


 return 0;
}