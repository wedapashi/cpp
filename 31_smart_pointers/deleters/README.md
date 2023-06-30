# Deleters for smart pointers

We have seen how smart pointers work in general. It is usually suggested to use `unique_ptr` whenever you are unsure of what type of smart pointer to use.
The Smart pointers uses the deleter functions to free the acquired memory. So, ideally it can be interpreted that when the object is deleted, the destructor called and the that piece of code does the janitor work of calling `free()` upon the pointer. Correct!

However, there can be a possibility to implemented your own deleter for smart pointers. I haven't stretched my brain-cells to think of a fitting use case, but this can be done and we'll see how!
You can have a class, a function object or a struct as a deleter implementation. See usage below.

Using the class or struct (change accordingly, of course):

    class Sensor { 
        // Some code here
    }; 

    class Deleter {
    public:
        void operator()(Sensor *p) {
            // Some user code
            // Finally, free it
            free(p);
        }
    }
	
And we can create a `unique_ptr` in the following manner -- see additional parameters there!
	
    std::unique_ptr<Sensor, Deleter> p(new Sensor(), Deleter{});
    
This invokes the overloaded function operator as a user-defined deleter for the `unique_ptr` instance that we created.

Using the function:

    class Sensor { 
    
    }; 

    void Deleter(Sensor *p) {
        // Some user code
        // Finally, free it
        free(p);
    }
    
And we can create a `unique_ptr` in the following manner -- see additional parameters there!
	
    std::unique_ptr<Sensor, void(*)(Sensor*)> p(new Sensor(), Deleter);
    
This uses a function pointer as an argument and a compatible user-defined deleter function, in our case `Deleter()` function.

In general, using class is better in terms of resources, as the function pointer mechanism somehow requires more memory. I didn't look for why that happens, because lets agree to call spade, a spade.

The only difference for this between a `unique_ptr` and a `shared_ptr` is, that for `shared_ptr` you don't have to specify the type (in triangular braces) as an additional argument.

***

### Program output:

    sensor()
    sensor()
    sensor()
    sensor()
    100
    200
    300
    400
    Deleter function is called!
    Deleter upon class object is called!
    Deleter function is called!
    Deleter upon class object is called!

