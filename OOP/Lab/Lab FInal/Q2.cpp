#include <iostream>
#include <vector>
using namespace std;

class Item
{
protected:
    int number;
public:
    Item(int num = 0) : number(num) {}
    virtual void setDetails() = 0;
    virtual void getDetails() = 0;
};

class Book : public Item
{
    string title;
    int pages;
public:
    Book(int num = 0, string title = "Null", int pages = 0) : Item(num), title(title), pages(pages) {}
    void setDetails()
    {
        cout << "Enter Book Number: ";
        cin >> number;
        cout << "Enter Title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter Total Pages: ";
        cin >> pages;
    }
    void getDetails()
    {
        cout << "Book Number: " << number << endl;
        cout << "Title: " << title << endl;
        cout << "Total Pages: " << pages << endl;
    }
};

class DVD : public Item
{
    int mins;
    string speaker;
public:
    DVD(int num = 0, int mins = 0, string speaker = "") : Item(num), mins(mins), speaker(speaker) {}
    void setDetails()
    {
        cout << "Enter DVD Number: ";
        cin >> number;
        cout << "Enter Total Minutes: ";
        cin >> mins;
        cout << "Enter Speaker: ";
        cin.ignore();
        getline(cin, speaker);
    }
    void getDetails()
    {
        cout << "DVD Number: " << number << endl;
        cout << "Total Minutes: " << mins << endl;
        cout << "Speaker: " << speaker << endl;
    }
};

class Magazine : public Item
{
    int issue_num;
    string title;
public:
    Magazine(int issueNum = 0, string title = "") : issue_num(issueNum), title(title) {}
    void setDetails()
    {
        cout << "Enter Magazine Number: ";
        cin >> number;
        cout << "Enter Title: ";
        cin.ignore();
        getline(cin, title);
        cout << "Enter Issue Number: ";
        cin >> issue_num;
    }
    void getDetails()
    {
        cout << "Magazine Number: " << number << endl;
        cout << "Title: " << title << endl;
        cout << "Issue Number: " << issue_num << endl;
    }
};

class Library
{
    vector<Item*> items;
public:
    void addItem(Item* item)
    {
        items.push_back(item);
    }
    void displayItems()
    {
        if (items.empty())
        {
            cout << "No items in the library." << endl;
            return;
        }
        cout << "Library Items:" << endl;
        for (Item* item : items)
        {
            item->getDetails();
            cout << endl;
        }
    }
};

int main()
{
    Library library;
    int choice;
    do
    {
        cout << "Library Management System" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Add DVD" << endl;
        cout << "3. Add Magazine" << endl;
        cout << "4. Display Library Items" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            Book* book = new Book();
            book->setDetails();
            library.addItem(book);
        }
        case 2:
        {
            DVD* dvd = new DVD();
            dvd->setDetails();
            library.addItem(dvd);
        }
        case 3:
        {
            Magazine* magazine = new Magazine;
            magazine->setDetails();
            library.addItem(magazine);

        }
        case 4:
        {
            library.displayItems();
        }
        case 5:
        {
            break;
        }
        }
    } while (choice != 5);

    return 0;
}

