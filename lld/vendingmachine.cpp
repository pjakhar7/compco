#include <bits/stdc++.h>

using namespace std;

enum Type{
    Fritter,
    Biscuit,
    Drink
};

enum VendingMachineState{
    MONEY_INSERTED,
    ITEM_DISPENSED,
    IDLE
};

struct State{
    int slotPosition;
    double amountInserted;
    VendingMachineState currentState;
};

static State machineState = State();

struct Item{
    string name;
    Type type;
    int itemId;
    int price;
};

class ItemSlot{
    public:
    vector<Item*> items;
    int position;
    double price;
    int availableCount;

    ItemSlot(int position, double price){
        this->position = position;
        this->price = price;
        availableCount = 0;
    }

    void addItem(Item *item){
        items.push_back(item);
        availableCount++;
    }

    int dispenseItem(){
        if(availableCount){
            cout << "Dispensed Item :" << this->position << endl;
            items.pop_back();
            availableCount--;
            return 0;
        }
        return -1;
    }
};

// class VendingFirmware{
//     double calculateCash(){}

//     int dispenseCash(){}

//     int dispenseItemSlot(){}
// };

class VendingMachine{
    private:
    VendingMachine(){}
    double dispenseCash(double amount){
        cout << "Dispensing change amount: " << amount << endl;
        return amount;
    }
    public:
    map<int, ItemSlot*> itemSlots;
    static VendingMachine *machine;
    // static VendingFirmware *firmware;

    string name;
    string location;

    static VendingMachine* getInstance(){
        if(machine==NULL){
            machine = new VendingMachine();
            // firmware = new VendingFirmware();
        }
        return machine;
    }
    
    void addItemSlot(ItemSlot *itemSlot){
        itemSlots[itemSlot->position] = itemSlot;
    }

    void addItem(Item *item, int position){
        itemSlots[position]->addItem(item);
    }

    int dispenseItem(int position){
        double change = machineState.amountInserted - itemSlots[position]->price;
        machineState.amountInserted -= itemSlots[position]->price;
        if(change<0)
            return -1;
        machineState.currentState = ITEM_DISPENSED;
        itemSlots[position]->dispenseItem();
        if(change>0){
            dispenseCash(change);
        }
        return change;
    }

    void insertCash(double amount){
        if(amount>0){
            machineState.amountInserted += amount;
            machineState.currentState = MONEY_INSERTED;
            cout << "Inserted cash of amount: " << amount << endl;
        }
    }

    
};

class User{

};

VendingMachine* VendingMachine::machine = NULL;

int main(){
    VendingMachine *machine = VendingMachine::getInstance();
    ItemSlot *slot1 = new ItemSlot(1, 10.0);
    machine->addItemSlot(slot1); 
    ItemSlot *slot2 = new ItemSlot(2, 13.0);
    machine->addItemSlot(slot2);
    Item* item1 = new Item();
    machine->addItem(item1, 1);
    machine->insertCash(10); 
    machine->dispenseItem(1);
    return 0;
}