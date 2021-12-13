# Inheritance in C++
C++ classes bring a higher level of reusability. Many vendors now offer class libraries, which consist of class
declarations and implementations. Because a class combines data representation with class methods, it provides a more
integrated package than does a function library.

Inheritance (using classes, of cource) lets you derive new classes from existing ones, with the derived class inheriting
the properties, including the methods, properties of the existing class -- or more precisely base class.

class <DerivedClass> : public <BaseClass> { };

The above inheritance is through a public derivation. With such a derivation, the public members of the base class
become public members of the dereived class. The private portions of a base class beome part of the derived class, but
they can be accessed only through public and protected methods of the base class.

The special relationship between a derived class and a base class is based on an underlying model for C++ inheritance.Actually, C++ has three varieties of inheritance: public, protected, and private. Public inheritance is the most common form, and it models an is-a relationship.This is shorthand for saying that an object of a derived class should also be an object of the base class. Anything you do with a base-class object, you should be able to do with a derived-class object.

Suppose you have a driver class. It supports init, read, write, enable, disable methods and data_in - data_out buffers.
Now, UART is an interface requiring a driver. Technically, UART is a driver. Hence, you can derive a UART class from the
Driver class. The UART class would inherit all the data members of the original class, so a UART class object would have
members representing the data members of a Driver class. 
