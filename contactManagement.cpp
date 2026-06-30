#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Contact {
    string name;
    string phone;
    string email;
};

void addContact() {
    Contact c;
    ofstream file("contacts.txt", ios::app);

    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, c.name);

    cout << "Enter Phone Number: ";
    getline(cin, c.phone);

    cout << "Enter Email: ";
    getline(cin, c.email);

    file << c.name << "|" << c.phone << "|" << c.email << endl;
    file.close();

    cout << "\nContact Added Successfully!"<<endl;
}

void viewContacts() {
    ifstream file("contacts.txt");
    string line;

    cout << "     CONTACT LIST     "<<endl;

    while (getline(file, line)) {
        int p1 = line.find('|');
        int p2 = line.rfind('|');

        cout << "Name : " << line.substr(0, p1) << endl;
        cout << "Phone: " << line.substr(p1 + 1, p2 - p1 - 1) << endl;
        cout << "Email: " << line.substr(p2 + 1) << endl;
        cout << "--------------------------"<<endl;
    }

    file.close();
}

void searchContact() {
    ifstream file("contacts.txt");
    string line, searchName;
    bool found = false;

    cout << "Enter Name to Search: ";
    cin.ignore();
    getline(cin, searchName);

    while (getline(file, line)) {
        int p1 = line.find('|');
        int p2 = line.rfind('|');

        string name = line.substr(0, p1);

        if (name == searchName) {
            cout << "\n     CONTACT FOUND     "<<endl;
            cout << "Name : " << name << endl;
            cout << "Phone: " << line.substr(p1 + 1, p2 - p1 - 1) << endl;
            cout << "Email: " << line.substr(p2 + 1) << endl;
            found = true;
        }
    }

    if (!found)
        cout << "\n     Contact Not Found!     "<<endl;

    file.close();
}

void deleteContact() {
    ifstream file("contacts.txt");
    ofstream temp("temp.txt");

    string line, deleteName;
    bool found = false;

    cout << "Enter Name to Delete: ";
    cin.ignore();
    getline(cin, deleteName);

    while (getline(file, line)) {
        int p = line.find('|');
        string name = line.substr(0, p);

        if (name != deleteName)
            temp << line << endl;
        else
            found = true;
    }

    file.close();
    temp.close();

    remove("contacts.txt");
    rename("temp.txt", "contacts.txt");

    if (found)
        cout << "\n     Contact Deleted Successfully!     "<<endl;
    else
        cout << "\n     Contact Not Found!     "<<endl;
}

int main() {
    int choice;

    do {
        cout << "\n==================================="<<endl;
        cout << "   CONTACT MANAGEMENT SYSTEM"<<endl;
        cout << "==================================="<<endl;
        cout << "1. Add Contact"<<endl;
        cout << "2. View Contacts"<<endl;
        cout << "3. Search Contact"<<endl;
        cout << "4. Delete Contact"<<endl;
        cout << "5. Exit"<<endl;
        cout << "Enter your choice: "<<endl;
        cin >> choice;

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                viewContacts();
                break;
            case 3:
                searchContact();
                break;
            case 4:
                deleteContact();
                break;
            case 5:
                cout << "\nThank you for using the Contact Management System!"<<endl;
                break;
            default:
                cout << "\n     Invalid Choice!     "<<endl;
        }

    } while (choice != 5);

    return 0;
}