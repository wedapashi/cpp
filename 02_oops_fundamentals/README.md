The concept of Object-Oriented design relies heavily on programming constructs given by the language itself. In the case of C++ those are:

* Abstraction
* Encapsulation
* Inheritance
* Polymorphism

# Abstraction

The idea of abstraction is to restrict the scope of something's access. 
When you buy a Ferrari, you don't really care what happens when you push the accelerator or the brakes, as long as they work as desired. When you buy a Rolex, you don't really care what mechanism it uses for time-keeping. Is it an SoC, or a simple RTC chip, or a built-in timer—_it doesn't matter!_  
C++ classes exhibit the property of abstracting their objects from unnecessary details. This property can be used with greater effect to abstract code from certain properties of the class, so that those aren't polluted by unforseen design issues.

# Encapsulation

A lot of people confuse abstraction with encapsulation with a notion of data hiding. Yes, encapsulation can be conceived as a way to hide data, but there is more that separates the two fundamentals. In normal terms, encapsulation is defined as the wrapping up of data and information under a single unit. In Object Oriented Programming, encapsulation is defined as the binding together of the data and the functions that manipulate them. In a nutshell, encapsulation also leads to data abstraction or hiding, as using encapsulation also hides the data.

# Inheritance

It depicts an "is-a" relationship. For example, a cube is a square, a sphere is a circle. An apple is a fruit. Inheritance (using classes, of course) lets you derive new classes from existing ones, with the derived class inheriting the properties, including the methods and properties, of the existing class—or more precisely, the base class.

    class : public { };

The above inheritance is through a public derivation. With such a derivation, the public members of the base class become public members of the derived class. The private portions of a base class become part of the derived class, but they can be accessed only through public and protected methods of the base class.  
The special relationship between a derived class and a base class is based on an underlying model for C++ inheritance. Actually, C++ has three varieties of inheritance: public, protected, and private. Public inheritance is the most common form, and it models an is-a relationship. This is shorthand for saying that an object of a derived class should also be an object of the base class. Anything you do with a base-class object, you should be able to do with a derived-class object.  
Suppose you have a driver class. It supports `init`, `read`, `write`, `enable`, `disable` methods, and `data_in`, `data_out` buffers. Now, UART is an interface requiring a driver. Technically, UART is a driver. Hence, you can derive a UART class from the Driver class. The UART class would inherit all the data members of the original class, so a UART class object would have members representing the data members of a Driver class.  
C++ classes bring a higher level of reusability. Many vendors now offer class libraries, which consist of class declarations and implementations. Because a class combines data representation with class methods, it provides a more integrated package than a function library.

# Polymorphism

Poly means multiple, morph means a form. Anything that changes its functional form with context is polymorphic. The button on a digital wrist-watch does a different functions in relation to what screen is being displayed. A knife is used to cut fruits, and it can also be used to spread jam on a slice of a bread. Context decides what form or behaviour is invoked. This can be leveraged to great potential.  
This sample code demonstrates how the runtime polymorphism works by implementing the pure virtual function in the Base class.

`comm_interface` is a base class, and uart is a derived class publicly inhering from the `comm_interface` class.

We, by design, want to generalise the communication interface as an entity, and hence define it as a comm_interface class. Various communication interfaces such as uart, usb, spi, i2c, etc can be inherited from this and implemented in their own-due methods.  
Now, we also want to mandate that the derived class must implement certain methods, such as `send()` and `receive()`. This is achieved by making those methods in the base class as pure virtual functions.
