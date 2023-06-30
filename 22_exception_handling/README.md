# Exception handling

Programs sometimes encounter runtime problems that prevent them from continuing normally.

What do we do for such cases in C? We either return with an `int` value, or set an error variable and just return with
nothing, and then implement the error handling in the glue logic.

However, for a code that is progressive in nature -- which is usually the case; the exception handling becomes painful
as we go. People often resort to setting flag variables and/or rely on a combination of such flag variables to indicate
where the code failed. As in -- the code peep into a global error code variable and a flag associated with the state
machine. That it is a terrible idea.

Thankfully, Usually, programmers try to anticipate such calamities. C++ exceptions provide a powerful and flexible tool for dealing with these situations.

## The Exception Mechanism
A C++ exception is a response to an exceptional circumstance that arises while a program is running. Exceptions provide
a way to transfer control from one part of a program to another, without having to write a lot of janitor code. 

Handling an exception has three components:
* Throwing an exception
* Catching an exception with a handler
* Using a `try` block

A program throws an exception when a problem shows up.
