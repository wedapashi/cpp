#include<iostream>
using namespace std;
#define msg(x)  #x

class foo final {
   
};

class bar:foo {

};

class driver {
    virtual void c_srand(unsigned long val) final {
    }
};

class instance:driver {
    void c_srand(unsigned long val) {
    }
};

int main(void) {
    return EXIT_SUCCESS;
}
