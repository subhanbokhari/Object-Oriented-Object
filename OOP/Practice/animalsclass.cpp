#include <iostream>
using namespace std;

class animals
{
    private:

    string type;
    string name;
    int age;
    string sound;

    public:

    void input()
    {
        //Setters
        cout << "Please Input Type of the Animal" << endl;
        cin >> type;
        cout << "Please Input Name of the Animal" << endl;
        cin >> name;
        cout << "Please Input the Age of "<<name << endl;
        cin >> age;
        cout << "Please Input The Sound of "<<name << endl;
        cin >> sound;
    }

    void out()
    {
        //Getters
        cout << "Type: " << type << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Sound: " << sound << endl;
    }
};

int main()
{
    animals A1;
    
    A1.input();
    A1.out();

    return 0;
}

