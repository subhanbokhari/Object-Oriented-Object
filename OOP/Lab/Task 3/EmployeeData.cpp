#include <iostream>
using namespace std;

class Employee
{
    private:
    int id;
    string name;
    string jobtitle;
    int hours;
    int salary;

    public:
    Employee()
    {
     id=0;
     name="NULL";
     jobtitle="NULL";
     hours=0;
     salary=0;       
    }
    void set_details(int id, string name, string jobtitle, int hours)
    {
     this -> id = id;
     this -> name = name;
     this -> jobtitle = jobtitle;
     this -> hours = hours;
    }
    void calc_salary(int hourlyrate)
    {
     int salary;
        if (hours <= 40)
        {
            salary = (hours * hourlyrate);
        }
        if(hours > 40)
        {
            salary = (40*hourlyrate);
            salary = salary + ((hours-40)*(2*hourlyrate));
            this -> salary = salary;
        }
    }
    void display(int employees)
    {
    for(int i = 0; i < employees; i++)
    {
        cout << "--------------------------------" << endl;
        cout << "ID:" << id << endl;
        cout << "Name:"  << name << endl;
        cout << "Job Type:" << jobtitle << endl;
        cout << "Hours Worked:" << hours << endl;
        cout << "Salary:" << salary << endl;
    }
    }
};

int main()
{
    int id;
    string name;
    string jobtitle;
    int hours;
    int employees;
    int hourlyrate;
         
    cout << "Enter the hourly rate:" << endl;
    cin >> hourlyrate;

    cout << "Number of Employee's ?" << endl;
    cin >> employees;

 Employee e1[employees];

    for(int i = 0; i < employees; i++)
    {
        cout << "Please Enter the ID:" << endl; cin >> id;
        cout << "Please Enter the Name:" << endl; cin >> name;
        cout << "Please Enter the Job Type:" << endl; cin >> jobtitle;
        cout << "Please Enter the hours worked:" << endl; cin >> hours;
        e1[i].set_details(id,name,jobtitle,hours);
    }

    for(int i =0; i < employees; i++)
    {
        e1[i].calc_salary(hourlyrate);
        e1[i].display(employees);
    }

 return 0;
}