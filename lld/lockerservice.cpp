#include <bits/stdc++.h>

using namespace std;

// R1: While ordering the item(s), the customer can choose the nearest location to pick up the order package from the locker.
// R2: One or more items can be contained in one order. An order will be placed in a package before the delivery.
// R3: There can be different sizes of lockers including extra small, small, medium, large, extra large, and double extra large.
// R4: The locker is assigned to the customer based on the size of the order package.
// R5: When the order package is delivered to the locker location specified by the customer, a 6-digit code will be sent to the customer to open the locker.
// R6: The package will be kept or placed inside the locker for three days only.
// R7: If the customer does not pick up the package from their locker within three days, the refund process will be initiated and the customer won’t be allowed to pick up the package any longer.
// R8: Only eligible packages can be placed in the locker such that the size of the package must be less than the size of the locker.
// R9: There can be multiple lockers at every locker location.
// R10: The Amazon Locker is accessed within a specific time. Every location has its opening and closing time. Therefore, the customer should pick up the package during this time period.
// R11: The item can be returned to the Amazon Locker if it doesn’t match the expectation of the customer or is faulty, and there is a refund policy available for that product.
// R12: To return an item, the customer needs to choose the nearest locker location. An available locker will be assigned to them based on the size and location.
// R13: When the customer picks up the order package from the locker, the locker’s state is changed to closed, and the customer will no longer be able to open the locker with the given code.

enum Size{
    S,
    M,
    L, 
    XL,
    XLL
};

enum Status{
    BOOKED,
    AVAILABLE,
    CLOSED
};

struct Order{
    int orderId;
    int uid;
    Size size;
};

class User{
    public:
    int uid;
    string name;
    
};

class Admin: public User{
    public:
};

class Customer: public User{
    public:
};

class Locker{
    public:
    int lId;
    Size size;
    Status status;
    int pin;
    int orderDeliveredOn;

    int unlock(int uid, int pin){
        if(pin!=this->pin)
            return -1;
        pin = 0;
        status = AVAILABLE;
        return 0;
    }
};

class LockerStation{
    public:
    string address;
    int lockerStationId;
    time_t openingTime;
    int closingTime;
    vector<Locker*> lockers;

    Locker* assignLocker(Order order){
        for(auto l: lockers){
            if(l->status == AVAILABLE && l->size>=order.size){
                l->status = BOOKED;
                l->pin = generatePin();
                return l;
            }
        }
        return NULL;
    }

    int generatePin(){
        return 100000+(rand()%900000);
    }
};

class LockerService{
    private:
        LockerService(){}
        static LockerService* lockerService;

    public:
        vector<LockerStation*> lockerStations;
        map<string, LockerStation*> lockersByLocation;

    LockerService* getInstance(){
        if(lockerService == NULL){
            lockerService = new LockerService();
        }
        return lockerService;
    }
    
    LockerStation* getLockerStation(string location){
        return lockersByLocation[location];
    }

    void addLockerStation(LockerStation *ls){
        lockerStations.push_back(ls);
        lockersByLocation[ls->address] = ls;
    }
};

int main(){
    return 0;
}