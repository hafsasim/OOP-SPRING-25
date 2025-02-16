#include <iostream>
using namespace std;

class jukebox {
    string songlist[100];
    int totalsongs = 0;
    string currentsong;
public:
    void addsong(string name) {
        songlist[totalsongs] = name;
        totalsongs++;
        cout << "Song added: " << name << endl;
    }
    void playsong(string name) {
        bool found = false;
        for (int i = 0; i < totalsongs; i++) {
            if (name == songlist[i]) {
                found = true;
                currentsong = name;
                cout << "Now playing: " << name << endl;
                break;
            }
        }
        if (!found) {
            cout << "Song not found. Add it first!" << endl;
        }
    }
    void showlist() {
        cout << "\n--- Your Playlist ---\n";
        if (totalsongs == 0) {
            cout << "No songs added yet.\n";
        } else {
            for (int i = 0; i < totalsongs; i++) {
                cout << i + 1 << ". " << songlist[i] << endl;
            }
        }
        cout << endl;
    }
    void removesong(string name) {
        bool found = false;
        int index;
        for (int i = 0; i < totalsongs; i++) {
            if (name == songlist[i]) {
                found = true;
                index = i;
                break;
            }
        }
        if (found) {
            for (int i = index; i < totalsongs - 1; i++) {
                songlist[i] = songlist[i + 1];
            }
            totalsongs--;
            cout << "Removed: " << name << endl;
        } else {
            cout << "Song not found in the list!" << endl;
        }
    }
};

int main() {
    bool running = true;
    int option;
    string name;
    jukebox myplayer;
    while (running) {
        cout << "\n=== Simple Music Player ===\n";
        cout << "1. Add a song\n";
        cout << "2. Remove a song\n";
        cout << "3. Play a song\n";
        cout << "4. Show playlist\n";
        cout << "5. Quit\n";
        cout << "Choose an option: ";
        cin >> option;
        
        switch (option) {
            case 1:
                cout << "Song to add: ";
                cin >> name;
                myplayer.addsong(name);
                break;
            case 2:
                cout << "Song to remove: ";
                cin >> name;
                myplayer.removesong(name);
                break;
            case 3:
                cout << "Song to play: ";
                cin >> name;
                myplayer.playsong(name);
                break;
            case 4:
                myplayer.showlist();
                break;
            case 5:
                running = false;
                cout << "Exiting... Enjoy your music!\n";
                break;
            default:
                cout << "Invalid option. Try again.\n";
        }
    }
}
