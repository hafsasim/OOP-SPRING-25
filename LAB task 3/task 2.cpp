#include <iostream>
using namespace std;

class stepcounter {
    string user;
    int target = 100;
    int steps = 0;
public:
    void settarget(int num) {
        target = num;
    } 
    void setuser(string name) {
        user = name;
    }
    bool isgoalmet() {
        return steps >= target;
    }
    int getcalories() {
        return steps * 10; 
    }
    void addsteps(int num) {
        steps += num;
    }
    void showsteps() {
        cout << "You have taken " << steps << " steps so far.\n";
    }
};

int main() {
    bool active = true;
    int choice;
    stepcounter tracker;
    tracker.setuser("Hafsa Asim");

    while (active) {
        cout << "\n=== Step Tracker ===\n";
        cout << "What would you like to do?\n";
        cout << "1. Add steps\n";
        cout << "2. Check calories burned\n";
        cout << "3. Check if goal is met\n";
        cout << "4. Set a new daily goal (default is 100)\n";
        cout << "5. Show total steps\n";
        cout << "6. Quit\n";
        cout << "Your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                int newsteps;
                cout << "How many steps did you take? ";
                cin >> newsteps;
                tracker.addsteps(newsteps);
                cout << "Steps added!\n";
                break;
            }
            case 2:
                cout << "You burned approximately " << tracker.getcalories() << " calories.\n";
                break;
            case 3:
                if (tracker.isgoalmet()) {
                    cout << "Congrats! You reached your daily step goal!\n";
                } else {
                    cout << "Keep going! You haven't reached your goal yet.\n";
                }
                break;
            case 4: {
                int newgoal;
                cout << "Enter your new step goal: ";
                cin >> newgoal;
                tracker.settarget(newgoal);
                cout << "New goal set!\n";
                break;
            }
            case 5:
                tracker.showsteps();
                break;
            case 6:
                active = false;
                cout << "Goodbye! Keep moving!\n";
                break;
            default:
                cout << "That's not a valid option. Try again!\n";
                break;
        }
    }
}
