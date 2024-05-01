# Make functions

As the name suggests, these functions are used to make a pointer unique or shared.
However, making a pointer unique is naturally a two step process that we have seen. First allocate some memory and have a `unique_ptr` initialized with it. 
The thumb rules of cleaner memory management recommends that we should avoid making calls to `new` and `delete` functions. The `delete` operation is taken care by smart pointer, agreed. But what about the allocation we have been doing using `new` call?
This can be wrapped using the make function call.

Lets use a different version of the `sensor` class from what we have seen in `unique_ptr` sample code. 

Instead of allocating it `new` as below:

    std::unique_ptr<sensor> sensPtr(new sensor);

we'll use a make function as below:

    auto sensPtr = std::make_unique<Sensor>();

This should work! The way it works is, it invokes a suitable constructor of the Sensor class. If we have a paramaterized constructor (which we do, in the sample code) that can be used as well, in the following manner:

    auto sensPtr = std::make_unique<Sensor>(1.021, 0.2107);

**Note:** The only case where you can not use these make functions is when you want to specify a custom `deleter` function.

***
### Program output:

    Sensor(double, double)
    64.1763
    ~Sensor()

