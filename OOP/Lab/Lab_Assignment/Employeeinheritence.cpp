#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string empName;
    int empNum;

public:
    Employee(string name, int num) {
        empName = name;
        empNum = num;
    }

    void getData() {
        cout << "Employee Name: " << empName << endl;
        cout << "Employee Number: " << empNum << endl;
    }

    void putData() {
        cout << "Employee Name: " << empName << endl;
        cout << "Employee Number: " << empNum << endl;
    }
};

class Manager : public Employee {
private:
    char title;
    double clubDues;

public:
    Manager(string name, int num, char t, double dues) : Employee(name, num) {
        title = t;
        clubDues = dues;
    }

    void getData() {
        Employee::getData();
        cout << "Title: " << title << endl;
        cout << "Club Dues: $" << clubDues << endl;
    }

    void putData() {
        Employee::putData();
        cout << "Title: " << title << endl;
        cout << "Club Dues: $" << clubDues << endl;
    }
};

class Scientist : public Employee {
private:
    int publications;

public:
    Scientist(string name, int num, int pub) : Employee(name, num) {
        publications = pub;
    }

    void getData() {
        Employee::getData();
        cout << "Publications: " << publications << endl;
    }

    void putData() {
        Employee::putData();
        cout << "Publications: " << publications << endl;
    }
};

class Programmer : public Employee {
private:
    double salary;
    string expertise;

public:
    Programmer(string name, int num, double sal, string exp) : Employee(name, num) {
        salary = sal;
        expertise = exp;
    }

    void getData() {
        Employee::getData();
        cout << "Salary: $" << salary << endl;
        cout << "Expertise: " << expertise << endl;
    }

    void putData() {
        Employee::putData();
        cout << "Salary: $" << salary << endl;
        cout << "Expertise: " << expertise << endl;
    }
};

int main() {
    Employee employee("John Smith", 12345);
    Manager manager("Jane Doe", 67890, 'M', 50.0);
    Scientist scientist("Bob Johnson", 24680, 5);
    Programmer programmer("Sarah Lee", 13579, 100000.0, "Java");

    employee.getData();
    cout << endl;

    manager.getData();
    cout << endl;

    scientist.getData();
    cout << endl;

    programmer.getData();
    cout << endl;

    return 0;
}
