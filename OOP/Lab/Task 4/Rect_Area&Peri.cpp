#include <iostream>
using namespace std;

class Rectangle
{
    float length;
    float width;

    public:
    
    void set_length(float length)
    {
        this -> length = length;
    }
    void set_width(float width)
    {
        this -> width = width;
    }
    float perimeter()
    {
        float perimeter;
        perimeter = ((2*length)+(2*width));
        return perimeter;
    }
    float area()
    {
        float area;
        area= (length*width);
        return area;
    }
    void show()
    {
        cout << "Length: " << this -> length << endl;
        cout << "Width: " << this -> width << endl;
    }
    int sameArea(Rectangle r2)
    {
        int check = 0 ;

        if (this->length == r2.length && this->width == r2.width)
        {
            check == 1;
        }
        return check;
    }

};
int main()
{
    int check;
    Rectangle r1;
    Rectangle r2;

    r1.set_length(5.0);
    r1.set_width(2.5);

    r2.set_length(15.0);
    r2.set_width(6.3);

    r1.show();
    r2.show();

    cout << "Area 1st Rectangle: " << r1.area() << endl;
    cout << "Area 2nd Rectangle: " << r2.area() << endl;

    cout << "Perimeter 1st Rectangle: " << r1.perimeter() << endl;
    cout << "Perimeter 2nd Rectangle: " << r2.perimeter() << endl;

    check = r1.sameArea(r2);
    if(check==0)
    {
        cout << "The Rectangles are differernt!" << endl;
    }
    else
    {
        cout << "Same Rectangles!" << endl;
    }

    r1.set_length(15.0);
    r1.set_width(6.3);

    cout << "=======================================" << endl;

    r1.show();
    r2.show();

    cout << "Area 1st Rectangle: " << r1.area() << endl;
    cout << "Area 2nd Rectangle: " << r2.area() <<endl;

    cout << "Perimeter 1st Rectangle: " << r1.perimeter() << endl;
    cout << "Perimeter 2nd Rectangle: " << r2.perimeter() << endl;
    
    check = r1.sameArea(r2);
    if(check==0)
    {
        cout << "The Rectangles are differernt!" << endl;
    }
    else
    {
        cout << "Same Rectangles!" << endl;
    }
    
 return 0;
}