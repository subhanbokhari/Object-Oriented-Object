#include <iostream>
#include <string>

using namespace std;

class Room {
protected:
    int roomNo;
    string type;
    string checkInTime;
    string checkOutTime;
    double rent;
    bool occupied;
public:
    Room(int no, string t, string inTime, string outTime, double r) {
        roomNo = no;
        type = t;
        checkInTime = inTime;
        checkOutTime = outTime;
        rent = r;
        occupied = false;
    }
    int getRoomNo() {
        return roomNo;
    }
    string getType() {
        return type;
    }
    string getCheckInTime() {
        return checkInTime;
    }
    string getCheckOutTime() {
        return checkOutTime;
    }
    double getRent() {
        return rent;
    }
    bool isOccupied() {
        return occupied;
    }
    virtual void setOccupied(bool value) {
        occupied = value;
    }
};

class BasicRoom : public Room {
public:
    BasicRoom(int no, string inTime, string outTime) : Room(no, "Basic", inTime, outTime, 50.0) {}
};

class StandardRoom : public Room {
public:
    StandardRoom(int no, string inTime, string outTime) : Room(no, "Standard", inTime, outTime, 100.0) {}
};

class LuxuryRoom : public Room {
public:
    LuxuryRoom(int no, string inTime, string outTime) : Room(no, "Luxury", inTime, outTime, 200.0) {}
};

class Hotel {
private:
    string name;
    string location;
    string owner;
    Room* rooms[100]; // maximum of 100 rooms
    int numRooms;
public:
    Hotel(string n, string l, string o) {
        name = n;
        location = l;
        owner = o;
        numRooms = 0;
    }
    string getName() {
        return name;
    }
    string getLocation() {
        return location;
    }
    string getOwner() {
        return owner;
    }
    void addRoom(Room* r) {
        rooms[numRooms++] = r;
    }
    void checkIn(int roomNo) {
        for (int i = 0; i < numRooms; i++) {
            if (rooms[i]->getRoomNo() == roomNo) {
                rooms[i]->setOccupied(true);
                cout << "Room " << roomNo << " is now occupied." << endl;
                return;
            }
        }
        cout << "Room " << roomNo << " does not exist." << endl;
    }
    void checkOut(int roomNo) {
        for (int i = 0; i < numRooms; i++) {
            if (rooms[i]->getRoomNo() == roomNo) {
                rooms[i]->setOccupied(false);
                cout << "Room " << roomNo << " is now available." << endl;
                return;
            }
        }
        cout << "Room " << roomNo << " does not exist." << endl;
    }
    void getAvailRoom() {
        cout << "Available rooms:" << endl;
        for (int i = 0; i < numRooms; i++) {
            if (!rooms[i]->isOccupied()) {
                cout << "Room " << rooms[i]->getRoomNo() << " (" << rooms[i]->getType() << ")" << endl;
            }
        }
    }
    void showRoomSummary(int roomNo) {
        for (int i = 0; i < numRooms; i++) {
            if (rooms[i]->getRoomNo() == roomNo) {
                if (rooms[i]->isOccupied()) {
                    cout << "Room " << roomNo << " is occupied by a customer who checked in at " << rooms[i]->getCheckInTime() << "." << endl;
                } else {
                    cout << "Room " << roomNo << " is available." << endl;
                }
                return;
            }
        }
        cout << "Room " << roomNo << " does not exist." << endl;
    }
};

int main() {
    // create hotel object
    Hotel myHotel("My Hotel", "New York", "John Doe");

    // add rooms to the hotel
    myHotel.addRoom(new BasicRoom(101, "2023-05-15 14:00", "2023-05-16 12:00"));
    myHotel.addRoom(new StandardRoom(102, "2023-05-16 15:30", "2023-05-18 10:00"));
    myHotel.addRoom(new LuxuryRoom(103, "2023-05-17 12:00", "2023-05-20 14:00"));
    myHotel.addRoom(new StandardRoom(104, "2023-05-19 16:00", "2023-05-22 12:00"));

    // check in customers
    myHotel.checkIn(101);
    myHotel.checkIn(102);

    // check available rooms
    myHotel.getAvailRoom();

    // check out a customer
    myHotel.checkOut(101);

    // show room summary
    myHotel.showRoomSummary(101);
    myHotel.showRoomSummary(102);
    myHotel.showRoomSummary(103);
    myHotel.showRoomSummary(104);

    return 0;
}