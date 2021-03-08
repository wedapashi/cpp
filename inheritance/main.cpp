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
        void show(void);
};

void Base::display(void)
{
    cout<<"In Base class display().."<<a<<endl;
}
void Derived::show(void)
{
    cout<<"In Derived class show().."<<endl;
}

int main(void)
{
    Derived D;
    D.a = 255;
    D.display();
    D.show();

    return 0;
}
