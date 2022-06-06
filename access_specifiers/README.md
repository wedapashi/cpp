# Access Specifiers

In C++, there are three access specifiers:
- **Public:** members are accessible from outside the class
- **Private:** members cannot be accessed (or viewed) from outside the class
- **Protected:** members cannot be accessed from outside the class, however, they can be accessed in inherited classes.

Look at the code (main.cpp):
`R1` is an object of class `Rectangle` which has `length` and `breadth` as `private` members.
If we try to access those directly in following way - 

    R1.length = 10;
    R1.breadth = 5;

The code doesn't compiler, the compiler reports following errors:

    g++ main.cpp -o access_specifiers.out -g -Werror -Wall -Wno-unknown-pragmas -lpthread -lrt
    main.cpp: In function ‘int main()’:
    main.cpp:61:8: error: ‘int Rectangle::length’ is private within this context
       61 |     R1.length = 10;
          |        ^~~~~~
    main.cpp:7:9: note: declared private here
        7 |     int length;
          |         ^~~~~~
    main.cpp:61:8: note: field ‘int Rectangle::length’ can be accessed via ‘int Rectangle::getLength()’
       61 |     R1.length = 10;
          |        ^~~~~~
          |        getLength()
    main.cpp:62:8: error: ‘int Rectangle::breadth’ is private within this context
       62 |     R1.breadth = 5;
          |        ^~~~~~~
    main.cpp:8:9: note: declared private here
        8 |     int breadth;
          |         ^~~~~~~
    main.cpp:62:8: note: field ‘int Rectangle::breadth’ can be accessed via ‘int Rectangle::getBreadth()’
       62 |     R1.breadth = 5;
          |        ^~~~~~~
          |        getBreadth()
    make: *** [Makefile:16: all] Error 1

Meaning, we can't access `private` members directly. So instead, we change to:

    //R1.length = 10;
    R1.setLength(10);
    //R1.breadth = 5;
    R1.setbreadth(5);

**Resulting in:**

    In constructor
    Area is 50
    Perimeter is 30
    In distructor
    
We'll get to constructors and destructors later.

