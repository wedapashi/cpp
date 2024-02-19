# Copy Elision

Copy elision is an optimization implemented by most compilers to prevent extra (potentially expensive) copies in certain situations. It makes returning by value or pass-by-value feasible in practice.

It's the only form of optimization that elides the as-if rule - copy elision can be applied even if copying/moving the object has side-effects.
Depending upon whether the expressions requires copy or move, the compiler may either use copy elision or move elision.

The Copy Elision is mostly ON by default in most IDEs as most modern compilers use Copy Elision and/or Move Elision. However, if you are using a GCC compiler, there is a flag which allows us to turn off the Copy Elision feature off.

`-fno-elide-constructors`

