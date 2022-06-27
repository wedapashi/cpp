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

***
### Compilation output:
    
    g++ main.cpp -o a.out -g -Werror -Wall -Wno-unknown-pragmas -lpthread -lrt
    main.cpp:9:7: error: cannot derive from ‘final’ base ‘foo’ in derived type ‘bar’
        9 | class bar:foo {
          |       ^~~
    main.cpp:19:10: error: virtual function ‘virtual void instance::c_srand(long unsigned int)’ overriding final function
       19 |     void c_srand(unsigned long val) {
          |          ^~~~~~~
    main.cpp:14:18: note: overridden function is ‘virtual void driver::c_srand(long unsigned int)’
       14 |     virtual void c_srand(unsigned long val) final {
          |                  ^~~~~~~
    make: *** [Makefile:17: all] Error 1

