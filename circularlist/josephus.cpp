#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next = nullptr;
};

class CircularList{
    Node* head = nullptr;

    public:Node* josephus(int n, int m){
        if (n<=0 || m<=0){
            return nullptr;
        }
        //creating a circular linked list with "n" number of nodes
        Node* new_node = new Node;
        new_node->data = 1;

        head = new_node;
        Node* current = head;
        for (int i = 2; i <= n; i++){
            new_node = new Node;
            new_node->data = i;

            current->next = new_node;

            current = current->next;
        }
        current->next = head;

        current = head;
        while (current->next != current){
            for (int i = 1; i < m-1; i++){
                current = current->next;
            }

            Node* next = current->next;
            current->next = next->next;

            delete next;
            current = current->next;
        }
        return current;
    } 
};

int main(){
    CircularList* my_list = new CircularList;
    int n,m;
    cout<<"Enter the total number of Persons: ";
    cin>>n;
    cout<<"Enter the value of M: ";
    cin>>m;

    Node* surviour = my_list->josephus(n,m);

    cout<<"The Position of the surviour is: "<<surviour->data;
}