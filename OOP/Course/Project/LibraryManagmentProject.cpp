#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Book { //Abstract Class : Pure virtual Functions act as an Template
protected:
    string title;
    string author;
    int year;
public:
    Book() {
        title = "";
        author = "";
        year = 0;
    }
    virtual ~Book() {}
    virtual void readData() {
        cout << "Enter Title: ";
        getline(cin, title);
        cout << "Enter Author: ";
        getline(cin, author);
        cout << "Enter Year: ";
        cin >> year;
        cin.ignore(); // ignore newline character left by cin
    }
    virtual void display() const {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "Year: " << year << endl;
    }
    virtual string getType() const {
        return "Book";
    }
    string getTitle() const {
        return title;
    }
    virtual string getDetails() const {
        return title + "," + author + "," + to_string(year);
    }
    virtual void setDetails(const string& details) {
    size_t pos = details.find(',');
    title = details.substr(0, pos);
    string remainingDetails = details.substr(pos + 1);
    pos = remainingDetails.find(',');
    author = remainingDetails.substr(0, pos);
    remainingDetails = remainingDetails.substr(pos + 1);
    year = stoi(remainingDetails);
}
};

class FictionBook : public Book {
private:
    string genre;
public:
    FictionBook() {
        genre = "";
    }
    void readData() override {
        Book::readData();
        cout << "Enter Genre: ";
        getline(cin, genre);
    }
    string getTitle() const {
        return title;
    }
    void display() const override {
        Book::display();
        cout << "Genre: " << genre << endl;
    }
    string getType() const override {
        return "FictionBook";
    }
    string getDetails() const override {
        return Book::getDetails() + "," + genre;
    }
    void setDetails(const string& details) override {
        Book::setDetails(details);
        size_t pos = details.find_last_of(',');
        genre = details.substr(pos + 1);
    }
};

class NonFictionBook : public Book {
private:
    string topic;
public:
    NonFictionBook() {
        topic = "";
    }
    void readData() override {
        Book::readData();
        cout << "Enter Topic: ";
        getline(cin, topic);
    }
    void display() const override {
        Book::display();
        cout << "Topic: " << topic << endl;
    }
    string getType() const override {
        return "NonFictionBook";
    }
    string getDetails() const override {
        return Book::getDetails() + "," + topic;
    }
    void setDetails(const string& details) override {
        Book::setDetails(details);
        size_t pos = details.find_last_of(',');
        topic = details.substr(pos + 1);
    }
};

class ReferenceBook : public Book {
private:
    string publisher;
public:
    ReferenceBook() {
        publisher = "";
    }
    void readData() override {
        Book::readData();
        cout << "Enter Publisher: ";
        getline(cin, publisher);
    }
    void display() const override {
        Book::display();
        cout << "Publisher: " << publisher << endl;
    }
    string getType() const override {
        return "ReferenceBook";
    }
    string getDetails() const override {
        return Book::getDetails() + "," + publisher;
    }
    void setDetails(const string& details) override {
        Book::setDetails(details);
        size_t pos = details.find_last_of(',');
        publisher = details.substr(pos + 1);
    }
};

class Customer {
private:
    string name;
    string address;
    string phone;
    vector<Book*> borrowedBooks; // list of borrowed books

public:
    Customer() {
        name = "";
        address = "";
        phone = "";
    }
    void readData(const string& details) {
    size_t pos1 = details.find(',');
    size_t pos2 = details.rfind(',');
    name = details.substr(0, pos1);
    address = details.substr(pos1 + 1, pos2 - pos1 - 1);
    phone = details.substr(pos2 + 1);
}
    void display() const {
        cout << "Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phone << endl;
    }
    string getDetails() const {
        return name + "," + address + "," + phone + ",";
    }
    Customer& operator=(const Customer& other) {
        if (this != &other) {
            name = other.name;
            address = other.address;
            phone = other.phone;
        }
        return *this;
    }
void borrowBook(Book* book, ofstream& outFile) {
    borrowedBooks.push_back(book);
    outFile << name << "," << book->getTitle() << endl;
    cout << "Book \"" << book->getTitle() << "\" borrowed successfully by " << name << "." << endl;
}

};

class Library {
private:
    vector<Book*> books;
    vector<Customer> customers;

void addBook() {
    int choice;
    do {
        cout << "Select Book Type:" << endl;
        cout << "1. Fiction Book" << endl;
        cout << "2. Non-Fiction Book" << endl;
        cout << "3. Reference Book" << endl;
        cout << "Enter Choice: ";
        cin >> choice;
        cin.ignore(); // ignore newline character left by cin
    } while (choice < 1 || choice > 3);
    Book* book = nullptr;
    try {
        switch (choice) {
            case 1:
                book = new FictionBook();
                break;
            case 2:
                book = new NonFictionBook();
                break;
            case 3:
                book = new ReferenceBook();
                break;
        }
        book->readData();
        books.push_back(book);
        cout << "Book added successfully." << endl;
    } catch (const exception& e) {
        delete book;
        throw runtime_error("Error: " + string(e.what()));
    }
}
void addCustomer() {
    Customer customer;
    string details;
    cout << "Enter Name, Address, and Phone (comma-separated): ";
    getline(cin, details);
    customer.readData(details);
    customers.push_back(customer);
    cout << "Customer added successfully." << endl;
}

