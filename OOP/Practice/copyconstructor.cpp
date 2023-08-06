#include <iostream>
using namespace std;

class Example
{
    public:
    int data;
    Example(int x=0)
    {
        data = x;
    }
    void display()
    {
        cout << "the data is :" << data << endl;
    }
};
int main()
{
    Example e1(50);
    Example e2(e1);

    e1.display();
    e2.display();

 return 0;
}