#include <iostream>
#include <string>

using namespace std;

class Brain {
private:
    string state;
public:
    Brain() {
        state = "awake";
    }
    string getState() {
        return state;
    }
    void setState(string newState) {
        state = newState;
    }
};

class Heart {
private:
    int rate;
public:
    Heart() {
        rate = 80;
    }
    int getRate() {
        return rate;
    }
    void setRate(int newRate) {
        rate = newRate;
    }
};

class Legs {
private:
    int steps;
public:
    Legs() {
        steps = 0;
    }
    int getSteps() {
        return steps;
    }
    void setSteps(int newSteps) {
        steps = newSteps;
    }
    void walk() {
        steps++;
    }
};

class Person {
private:
    string name;
    int age;
    Brain brain;
    Heart heart;
    Legs legs;
public:
    Person(string n, int a) {
        name = n;
        age = a;
    }
    string getName() {
        return name;
    }
    int getAge() {
        return age;
    }
    string getBrainState() {
        return brain.getState();
    }
    void setBrainState(string newState) {
        brain.setState(newState);
    }
    int getHeartRate() {
        return heart.getRate();
    }
    void setHeartRate(int newRate) {
        heart.setRate(newRate);
    }
    int getSteps() {
        return legs.getSteps();
    }
    void setSteps(int newSteps) {
        legs.setSteps(newSteps);
    }
    void walk() {
        legs.walk();
    }
};

int main() {
    Person john("John", 30);

    cout << "Name: " << john.getName() << endl;
    cout << "Age: " << john.getAge() << endl;

    cout << "Brain state: " << john.getBrainState() << endl;
    john.setBrainState("asleep");
    cout << "Brain state: " << john.getBrainState() << endl;

    cout << "Heart rate: " << john.getHeartRate() << endl;
    john.setHeartRate(90);
    cout << "Heart rate: " << john.getHeartRate() << endl;

    cout << "Steps: " << john.getSteps() << endl;
    john.walk();
    john.walk();
    cout << "Steps: " << john.getSteps() << endl;

    return 0;
}