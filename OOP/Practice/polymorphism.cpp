#include <iostream>
using namespace std;

class A
{
    private:
    int n;
    public:
    void in ()
    {
        cout << "Enter the value"<< endl;
        cin >> n;
    }
    void out ()
        {
            cout << "The Value of n is: " << n << endl;
        }
};

int main()
{
    A *ptr;
    ptr= new A;

    ptr->in();
    ptr->out();

    delete ptr;

 return 0;
}