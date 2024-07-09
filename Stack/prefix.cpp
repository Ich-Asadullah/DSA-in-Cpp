#include<iostream>
#include<math.h>
using namespace std;

//Stack implemented on Arrays to store Integers
class IntegerStack
{
    public:
    int size;
    int* arr;
    int top;
    IntegerStack()
    {
        arr = new int[100];
        size = 100;
        top = -1;
    }
    IntegerStack(int size)
    {
        arr = new int[size];
        top = -1;
    }
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

    void push(int element)
    {
        if(isFull())
        {
            cout<<"Array is full"<<endl;
            return;
        }
        top++;
        arr[top] = element;
    }

    int pop()
    {
        if(isEmpty())
        {
            cout<<"Array is empty "<<endl;
            return -1;
        }
        int x = arr[top];
        top--;
        return x;
    }

    int topShow()
    {
        if(isEmpty())
        {
            cout<<"Array is empty"<<endl;
            return -1;
        }
        return arr[top];
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
};//Integers Stack ends here

//Stack Implemented on arrays to store characters
class CharStack
{
    public:
    char* arr;
    int size;
    int top;
    CharStack()
    {
        size = 100;
        arr = new char[size];
        top = -1;
    }
    CharStack(int size)
    {
        arr = new char[size];
        top = -1;
    }
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
            return -1;
        }
        char x = arr[top];
        top--;
        return x;
    }

    char topShow()
    {
        if(isEmpty())
        {
            cout<<"Array is empty"<<endl;
            return '-';
        }
        return arr[top];
    }
    void display()
    {
        if(isEmpty())
        {
            cout<<"Empty"<<endl;
            return;
        }
        char a = top;
        for(int i = a ; a>=0 ; a--)
        {
            cout<<arr[a]<<endl;
        }
    }
};

void prefixEvaluation(IntegerStack &s , string str)
{
    for(int i = str.length()-1 ; i>=0 ; i--)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            s.push(str[i]-'0');
        }
        else
        {
            int op1 = s.pop();
            int op2 = s.pop();
            switch(str[i])
            {
            case '+':
                s.push(op1+op2);
                break;
            case '-':
                s.push(op1-op2);
                break;
            case '*':
                s.push(op1*op2);
                break;
            case '/':
                s.push(op1/op2);
                break;  
            default:
                break;
            }
        }
    }
    cout<<s.pop()<<endl;
}

void postfixEvaluation(IntegerStack &s , string str)
{
    for(int i =0 ; i<=str.length()-1 ; i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            s.push(str[i]-'0');
        }
        else
        {
            int op1 = s.pop();
            int op2 = s.pop();
            switch(str[i])
            {
            case '+':
                s.push(op2+op1);
                break;
            case '-':
                s.push(op2-op1);
                break;
            case '*':
                s.push(op2*op1);
                break;
            case '/':
                s.push(op2/op1);
                break;  
            default:
                break;
            }
        }
    }
    cout<<s.pop()<<endl;
}

int presidence(char c)
{
    if(c == '^')
    {
        return 3;
    }
    else if(c == '/' || c=='*')
    {
        return 2;
    }
    else if(c == '-' || c=='+')
    {
        return 1;
    }
    else
    {
        return -1;
    }

}

string infixToPostfix(CharStack &s , string str)
{
    string result = "";
    for(int i = 0 ; i<=str.length()-1 ; i++)
    {
        if(str[i] >='0' && str[i] <='9')
        {
            result+=str[i];
        }
        else if (str[i] == '(')
        {
            s.push(str[i]);
        }
        else if(str[i] ==')')
        {
            while(!s.isEmpty() && s.topShow() != '(')
            {
                result+=s.pop();
            }      
            char temp = s.pop();            
        }
        else
        {
            while(!s.isEmpty() && presidence(s.topShow()) >= presidence(str[i]))
            {
                result+=s.pop();
            }
            s.push(str[i]);
        }
    }
    while(!s.isEmpty())
    {
        result+=s.pop();
    }

    return result;
}

