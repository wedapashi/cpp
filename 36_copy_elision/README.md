# Copy Elision

Copy elision is an optimization implemented by most compilers to prevent extra (potentially expensive) copies in certain situations. It makes returning by value or pass-by-value feasible in practice.

It's the only form of optimization that elides the as-if rule - copy elision can be applied even if copying/moving the object has side-effects.
Depending upon whether the expressions requires copy or move, the compiler may either use copy elision or move elision.

The Copy Elision is mostly ON by default in most IDEs as most modern compilers use Copy Elision and/or Move Elision. However, if you are using a GCC compiler, there is a flag which allows us to turn off the Copy Elision feature off.

`-fno-elide-constructors`

### Example explained:

`Integer` is a wrapper class around a dynamically allocated `int`. I know in reality no one will implement such a class, it makes no sense! However, lets look at it.

There is a `add` method that takes two `int` args and returns them into a `Integer` type. And `add` is implemented as follows:

    Integer add(int a, int b) {
        Integer temp (a + b);
        return temp;
    }

So, with 

    Integer sum = add(10, 20);

The following outout is seen:  

![](https://img.shields.io/badge/C++11-00FFFF)

    Integer(int)
    Integer(Integer&&)
    ~Integer()
    Integer(Integer&&)
    ~Integer()
    ~Integer()

## Why?

It creates one instance of `Integer` when it invokes a parameterized c'tor where it does `Integer temp (a + b);`. It creates a second instance of `Integer` when it is returnd by value.
And, this return value is caught into an `Integer` which is basically thrid intance of `Integer`.

If we __elide__ using `-fno-alide-constructors` flag in our make command, we see the following output:

    Integer(int)
    ~Integer()

Meaning, it elided (avoided) creating a copy of the object what was being moved around. Because, it was being returned as value, and a move/copy operation was elided. This is called Copy Elision.

Lets try the same code on C++17:  
![](https://img.shields.io/badge/C++17-00FFFF)


    Integer(int)
    Integer(Integer&&)
    ~Integer()
    ~Integer()

This is because, the compiler elided creating a copy of `Integer` when it was returned as value. This is also a form of Copy Elision, but is known as Named Return Value Optmization.

So in a nutshell, a better version of `add()` would be:

    Integer add(int a, int b) {
        return Integer(a + b);
    }


