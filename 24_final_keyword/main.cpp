#include<iostream>
using namespace std;

class foo final {
   
};

class bar : public foo {

};

class driver {
    virtual void c_srand(unsigned long val) final { 
        // some code
    }
};

class instance : public driver {
    void c_srand(unsigned long val) {
        // some code 
    }
};

class alpha { 
   virtual void method(int x) { 
       // some code 
   }
   void altMethod(int x) { 
       // some code 
   }
};

class brave : alpha { 
   void method(float x) override {
       // some code
   }
   void altMethod(int x) override {
       // some code 
   }
};

int main(void) {
    return EXIT_SUCCESS;
}
