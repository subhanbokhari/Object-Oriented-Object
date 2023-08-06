#include <iostream>
using namespace std;

class inventory
{
    private:
        int id;
        string name;
        int price;
        int quantity;
    public:
        inventory(int id = 0 , string name = "Null", float price = 0.0, int quantity = 0)
        {
            this -> id = id;
            this -> name = name;
            this -> price = price;
            this -> quantity = quantity;
        }

        void set_details (int id, string name, int price, int quantity)
        {
            this -> id = id;
            this -> name = name;
            this -> price = price;
            this -> quantity = quantity;
        }
        
        ~inventory()
        {
            cout << "Object Destroyed!" << endl;
        }

        void display_item(int num, inventory items[]);
        void update_item(inventory items[],int change, int i);
        void search_item(int id, int size);
};

void inventory :: display_item(int num, inventory items[])
{
    for (int i = 0; i < num; i++)
    {
        cout << "ID:" << id << endl;
        cout << "Name:" << name << endl;
        cout << "Price:" << price << endl;
        cout << "Quantity:" << quantity << endl;
    }
}
void inventory :: update_item(inventory items[],int change, int i)
{
    this -> id = id;
    this -> name = name;
    this -> price = price;
    this -> quantity = quantity;
}
void inventory :: search_item(int id, int size)
{
    if ( this -> id == id)
    {
        cout << "Found!" << endl;
        cout << "ID:" << id << endl;
        cout << "Name:" << name << endl;
        cout << "Price:" << price << endl;
        cout << "Quantity:" << quantity << endl;
    }
}

int main()
{
    int choice,choice2,id,id2,price2,price,quantity;
    string name;

    cout << "Total Items?" << endl;
    cin >> choice;

    inventory items[choice];

    for (int i = 0; i < choice; i++)
    {
        cout << "Please Enter The ID " << endl; cin >> id2;
        cout << "Please Enter The Name" << endl; cin >> name;
        cout << "Please Enter The Price" << endl; cin >> price2;
        cout << "Please Enter The Quantity" << endl; cin >> quantity;
        items[i].set_details(id2,name,price2,quantity);
    }

    cout << "1. Display Items" << endl << "2. Update item details" << endl << "3. Search for items by ID" << endl << "4. End" << endl;
    cin >> choice2;
    {
        if (choice2 == 1)
        {
            for (int i =0; i < choice; i++)
            {
                items[i].display_item(i,items);
            }
        }
        if (choice2 == 2)
        {
            cout << "Which item please enter";
            cin >> choice;

            cout << "What do you want to update, 1. Price or 2. Quantity?" << endl;
            cin >> choice2;

            if (choice2 == 1)
            {
                cout << "Please Enter New Price";
                cin >> price;
                items[choice].update_item(items,price,choice);            
            }
            if (choice2 == 2)
            {
                cout << "Please Enter New Quantity" << endl;
                cin >> price;
                items[choice].update_item(items,price,choice);
            }
        }
        if (choice2 == 3)
        {
            cout << "Please enter the id" << endl;
            cin >> id;
            for (int i = 0; i < choice; i++  )
            {
                items[i].search_item(id,choice);
            }
        }
        if (choice2 != 1 && choice2 !=2 && choice2==3)
        {
            cout << "Input Out of Bound!" << endl;
        }
    }
    return 0;
}