#include <bits/stdc++.h>
#define MAX 10
using namespace std;
struct person
{
    long int mobile;
    char name[40];
    void readData()
    {
        cout << "Enter Name: ";
        cin >> name;
        cout << "Enter Mobile No.: ";
        cin >> mobile;
    }
    void putData()
    {
        cout << "\t|\t" << name;
        cout << "\t|\t" << mobile << "\t\t|";
    }
};
class hashTable
{
    person ht[MAX];

public:
    hashTable()
    {
        for (int i = 0; i < MAX; i++)
        {
            ht[i].mobile = 0;
            strcpy(ht[i].name, "");
        }
    }
    int hash(long int key)
    {
        return (key % 10);
    }
    void insert(person p)
    {
        int pos = hash(p.mobile);
        if (ht[pos].mobile == 0)
            ht[pos] = p;
        else
        {
            for (int i = pos + 1; i % MAX != pos; i = (i + 1 % MAX))
            {
                if (ht[i].mobile == 0)
                {
                    ht[i] = p;
                    return;
                }
            }
            cout << "The hashtable is full!";
        }
    }
    void compare(long int n)
    {
        int k = 1;
        int pos = hash(n);
        if (ht[pos].mobile == n)
        {
            cout << "Found with " << k << " comparisons at " << pos << "." << endl;
            return;
        }
        for (int i = pos + 1; i % MAX != pos; i = (i + 1) % MAX)
        {
            k++;
            if (ht[i].mobile == n)
            {
                cout << "Found with " << k << " comparisons at " << i << "." << endl;
                return;
            }
        }
        if (k >= MAX)
        {
            cout << "Not found" << endl;
            return;
        }
    }
    void insWReplace(person p)
    {
        int pos = hash(p.mobile);
        if (ht[pos].mobile == 0)
            ht[pos] = p;
        else if ((ht[pos].mobile) % 10 != pos)
        {
            person temp = ht[pos];
            ht[pos] = p;
            for (int i = pos + 1; i % MAX != pos; i = (i + 1) % MAX)
            {
                if (ht[i].mobile == 0)
                {
                    ht[i] = temp;
                    return;
                }
            }
        }
        else
        {
            for (int i = pos + 1; i % MAX != pos; i = (i + 1) % MAX)
            {
                if (ht[i].mobile == 0)
                {
                    ht[i] = p;
                    return;
                }
            }
            cout << "Hash Table is full!!" << endl;
            return;
        }
    }
    void search(long int key)
    {
        int pos = hash(key);
        if (ht[pos].mobile == key)
        {
            cout << "Record found!";
            cout << "|Sr.no. |\tName\t|\tMobile Number\t|";
            cout << "\n|" << pos;
            ht[pos].putData();
        }
        else
        {
            for (int i = pos + 1; i % MAX != pos; i = (i + 1 % MAX))
            {
                if (ht[i].mobile == key)
                {
                    cout << "Record found!";
                    cout << "|Sr.no. |\tName\t|\tMobile Number\t|";
                    cout << "\n|" << i;
                    ht[i].putData();
                    return;
                }
            }
            cout << "Record not found!";
        }
    }
    void deleteRecord(long int key)
    {
        int pos = hash(key);
        if (ht[pos].mobile == key)
        {
            ht[pos].mobile = 0;
            strcpy(ht[pos].name, "");
            cout << "Record deleted successfully!";
        }
        else
        {
            for (int i = pos + 1; i % MAX != pos; i = (i + 1 % MAX))
            {
                if (ht[i].mobile == key)
                {
                    ht[pos].mobile = 0;
                    strcpy(ht[pos].name, "");
                    cout << "Record deleted successfully!";
                    return;
                }
            }
            cout << "Record not found!";
        }
    }
    void display()
    {
        cout << "The contents of the hashtable are: \n";
        cout << "|Sr.no. |\tName\t|\tMobile Number\t|";
        for (int i = 0; i < MAX; i++)
        {
            cout << "\n|" << i;
            ht[i].putData();
        }
    }
};
int main()
{
    hashTable h, hr;
    person p;
    long int key;
    int choice;
    do
    {
        cout << "\nOptions:\n1. Insert Data\n2. Search\n3. Delete\n4. Display\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            p.readData();
            h.insert(p);
            hr.insWReplace(p);
            break;
        case 2:
            cout << "Enter the phone number that you want to search: ";
            cin >> key;
            h.compare(key);
            break;
        case 3:
            cout << "Enter the phone number of the person whose record you want to delete: ";
            cin >> key;
            h.deleteRecord(key);
            break;
        case 4:
            h.display();
            cout << endl;
            break;
        }
    } while (choice < 5);
    return 0;
}
