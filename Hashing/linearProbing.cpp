#include <iostream>
using namespace std;
#define size 10

int h[size];

void init()
{
    for (int i = 0; i < size; i++)
    {
        h[i] = -1; // Using -1 to indicate empty slots
    }
}

void insert()
{
    int key, hashKey, i;
    int index = 0;
    cout << "Enter the key you wanna insert: " << endl;
    cin >> key;
    hashKey = key % size;
    for (i = 0; i < size; i++)
    {
        index = (hashKey + i) % size;
        if (h[index] == -1)
        { // Using -1 to check for empty slots
            h[index] = key;
            break;
        }
    }
    if (i == size)
    {
        cout << "Element cannot be inserted. Hash table is full." << endl;
    }
}

void search()
{
    int key, hashKey, index = 0;
    cout << "Enter the element you wanna search: " << endl;
    cin >> key;
    hashKey = key % size;
    int i;
    for (i = 0; i < size; i++)
    {
        index = (hashKey + i) % size;
        if (h[index] == key)
        {
            cout << "Value is found at index " << index << endl;
            break;
        }
        if (h[index] == -1)
        { // Stop searching if an empty slot is found
            break;
        }
    }
    if (i == size || h[index] == -1)
    {
        cout << "Value is not found." << endl;
    }
}

void display()
{
    cout << "Elements in hashTable are:\n";
    for (int i = 0; i < size; i++)
    {
        if (h[i] == -1)
        {
            cout << "At index " << i << "\tValue = NULL" << endl;
        }
        else
        {
            cout << "At index " << i << "\tValue = " << h[i] << endl;
        }
    }
}

int main()
{
    init();
    insert();
    insert();
    insert();
    insert();
    insert();
    display();
    search();
    return 0;
}
