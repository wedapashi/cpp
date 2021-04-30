# Polymorphism
This sample code demonstrates the runtime polymorphism by implementing the pure virtual function in Base class.

`comm_interface` is a base class and uart is a derived class publically inhering from comm_interface class.

We, by design want to generalize the communication interface as an enity, and hence defined as a comm_interface class.
Various communication interfaces such as uart, usb, spi, i2c, etc can be inherited from this implement their own-due
methods. 

Now, we also want to madate that the derived class must implement certain methods say, such as send() and receive().
This is achieved by making those methods in base class as pure virtual functions. 
