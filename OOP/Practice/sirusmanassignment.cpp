#include <iostream>
using namespace std;



class Cs_department
{
    private:
    string section_name[5];
    int no_of_students;

};

class Student
{
    private:
    int roll_number;
    string name;
    char section;
    string password;
};
class Admin
{
    string name;
    string designation;
    string password;
    string username;

    void set_password(string password)
    {
        this -> password = password;
    }
};



int main()
{
    int choice;
    string username;
    string password;
    cout << "Welcome to the Department of Computer Science!" << endl << endl << endl;

    cout << "Press 1 to login as Admin" << endl;
    cout << "Press 2 to login as Student" << endl;
    cin >> choice;

    if (choice == 1)
    {
        cout << "User Name: "; cin >> username; cout << endl;
        cout << "Password: "; cin >> password; cout << endl << endl;

        if(username == "admin" && password == "admin")
        {
            cout << "Please change your password." << endl;
            cin >> password;
            
            

        }
    }

 return 0;
}