#include <iostream>
using namespace std;

class Airline_tickets
{
    private:
    string dep_city;
    string arr_city;
    int flight_no;
    string seat_no;
    public:
    Airline_tickets(string dep_city="NULL", string arr_city="NULL", int flight_no=0, string seat_no = "0A")
    {
        this -> dep_city = dep_city;
        this -> arr_city = arr_city;
        this -> flight_no = flight_no;
        this -> seat_no = seat_no; 
    }
    void get_info (Airline_tickets a1)
    {
        cout << "Arrival: " << a1.arr_city << endl;
        cout << "Departure: " << a1.dep_city << endl;
        cout << "Flight No: " << a1.flight_no << endl;
        cout << "Your Seat Number is :" << a1.seat_no << endl;
    }
};

int main()
{
    Airline_tickets a1("Peshawar","Lahore",12,"41F");
    a1.get_info(a1);


    return 0;

}