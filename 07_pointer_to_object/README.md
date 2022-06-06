# Accessing object using pointers
Just like general purpose pointers, C++ also allows accessing member functions and data members of the class using a pointer of the compatible (class) type.

In the code, `Rectangle` is the class having `area()` and `perimeter()` as public member functions, and `length` and `breadth` as the public data members.

`pRect` is a pointer of `Rectangle` type. As we already know, there can be 2 ways to have this pointer pointing to object of `Rectangle` class - Statically and dynamically. I have put at `STATIC_ALLOC` for conditional compilation to switch between the two ways. 

The outcome is simple enough -- It prints area and perimeter based on the values set for `length` and `breadth` before calling `area()` and `perimeter()` upon the objects.
