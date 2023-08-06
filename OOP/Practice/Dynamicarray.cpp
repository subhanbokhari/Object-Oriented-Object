#include <iostream>
using namespace std;
int main()
{
  int *p;
  p= new int;
  cout << &p << endl;
  delete p;

 return 0;
}