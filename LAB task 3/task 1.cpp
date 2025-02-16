#include <iostream>
using namespace std;

class wallet {
    string owner;
    int balance = 0;
    string history = "";
public: 
    void setname(string name) {
        owner = name;
    }
    void add(int amount) {
        balance += amount;
        history += "\nAdded PKR: " + to_string(amount) + ".\n";
    } 
    void spend(int amount) {
        if (amount > balance) {
            cout << "Not enough balance!\n";
        } else {
            balance -= amount;
            history += "\nSpent PKR: " + to_string(amount) + ".\n";
        }
    }
    void showhistory() {
        if (history.empty()) {
            cout << "No transactions yet.\n";
        } else {
            cout << "Transaction History:" << history << "\n";
        }
    }
};

int main() {
    wallet mywallet;
    mywallet.setname("Hafsa Asim");
    int choice;
    bool running = true;
    
    while (running) {
        cout << "\n===== Wallet System =====\n";
        cout << "Select an option:\n";
        cout << "1. Add money\n";
        cout << "2. Spend money\n";
        cout << "3. View history\n";
        cout << "4. Exit\n";
        cout << "Your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                int amount;
                cout << "Enter amount to add: ";
                cin >> amount;
                mywallet.add(amount);
                cout << "Money added successfully!\n";
                break;
            }
            case 2: {
                int amount;
                cout << "Enter amount to spend: ";
                cin >> amount;
                mywallet.spend(amount);
                break;
            }
            case 3:
                mywallet.showhistory();
                break;
            case 4:
                running = false;
                cout << "Exiting... Have a great day!\n";
                break;
            default:
                cout << "Invalid option. Please try again.\n";
                break;
        }
    }
}
