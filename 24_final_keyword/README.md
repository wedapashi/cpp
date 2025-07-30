# Final Keyword

We have already discussed about inheritance and how it works, or is supposed to be used. However, there can be scenarios
where as a designed you would want to prevent any other module from inheriting from a certain class, or even would want
to prevent function overriding in inherited classes. That is where `final` keyword comes in play.
If we append the keyword `final` in class declaration, the class can not be further inherited.

    class driver final {

    }

will be a class which can not be inherited. So,

    class instance:driver {
        // Some code -- not of any interest here
    }

will result in a compilation error.

Additionally,

    class driver {
        virtual void c_srand(unsigned long val) final {
            // Some code -- not of any interest here
        }
    }

If we try to override `c_srand()` method as below, 

    class instance:driver {
        void c_srand(unsigned long val) {
            // Some code -- not of any interest here
        }
    }

the code won't compile.

# Override Keyword

With inheritance, we use `virtual` keyword with functions in the base class, and then we override them in the derieved class. Suppose we mistakenly change the signature of the function in the derived class, the compiler does not complain about it. 
This is where the `override` keyword helps. Mark the function in derived class as `override` and thent he compiler will raise an error that we are trying to override a non-virtual function.

***
### Compilation output:
    
    g++ main.cpp -o a.out -g -Werror -Wall -Wno-unknown-pragmas -lpthread -lrt
    main.cpp:9:7: error: cannot derive from ‘final’ base ‘foo’ in derived type ‘bar’

    main.cpp:8:7: error: cannot derive from ‘final’ base ‘foo’ in derived type ‘bar’
        8 | class bar : public foo {
          |       ^~~
    main.cpp:19:10: error: virtual function ‘virtual void instance::c_srand(long unsigned int)’ overriding final function
       19 |     void c_srand(unsigned long val) {
          |          ^~~~~~~
    main.cpp:13:18: note: overridden function is ‘virtual void driver::c_srand(long unsigned int)’
       13 |     virtual void c_srand(unsigned long val) final {
          |                  ^~~~~~~
    main.cpp:34:9: error: ‘void brave::method(float)’ marked ‘override’, but does not override
       34 |    void method(float x) override {
          |         ^~~~~~
    main.cpp:37:9: error: ‘void brave::altMethod(int)’ marked ‘override’, but does not override
       37 |    void altMethod(int x) override {
          |         ^~~~~~~~~
    make: *** [Makefile:17: all] Error 1

