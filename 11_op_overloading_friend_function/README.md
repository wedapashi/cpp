# Operator overloading

Imagine, you are a mountaineer and at the same time frantic about statastics.
You are Everesting -- meaning you are climbing a small hill nearby for multiple times until your total height gained is equal to 8848 m, which in fact is the height of Mt. Everest. The key is, you want to get to that goal in fixed time, so every minute counts!

Your nephew is writing a code to add your lap-times. You specify the lap times in HH:MM format. Now, how incovenient it would be for him to add hours and minutes seperately. He would have to add hours first, then add minutes and process all chunks of 60 minutes into hours. But, he pulls off something like `T = T1+T2` where T1 and T2 contains two separate values -- hours and minutes, and still the addition goes through! 

Here’s an example where the concept of addition makes sense, but the units that you are adding (a mixture of hours and minutes) don’t match a built-in type.

Operator overloading extends the overloading concept to operators, letting you assign multiple meanings to C++ operators. In a pedantic sense, many operators in C and C++ are already overloaded, for example `*` -- It serves as a
dereferencing operator as well as multiplication operator. 

C++ lets you extend operator overloading to user-defeined types, allowing you, say to use `+` symbol to add two objects.
Does C allow you to add two structs of the same data type? No, it doesn't. Can operator overloading allow implementation
to add objects of the same class such that all data members of the one object are added with corresponding data member
of the other object? Yes!

The simple addition notation conceals the mechanics and emphasizes what is essential, and that is another goal of OOP.

*Operator overloading* is an example of C++ Polymorphism.


***
### Program output:

    Calling overloaded friend function..
    Time: 5:40


