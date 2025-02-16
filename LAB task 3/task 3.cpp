#include <iostream>
using namespace std;

class bookshelf {
    string books[20];
    string borrowed[20];
    string available[20];
    int totalbooks = 0;
    int borrowedcount = 0;
    int availablecount = 0;
public:
    void addbook(string title) {
        books[totalbooks] = title;
        available[availablecount] = title;
        totalbooks++;
        availablecount++;
    }
    void borrowbook(string title) {
        bool found = false;
        bool isavailable = false;
        
        for (int i = 0; i < totalbooks; i++) {
            if (books[i] == title) {
                for (int j = 0; j < availablecount; j++) {
                    if (available[j] == title) {
                        available[j] = "";
                        borrowed[borrowedcount] = title;
                        borrowedcount++;
                        availablecount--;
                        isavailable = true;
                        cout << "You borrowed \"" << title << "\".\n";
                        break;
                    }
                }
                found = true;
                break;
            }
        }
        
        if (!found) {
            cout << "This book is not in our collection.\n";
        } else if (!isavailable) {
            cout << "Sorry, this book is already borrowed.\n";
        }
    }
    void returnbook(string title) {
        available[availablecount] = title;
        availablecount++;
        borrowedcount--;
        cout << "You returned \"" << title << "\". Thanks!\n";
    }
    void showbooks() {
        cout << "\n--- Book Collection ---\n";
        for (int i = 0; i < totalbooks; i++) {
            cout << i+1 << ": " << books[i] << endl;
        }
    }
};

int main() {
    bool running = true;
    int option;
    bookshelf mybooks;
    string bookname;
    
    while (running) {
        cout << "\n=== Book Tracker ===\n";
        cout << "Choose an option:\n";
        cout << "1. Add a new book\n";
        cout << "2. Borrow a book\n";
        cout << "3. Return a book\n";
        cout << "4. View all books\n";
        cout << "5. Exit\n";
        cout << "Your choice: ";
        cin >> option;
        
        switch (option) {
            case 1:
                cout << "Enter the book's title: ";
                cin >> bookname;
                mybooks.addbook(bookname);
                cout << "Book added to the collection!\n";
                break;
            case 2:
                cout << "Enter the title to borrow: ";
                cin >> bookname;
                mybooks.borrowbook(bookname);
                break;
            case 3:
                cout << "Enter the title to return: ";
                cin >> bookname;
                mybooks.returnbook(bookname);
                break;
            case 4:
                mybooks.showbooks();
                break;
            case 5:
                running = false;
                cout << "Goodbye! Happy reading!\n";
                break;
            default:
                cout << "That's not a valid option. Try again.\n";
                break;
        }
    }
}
