#include<iostream>
using namespace std;

class Base
{
    public:
        int a;
        void display(void);
};

class Derived:public Base
{
    public:
        void display(void);
};

void Base::display(void)
{
    cout<<"In Base class display().. a = "<< a <<endl;
}
void Derived::display(void)
{
    cout<<"In Derived class display().. a = "<< a << endl;
}

int main(void)
{
    Base B;
    Derived D;
    D.a = 255;
    B.a = 250;
    B.display();
    D.display();
    cout << "display() method is being overrdden here when invoked via an object of derived class!" << endl;
    return 0;
}
