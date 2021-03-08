#include<iostream>
using namespace std;

template<class T>
class Stack
{
private:
    T *pStack;
    int top;
    int size;
public:
    Stack(int sz);
    void push(T x);
    T pop(void);
    void display(void);
    ~Stack();
};

template<class T>
Stack<T>::Stack(int sz)
{
    this->size = sz;
    this->top = -1;
    this->pStack = new T[this->size];
}

template<class T>
void Stack<T>::push(T x)
{
    if(this->size-1==top)
    {
        throw 1;
    }
    else
    {
        this->top++;
        this->pStack[top]=x;
    }
}

template<class T>
T Stack<T>::pop(void)
{
    T x = 0;
    if(-1==this->top)
    {
        throw 2;
    }
    else
    {
        x = pStack[top];
        top--;
    }

    return x;
}

template<class T>
void Stack<T>::display(void)
{
    int t = this->top;
    if(-1==this->top)
    {
        cout<<"Stack is empty.."<<endl;
    }
    else
    {
        cout<<"Stack elements are:"<<endl;
        while(t != -1)
        {
            cout<<pStack[t]<<endl;
            t--;
        }
    }
}

template<class T>
Stack<T>::~Stack()
{
    cout<<"In default destructor.."<<endl;
}

int main(void)
{
    Stack<int> S(10);

    try{
        S.push(10);
        S.display();
        S.push(23);
        S.display();
        S.push(45);
        S.display();
        S.pop();
        S.display();
        S.pop();
        S.display();
        S.pop();
        S.display();
        S.pop();
        S.display();
    }
    catch(int e)
    {
        if(1==e)
            cout<<"Exception: Stack full.."<<endl;
        else if(2==e)
            cout<<"Exception: Stack empty.."<<endl;
        else
            cout<<"Exception: Unhandled.."<<endl;
    }
    catch(...)
    {
        cout<<"In catch-all block.."<<endl;
    }

    return 0;
}


