## Basic stuff to start with:

    int a; // Uninitialized
    int a2 = 0; // Copy initialized
    int a3(5); // Direct initialization
    char arr[8] = {'a','b','c','d'}; // Aggregate initalization

Whenever assignment operator is used for initialization, it is a copy initialization. In some cases, first a copy of value to be initialized with is created. 

Pardon the variable naming convention, but looking at the code does is look consistant? It doesn't!
Lets see if there is anything that can bring a uniformity in the initialization syntax.

    int a{}; // Value/Default initialization -- which is 0

This is value initialization, whichi is always `0`.
One might err to think the following would do the same:

    int a(); 
    
Though, it doesn't! Does this look like a function `a()` taking no arguments and returning an `int` ? There is a ambiguity with how a compiler sees it. This is also referred as most vexing parse. 

    int a{5}; 
    
This as we know, will initialize `a` with a value of `5`. 

From C++11, C++ extends the applicability of the brace-enclosed list (*list_initialization*) so that it can be used with all built-in types and with user-defined types (i.e. class objects too). The list can be used either with or without `=` sign.

    int x = {7};
    double y {21.11};
    short kms[5] {21, 13, 9, 10, 20};

Also, the list-initialization syntax can be used with `new` (meaning, dynamically allocated) expressions:

    int *ar = new int[4] {21,13,9,10,20}; // That's C++11

With class objects, a braced list can be used instead of a paranthesized list to invoke a constructor:

    class driver {
    private:
        uint16_t dataRate;
        uint8_t dmaChannel;
        // Other members will follow
    public:
        uint16_t getDatarate(void) { return dataRate; }
        uint8_t  getDMAChannel(void) { return dmaChannel; }
        driver(uint16_t dRate, uint8_t dmaChan) : dataRate(dRate), dmaChannel(dmaChan) {}
    };

And the code where it is instantiated..

    driver i2c2(9600, 3U); // This is old-style
    driver i2c1{4800, 3U}; // Supported in C++11
    driver i2cn = {2400, 3U}; // Supported in C++11

# Key notes:
- If a class has a constructor whose argument is a `std::initializer_list` template, then only that constructor can use the list-initialization form.
- [Before C+11] Scalar types can be initialized with `=` or `()`
- [Before C+11] Array types must be initialized with `{}`
