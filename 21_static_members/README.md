# Static data members and member functions

When you declare a `static` data member, it has to be declared outside the class with scope resolution operator.
The static member is then treated as a global variable but only within the class, hence `static`.
In the example code, `ppid` is a `static` data member. Static data members can be accessed using object names as well upon the class withuot taking an object of the class.

It is important to note that a static member function can only access static data members of the class, they can't access non-static data members. Look at the snippet below, `update_ppid` is a `static` member function of class `Info`. `ppid` is a `static` variable and `pid` is a non-static data member.

    static void update_ppid(int v) {
        ppid = v;
        pid = -1;
    }
    
**Compilation error:**

    main.cpp: In static member function ‘static void Info::update_ppid(int)’:
    main.cpp:20:9: error: invalid use of member ‘Info::pid’ in static member function
       20 |         pid = -1;
          |         ^~~
    main.cpp:6:9: note: declared here
        6 |     int pid;
          |         ^~~
    make: *** [Makefile:17: all] Error 1

In a nutshell, static data members are helpful for inter-object communication of a class. Secondly, such static data members can hold information about the class itself rather than objects of the class.

An example of a use-case for this feature that I can think of is, a requirement to keep count of how many objects of a class have been created. I can use a `static` variable as a counter, increment and decrement it in constructor and destructor respectively, and that way, I'd know how many objects have been created. 

***
### Program output:

    PPID when accessed through object P1 is: 100
    PPID when accessed through object P2 is: 100
    PPID when accessed through class method without using an object is: 100
