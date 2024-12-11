#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

class db {
    int roll;
    char name[20];
    char Class[10];
    char Div[10];
    char dob[10];
    char bg[3], contact[10];
    char phone[10], license[12];

public:
    static int stdno;

    static void count() {
        cout << "No. of objects created: " << stdno << endl;
    }

    void fin() { cout << "Inline Function!" << endl; }

    db() {
        roll = 0;
        strcpy(name, "Sachin");
        strcpy(Class, "I");
        strcpy(Div, "A");
        strcpy(dob, "11/11/1111");
        strcpy(bg, "A");
        strcpy(contact, "city");
        strcpy(phone, "9000000000");
        strcpy(license, "A0101010");
        ++stdno;
    }

    db(db* ob) {
        strcpy(name, ob->name);
        strcpy(dob, ob->dob);
        strcpy(Class, ob->Class);
        strcpy(Div, ob->Div);
        strcpy(bg, ob->bg);
        strcpy(contact, ob->contact);
        strcpy(phone, ob->phone);
        strcpy(license, ob->license);
        ++stdno;
    }

    void getdata() {
        cout << "Enter Name Of Student: ";
        cin >> name;
        cout << "Enter Roll Number: ";
        cin >> roll;
        cout << "Enter Class: ";
        cin >> Class;
        cout << "Enter Division: ";
        cin >> Div;
        cout << "Enter Date Of Birth: ";
        cin >> dob;
        cout << "Enter Blood Group: ";
        cin >> bg;
        cout << "Enter Address: ";
        cin >> contact;
        cout << "Enter Contact Number: ";
        cin >> phone;
        cout << "Enter License No.: ";
        cin >> license;
    }

    friend void display(const db& d);

    ~db() {
        cout << this->name << "(Object) is destroyed!" << endl;
    }
};

void display(const db& d) {
    cout << setw(12) << "Index" << setw(12) << "Name" << setw(12) << "Roll" 
         << setw(10) << "Class" << setw(8) << "Div" << setw(12) << "DOB" 
         << setw(5) << "Blood Group" << setw(12) << "Contact" << setw(12) << "Phone" 
         << setw(12) << "License" << endl;

    cout << setw(12) << 0 << setw(12) << d.name << setw(12) << d.roll 
         << setw(10) << d.Class << setw(8) << d.Div << setw(12) << d.dob
         << setw(5) << d.bg << setw(12) << d.contact << setw(12) << d.phone 
         << setw(12) << d.license << endl;
}



int db::stdno = 0;

int main() {
    db defaultObj;
    cout << "Default values of the object: ";
    cout<<endl;
    display(defaultObj);

    int n, i, delIndex;
    cout << "How many objects do you want to create?: ";
    cin >> n;
    db** ptr = new db*[n];
    for (i = 0; i < n; i++) {
        ptr[i] = new db();
        ptr[i]->getdata();
    }
    cout << setw(12) << "Index" << setw(12) << "Name" << setw(5) << "Roll" << setw(4) << "Class" << setw(4) << "Div" << setw(12) <<
        "DOB" << setw(4) << "Blood Group" << setw(12) << "Contact" << setw(12) << "Phone" << setw(12) << "License" << endl;
    for (i = 0; i < n; i++) {
        cout << setw(12) << i;
        display(*ptr[i]);
    }
    db::count();

    char choice;
    do {
        cout << "**Menu**";
        cout << "1. Add new object";
        cout << "2. Delete an object";
        cout << "3. Exit";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) {
            case '1': {
                db** newPtr = new db*[n + 1];
                for (i = 0; i < n; i++) {
                    newPtr[i] = ptr[i];
                }
                newPtr[n] = new db();
                newPtr[n]->getdata();
                ptr = newPtr;
                n++;
                cout << setw(12) << "Index" << setw(12) << "Name" << setw(5) << "Roll" << setw(4) << "Class" << setw(4) << "Div" << setw(12) <<
                    "DOB" << setw(4) << "Blood Group" << setw(12) << "Contact" << setw(12) << "Phone" << setw(12) << "license" << endl;
                for (i = 0; i < n; i++) {
                    cout << setw(12) << i;
                    display(*ptr[i]);
                }
                db::count();
                break;
            }
            case '2': {
                cout << "Enter the index of the object you want to delete (0 to " << n - 1 << "): ";
                cin >> delIndex;
                if (delIndex >= 0 && delIndex < n) {
                    delete ptr[delIndex];
                    ptr[delIndex] = NULL;
                    cout << "Object at index " << delIndex << " deleted!" << endl;
                } else {
                    cout << "Invalid index!" << endl;
                }

                cout << "Remaining objects:" << endl;
                for (i = 0; i < n; i++) {
                    if (ptr[i] != NULL) {
                        cout << setw(12) << i;
                        display(*ptr[i]);
                    }
                }
                break;
            }
            case '3': {
                cout << "Exiting program." << endl;
                break;
            }
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    } while (choice != '3');

    for (i = 0; i < n; i++) {
        if (ptr[i] != NULL) {
            delete ptr[i];
        }
    }
    delete[] ptr;
    return 0;
}
