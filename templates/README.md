# Templates
The essense of the whole object-oriented programming is to levarage/exploit reusability.
However, Inheritance and containment aren't always the solutions when reusability is desired.
Imagine scenarios with stacks. Typically, people demonstrate stack with plain numbers that are integers. So, we develop a container class for a stack of integers, fair enough.  
In such as case when you need a stack of floating point values, then you'd have to have a separate container class for a stack of floats, which is doable but defnitely not efficient. Imagine the code duplication for conceptually similar operations.

Rather than write new class declarations, it would be great if you could define a stack in a generic (that is, type-independent) fashion and then provide a specific type as a parameter to the class. Then, you could use the same generic code to produce stacks of different kinds of values.

C++’s class templates provide a better way to generate generic class declarations.

Templates provide parameterized types—that is, they are capable of passing a type name as an argument to a recipe for building a class or a function.  
By feeding the Class Templates type name int to a `Queue` template, for example, you can get the compiler to construct a `Queue` class for queuing `int`s.

The keyword `template` informs the compiler that you’re about to define a template.
The part in angle brackets is analogous to an argument list to a function. You can think of
the keyword `class` as serving as a type name for a variable that accepts a type as a value,
and of Type as representing a name for this variable.  
Using `class` here doesn’t mean that `Type` must be a class; it just means that `Type` serves as a generic type specifier for which a real type will be substituted when the template is used.

Template class usage:  

Merely including a template in a program doesn’t generate a template class. You have to ask for an instantiation.To do this, you declare an object of the template class type, replacing the generic type name with the particular type you want.

Generic type identifiers such as `Type` in the example are called type parameters, meaning that they act something like variables, but instead of assigning a numeric value to a type parameter, you assign a type to it. 