    void displayBooks() const {
        for (const auto& book : books) {
            book->display();
            cout << endl;
        }
    }

    void searchBook(const string& searchTerm) const {
        bool found = false;
        for (const auto& book : books) {
            string title = book->getType() + ": " + book->getDetails();
            if (title.find(searchTerm) != string::npos) {
                book->display();
                cout << endl;
                found = true;
            }
        }
        if (!found) {
            cout << "No books found matching \"" << searchTerm << "\"." << endl;
        }
    }

    void loadBooksFromFile() {
    ifstream inFile("books.txt");
    if (!inFile) {
        throw runtime_error("Error: could not open file books.txt for reading.");
    } else {
        string line;
        while (getline(inFile, line)) {
            size_t pos = line.find(',');
            string type = line.substr(0, pos);
            line = line.substr(pos + 1);
            Book* book = nullptr;
            if (type == "FictionBook") {
                book = new FictionBook();
            } else if (type == "NonFictionBook") {
                book = new NonFictionBook();
            } else if (type == "ReferenceBook") {
                book = new ReferenceBook();
            } else {
                throw runtime_error("Error: unknown book type \"" + type + "\" found in file.");
            }
            try {
                book->setDetails(line);
                books.push_back(book);
            } catch (const exception& e) {
                delete book;
                throw runtime_error("Error: " + string(e.what()));
            }
        }
        inFile.close();
        cout << "Books loaded from file books.txt." << endl;
    }
}

    void loadCustomersFromFile() {
    ifstream inFile("customers.txt");
    if (!inFile) {
        cout << "Error: could not open file customers.txt for reading." << endl;
    } else {
        string line;
        while (getline(inFile, line)) {
            size_t pos = line.find(',');
            string name = line.substr(0, pos);
            string address = line.substr(pos + 1);
            Customer customer;
            customer.readData(name);
            customers.push_back(customer);
        }
        inFile.close();
        cout << "Customers loaded from file customers.txt." << endl;
    }
}
void saveDataToFile() const {
    ofstream outFile("borrowers.txt");
    if (outFile) {
        for (const auto& customer : customers) {
            outFile << customer.getDetails() << endl;
        }
        outFile.close();
        cout << "Borrowers saved to file borrowers.txt." << endl;
    } else {
        cout << "Error: could not open file borrowers.txt for writing." << endl;
    }

    outFile.open("books.txt");
    if (outFile) {
        for (const auto& book : books) {
            outFile << book->getType() << "," << book->getDetails() << endl;
        }
        outFile.close();
        cout << "Books saved to file books.txt." << endl;
    } else {
        cout << "Error: could not open file books.txt for writing." << endl;
    }

    outFile.open("customers.txt");
    if (outFile) {
        for (const auto& customer : customers) {
            outFile << customer.getDetails() << endl;
        }
        outFile.close();
        cout << "Customers saved to file customers.txt." << endl;
    } else {
        cout << "Error: could not open file customers.txt for writing." << endl;
    }
}

    void displayCustomers() const {
        for (const auto& customer : customers) {
            customer.display();
            cout << endl;
        }
    }

public:
    Library() {}
    ~Library() {
        for (const auto& book : books) {
            delete book;
        }
    }

void run() {
    loadBooksFromFile();
    loadCustomersFromFile();
    int choice;
    do {
        cout << endl;
        cout << "Welcome to the Library Management System!" << endl;
        cout << "Select Operation:" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Add Customer" << endl;
        cout << "3. Display Books" << endl;
        cout << "4. Search Books" << endl;
        cout << "5. Display Customers" << endl;
        cout << "6. Borrow Book" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter Choice: ";
        cin >> choice;
        cin.ignore(); // ignore newline character left by cin
        switch (choice) {
            case 1:
                addBook();
                break;
            case 2:
                addCustomer();
                break;
            case 3:
                displayBooks();
                break;
            case 4: {
                string searchTerm;
                cout << "Enter search term: ";
                getline(cin, searchTerm);
                searchBook(searchTerm);
                break;
            }
            case 5:
                displayCustomers();
                break;
           case 6: {
                string customerName;
                string bookTitle;
                cout << "Enter customer name: ";
                getline(cin, customerName);
                auto it = find_if(customers.begin(), customers.end(), [&customerName](const Customer& customer) {
                    return customer.getDetails().find(customerName) != string::npos;
                });
                if (it == customers.end()) {
                    cout << "Error: customer not found." << endl;
                    break;
                }

                cout << "Enter book title: ";
                getline(cin, bookTitle);
                auto bookIt = find_if(books.begin(), books.end(), [&bookTitle](const Book* book) {
                    return book->getTitle().find(bookTitle) != string::npos;
                });
                if (bookIt == books.end()) {
                    cout << "Error: book not found." << endl;
                    break;
                }

                ofstream outFile("borrowers.txt", ios::app);
                if (!outFile) {
                    cout << "Error: could not open file borrowers.txt for writing." << endl;
                    break;
                }

                (*it).borrowBook(*bookIt, outFile);
                outFile.close();
                break;
}
            case 7:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid Choice!" << endl;
                break;
        }
    } while (choice != 7);
        saveDataToFile();
}
};

int main() {
    Library library;
    library.run();
    return 0;
}