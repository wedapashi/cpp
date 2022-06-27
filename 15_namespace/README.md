# Namespaces

C++ now adds the ability to create named namespaces by defining a new kind of declarative region, one whose main purpose is to provide an area in which to declare names. The names in one namespace don’t conflict with the same names declared in other namespaces, and there are mechanisms for letting other parts of a program use items declared in a namespace.

A *declarative region* is a region in which declarations can be made. For example, you can declare a global variable outside any function.The declarative region for that variable is the file in which it is declared. If you declare a variable inside a function, its declarative region is the innermost block in which it is declared.

The *potential scope* for a variable begins at its point of declaration and extends to the end of its declarative region. So the potential scope is more limited than the declarative region because you can’t use a variable above the point where it is first defined.
However, a variable might not be visible everywhere in its potential scope. For instance, it might be hidden by another variable of the same name declared in a nested declarative region. For example, a local variable declared in a function (for this variable, the declarative region is the function) hides a global variable declared in the same file (for this variable, the declarative region is the file).The portion of the program that can actually see the variable is termed the scope, which is the way we’ve been using the term all along!

In a nutshell, C++’s rules about global and local variables define a kind of namespace hierarchy. Each declarative region can declare names that are independent of names declared in other declarative regions.A local variable declared in one function doesn’t conflict with a local variable declared in a second function.
Namespaces can be located at the global level or inside other namespaces, but they cannot be placed in a block.Thus, a name declared in a namespace has external linkage by default (unless it refers to a constant). The names in any one namespace don’t conflict with names in another namespace.
Having to qualify names every time they are used is not always an appealing prospect, so C++ provides two mechanisms—the using declaration and the `using` directive—to simplify using namespace names. The `using` declaration lets you make particular identifiers available, and the using directive makes the entire namespace accessible.

Look at the code: We have two namespaces `Dev1` and `Dev2`. Each of them have a method `printVersion()`, which prints a message containing a unique string -- version for example.

    namespace Dev1 {
        void printVersion(void) {
            cout << msg(V1.00) << endl;
        }
    };

And, 

    namespace Dev2 {
        void printVersion(void) {
            cout << msg(V2.00) << endl;
        }
    };

We can use either of the two namespaces using the `using` keyword. However, with a large code-base, `using` namespace
can be a little tricky. So restricting the usage of `using` in global scope is a safer practice. Scope resolution
operator `::` is a recommended way. Look at the code below --

    int main(void) {
        using namespace Dev1;
        printVersion();
        Dev1::printVersion();
        Dev2::printVersion();
        return EXIT_SUCCESS;
    }

***
### Program output:
    V1.00
    V1.00
    V2.00
