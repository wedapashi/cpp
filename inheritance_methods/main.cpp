#include<iostream>
using namespace std;

class Parent
{
    private:
        int a;
    protected:
        int b;
    public:
        int c;
        void Parent_display(void)
        {
            a = 10;
            b = 20;
            c = 30;
        }
};

class Child: public Parent
{
    public:
        void Child_display(void)
        {
            a = 1;
            b = 2;
            c = 3;
        }
};

class Child2: protected Parent
{
    public:
        void Child_display(void)
        {
            a = 1;
            b = 2;
            c = 3;
        }
};

class GrandChild: public Child
{
    public:
        void GrandChild_display(void)
        {
            a = 11;
            b = 22;
            c = 33;
        }
};

class GrandChild2: protected Child
{
    public:
        void GrandChild_display(void)
        {
            a = 11;
            b = 22;
            c = 33;
        }
};

int main(void)
{
    Child C;
    
    return 0;
}
