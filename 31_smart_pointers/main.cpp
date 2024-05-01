#include <iostream>
using namespace std;

class Seed {
private:
    int value;
public:
    void setSeed(int s) {
        value = s;
    }
    int getSeed(void) {
        return value;
    }
};

class seedPtr {
    Seed *ptr; // Pointer to seed class
public:
    // Constructor delegation
    seedPtr(Seed *p = nullptr):ptr(p) {

    }
    // Destructor
    ~seedPtr() { 
        cout << "Returning the memory borrowed.." << endl;
        delete (ptr); 
    }
    // Overloading dereferencing operator
    Seed& operator*() {
        return *ptr;
    }
    // Overloading the arrow operator
    Seed *operator ->() {
        return ptr;
    }
};
  
int main() {
    seedPtr pSeed = new Seed;
    pSeed->setSeed(123);
    cout << "Seed value is " << pSeed->getSeed() << endl;
    return EXIT_SUCCESS;
}
