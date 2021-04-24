#include<iostream>

using namespace std;

class Test {

private:
    int a;
protected:
    int b;
public:
    int c;
friend void function(void);
};

class Your;

class My
{        
private:
    int a;
protected:
    int b;
public:
    int c;
    friend Your;
};

class Your {

public:

    My m;
    void fun(void)
    {
        m.a = 100;
        m.b = 200;
        m.c = 300;
    }
};


void function(void)
{
    Test t;
    cout << "Setting value of a and b which are private and protected members of the class Test respectively." << endl;
    cout << "This is done by making function() a friend function in class Test" << endl;

    t.a = 10;
    t.b = 20;
    t.c = 30;
    // Supress the studip warning (treated as error) with unused variable
    t = t;

    cout << "a = " << t.a << ", b = " << t.b << ", c = " << t.c << endl << endl;
}

int main(void)
{
    function();
    Your y;
    cout << "Class My and class Yous shares a 'has a' relationship. We can access a and b which are private and protected members of the class My respectively by making class Your a friend class in Class My declaration (See code for details).." << endl;
    y.fun();

    return 0;
}
