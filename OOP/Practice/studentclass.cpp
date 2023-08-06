#include <iostream>

using namespace std;

class studentdata
{
    private:

    int rollnumber;
    float totalmarks;
    float obtainedmarks;
    float percentage;

    public:

    //Constructor

    studentdata()
    {
     rollnumber=0;
     totalmarks=0;
     obtainedmarks=0;
     percentage=0;
    }

    //setters

    void set_rollnumber(int rollnumber)
    {
        this->rollnumber=rollnumber;
    }

    void set_totalmarks(float totalmarks)
    {
        this->totalmarks= totalmarks;
    }

    void set_obtainedmarks(int obtainedmarks)
    {
        this->obtainedmarks=obtainedmarks;
    }

    void set_percent()
    {
        this -> percentage= (obtainedmarks/totalmarks)*100;
    }

    //getters


    int get_rollnumber()
    {
        return this->rollnumber;
    }
    float get_totalmarks()
    {
        return this->totalmarks;
    }
    int set_obtainedmarks()
    {
        return this->obtainedmarks;
    }

        float get_percent()
    {
        return this -> percentage;
    }

};

int main()
{
    int rollnumber;
    float totalmarks=200;
    float obtainedmarks;

    cout << "Please Input Roll Number" << endl;
    cin >> rollnumber;
    cout << "Please Input Obtained Marks" << endl;
    cin >> obtainedmarks;

    studentdata s1;
    s1.set_rollnumber(rollnumber);
    s1.set_obtainedmarks(obtainedmarks);
    s1.set_totalmarks(totalmarks);
    s1.set_percent();

    cout << s1.get_rollnumber() << endl;
    cout << s1.get_totalmarks() << endl;
    cout << s1.set_obtainedmarks() << endl;
    cout << s1.get_percent() << endl;


 return 0;
}