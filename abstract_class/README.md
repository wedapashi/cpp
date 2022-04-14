# Abstract class

Function overriding helps levaraging inheritance. Virtual functions help to define interfaces.
And, pure virtual functions are required to achieve polymorphism.

A class that contains pure virtual function is called abstract class.
You can't create an object of such a (abstract) class, you can not instantiate an abstract class. The idea is that the class with pure virtual functions exist solely to serve as a base classes, However, you can declare a pointer of the abstract class type.
Fundamentally, abstract class demands that its pure virutal functions to be overridden in any concrete derived class -- forcing the derive the rules of interface the abstract ckass has set.

By the way, if a base class contains only the pure virtual functions, then it also is an Interface.

In this example, `comm_interface` is class with `send()` and `receive()` declared as oure virtual functions. This would be our base class and `uart` is a class that publically inherits `comm_interface`.
We can have a pointer `p` of the `comm_interface` type (base class type) and instantiate it with object of `uart` class which happens to be a derived class. We can call `send` which is a pure virtual function within the base class `comm_interface`, yet, it invokes the member function upon the derived class.

This strategy can help you design reusable code/classes and let the derived class inplement the relevant functionality.
