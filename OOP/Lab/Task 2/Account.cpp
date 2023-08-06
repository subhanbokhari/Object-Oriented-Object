#include <iostream>
using namespace std;

class Account
{
    private :

     string name;
     int balance;

    public :

     void set_amount(int amount)
     {
        balance = amount;
     }

     void set_name(string name)
     {
        this->name=name;
     }

     int get_amount()
     {
        return this->balance;
     }
     string get_name()
     {
        return this->name;
     }

     void deposit_amount(int amount)
     {
        balance = balance + amount;
     }
     void withdraw_amount(int amount)
     {
        if (amount <= balance)
        {
            balance = balance - amount;
        }
     }
};

Account create_acount(string name, int amount)
{
    Account a1;
    a1.set_name(name);
    a1.set_amount(amount); 

    return a1;
}


int main()
{
    string name;
    int amount;
    Account a1;
    int option = 0;

    cout << "Please Input your name" << endl;
    cin >> name;
    cout << "Please Input the Amount" << endl;
    cin >> amount;

    a1 = create_acount(name,amount);

    while(option == 4){ 
      cout << "Please Press" << endl << "1.Display balance" << endl << "2.Deposit Amount" << endl << "3.Withdraw Amount" << endl << "4.Exit" << endl;
      cin >> option;
      
      if (option == 1)
      {
         cout << "Balance: " << a1.get_amount() << endl;
      }
      else if (option == 2)
      {
         cout << "How much do you want to deposit?";
         cin >> amount;
         a1.deposit_amount(amount);
         cout << "New Amount =" << a1.get_amount() << endl;
      }
      else if(option == 3)
      {
         cout << "How much do you want to Withdraw?";
         cin >> amount;
         a1.withdraw_amount(amount);
         cout << "New Balance =" << a1.get_amount() << endl;
      }
      else if (option != 4)
      {
         cout << "Exited.";
      }
    } 
return 0;
}