# Scope resolution operator

Ever come across a situation when there are 2 'John Doe' around? You need something which can take care of addressing the correct 'John Doe' here.
The same can happen in case of variables. Look at the code below --

    uint32_t u32Count = 10;
    int main(void) {
        uint32_t u32Count = 5;
        function(u32Count);
    }

Our programming wisdom tells us that `function()` would be called with local `u32Count` as argument, because of the block scope rules. However, how do we make sure the glocal variable `u32Count` is used? That's where, scope resolution operator come in play. Using scope resolution operator `::` we can access a global variable. 


    uint32_t u32Count = 10;
    int main(void) {
        uint32_t u32Count = 5;
        function(::u32Count);
    }

Such variable naming convetion (shadowing of variables) in programming is anyway discouraged. 
There is another and probably more applicable use-case for scope resolution operator, when these are used with _classes_.

A typical syntax to indicate John Doe of Texas would be:

    Texas::John_Doe
    
So,

    uint32_t foo::write(void) {
        // Some code
    }

would indicate that the following `write()` method is of `Class foo`.

Scope resolution operator does come handy when accessing the static data members of the class. The syntax remains the same.

***

### Program output:

    u32Count (local) = 10
    u32Count (global) = 100
    u32Count (alloc) = 50
    In read..
    In write..


