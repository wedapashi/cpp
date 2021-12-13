# Abstract class

Function overriding helps levaraging inheritance. Virtual functions help to define interfaces.
And, pure virtual functions are required to achieve polymorphism.

A class that contains pure virtual function is called abstract class.
You can't create an object of such a (abstract) class, you can not instantiate an abstract class. The idea is that the
class with pure virtual functions exist solely to server as base classes, However, you can declare a pointer of the abstract class type.
Fundamentally, abstract class demands that its pure virutal functions to be overridden in any concrete derived class --
forcing the derive the rules of interface the abstract ckass has set.

By the way, if a base class contains only the pure virtual functions, then it also is an Interface.
