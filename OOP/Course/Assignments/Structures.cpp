#include <iostream>
using namespace std;

struct Movie_data
{
    string title;
    string director;
    int year_released;

    void Create_Movie_data(string title, string director, int year_released)
    {
        this-> title = title;
        this-> director = director;
        this-> year_released = year_released;

    }
    void Display_Movie_Data()
    {
        cout << endl <<  "Movie Title: " << this->title << endl;
        cout << "Director: " << this->director << endl;
        cout << "Year released: " << this->year_released << endl;
        cout << "------------------------------------------------------";

    }
};


int main()
{
    Movie_data titanic;
    titanic.Create_Movie_data("Titanic","James Cameron",1997);
    titanic.Display_Movie_Data();


    Movie_data insidious;
    insidious.Create_Movie_data("Insidious","James Wan",2011);
    insidious.Display_Movie_Data();

    return 0;
}