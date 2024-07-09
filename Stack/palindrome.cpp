#include<iostream>
using namespace std;


//Stack implemented on Arrays
class ArrayStack
{
    public:
    int size;
    char* arr;
    int top;

    //Constructors
    ArrayStack()
    {
        arr = new char[10];
        size = 10;
        top = -1;
    }
    ArrayStack(int si)
    {
        arr = new char[si];
        size = si;
        top = -1;
    }//constructors end here

    bool isFull()
    {
        if(top == size-1)
        {
            return true;
        }
        return false;
    }
    bool isEmpty()
    {
        if(top == -1)
        {
            return true;
        }
        return false;
    }

    void push(char element)
    {
        if(isFull())
        {
            cout<<"Array is full"<<endl;
            return;
        }
        top++;
        arr[top] = element;
    }

    char pop()
    {
        if(isEmpty())
        {
            cout<<"Array is empty "<<endl;
            return '-';
        }
        char x = arr[top];
        top--;
        return x;
    }

    void topShow()
    {
        if(isEmpty())
        {
            cout<<"Array is empty"<<endl;
            return;
        }
        cout<<arr[top]<<endl;;
    }
    void display()
    {
        if(isEmpty())
        {
            cout<<"Empty"<<endl;
            return;
        }
        int a = top;
        for(int i = a ; a>=0 ; a--)
        {
            cout<<arr[a]<<endl;
        }
    }

    //function to check if a string is palindrome or not
    bool checkPalindrome(ArrayStack stak , string str)
    {
        for(int i = 0 ; i<str.length() ; i++)
        {
            stak.push(str[i]);
        }
        string reversed;
        for(int i = 0 ; i<str.length() ; i++)
        {
            reversed += stak.pop();
        }
        if(str == reversed)
        {
            return true;
        }
        return false;
    }//check palindrome ends here
};//Stack on Arrays ends here


//Node for singly linked list
class Node
{
    public:
    char data ;
    Node* next = NULL;
    Node(char ch)
    {
        data = ch;
    }
};//node class ends here

//Node for Doubly linked list
class DoublyNode
{
    public:
    char data;
    DoublyNode* next = NULL;
    DoublyNode* pre = NULL;

    DoublyNode(char ch)
    {
        data = ch;
    }
};//doubly node class ends here

//Stack implemented on Singly Linked list and Also Doubly Linked list
class SinglyStack
{
    public:
    Node* top = NULL;

    bool isEmpty()
    {
        if(top == NULL)
        {
            return true;
        }
        return false;
    }

    void push(char a)
    {
        Node* newNode = new Node(a);
        if(top == NULL)
        {
            top = newNode;
            return;
        }
        newNode->next = top;
        top = newNode;

    }

    void pop()
    {
        if(isEmpty())
        {
            cout<<"Empty "<<endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        delete(temp);
    }

    char showTop()
    {
        if(isEmpty())
        {
            cout<<"Empty"<<endl;
            return '-';
        }
        return top->data;
    }
    
    void display()
    {
        Node* temp = top;
        while(temp !=NULL)
        {
            cout<<temp->data<<" --> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

    bool checkPalindrome(SinglyStack stak , string str)
    {
        for(int i = 0 ; i<str.length() ; i++)
        {
            stak.push(str[i]);
        }
        string reversed;
        for(int i = 0 ; i<str.length() ; i++)
        {
            reversed += stak.showTop();
            stak.pop();
        }
        if(str == reversed)
        {
            return true;
        }
        return false;
    }

};//Singly Stcck ends here

//Stack Implemented on Doubly Linked List
class DoublyStack{
    public:
    DoublyNode* top = NULL;

    bool isEmpty()
    {
        if(top == NULL)
        {
            return true;
        }
        return false;
    }

    void push(char a)
    {
        DoublyNode* newNode = new DoublyNode(a);
        if(top == NULL)
        {
            top = newNode;
            return;
        }
        newNode->next = top;
        top->pre = newNode;
        top = newNode;
    }

    void pop()
    {
        if(isEmpty())
        {
            cout<<"Empty "<<endl;
            return;
        }
        
        DoublyNode* temp = top;
        top = top->next;
        delete(temp);
    }

    char showTop()
    {
        if(isEmpty())
        {
            cout<<"Empty"<<endl;
            return '-';
        }
        return top->data;
    }

    void display()
    {
        DoublyNode* temp = top;
        while(temp !=NULL)
        {
            cout<<temp->data<<" --> ";
            temp = temp->next;
        }
        cout<<"NULL"<<endl;
    }

    bool checkPalindrome(DoublyStack stak , string str)
    {
        for(int i = 0 ; i<str.length() ; i++)
        {
            stak.push(str[i]);
        }
        string reversed;
        for(int i = 0 ; i<str.length() ; i++)
        {
            reversed += stak.showTop();
            stak.pop();
        }
        if(str == reversed)
        {
            return true;
        }
        return false;
    }

};//Doubly Stack ends here

int main()
{
    SinglyStack singlyStack;
    DoublyStack doublyStack;
    ArrayStack arrayStack;

    int choice;
    while(true)
    {
        cout<<"\nCheck For Palindrome \n 1-Using Array Stack \n 2-Singly linked List Stack  \n 3-Doubly Linked List Stack \n 0-Exit \n"<<endl;
        cin>>choice;

        if(choice == 1)
        {
            string str;
            cout<<"Enter string "<<endl;
            cin>>str;
            if(arrayStack.checkPalindrome(arrayStack ,str)){
                cout<<"IS Palindrome......\n";
            }
            else{
                cout<<"Not Palindrome....\n";
            }
        }
        else if(choice == 2)
        {
            string str;
            cout<<"Enter string "<<endl;
            cin>>str;
            if(singlyStack.checkPalindrome(singlyStack ,str)){
                cout<<"IS Palindrome......\n";
            }
            else{
                cout<<"Not Palindrome....\n";
            }
        }
        else if(choice == 3)
        {
            string str;
            cout<<"Enter string "<<endl;
            cin>>str;
            if(doublyStack.checkPalindrome(doublyStack ,str)){
                cout<<"IS Palindrome......\n";
            }
            else{
                cout<<"Not Palindrome....\n";
            }
            
        }
        else if (choice==0)
        {
            cout<<"Program end....."<<endl;
            break;
        }
        else
        {
            cout<<"Invalid Input.....\n"<<endl;
        }
    }
    return 0;
}