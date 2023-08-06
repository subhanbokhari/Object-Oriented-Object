#include <iostream>
using namespace std;

class Birthday
{
    public:
    int date;
    int month;
    int year;

    Birthday (int day = 1, int month = 1, int year = 1970) 
    {
      this->date = day;
      this->month = month;
      this->year = year;
    }
    int get_month()
    {
     return month;
    }

};
class Contact
{
    public:
    string name;
    Birthday date;
    int phone_no;
    string email;

    Contact() 
    {
    } 

    Contact(Birthday date_of_birth, string name= "null", int phone_no = 0000, string email = "null") 
    {
        this->name = name;
        this->phone_no = phone_no;
        this->email = email;
        this->date = date_of_birth;
    }
    void addContact() 
    {
        string name, email;
        int phone_no;
        int day, month, year;

        cout << "Enter the name: ";
        cin >> name;
        cout << "Enter the phone number: ";
        cin >> phone_no;
        cout << "Enter the email: ";
        cin >> email;
        cout << "Enter the date of birth (DD MM YYYY): ";
        cin >> day >> month >> year;
        Birthday date_of_birth(day, month, year);
        this->name = name;
        this->phone_no = phone_no;
        this->email = email;
        this->date = date_of_birth;
    }
    string get_name()
    {
        return this->name = name;
    }
    int get_phone()
    {
        return this->phone_no;
    }
    string get_email()
    {
        return this->email;
    }
    Birthday get_bd()
    {
        return date;
    }
};
class Contact_book
{
    public:
    int month_user;
    int num;
    int contacts;
    Contact c[5];

    Contact_book()
    {
    }


    void month_birthday()
    {
        cout << "Please Input the month for which you want contacts" << endl;
        cin >> month_user;
    }

    void dis_contacts()
    {
        for(int i=0;i<5;i++)
        {
            cout << c[i].name << endl;
            cout << c[i].get_phone() << endl;
            cout << c[i].email << endl;
            cout << c[i].date.date << "/" << c[i].date.month << "/" << c[i].date.year << endl;
        }
    }


    void emp_bd()
    {

        for (int i =0; i < 5; i++ )
        {
            if (c[i].date.get_month() == month_user)
            {
                cout << c[i].get_name() << endl;
            }
        }
    }
};


int main()
{
    Contact_book cb;
    int choice;
    int choice2;

    do
    {
        cout << endl << "1.Add" << endl << "2. Display with month" << endl << "3.Display All" << endl << "4.End" << endl;
        cin >> choice;

        if (choice == 1)
        {
        cb.c->addContact();
        }
        if (choice == 2)
        {
            cb.month_birthday();
            cb.emp_bd();
        }
        if (choice == 3)
        {
            cb.dis_contacts();
        }
    } while(choice != 4);



 return 0;
}