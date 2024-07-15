#include <iostream>
using namespace std;
#define size 7

struct node
{
    int data;
    node *next;
    node(int val)
    {
        data = val;
        next = nullptr;
    }
};

node *chain[size];

void init()
{
    for (int i = 0; i < size; i++)
    {
        chain[i] = nullptr;
    }
}

void insert(int val)
{
    node *n = new node(val);
    int hashKey = val % size;
    if (chain[hashKey] == nullptr)
    {
        chain[hashKey] = n;
    }
    else
    {
        node *temp = chain[hashKey];
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = n;
    }
}

void deleteNode(int val)
{
    int hashKey = val % size;
    node *temp = chain[hashKey];
    node *prev = nullptr;
    // If the node to be deleted is the first node
    if (temp->data == val)
    {
        chain[hashKey] = temp->next;
        delete temp;
        return;
    }

    // If the chain is empty
    if (temp == nullptr)
    {
        cout << "Value not found\n";
        return;
    }


    // Search for the node to be deleted
    while (temp != nullptr && temp->data != val)
    {
        prev = temp;
        temp = temp->next;
    }

    // If the value is not found in the chain
    if (temp == nullptr)
    {
        cout << "Value not found\n";
        return;
    }

    // Remove the node
    prev->next = temp->next;
    delete temp;
}

void print()
{
    for (int i = 0; i < size; i++)
    {
        node *temp = chain[i];
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
}

int main()
{
    init();
    insert(7);
    insert(0);
    insert(3);
    insert(10);
    insert(4);
    insert(5);

    cout << "Hash table after insertion:\n";
    print();

    deleteNode(10);
    cout << "Hash table after deleting 10:\n";
    print();

    deleteNode(4);
    cout << "Hash table after deleting 4:\n";
    print();

    deleteNode(7);
    cout << "Hash table after deleting 7:\n";
    print();

    deleteNode(15); // Attempting to delete a non-existent element
    cout << "Hash table after attempting to delete 15 (non-existent):\n";
    print();

    return 0;
}
