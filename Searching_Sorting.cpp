#include<iostream>
#include<cstring>
#include<cstdlib>
#include<algorithm>
#include<vector>
using namespace std;
typedef struct rec
{
    char name[20];
    char birthdt[20];
    char phone[11];
}node;
node temp;
vector<node> rec;
vector<node>::iterator ptr;
bool compare(node &r1, node &r2)
{
    if(strcmp(r1.name, r2.name) < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void create()
{
    int n, i;
    cout << "How many elements do you want to insert: ";
    cin >> n;
    cout << "Enter the elements in the database:"<<endl;
    for(i = 0; i < n; i++)
    {
        cout << "Name: ";
        cin >> temp.name;
        cout << "Birthdt(dd-mm-yy): ";
        cin >> temp.birthdt;
        cout << "Phone number: ";
        cin >> temp.phone;
        rec.push_back(temp);    
    }
}
void display()
{
    cout << "\tThe contents of the database are:" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "NAME              DATE OF BIRTH         PHONE NUMBER" << endl;
    cout << "------------------------------------------------------" << endl;
    for(ptr = rec.begin(); ptr != rec.end(); ptr++)
    {
        cout << (*ptr).name << "             " << (*ptr).birthdt << "                 " << (*ptr).phone << endl;
    }
}
void searching()
{
    char key[20];
    int flag = 0;
    cout << "Enter the name which you want to search: ";
    cin >> key;
    for(ptr = rec.begin(); ptr != rec.end(); ptr++)
    {
        if(strcmp((*ptr).name, key) == 0)
        {
            flag = 1;
            break;
        }
        else
        {
            flag = 0;
        }    
    }
    if(flag == 1)
    {
        cout << "Desired element is present in the database:" << endl;    
    }
    else
    {
        cout << "Desired element is not present in the database:" << endl;
    }
}
void sorting()
{
    sort(rec.begin(), rec.end(), compare);
    cout << "Record is sorted!" << endl;
}
int main()
{
    char ans = 'y';
    int choice;
    cout << "\t Program for searching and sorting" << endl;
    do
    {
        cout << "Main Menu" << endl;
        cout << "1. Create a database" << endl;
        cout << "2. Display the database" << endl;
        cout << "3. Search the element in the database" << endl;
        cout << "4. Sort the database (Name)" << endl;
        cout << "Enter the choice what do you want: ";
        cin >> choice;
        switch(choice)
        {
            case 1: create();
                    break;
            case 2: display();
                    break;
            case 3: searching();
                    break;
            case 4: sorting();
                    display();
                    break;
        }
        cout << "Do you want to go back to the menu(y): ";
        cin >> ans;
    } while(ans == 'y');
    return 0;
}
