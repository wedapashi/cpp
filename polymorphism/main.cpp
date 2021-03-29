#include<iostream>
using namespace std;

class comm_interface
{
    public:
        virtual void send(void)=0;
        virtual void receive(void)=0;
};

class uart:public comm_interface
{
    public:
        void send(void);
        void receive(void);
};

void uart::send(void)
{
    cout<<"In Derived class send().."<<endl;
}
void uart::receive(void)
{
    cout<<"In Derived class receive().."<<endl;
}

int main(void)
{
    comm_interface *p = new uart();
    p->send();
    return 0;
}
