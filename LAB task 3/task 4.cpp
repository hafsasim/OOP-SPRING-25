#include <iostream>
using namespace std;

class vehicle {
    string make;
    string type;
    int tank = 0;
public:
    void drive(int used) {
        tank -= used;
    }
    void refuel(int added) {
        tank += added;
    }
    void checkfuel() {
        cout << "Fuel left: " << tank << " liters.\n";
    }
    void setmake(string name) {
        make = name;
    }
    void settype(string name) {
        type = name;
    }
};

int main() {
    bool running = true;
    int choice;
    int amount;
    vehicle mycar;
    mycar.setmake("Ferrari");
    mycar.settype("Enzo");

    while (running) {
        cout << "\n=== Fuel Tracker ===\n";
        cout << "What would you like to do?\n";
        cout << "1. Drive the car\n";
        cout << "2. Refuel the car\n";
        cout << "3. Check fuel level\n";
        cout << "4. Quit\n";
        cout << "Your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "How much fuel did you use? ";
                cin >> amount;
                mycar.drive(amount);
                cout << "You drove the car.\n";
                break;
            case 2:
                cout << "How much fuel did you add? ";
                cin >> amount;
                mycar.refuel(amount);
                cout << "Car refueled.\n";
                break;
            case 3:
                mycar.checkfuel();
                break;
            case 4:
                running = false;
                cout << "Exiting... Have a safe drive!\n";
                break;
            default:
                cout << "Not a valid option. Try again.\n";
                break;
        }
    }
}
