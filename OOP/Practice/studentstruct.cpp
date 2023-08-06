#include <iostream>

using namespace std;

struct student
{
int rollnumber;
float gpa;
string name;
};

int main()
{
student s1;
s1.name = "Subhan Bokhari";
s1.gpa = 2.8;
s1.rollnumber = 9447;

// Using pointer to access object
student *s;
s = &s1;

cout << (*s).name << endl;
cout << (*s).gpa;

//No Variable name //new instance
s = new student;
s -> name = "Subhan";

//Delete Existing instance
delete s;


return 0;
}