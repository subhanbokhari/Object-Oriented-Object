#include <iostream>
#include <string>
using namespace std;

class Date {
private:
    int day, month, year;
public:
    Date(int day = 1, int month = 1, int year = 1970) {
        this->day = day;
        this->month = month;
        this->year = year;
    }
    int getDay() const {
        return day;
    }
    int getMonth() const {
        return month;
    }
    int getYear() const {
        return year;
    }
};

class Contact {
private:
    string name, phone_no, email;
    Date date_of_birth;
public:
    Contact(string name, string phone_no, string email, Date date_of_birth) {
        this->name = name;
        this->phone_no = phone_no;
        this->email = email;
        this->date_of_birth = date_of_birth;
    }
    string getName() const {
        return name;
    }
    string getPhoneNo() const {
        return phone_no;
    }
    string getEmail() const {
        return email;
    }
    Date getDateOfBirth() const {
        return date_of_birth;
    }
};

class ContactBook {
private:
    Contact* contacts;
    int size;
public:
    ContactBook(int size) {
        this->size = size;
        contacts = new Contact[size];
    }
    ~ContactBook() {
        delete[] contacts;
    }
    void addContact() {
        string name, phone_no, email;
        int day, month, year;

        cout << "Enter the name: ";
        cin >> name;
        cout << "Enter the phone number: ";
        cin >> phone_no;
        cout << "Enter the email: ";
        cin >> email;
        cout << "Enter the date of birth (DD MM YYYY): ";
        cin >> day >> month >> year;

        Date date_of_birth(day, month, year);
        Contact new_contact(name, phone_no, email, date_of_birth);

        for (int i = 0; i < size; i++) {
            if (contacts[i].getName() == "") {
                contacts[i] = new_contact;
                break;
            }
        }
    }
    void printContactsByMonth(int month) {
        bool found = false;
        for (int i = 0; i < size; i++) {
            if (contacts[i].getName() != "") {
                Date date_of_birth = contacts[i].getDateOfBirth();
                if (date_of_birth.getMonth() == month) {
                    cout << contacts[i].getName() << endl;
                    found = true;
                }
            }
        }
        if (!found) {
            cout << "No contacts found with a birthday in this month." << endl;
        }
    }
};

int main() {
    int size, choice, month;
    cout << "Enter the size of the contact book: ";
    cin >> size;
    ContactBook book(size);
    while (true) {
        cout << endl << "Select an option:" << endl;
        cout << "1. Add contact" << endl;
        cout << "2. Print contacts by month" << endl;
        cout << "3. Search contact by name" << endl;
        cout << "4. Update contact" << endl;
        cout << "5. Delete contact" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
        case 1:
            book.addContact();
            break;
        case 2:
            cout << "Enter the month (1-12)";
            cin >> month;
            book.printContactsByMonth(month);
            break;

        case 6:
            return 0;
        default:
            cout << "Invalid choice. Please try again." << endl;
            break;
        }
    }
}