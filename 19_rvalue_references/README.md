# L-value, R-value and R-value references

#### L-Value and R-Value

L-values:
 - Has a name
 - all variables are l-values
 - Can be assigned with values
 - Some expressions return l-values
 - l-value persists beyond the expression
 - Functions that return by references return l-value

R-values:
 - Does not have a name
 - R-value is a temporary value
 - Cannot be assigned values
 - Some expressions return r-value
 - Does not persist beyond the expression
 - Functions that return-by-value return r-value

What is a temporary? 

    int x = 5;

Here `5` is a temporary.

How does an expression return l-value? A typical example would be increment and decrement operators. For example, `++x;` is an l-value, and so is `~x;`.

How does an expression return r-value?
    
    int x = 5+10;
    int y = x + 5;
    int z = x + y;

Here `5+10` is an expression, that returns `15` which is a r-value. Similarly, `x + 5` and `x + y` are r-values, they
don't persist beyond expressions.

What is a function that returns by-value?

    pid_t getpid(void);

This is a function that returns `pid_t`, which is a r-value.Similarly, `strlen()`, `rand()` are the functions that
return by value -- returning a r-value.

What are functions that return by reference:

    double& calibrate(double& d) {
        const double m = 1.146789;
        const double c = -0.004583;
        d = d*m+c;
        return d;
    }

This function returns by reference.

#### R-Value References
 - Introduced in `C++11`
 - It is a reference created to a memory
 - Represents a temporary
 - Created with `&&` operator
 - Cannot point to l-values
 - Alwats bind to temporaries and/or l-values

Lets see some examples:

    int &&r1 = 55; // 55 is a temporary
    int &&r2 = getpid(); // Returnd pid_t which is a value -- temporary!
    int &&r3 = 10+20; // Which is a expression that returns a temporary

R-values references can not bind to l-values:

    int x = 0;
    int &&r = x; // This is a compilation error

Using this, we can detect temporaries and r-values.
Lets write a function that takes a l-value as an argument: 

    void function(int &v) {
        cout << "int &" << endl;
    }
    
We'll write another function that takes a `const` l-value reference

    void function(const int &v) {
        cout << "const int &" << endl;
    }

Now,

    int main(void) {
        int x = 10;
        function(x);
        function(50);
    }

will print:

    int&
    const int&
    
If we write another function that takes a r-value reference:

    void function(int&& v) {
        cout << "int &&" << endl;
    }

will print:
    
    int&
    int&&

Because, temporaries _always_ bind to r-value references, however, in absence of r-value referecnes, they will bind to constant references -- as seen earlier above.

This is the fundamental concept of move semantics.

***
### Program Output:

    48.8083
    Calling -- function(pressure) -- with l-value
    (function) double& -- bound to l-value reference
    Calling -- function(10.10) -- with temporary which is a r-value
    (function) const double& -- bound to constant l-value reference
    Calling -- test(10.10) -- with temporary which is a r-value
    (test) double&& -- bound to r-value reference



