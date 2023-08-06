#include <iostream>
#include <cstdlib>
#include <ctime>
#include <unistd.h> // for sleep()

using namespace std;

// Define the length of the race track
const int TRACK_LENGTH = 70;

// Define the movements of the tortoise and the hare
const int NUM_HARE_MOVES = 5;
const int HARE_MOVES[NUM_HARE_MOVES] = { 0, 1, 2, 9, 12 };

const int NUM_TORTOISE_MOVES = 3;
const int TORTOISE_MOVES[NUM_TORTOISE_MOVES] = { 1, 6, 3 };


// Define a class for the animals
class Animal {
public:
    Animal(const string& name, int position) : name_(name), position_(position) {}
    virtual void move() = 0;
    const string& name() const { return name_; }
    int position() const { return position_; }
protected:
    string name_;
    int position_;
};

// Define a class for the tortoise
class Tortoise : public Animal {
public:
    Tortoise(int position) : Animal("Tortoise", position) {}
    virtual void move() override {
        int move = TORTOISE_MOVES[rand() % NUM_TORTOISE_MOVES];
        position_ = max(1, min(position_ + move, TRACK_LENGTH));
    }
};

// Define a class for the hare
class Hare : public Animal {
public:
    Hare(int position) : Animal("Hare", position) {}
    virtual void move() {
        int move = HARE_MOVES[rand() % NUM_HARE_MOVES];
        position_ = max(1, min(position_ + move, TRACK_LENGTH));
    }
};

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Create the tortoise and the hare
    Tortoise tortoise(1);
    Hare hare(1);

    // Print the starting positions of the animals
    cout << "BANG !!!!!\nAND THEY'RE OFF !!!!!\n" << endl;
    cout << tortoise.name() << ": " << string(tortoise.position() - 1, '-') << "T" << endl;
    cout << hare.name() << ": " << string(hare.position() - 1, '-') << "H" << endl;

    // Loop until one of the animals reaches the end of the track
    int timer = 0;
    while (tortoise.position() < TRACK_LENGTH && hare.position() < TRACK_LENGTH) {
        tortoise.move();
        hare.move();


        //Print the current positions of the animals
        cout << tortoise.name() << ": " << string(tortoise.position() - 1, '-') << "T" << endl;
        cout << hare.name() << ": " << string(hare.position() - 1, '-') << "H" << endl;

        // Wait for one second
        sleep(1);

        // Increment the timer
        timer++;
    }


    // Determine the winner of the race
    if (tortoise.position() >= TRACK_LENGTH && hare.position() >= TRACK_LENGTH) {
        cout << "It's a tie!" << endl;
        cout << "Both animals get carrots and lettuce!" << endl;
    }
    else if (tortoise.position() >= TRACK_LENGTH) {
        cout << "TORTOISE WINS!!!" << endl;
        cout << "Tortoise gets the carrots and lettuce!" << endl;
    }
    else {
        cout << "Hare wins. Yuch." << endl;
        cout << "Hare gets the carrots and lettuce!" << endl;
    }

    // Print the time taken for the race to finish
    cout << "The race lasted for " << timer << " seconds." << endl;

    return 0;
}