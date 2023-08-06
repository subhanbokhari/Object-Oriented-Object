#include<iostream>
#include<typeinfo>
#include<string>

using namespace std;

struct student{
	int rollno;
	int marks[3];
	string final_result;
	
	
	void output(){
		cout<<"\nRoll no: "<<rollno;
		
		for(int i=0;i<=2;i++)
		{
			cout<<"\nScore "<<i<<" : "<<marks[i];
		}
			cout<<"\n Final Result: "<<final_result;
	}
	
	
};


int main()
{
	
student student1;
student1.rollno=445;

student1.marks[0]=12;
student1.marks[1]=34;
student1.marks[2]=55;

student1.final_result="Fail try again";

student1.output();
	
	
	return 0;
	
}