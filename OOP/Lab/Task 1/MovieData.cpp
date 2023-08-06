#include <iostream>
using namespace std;

struct Movie_data
{
    string title;
    string director;
    int year_released;
};

Movie_data Create_Movie_data(string title, string director, int year_released)
{
    Movie_data m;

    m.title = title;
    m.director = director;
    m.year_released = year_released;

    return m;
}
void Display_Movie_Data( Movie_data m)
{
    cout << endl <<  "Movie Title: " << m.title << endl;
    cout << "Director: " << m.director << endl;
    cout << "Year released: " << m.year_released << endl;
    cout << "------------------------------------------------------";
}


int main()
{
    Movie_data m1;

    m1 = Create_Movie_data("Titanic","James Cameron",1997);
    Display_Movie_Data(m1);


    Movie_data m2;

    m2 = Create_Movie_data("Insidious","James Wan",2011);
    Display_Movie_Data(m2);

    return 0;
}