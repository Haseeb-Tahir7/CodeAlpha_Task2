
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class User {
private:
    string username;
    string password;

public:
    void registerUser() {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        ofstream file("users.txt", ios::app);
        file << username << " " << password << endl;
        file.close();

        cout << "Registration successful!" << endl;
    }

    void loginUser() {
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        ifstream file("users.txt");
        string user, pass;
        bool found = false;

        while (file >> user >> pass) {
            if (user == username && pass == password) {
                found = true;
                break;
            }
        }

        file.close();

        if (found)
            cout << "Login successful!" << endl;
        else
            cout << "Invalid credentials!" << endl;
    }
};

int main() {
    User u;
    int choice;
    cout << "1. Register\n2. Login\nEnter choice: ";
    cin >> choice;

    if (choice == 1)
        u.registerUser();
    else if (choice == 2)
        u.loginUser();
    else
        cout << "Invalid choice!" << endl;

    return 0;
}
