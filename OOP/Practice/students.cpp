#include <iostream>
using namespace std;

class Students
{
    private:
    string firstname;
    string lastname;
    int classyear;
    string major;
    public:
    void set_details(string fn,string ln,int cy, string major)
    {
        firstname = fn;
        lastname = ln;
        classyear = cy;
        this -> major = major;
    }
    void get_details()   
    {
        cout << "----------------------------------------------" << endl;
        cout << "Name =" << firstname <<" "<< lastname<< endl;
        cout << "Year =" << classyear << endl;
        cout << "Major =" << major << endl; 
    }

};


int main()
{

    Students s1;
    s1.set_details("Subhan","Bokhari",2022,"CS");
    s1.get_details();

    Students s2;
    s2.set_details("Rafay","Kaim",2022,"AI");
    s2.get_details();

 return 0;
}