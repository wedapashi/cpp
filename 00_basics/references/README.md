## Reference in C++

We all know pointers. 

    int number = 10;
    int *p = &number;

This creates two variables: A `number` as an `int` initialized with value of `10`. And, a pointer `p` of the compatible data-type initialized with address of `number`. So, to point to a variable, we are investing a 32-bit memory just to hold the address. It works, but C++ has a better way to deal with this requirement.

C++ has References. Its an alias for a variable name. It is created with `&` operator during the declaration. The initiazer, meaning the variable it is referring to is called *referent*. There is noseparate memory allocated to a reference. 

Look at an example of memory layout with a pointer:

         _          ________________
        |          |________________|
        |          |________________|
        |          |________________|
        |  0x1000 >|_______10_______| < number 
    RAM>|  0x1008 >|_____0x1000_____| < p
        |          |________________|
        |          |________________|
        |          |________________|
        |_         |________________|

With reference:

         _          ________________
        |          |________________|
        |          |________________|
        |          |________________|
        |  0x1000 >|_______10_______| < number | ref
    RAM>|  0x1008 >|________________|
        |          |________________|
        |          |________________|
        |          |________________|
        |_         |________________|

As said earlier, reference must initialized during the declaration itself. If not, compiler throws an error.

    main.cpp:8:15: error: ‘ref’ declared as reference but not initialized
    8 |     uint32_t &ref;

One can figure out the differences between references & pointers:
- References are alias, they do not require additional space for storing the value, pointers are variables, require storage to hold addresses
- References must be initialized, pointers can be left uninitialized -- but that will lead to issues later
- In case of a reference the initializer is always a lvalue, in case of pointer it can lvalue or a number/literal
- Pointers can be assigned as `nullptr`, references can not!
- References are bounded to its referent, pointers are mutable
- Pointers needs to be dereferenced, references are never dereferenced

***

## Program output:

    number = 10
    ref = 10
    Address of number = 0x7ffef0f6dd8c
    Address of ref = 0x7ffef0f6dd8c

