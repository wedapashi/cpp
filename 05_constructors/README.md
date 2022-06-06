# Constructors

Okay, you have a `class` and you have developed member fuctions to access the values of data-members of the class. The basic principle of encapsulationr recommends to avoid using `public` data members and instead it suggests that every member should be made `private`. That said, you also need to find a way to initialize the data-members, and conversely, to access private data members you need an object of the class, as you do so, the object of the class is uninitialized. A perfect recipe for checken-and-egg story!

To accomplish this, C++ provides for special member functions, called class constructors, especially for constructing new objects and assigning values to their data members. More precisely, C++ provides a name for these member functions and a syntax for using them, and you provide the method definition.The name is the same as the class name.

The constructor prototype and header have an interesting property -- Although the constructor has no return value, it’s not declared type `void` either. In fact, a constructor has no declared type.

# Types of constructors:

1. Default constructor -- A *default constructor* is a constructor that is used to create an object when you don’t provide explicit initialization values.
2. Copy constructor -- A copy constructor for a class normally has this prototype:Class_name(const Class_name &); -- A *copy constructor* is used to copy an object to a newly created object. That is, it’s used during initialization, including passing function arguments by value and not during ordinary assignment.
3. Parameterized constructor -- It is possible to pass arguments to constructors. Typically, these arguments help initialize an object when it is created. To create a parameterized constructor, simply add parameters to it the way you would to any other function. When you define the constructor’s body, use the parameters to initialize the object. 



