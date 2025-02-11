#include <bits/stdc++.h>
#include <stdexcept>


using namespace std;

class FloorDisplay{
    public:
    int liftsCurrentFloor;
    int directionOfLift;
};

class Floor{
    public:
    int floorId;
    vector<FloorDisplay> floorDisplays;
};

class Elevator{
    public:
    int id;
    int currentFloor;
    int status;
    int direction;
    int doorStatus;
};

class ElevatorSystem{
    public:
    string buildingName;
    string address;
    map<int, Floor> floors;
    map<int, Elevator> elevators;

    bool callElevator(int dir, int floor){

        return true;
    };


};

class Person{
    public:
    string name;
    int currentFloor;

    Person(string name, int currentFloor){
        this->name = name;
        this->currentFloor = currentFloor;
    }
};

int main(){
    
}