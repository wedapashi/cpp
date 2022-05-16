# Static data members and member functions

When you declare a static data member, it has to be declared outside the class with scope resolution operator.
The static member is then treated as a global variable but only within the class, hence static.
In the example code, `ppid` is a static data member.
static data members can be accessed using object names as well upon the class withuot taking an object of the class.

A static member function can only access static data members of the class, they can't access non-static data members.

In a nutshell, static data members are helpful for inter-object communication of a class. Secondly, such static data members can hold information about the class itself rather than objects of the class.
