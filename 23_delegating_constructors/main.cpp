#include <iostream>
using namespace std;

class foo
{
private:
    uint32_t bar;
    uint32_t baz;
public:
    foo():foo(0) {
        
    }
    foo(uint32_t Bar):foo(Bar, 0) {

    }
    foo(uint32_t Bar, uint32_t Baz) {
        cout<<"In foo: In parameterized constructor"<<endl;
        bar = Bar;
        baz = Baz;
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
    void print(void)
    {
        cout << "bar = " << bar << ", baz = " << baz << endl; 
    }
    ~foo()
    {
        cout << "foo: In destructor" << endl;
    }
};

int main(void)
{
    foo f1(20);
    foo f2(10, 5); // Invokes paramterized constructor

    f1.print();
    f2.print();

    return 0;
}
