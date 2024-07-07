#include <iostream>

using namespace std;

struct Student
{
    int id;
    string name;

    Student *next = nullptr;
    Student *prev = nullptr;
};

class Double_LinkedList{

    Student *head = nullptr;
    Student *tail = nullptr;
    public:int nextId = 1;
    public:void display(){
        if (head == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }
        
        Student *curr = head;
        while (curr != nullptr)
        {
            cout << "Student ID: " << curr->id << "\n";
            cout << "Student Name: " << curr->name << "\n";
            curr = curr->next;
            cout<<"\n\n";
        }
        }// Display ends here

    // Function to add at end
    public:void append(Student *curr){
        if (head == nullptr)
        {
            head = tail = curr;
        }
        else
        {
            tail->next = curr;
            curr->prev = tail;
            tail = curr;
        }
        }// append ends here

    // Function to swap alternate nodes by changing links
    public:void swap_alternate() {
        if (!head || !head->next) {
            return; // Not enough nodes to swap
        }

        Student* start = head;
        Student* end = tail;
        Student* temp = nullptr;

        Student *p1;
        Student *p2;

        int current = 1;

        while (start != end) {
            if(current%2 ==0){
                if(end->next == start || start->next == end){
                    start->prev->next = end;
                    end->prev = start->prev;

                    start->prev = end;
                    start->next = end->next;

                    end->next->prev = start;
                    end->next = start;

                    break;
                }
                else{
                    p1 = start->next;
                    p2 = end->next;
                    temp = start->prev;

                    //setting next of previous nodes
                    temp->next = end;
                    end->prev->next = start;
                    //setting prev of swapping nodes
                    start->prev = end->prev;
                    end->prev = temp;
                    //setting next of swapping nodes
                    end->next = p1;
                    start->next = p2;
                    //setting prev of next nodes
                    p1->prev = end;
                    p2->prev = start;
                }
                
                //adjusting for next iteration
                temp = start;
                start = end->next;
                end = temp->prev;
            }
            else{
                if(end->next == start || start->next == end){
                    break;
                }
                start = start->next;
                end = end->prev;
            }
            current++;
        }
    }//swap_alternate ends here
};

int main(){

    int check = 1;

    Double_LinkedList *my_list = new Double_LinkedList;

    while (check != 0)
    {
        cout << "1- Add Student\n2- Display Students\n3- swap\n0-Exit\n";
        cin >> check;

        if (check == 1)
        {
            Student *curr = new Student;
            cout << "Enter name: ";
            cin >> curr->name;
            curr->id = my_list->nextId;
            my_list->nextId++;
            my_list->append(curr);
        }
        else if (check == 2)
        {
            my_list->display();
        }
        else if(check == 3){
            my_list->swap_alternate();

        }
        else{
            cout<<"Wrong Input\n";
        }
    }
}