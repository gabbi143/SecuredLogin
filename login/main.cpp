#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void createUserFolder(const string& username) {
    string folderName = username + "_data";

    // Create folder
    string createCommand = "mkdir " + folderName;
    system(createCommand.c_str());

    // Lock folder (deny access)
    string lockCommand = "icacls " + folderName + " /deny Everyone:(OI)(CI)(RX)";
    system(lockCommand.c_str());

    cout << "Folder '" << folderName << "' created and locked!" << endl;
}

void unlockUserFolder(const string& username) {
    string folderName = username + "_data";

    // Unlock folder (restore access)
    string unlockCommand = "icacls " + folderName + " /grant Everyone:(OI)(CI)(RX)";
    system(unlockCommand.c_str());

    cout << "Folder '" << folderName << "' unlocked! You can now access your files." << endl;
}

int main() {
    string username;
    int choice;

    cout << "1. Sign Up (Create & Lock Folder)\n2. Unlock Folder\nChoice: ";
    cin >> choice;
    cin.ignore();

    cout << "Enter username: ";
    getline(cin, username);

    if (choice == 1) {
        createUserFolder(username);
    } else if (choice == 2) {
        unlockUserFolder(username);
    } else {
        cout << "Invalid choice!" << endl;
    }

    return 0;
}
