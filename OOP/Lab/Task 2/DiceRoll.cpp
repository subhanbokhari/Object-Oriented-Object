#include<iostream>
#include<stdlib.h>
#include<time.h>
using namespace std;
class Dice
{
    private:
    int value;

    public:
    Dice()
    {
        value = 0;
    }
    int roll()
    {
       srand(time(0));sched_yield;
       value = rand()%6+1;
       return value;
    }
};

int main()
{
    Dice obj;
    char ch;
    cout<<"\n Do you want to roll the dice? Y/N : ";
    cin>>ch;
    while(ch=='y' || ch=='Y')
    {
        int check = obj.roll();
        if(check >= 1 && check <6 )
        {
            cout<<check<<" :  Best of luck"<<endl;
        }
        else
          cout<<check<<" : chakaaaa"<<endl;
        
        cout<<"\n Do you want to roll the dice? Y/N : ";
        cin>>ch;
    }
}