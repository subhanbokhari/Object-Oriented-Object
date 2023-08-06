#include <iostream>
using namespace std;

class fruit
{
private:

int n;

public:

fruit();
fruit(int n);

void output();
};
fruit::fruit()
{
cout << "default callled" << endl;
n = 0;
}
fruit::fruit(int n1)
{
cout << "para called" << endl;
n = n1;
}

void fruit::output()
{
cout << "n =" << n;
}
int main()
{
fruit t(2);//para
fruit t1;//default
t1.output();
t.output();

return 0;
}