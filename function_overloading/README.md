# Function overloading
Before diving deep in technical jargon, lets think of something simple.
Imagine having to use different verbs which indicate the same action in essense, but different actual verb changes with different object. Such as -- _raise_right_ for raising right hand, and _raise_left_ for raising left hand. Strange and unattractive? 
Try and correlated that with programming now, for example C -- `uart_write()`, `spi_write()`, `i2c_write()`, etc. Works, but ineffective?
C++ lets you deal with it in a different way, if you want to -- otherwise it is easy to syntactically write C++ programs in a procedural way like C, ain't fun!

So, Function overloading is a feature where two or more functions can have the same name but different parameters. Meaning, C++ allows you to have two functions with the same name, of course with a constraint that the arguments should be different. 
The key to function overloading is a function’s argument list, also called the function signature. If two functions use the same number and types of arguments in the same order, they have the same signature; the variable names don’t matter.

Stephen Prata quotes:
> The word _polymorphism_ means having many forms, so function polymorphism lets a function have many forms. Similarly, the expression function overloading means you can
attach more than one function to the same name, thus overloading the name.

Note: It is important to note that functions can not be overloaded if they differ only in the return type. Also, Member function declarations with the same name and the name parameter-type-list cannot be overloaded if any of them is a static member function declaration.

How does this works anyways?
Quoting Stephen Prata:
> How does C++ keep track of which overloaded function is which? It assigns a secret identity
to each of these functions. When you use the editor of your C++ development tool to write
and compile programs, your C++ compiler performs a bit of magic on your behalf—known as
name decoration or name mangling—through which each function name is encrypted, based
on the formal parameter types specified in the function’s prototype.
