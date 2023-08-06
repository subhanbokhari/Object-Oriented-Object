#include <iostream>
using namespace std;

class Animal
{
    public:
    string name;
    int age;
    Animal(string name="Null", int age=0)
    {
        this -> name = name;
        this -> age = age;
    }
    virtual void speak()
    {
    }
};
class Reptile : private Animal
{
    private:
    string habitat;
    public:
    Reptile (string name, int age, string habitat) : Animal(name,age)
    {
        this -> habitat = habitat;
    }
    void speak()
    {
        cout << "My name is: " << name <<" My age is: "<< age << endl <<" I am a Reptile and I can creep..." << endl;
    }
};
class Bird : private Animal
{
    private:
    int wingLength;
    public:
    Bird (string name, int age, int wingLength) : Animal(name,age)

    {
        this -> wingLength = wingLength;
    }
    void speak()
    {
        cout << "My name is: " << name  << " My age is: "<< age << endl << " I am a Reptile and sing..." << endl;
    }    
};


int main()
{
    Bird bird("sparrow",2,10);
    Reptile reptile("Lizard",4,"Forest");

    bird.speak();
    reptile.speak();

 return 0;
}