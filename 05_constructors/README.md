# Constructors

Okay, you have a `class` and you have developed member fuctions to access the values of data-members of the class. The basic principle of encapsulationr recommends to avoid using `public` data members and instead it suggests that every member should be made `private`. That said, you also need to find a way to initialize the data-members, and conversely, to access private data members you need an object of the class, as you do so, the object of the class is uninitialized. A perfect recipe for checken-and-egg story!

To accomplish this, C++ provides for special member functions, called class constructors, especially for constructing new objects and assigning values to their data members. More precisely, C++ provides a name for these member functions and a syntax for using them, and you provide the method definition.The name is the same as the class name.

The constructor prototype and header have an interesting property -- Although the constructor has no return value, it’s not declared type `void` either. In fact, a constructor has no declared type.

# Types of constructors:

1. Default constructor -- A *default constructor* is a constructor that is used to create an object when you don’t provide explicit initialization values.
2. Copy constructor -- A copy constructor for a class normally has this prototype:Class_name(const Class_name &); -- A *copy constructor* is used to copy an object to a newly created object. That is, it’s used during initialization, including passing function arguments by value and not during ordinary assignment.
3. Parameterized constructor -- It is possible to pass arguments to constructors. Typically, these arguments help initialize an object when it is created. To create a parameterized constructor, simply add parameters to it the way you would to any other function. When you define the constructor’s body, use the parameters to initialize the object. 

# Playing around with constructors:

Suppose we have a class containing a `uint32_t`.

    class foo
    {
    private:
        uint32_t bar;
    public:
        // Parameterized constructor, as default argument constructor
        // If default arguments are provided, the default constructor is no longer required.
        foo(uint32_t a=1)
        {
            cout<<"foo: In parameterized constructor"<<endl;
            bar = a;
        }
        // Copy constructor
        foo(foo &f)
        {
            cout<<"foo: In copy constructor"<<endl;
            bar = f.bar;
        }
        uint32_t getBar(void) { return bar; }
    };

Creating a object by `foo f1(10);` invokes the parameterized constructor.  
And `foo f2(f1);` invokes the copy constructor.
if we initialize the value with suitable data type, such as
    
    foo f3 = 144U; 

the compiler looks for a parameterized constructor that can take the value `144U` which fits as a `uint32` type.
Of cource if we attempt 
    
    foo f3 = "stupid";
    
The compiler won't be able to find a paramaterized constructor than can take a string as a parameter, so the compiler will complain:

    g++ main.cpp -o a.out -g -std=c++17 -Werror -Wall -Wno-unknown-pragmas -lpthread -lrt
    main.cpp: In function ‘int main()’:
    main.cpp:34:14: error: invalid conversion from ‘const char*’ to ‘uint32_t’ {aka ‘unsigned int’} [-fpermissive]
        34 |     foo f4 = "stupid";
           |              ^~~~~~~~
           |              |
           |              const char*

If there is a function that takes a user-defined type as an argument, for example an argument of class `foo` type.

    void print(foo fTemp) {
        std::cout << fTemp.getBar() << std::endl;
    }

Depending upon how the function is called, the compiler will look for a suitable constuctor, such that:

    prinf(f3);

invokes the copy constructor whereas,

    print(250U);

invokes a parameterized constructor as compiler does the implicit conversion between primitive type to user-defined type. 

***

### Program output:

    foo: In parameterized constructor
    foo: In copy constructor
    foo: In parameterized constructor
    foo: In copy constructor
    144
    foo: In parameterized constructor
    250


