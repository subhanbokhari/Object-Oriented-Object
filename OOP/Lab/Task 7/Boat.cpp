#include <iostream>
using namespace std;

class Boat
{
    public:
    int boatLength;

    Boat(int boatLength = 0)
    {
        this->boatLength = boatLength;
    }
    void swim()
    {
        cout << "I am Swimming" << endl;
    }
};
class Plane
{
    public:
    int maxAltitude;

    Plane(int maxAltitude = 0)
    {
        this->maxAltitude = maxAltitude;
    }
    void fly()
    {
        cout << "I am Flying" << endl;
    }
};
class Skimmer : protected Boat, Plane
{
    int numPassengers;

    public:
    Skimmer(int bl, int ma, int numPassengers) : Boat(boatLength), Plane(maxAltitude) 
    {
        this->numPassengers = numPassengers;
    }
    void swimAndFly()
    {
        swim();
        fly();
    }
    void display() 
    {
        cout << endl << "Skimmer Name : Swim & Fly  Length: " << boatLength << "ft," << " Max Altitude: " << maxAltitude << "ft," << "Passengers: " << numPassengers << endl;
    }    
};

int main()
{
    Skimmer skimmer(40, 13000, 2);
    skimmer.display();
    skimmer.swimAndFly();
    cout << endl << "-------------------------------------------" << endl;

 return 0;
}