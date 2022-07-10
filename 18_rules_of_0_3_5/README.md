# Rules in C++

In most cases, classes own some resource, such as a pointer to critical section, file handle, mutex/semaphore or a socket. Usually, these would be acquired in the class constructor. How would one decide what action needs to be taken in case objects of such a classes are copied, moved or destroyed.

For such a scenario, the implementation should follow Rule of 5.

### Rule of 5
If a class has ownership semantics, then designed must provide a user-defined:
 - Destructor 
 - Copy constructor
 - Copy assignement operator
 - Move constructor
 - Move assignement operator

Because the presence of a user-defined (or = default or = delete declared) destructor, copy-constructor, or copy-assignment operator prevents implicit definition of the move constructor and the move assignment operator, any class for which move semantics are desirable, has to declare all five special member functions.

***
### Rule of 3

If a class requires a user-defined destructor, a user-defined copy constructor, or a user-defined copy assignment
operator, it almost certainly requires all three.

As C++ copies and copy-assigns objects of user-defined types in various situations such as passing/returning by value,
manipulating a container, etc -- these special member functions will be called, if accessible and if they are not user-defined, they are implicitly-defined by the compiler.

The implicitly-defined special member functions are typically incorrect if the class manages a resource whose handle is an object of non-class type (raw pointer, POSIX file descriptor, etc), whose destructor does nothing and copy constructor/assignment operator performs a "shallow copy" (copy the value of the handle, without duplicating the underlying resource).

***
### Rule of 0

If a class does not have ownership semantics, then do not provide any user-defined function from the rule of 5. Thats
Rule 0, simple! That way the compiler will automatically synthesize the necessary functions. Concurrently, providding
user-defined implementation of some of functions will prevent the complier from synthesizing others.

When a base class is intended for polymorphic use, its destructor may have to be declared `public` and `virtual`. This
blocks implicit moves (and deprecates implicit copies), and so the special member functions have to be declared as
defaulted.

    class base_of_five_defaults
    {
    public:
        base_of_five_defaults(const base_of_five_defaults&) = default;
        base_of_five_defaults(base_of_five_defaults&&) = default;
        base_of_five_defaults& operator=(const base_of_five_defaults&) = default;
        base_of_five_defaults& operator=(base_of_five_defaults&&) = default;
        virtual ~base_of_five_defaults() = default;
    };


