# Lambda Expressions

`C++11` supports a feature called _Lambda Expressions_. This feature allows you to declare and call unnamed functions
from a function body itself.
There are certain syntactical gimmicks that allow you to capture the return value, pass arguments, use a variable as a
reference to a function and modify the local variables of the calling function from within the unnamed function. Lets
see them one by one --

Typical nature of syntax is:

    [capture_list](args){ //body };

And a functional call would be:

    [capture_list](args){ //body }();

Usage:

    int main(void) {
        []() { std::cout << "Capture list empty, args list empty, no return value, done!" << endl; }();
        return EXIT_SUCCESS;
    }

Can we set a reference (usage: somewhat like a function pointer) to this? Yes we can:

    int main(void) {
        auto funRef = []() { std::cout << "Capture list empty, args list empty, no return value, done!" << endl; }; //
        Notice the missing (); in the back!
        funRef(); // Its here!
        return EXIT_SUCCESS;
    }

Passing arguments and fetching the return value:

    int main(void) {
        uint32_t ret = [](uint32_t foo, uint32_t bar) { foo + bar; }(10U, 20U);
        //                                                           ^    ^
        return EXIT_SUCCESS;
    }

Passing local variables as an argument to unname function:

    int main(void) {
        uint32_t foo = 10;
        double pi = 3.14;
        double ret = [foo, pi](){ return pi*foo; }();
        //            ^    ^
    }

Modifying the local values from the unname function:

    int main(void) {
        uint32_t foo = 10;
        uint32_t bar = 20;
        [&foo, &bar]() { ++foo; ++bar; }();
//       ^     ^   
        // Here -- foo and bar will have incremented value.
    }

Ahh, capturing all local variables such that those are modifiable in unname function:

    int main(void) {
        [&]() { // All local vars are modifiable here }();
    }

***
### Program output:

    foo = 10, bar = 20
    foo = 20, bar = 10


