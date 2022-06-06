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

    t.a = 10;
    t.b = 20;
    t.c = 30;
    // Supress the stupid warning (treated as error) with unused variable
    t = t;

    cout << "a = " << t.a << ", b = " << t.b << ", c = " << t.c << endl << endl;
}

int main(void)
{
    function();
    Your y;
    y.fun();

    return 0;
}
