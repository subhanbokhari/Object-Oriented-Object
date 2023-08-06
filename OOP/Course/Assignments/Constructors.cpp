#include <iostream>
using namespace std;

class Cars
{
    public:
    string company;
    string model;
    int year;
    int price;

    public:

    // Cars() //Default Constructor
    // {
    //  company = "Mercedes";
    //  model = "E-class";
    //  year = 2022 ;
    // }

    Cars(string company = "Mercedes", string model = "S-Class", int year = 2022) //3 Parameter Constructor
    {
        this -> company = company;
        this -> model = model;
        this -> year = year;
    }

    void get_price(int price)
    {
        this -> price = price;
    }

};

int main()
{

    int price;
    Cars bmw("Bmw" ,"M5",2022);

    int price2;
    Cars mercedes;

    cout << "Please Input Price" << endl;
    cin >> price;

    bmw.get_price(price);

}