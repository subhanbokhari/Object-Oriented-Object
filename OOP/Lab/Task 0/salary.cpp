#include<iostream>

using namespace std;

struct employee{
	int numid;
	string name;
	int age;
	long salary;
	
	void output(){
		cout<<"\n Num id:"<<numid;
		cout<<"\n Name:"<<name;
		cout<<"\n Age:"<<age;
		cout<<"\n Salary: $"<<salary;
		
	}
	
};

int main()
{
	
employee e1;

e1.age=35;
e1.name="Kamil";
e1.numid=76541;
e1.salary=4500;	
e1.output();
	
return 0;	
}


