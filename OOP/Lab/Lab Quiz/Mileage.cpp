#include <iostream>
using namespace std;

// Base class to represent a single trip
class Trip {
protected:
    int miles;
    int gallons;

public:
    Trip(int m, int g) {
        miles = m;
        gallons = g;
    }

    virtual void display() = 0;

    float calculate_mpg() {
        return (float)((miles) / gallons);
    }

    int get_miles()
    {
        return miles;
    }

    int get_gallons()
    {
        return gallons;
    }
};

// Derived class for multiple trips and calculate the overall mpg
class Trips {
private:
    int total_miles;
    int total_gallons;
    int trip_count;

public:
    Trips() {
        total_miles = 0;
        total_gallons = 0;
        trip_count = 0;
    }

    void add_trip(Trip *trip) {
        total_miles += trip->get_miles();
        total_gallons += trip->get_gallons();
        trip_count++;
        display();
    }

    float calculate_total_mpg() {
        return (float)((total_miles) / total_gallons);
    }

    virtual void display() {
        cout << "Trip added. Total MPG: " << calculate_total_mpg() << endl << endl;
    }
};

// Derived class to represent a single trip and display its mpg
class SingleTrip : public Trip {
public:
    SingleTrip(int m, int g) : Trip(m, g) {}

    virtual void display() {
        cout << "MPG this trip: " << calculate_mpg() << endl;
    }
};

int main() {
    int t;
    cout << "For How many Trips?";
    cin >> t;


    Trips trips;
    int miles, gallons;

    if(t>1)
    {
        cout << "Enter miles driven (-1 to quit): ";
        cin >> miles;

        while (miles != -1) {
            cout << "Enter gallons used: ";
            cin >> gallons;

            Trip *trip = new SingleTrip(miles, gallons);
            trips.add_trip(trip);

            cout << "Enter miles driven (-1 to quit): ";
            cin >> miles;

        }
        cout << "Thank You For Using." << endl;
    }
    else if(t=1)
    {
      int m1;
      int g1;
      cout << "Enter Miles" << endl;
      cin >> m1;
      cout << "Enter Gallons" << endl;
      cin >> g1;

      SingleTrip s1(m1,g1);
      s1.calculate_mpg();
      s1.display();
      cout << "Thank You For Using." << endl;

    }
    else if(t=0)
    {
        cout << "Thank You For Using." << endl;
    }


    return 0;
}
