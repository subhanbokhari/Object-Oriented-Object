#include <iostream>
using namespace std;

class A
{
    public:
    int b;
    A(int b = 0)
    {
        this->b = b;
    }

};
class B
{
    public:
    A obj1;
    int d;
    B(int b, int d = 0 ) : obj1(b)
    {
        this -> d = d;
    }
    void add()
    {
        cout << "sum: " << obj1.b + d << endl;
    }

};
int main()
{

    B obj2(3,2);
    obj2.add();

 return 0;
}