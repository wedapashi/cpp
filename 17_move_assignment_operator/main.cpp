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
        // Move Constructor
        Foo (Foo&& obj) {
            cout << "In move constructor" << endl;
            ptr = obj.ptr;
            obj.ptr = nullptr;
        }
        // Move assignment operator
        Foo& operator=(Foo&& obj) {
            cout << "In Move Assignment Operator" << endl;
            if(this == &obj) {
                return *this;
            }
            delete ptr;
            ptr = obj.ptr;
            obj.ptr = nullptr;
            return *this;
        }
};

int main(void)
{
    Foo f;
    int pointMe = 10;
    f.setPtr(&pointMe);
    f.printValue();
    Foo f3;
    f3 = move(f);
    f3.printValue();
    return EXIT_SUCCESS;
}
