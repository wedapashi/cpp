#include <iostream>
using namespace std;

class Foo {
    private:
        int* ptr;
    public:
        int* getPtr(void) {
            return ptr;
        }
        void setPtr(int *p) {
            ptr = p;
        }
        void printValue(void) {
            cout << *ptr << endl;
        }
        Foo() {
            cout << "In default constructor" << endl;
            ptr = new int;
        }
        // Copy Constructor
        Foo (const Foo& obj) {
            cout << "In copy constructor" << endl;
            ptr = new int(*obj.ptr);
        }
        // Copy assignment operator
        Foo& operator=(const Foo& obj) {
            cout << "In Copy assignment operator" << endl;
            if(this == &obj) {
                return *this;
            }
            delete ptr;
            ptr = new int(*obj.ptr);
            return *this;
        }
};



int main(void)
{
    Foo f;
    int pointMe = 10;
    f.setPtr(&pointMe);
    f.printValue();
    Foo f2(f);
    f2.printValue();
    Foo f3;
    f3 = f2;
    f3.printValue();
    return EXIT_SUCCESS;
}
