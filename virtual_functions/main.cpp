#include<iostream>
using namespace std;

class Base
{
    public:
        int a;
        virtual void display(void);
};

class Derived:public Base
{
    public:
        void display(void);
};

void Base::display(void)
{
    cout<<"In Base class display().."<<endl;
}

void Derived::display(void)
{
    cout<<"In Derived class display().."<<endl;
}

int main(void)
{
    Derived D;
    Base *B = &D;
    B->display();     
    cout<<"display() is invoked using the base class pointer assigned with an object of derived class. This is achieved by declaring display() function as virtual in base class"<<endl;
    return 0;
}
