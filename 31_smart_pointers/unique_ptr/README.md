# Unique pointers

It is introduced in `C++11` version.
As the name suggests, at a time only one pointer can point to the object.
It is used when you do not want to share the underlying resource, in this case the `sensor` class.
Suppose we have a `sensor` class and a `sensorHandlePtr` class. And we have created a unique pointer in the following
way: 

    std::unique_ptr<sensor> sensPtr(new sensor);

Upon creation, the constructor of the class `sensor` in called. 
This works until you try to create a copy of this pointer.
The compiler will not allow creating a copy of it because copy constructor of `unique_ptr`is a deleted function. 
Suppose we try to do that by:

    auto tempPtr(p);

Following compilation error is thrown:

    g++ main.cpp -o a.out -g -std=c++17 -Werror -Wall -Wno-unknown-pragmas -lpthread -lrt
    main.cpp: In function ‘void createSensorHandle()’:
    main.cpp:45:25: error: use of deleted function ‘std::unique_ptr<_Tp, 
        _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = sensor; _Dp = std::default_delete<sensor>]’
     45 |     auto tempPtr(sensPtr);
        |                         ^
    In file included from /usr/include/c++/11/memory:76, from main.cpp:2:
        /usr/include/c++/11/bits/unique_ptr.h:468:7: note: declared here
    468 |       unique_ptr(const unique_ptr&) = delete;
        |       ^~~~~~~~~~
    make: *** [Makefile:17: all] Error 1

If you pass this pointer as an argument to a function, you still get the same issue. Support there is a `transfer`
function which takes `unique_ptr` as an argument. 

    void transfer(std::unique_ptr<sensor> ptr)
    {
        // some code
        std::cout << ptr->getRawValue() << std::endl;
    }

and it is invoked as:

    transfer(sensPtr);

You'd still get compilation errors:

    g++ main.cpp -o a.out -g -std=c++17 -Werror -Wall -Wno-unknown-pragmas -lpthread -lrt
    main.cpp: In function ‘void createSensorHandle()’:
    main.cpp:55:13: error: use of deleted function ‘std::unique_ptr<_Tp, 
        _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = sensor; _Dp = std::default_delete<sensor>]’
     55 |     transfer(sensPtr);
        |     ~~~~~~~~^~~~~~~~~
    In file included from /usr/include/c++/11/memory:76,from main.cpp:2: 
        /usr/include/c++/11/bits/unique_ptr.h:468:7: note: declared here
    468 |       unique_ptr(const unique_ptr&) = delete;
        |       ^~~~~~~~~~
    main.cpp:41:39: note:   initializing argument 1 of ‘void transfer(std::unique_ptr<sensor>)’
     41 | void transfer(std::unique_ptr<sensor> ptr)
        |               ~~~~~~~~~~~~~~~~~~~~~~~~^~~
    make: *** [Makefile:17: all] Error 1

You can move a unique pointer because thought it doesn't have copy semantics, it has move semantics.
So, if you are willing to pass this pointer as a smart pointer to a function, you ought to move it in the function call using `std::move`.

    transfer(std::move(sensPtr));

This should work! Obviously, after this function call, `sensPtr` is a null pointer and shouldn't be used.

***
### Program output:

    default constructor of sensor class
    50
    50
    default destructor of sensor class
