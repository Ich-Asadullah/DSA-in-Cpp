#include<iostream>
using namespace std;

class PriorityQueue{

public:
    int front = -1;
    int rear = -1;
    int size_list;
    int* que;

    PriorityQueue(){
        size_list = 10;
        que = new int[10];
    }

    PriorityQueue(int s){
        size_list = s;
        que = new int[s];
    }

    bool is_empty() {
        return (rear == -1);
    }

    bool is_full() {
        return ((rear + 1) % size_list == front);
    }
    
    void enqueue(int val){
        int i = rear;


        if(is_empty()){
            que[0] = val;
            rear = front = 0;
        }
        else if(!is_full())
        {
            do{
                if(val < que[i]){
                    que[(i+1)%size_list] = que[(i)%size_list];
                    i = (i-1)%size_list;
                }
                

            }while(i >= 0 && val < que[i]);


            que[(i+1)%size_list] = val;
            rear = (rear+1)%size_list;
        }
        else{
            cout<<"List is full........\n";
        }
        
    }

    void dequeue(){
        if(!is_empty()){
            front = (front+1)%size_list;
        }
        else{
            cout<<"List Empty....\n";
        }
    }

    void top(){
        if(!is_empty()){
            cout << "Top element: " << que[front] << endl;
        }
        else{
            cout<<"List Empty....\n";
        }
    }
};

int main(){
    int choice = 1;
    int len;

    cout<<"Enter length of Queue: ";
    cin>>len;
    PriorityQueue* queu = new PriorityQueue(len);
    
    
    while (choice!=0){
        cout<<"1- Enque\n2- Deque\n3- Top\n0- Exit\n";
        cin>>choice;

        if (choice==1){
            int value;
            cout<<"Enter value to add: ";
            cin>>value;

            queu->enqueue(value);
        }
        else if (choice==2){
            queu->dequeue();
        }
        else if (choice==3){
            queu->top();
        }
        else if (choice==4){
            for(int i=0; i<len; i++){
                cout<<queu->que[i]<<endl;
            }
            cout<<".......................................";
        }
        else{
            cout<<"Invalid";
        }

    }

}