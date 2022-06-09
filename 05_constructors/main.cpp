#include <iostream>
using namespace std;

class foo
{
private:
    uint32_t bar;
    uint32_t baz;

public:
#if 0
    // Default constructor, can't return anything!
    foo()
    {
        cout<<"In foo: default constructor"<<endl;
        bar = 1;
        baz = 1;
    }
#endif
    // Parameterized constructor, can't return anything! This also acts as default argument constructor
    // If default arguments are provided, the deault constructor is no longer required.
    foo(uint32_t a=1, uint32_t b=1)
    {
        cout<<"In foo: In parameterized constructor"<<endl;
        setBar(bar);
        setBaz(baz);
    }
    // Copy constructor
    foo(foo &f)
    {
        cout<<"foo: In copy constructor"<<endl;
        bar = f.bar;
        baz = f.baz;
    }
    void setBar(uint32_t b) // Mutator
    {
        bar = b;
    }
    uint32_t getBar() // Facilitator
    {
        return bar;
    }
    void setBaz(uint32_t b) // Mutator
    {
        baz = b;
    }
    uint32_t getBaz() // Facilitator
    {
        return baz;
    }
    ~foo()
    {
        cout << "foo: In destructor" << endl;
    }
};

int main(void)
{
    foo f1;  // Invokes default constructor
    foo f2(10, 5); // Invokes paramterized constructor
    foo f3(f2); // Invokes copy constructor

    return 0;
}