string infixToprefix(CharStack &s , string str)
{
    string str2 = "";
    for(int i = str.length()-1 ; i>=0 ; i--)
    {
        str2+=str[i];
    }
    for(int i =0  ; i<=str2.length()-1 ; i++)
    {
        if(str2[i] == '(')
        {
            str2[i] = ')';
        }
        else if(str2[i] ==')')
        {
            str2[i] = '(';
        }
        else
        {
            continue;
        }
    }
    str = str2;
    cout<<str<<endl;

    string result = "";
    for(int i = 0 ; i<=str.length()-1 ; i++)
    {
        if(str[i] >='0' && str[i] <='9')
        {
            result+=str[i];
        }
        else if (str[i] == '(')
        {
            s.push(str[i]);
        }
        else if(str[i] ==')')
        {
            while(!s.isEmpty() && s.topShow() != '(')
            {
                result+=s.pop();
            }      
            char temp = s.pop();            
        }
        else
        {
            while(!s.isEmpty() && presidence(s.topShow()) >= presidence(str[i]))
            {
                result+=s.pop();
            }
            s.push(str[i]);
        }
    }
    while(!s.isEmpty())
    {
        result+=s.pop();
    }
    string result2 = "";
    for(int i = result.length()-1 ; i>=0 ; i--)
    {
        result2+=result[i];
    }


    return result2;
    
}

int precedenceBracket(char c)
{
    if(c == '(')
    {
        return 3;
    }
    else if(c == '{')
    {
        return 2;
    }
    else if (c =='[')
    {
        return 1;
    }
    else if (c ==')')
    {
        return 3;
    }
    else if(c == '}')
    {
        return 2;
    }
    else if (c ==']')
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool SingleBalancedParanteses(CharStack st , string s)
{

    for(int i = 0 ; i<s.length() ; i++)
    {
        if(s[i] == '(' || s[i] =='{' || s[i] == '[')
        {
            st.push(s[i]);
        }
        else if(s[i] == ')' || s[i] =='}' || s[i] == ']')
        {
            if(st.isEmpty())
            {
                cout<<"Not Balanced......"<<endl;
                return false;
            }
            char temp = st.pop();
        }
        else
        {
            continue;
        }
    }

    if(st.isEmpty())
    {
        cout<<"Balanced ...."<<endl;
        return true;
    }
    cout<<"Not Balanced ...."<<endl;
    return false;
}

bool checkFormat(CharStack &s , string str)
{
    for(int i = 0 ; i<str.length() ; i++)
    {
        if(str[i] == '[' || str[i] == '{' || str[i] == '(')
        {
            if(s.isEmpty() || (precedenceBracket(str[i]) >= precedenceBracket(s.topShow())))
            {
                s.push(str[i]);
            }
            else if(precedenceBracket(str[i]) < precedenceBracket(s.topShow()))
            {
                return false;
            }

        }

        else if(str[i] == ']' || str[i] == '}' || str[i] == ')')
        {
            if(precedenceBracket(str[i]) == precedenceBracket(s.topShow()))
            {
                char temp = s.pop();
            }
            else if(s.isEmpty())
            {
                return false;
            }
            else
            {
                return false;
            }
        }

        else
        {
            continue;
        }
    }
    if(s.isEmpty())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void sort(IntegerStack &s , int ele)
{
    if(s.isEmpty() || s.topShow() > ele)
    {
        s.push(ele);
        return;
    }
    int temp = s.pop();
    sort(s , ele);
    s.push(temp);
}

void emptyStack(IntegerStack &s )
{
    if(s.isEmpty())
    {
        return;
    }

    int temp = s.pop();
    emptyStack(s);
    sort(s , temp);
}

int main()
{
    IntegerStack s;
    CharStack s2;
 
    int choice;
    while(true)
    {
        cout<<"\n 1-Check Single type braces \n 2-Check Multiple braces \n 3-Infix expression to postfix expression \n 4-Evaluate Postfix expression \n 0-Exit \n"<<endl;
        cin>>choice;

        if(choice == 1)
        {
            string str;
            cout<<"Enter braces "<<endl;
            cin>>str;
            cout<<SingleBalancedParanteses(s2 ,str);
        }
        else if(choice == 2)
        {
            string str;
            cout<<"Enter braces "<<endl;
            cin>>str;
            cout<<checkFormat(s2 ,str);
        }
        else if(choice == 3)
        {
            string str;
            cout<<"Enter infix Expression "<<endl;
            cin>>str;
            cout<<infixToPostfix(s2 ,str);
        }
        else if(choice == 4)
        {
            string str;
            cout<<"Enter PostFix expression "<<endl;
            cin>>str;
            postfixEvaluation(s ,str);
        }
        else
        {
            cout<<"Program end....."<<endl;
            break;
        }
    }
    return 0;
}