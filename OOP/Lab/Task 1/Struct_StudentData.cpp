#include <iostream>
using namespace std;

struct Student_Data
{
    string name;
    int marks[3];
};

void Display_data(Student_Data s)
{
    cout << "Student: " << s.name << endl;

    for(int i =0; i<3;i++)
    {
        cout << "Marks for Course 1: " << s.marks[i] << endl;
    }
}

void change_marks(Student_Data s, int course, int newmarks)
{
    s.marks[course] = newmarks;
}

void Average_marks(Student_Data s)
{
    float avg;

    avg = ((s.marks[0]+s.marks[1]+s.marks[2])/3);
    cout << "Average: " << avg << endl;   
}


int main()
{
    int newmarks;
    string name;
    int option;
    int option2;
    int course;

    Student_Data s1;

    cout << "Enter Student Name." << endl;
    cin >> s1.name;

    for(int i =0; i<3;i++)
    {
        cout << "Enter Student marks for course: " << i+1 << endl;
        cin >> s1.marks[i];
    }

    Student_Data s2;

    cout << "Enter Student Name." << endl;
    cin >> s2.name;

    for(int i =0; i<3;i++)
    {
        cout << "Enter Student marks for course: " << i+1 << endl;
        cin >> s2.marks[i];
    }


     cout << endl << "Please Input 1 Option" << endl << "1. Display Student Data" << endl << "2. Calculate Average Marks" << endl <<  "3. Change marks" << endl << "4. Exit";
     cin >> option;

     if (option == 1)
     { 
         Display_data(s1);
         Display_data(s2);
     }
     else if (option == 2)
     {
        cout << "Please Input Student Number: " << endl;
        cin >> option2;
 
         if(option2 == 1)
        {
         Average_marks(s1);
        }
        else
        {
         Average_marks(s2);
        }
     }
     else if (option == 3)
     {
        cout << "Please Input Student Number: " << endl;
        cin >> option2;

        cout << "Please Input Course Number: " << endl;
        cin >> course;

        cout << "Enter Updated Marks." << endl;
        cin >> newmarks;

        if (option2 == 1)
        {
         change_marks(s1, course, newmarks);
        }
        else if (option2 == 2)
        {
         change_marks(s2, course, newmarks);
        }
     }
     else if (option == 4)
     {
     }

    return 0;
}
