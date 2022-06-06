#include <iostream>
using namespace std;
  
class SmartPtr {
    int* ptr; // Actual pointer
public:
    explicit SmartPtr(int* p = NULL) { ptr = p; }
    // Destructor
    ~SmartPtr() { 
        cout << "Returning the memory borrowed.." << endl;
        delete (ptr); 
    }
    // Overloading dereferencing operator
    int& operator*() { return *ptr; }
};
  
int main()
{
    SmartPtr ptr(new int());
    cout << "The idea is to use constructor and destructor mechanism of C++ to initialize the pointer and then let the destructor do the janitor work!" << endl;
    cout << "Smart ptr(new int()); -- This does exactly what we stated above.. Borrows the memory from the heap by new() call." << endl;
    cout << "And the constructor ensures that the int pointer which is a private data member of class SmartPtr is initialized with the address of newly allocated memory.." << endl;
    cout << "Lets set the value to 20, to test it.. If something is wrong we should see a core-dump!" << endl;
    *ptr = 20;
    cout << "The value is " << *ptr << endl;
    cout << "We don't need to call delete ptr: when the object ptr goes out of scope, the destructor for it is automatically called and destructor does delete ptr. " << endl << endl; 
    return 0;
}
