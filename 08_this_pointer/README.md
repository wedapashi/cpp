# This pointer

Looking at the code, there is a class `interface` and we have created 2 objects `iface1` and `iface2`. When we call `configure()` member function upon objects, internally `this` pointer is updated with the address of that object.
With two objects, there would be two copies of data members, but just one instance of member functions. If so, how is the compiler supposed to know which copy variables to use when `configure()` is called? It would know that based on what object is used to invoke the member function. So, `this` pointer is updated with the address of the object upon which the member function is called and all accesses to `pin` and other variables in the class are internally converted into `this->pin`.

To understand `this` pointer, it is important to know how objects look at functions and data members of a class.

1. Each object gets its own copy of the data member.  
2. All-access the same function definition as present in the code segment.  

Meaning, each object gets its own copy of data members and all objects share a single copy of member functions.
The compiler supplies an implicit pointer along with the names of the functions as ‘this’.
The ‘this’ pointer is passed as a hidden argument to all non-static member function calls and is available as a local variable within the body of all non-static functions. ‘this’ pointer is not available in static member functions as static member functions can be called without any object (with class name).

***

### Program Output:

    Address of iface1 object:0x7ffc7830b6f0
    Address held in this pointer:0x7ffc7830b6f0
    Address of iface2 object:0x7ffc7830b6f4
    Address held in this pointer:0x7ffc7830b6f4
