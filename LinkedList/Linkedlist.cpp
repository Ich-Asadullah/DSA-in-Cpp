
#include <iostream>
using namespace std;

struct Student
{
    string name;
    int id;
    int age;
    Student *next = nullptr;
};

class LinkedList
{
    public:int nextId = 1;
    Student *head = nullptr;
    Student *tail = nullptr;
    int length = 0;

//Function to check if two Students are duplicate
public:bool equals(Student* p1, Student* p2){
    if((p1->name == p2->name) && (p1->age == p2->age)){
        return true;
    }
    else{
        return false;
    }
}//equals ends here

// Function to print whole list
public:void display(Student* head_p){
        if (head_p == nullptr)
        {
            cout << "List is empty." << endl;
            return;
        }
        
        Student *curr = head_p;
        while (curr != nullptr)
        {
            cout << "Student ID: " << curr->id << "\n";
            cout << "Student Name: " << curr->name << "\n";
            cout << "Student Age: " << curr->age << "\n";
            curr = curr->next;
            cout<<"\n";
        }
    }// Display ends here

// Function to add at end
public:void append(Student *curr){

        if (head == nullptr)
        {
            head = tail = curr;
            length+=1;
        }
        else
        {
            tail->next = curr;
            tail = curr;
            length+=1;
        }
    }// append ends here


// Function to add at Start
public:void insert_start(Student *curr){

    if (head == nullptr)
    {
        head = tail = curr;
    }
    else
    {
        curr->next = head;
        head = curr;
    }
    length+=1;
}//insert_start ends here

//Function to insert after specific value
public:void insert_after(int key, Student *curr){

    Student *p = search(key);

    if (p==nullptr){
        cout<<"Not Found";
    }
    else{
        if (p == tail){
            tail->next = curr;
            tail = curr;
            length+=1;
        }
        else{
            curr->next = p->next;
            p->next = curr;
            length+=1;
        }
    }
}// insert_after ends here

//Function to insert before a specific value
public:void insert_before(int key, Student *curr){

    Student *p = search(key);
    Student *pp = search_prev(key);

    if (p==nullptr){
        cout<<"Not Found";
    }
    else{
        if (p == head){
            curr->next = head;
            head = curr;
            length+=1;
        }
        else{
            curr->next = pp->next;
            pp->next = curr;
            length+=1;
        }
    }
}//insert_before ends here

//Function to search previous node of a specific ID
public:Student* search_prev(int key){
    Student *p = head;
    Student *k = nullptr;

    while (p != nullptr && p->id != key){
        k = p;
        p = p->next;
    }
    return k;
}//search_prev ends here

//Function to find node using an ID
public:Student* search(int key){
    Student *p = head;

    while (p != nullptr && p->id != key){
        p = p->next;
    }
    return p;
}//search ends here

//Function to delete last node
public:void delete_end(){
    if (head==nullptr){
        cout<<"List Empty\n";
    }
    else if(head==tail){
        head = tail = nullptr;
        length--;
    }
    else{
        Student *p = head;
        while (p->next!=tail){
            p = p->next;
        }
        p->next = nullptr;
        delete tail;
        tail = p;
        length--;
    }
}//delete_end ends here

//Function to delete first node
public:void delete_start(){
    if (head==nullptr){
        cout<<"List Empty\n";
    }
    else if(head==tail){
        head = tail = nullptr;
        length--;
    }
    else{
        Student *temp = head;
        head = head->next;
        temp->next = nullptr;
        delete temp;
        length--;
    }
}//delete_start ends here

//Function to delete specific node
    public:void delete_specific(int key){

        if(head == nullptr){
            cout<<"Empty";
        }
        else if(head == tail){
            head = tail = nullptr;
        }
        else{
            Student *point = search(key);
            Student *previous = search_prev(key);

            if(point){

                if(point == head){
                    delete_start();
                }
                else if (point == tail){
                    delete_end();
                }

                else{
                    previous->next = point->next;
                    length--;
                }
                
            }
            else{
                cout<<"Cannot find Student with id: "<<key<<"\n";
            }
        }
    }//delete_specific ends here

//Function to delete before a specific value
public:void delete_before(int key){

    Student *p = search(key);

    if (p==nullptr){
        cout<<"Not Found";
    }
    else{
        if (p == head){
            cout<<"Nothing to Delete";
        }
        else{
            Student *point = head;
            while (point->next!=nullptr && point->next->next !=p){
                point = point->next;
                length--;
            }
            point->next = p;
        }
    }
}//delete_before ends here

//Function to delete after specific value
public:void delete_after(int key){

    Student *p = search(key);

    if (p==nullptr){
        cout<<"Not Found";
    }
    else{
        if (p == tail){
            cout<<"Nothing to remove";
        }
        else{
            p->next = p->next->next;
            length--;
        }
    }
}// delete_after ends here

//Function to reverse the full list
public:void reverse(){
    if (head == nullptr || head->next == nullptr) {
            return;
        }

        Student *prev = nullptr;
        Student *curr = head;
        Student *nxt = nullptr;

        while (curr != nullptr) {
            nxt = curr->next; 
            curr->next = prev; 
            prev = curr;
            curr = nxt;
        }
        tail = head;
        head = prev;
    }//reverse ends here


//function to display list in reverse order iterative method(Donot reverse the list, just displays reverse)
public:void display_reverse(){
    Student *p = head;
    Student *last = tail;

    while (last != head){
        while(p->next != last){
            p = p->next;
        }
        cout << "Student ID: " << last->id << "\n";
        cout << "Student Name: " << last->name << "\n";
        cout << "Student Age: " << last->age << "\n";
        last = p;
        cout<<endl;
        p = head;
    }
    cout << "Student ID: " << head->id << "\n";
    cout << "Student Name: " << head->name << "\n";
    cout << "Student Age: " << head->age << "\n";
}//display_reverse ends here

//Function to display the list in reverse order using recursion
public:void display_reverse_recursion(Student *p = nullptr) {
    if (head == nullptr){
        return;
    }
    if (p == nullptr) {
        p = head;
    }
    // Base case
    if (p == tail) {
            cout << "Student ID: " << p->id << "\n";
            cout << "Student Name: " << p->name << "\n";
            cout << "Student Age: " << p->age << "\n";
        return;
    }
    display_reverse_recursion(p->next);
    cout << "Student ID: " << p->id << "\n";
    cout << "Student Name: " << p->name << "\n";
    cout << "Student Age: " << p->age << "\n";
    cout<<endl;
}//display_reverse_recursion ends here



//Function to swap 2 nodes using their ID's
public:void swap(int n1, int n2){

    Student *p1;
    Student *p2;

    Student *t1;
    Student *t2;

    if (n1 >= nextId || n2 > nextId){
        if (n1 > tail->id){
            cout<<"Student not found with id "<<n1<<endl;
        }
        else{
            cout<<"Student not found with id "<<n2<<endl;
        }
    }
    else if (n1 == head->id || n2 == head->id){

        p1 = head;
        t1 = p1->next;

        if (n1 == head->id){
            p2 = this->search_prev(n2);
        }
        else{
            p2 = this->search_prev(n1);
        }

        t2 = p2->next;
        p1->next = t2->next;
        p2->next = p1;

        t2->next = t1;
        head = t2;
        
    }
    else{
        p1 = this->search_prev(n1);
        p2 = this->search_prev(n2);

        t1 = p1->next;
        t2 = p2->next;

        p1->next = t2;
        p2->next = t1;

        Student *t3 = t1->next;
        t1->next = t2->next;
        t2->next = t3;
    }
}//swap ends here

//Function to divide the list into two lists of even and odd id's
public:void divide_in_even_and_odd(){

    Student* curr = head;
    Student* odd = nullptr;
    Student* even = nullptr;
    Student* e_next = nullptr;
    Student* o_next = nullptr;
    while(curr != nullptr)
    {
        if(curr->id %2 ==0)
        {
            if(even == nullptr)
            {
                even = e_next = curr;
            }
            else
            {
                e_next->next = curr;
                e_next = e_next->next;
            }
        }
        else
        {
            if(odd == nullptr)
            {
                odd = o_next = curr;
            }
            else
            {
                o_next->next = curr;
                o_next = o_next->next; 
            }
        }
        curr = curr->next;
    }
    if(e_next != nullptr)
    {
        e_next->next = nullptr;
    }
    if(o_next != nullptr)
    {
        o_next->next = nullptr;
    }

    display(even);
    display(odd);

    if(e_next != nullptr)
    {
        e_next->next = odd;
    }
    if(o_next != nullptr)
    {
        o_next->next = nullptr;
        tail = o_next;
    }
    else{
        tail = e_next;
    }
    head = even;

}//divide_in_even_and_odd ends here

//Function to remove duplicates
public:void remove_duplicates() {
    if(head == nullptr) {
        cout << "List Empty";
        return;
    }
    Student *p1 = head;
    while(p1 != nullptr && p1->next != nullptr) {
        Student *p2 = p1;
        while(p2->next != nullptr) {
            if(equals(p1,p2->next)) {
                if(p2->next == tail){
                    p2->next = nullptr;
                    tail = p2;
                }
                else{
                    Student* to_del = p2->next;
                    p2->next = p2->next->next;
                    delete to_del;
                }
                length--;
            } else {
                p2 = p2->next;
            }
        }
        p1 = p1->next;
    }
}//remove_duplicates ends here

//Function to detect loop in a list
public:bool detect_loop(){
    if(head==nullptr){
        cout<<"List Empty";
    }
    else{
        Student *slow = head;
        Student *fast = head;
        while(fast!=nullptr && fast->next != nullptr){
            slow = slow->next;
            fast=fast->next->next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
}//detect_loop ends here

//Function to reverse first and secind half
public:void reverse_half() {
    Student *slow = head;
    Student *fast = head;
    
    // Find the mid of the list
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Reverse the first half
    Student *prev = nullptr;
    Student *curr = head;
    Student *nxt = nullptr;
    
    while (curr != slow) {
        nxt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nxt;
    }
    
    //head pointer update
    head = prev;

    // Reverse second half from the mid
    prev = nullptr;
    while (slow != nullptr) {
        nxt = slow->next;
        slow->next = prev;
        prev = slow;
        slow = nxt;
    }
    
    // Connect the two halves
    curr = head;
    while (curr->next != nullptr) {
        curr = curr->next;
    }
    curr->next = prev;
}


//Function to swap pairs
public:void swap_pairs() {
    Student *temp = new Student;
    temp->next = head;

    Student *first;
    Student *second;
    
    Student *prev = temp;
    while (prev->next && prev->next->next) {
        first = prev->next;
        second = first->next;
        
        // Swap nodes
        prev->next = second;
        first->next = second->next;
        second->next = first;

        prev = first;
    }
    //setting value of head
    head = temp->next;
    delete temp;

    first = head;
    while (first->next != nullptr){
        first = first->next;
    }
    //setting value of tail
    tail = first;
}//swap_pairs ends here

//function to return length of the List
public:int getLength(){
    return length;
}

};//Linkedlist class ends here


int main()
{
    int check = 1;

    LinkedList *my_list = new LinkedList;

    while (check != 0)
    {
    cout << "1- Add Node\n2- Display List\n3- Display Reverse\n4- Reverse List\n5- Swap Two Nodes\n6- Divide in Even and Odd\n7- Reverse First half\n8- Swap PairWise\n9- Detect Loop\n10- Remove Duplicates\n11- Delete Specific Student\n0-Exit\n";
        cin >> check;

        if(check == 0){
            break;
        }
        else if (check == 1)
        {
            Student *curr = new Student;
            cout << "Enter name: ";
            cin >> curr->name;
            cout << "Enter age: ";
            cin >> curr->age;
            curr->id = my_list->nextId;
            my_list->nextId++;

            my_list->append(curr);
        }
        else if (check == 2)
        {
            my_list->display(my_list->head);
        }
        else if(check == 3){
            my_list->display_reverse_recursion();
        }
        else if(check == 4){
            my_list->reverse();
        }
        else if(check == 5){
            int n1,n2;
            cout << "Enter First ID: ";
                cin >> n1;
            cout << "Enter Second ID: ";
                cin >> n2;
            
            my_list->swap(n1,n2); 
        }
        else if (check == 6){
            my_list->divide_in_even_and_odd();
        }
        else if(check == 7){
            my_list->reverse_half();
        }
        else if(check==8){
            my_list->swap_pairs();
        }
        else if(check == 9){
            bool res = my_list->detect_loop();
            if (res){
                cout<<"LOOP DETECTED........\n";
            }
            else{
                cout<<"NO LOOP.........\n";
            }

        }
        else if(check == 10){
            my_list->remove_duplicates();
        }
        else if(check == 11){
            int n;
            cout << "Enter Student ID: ";
            cin >> n;
            my_list->delete_specific(n);
        }
        else
        {
            cout<<"Invalid Input\n";
        }
    }

    delete my_list;

    return 0;
}
