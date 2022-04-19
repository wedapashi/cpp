C++ extends the applicability of the brace-enclosed list (*list_initialization*) so that it can be used with all built-in types and with user-defined types (i.e. class objects too). The list can be used either with or without `=` sign.

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
        // Other membsers will follow
    public:
        uint16_t getDatarate(void) { return dataRate; }
        uint8_t  getDMAChannel(void) { return dmaChannel; }
        driver(uint16_t dRate, uint8_t dmaChan) : dataRate(dRate), dmaChannel(dmaChan) {}
    };

And the code where it is instantiated..

    driver i2c2(9600, 3U); // This is old-style
    driver i2c1{4800, 3U}; // Supported in C++11
    driver i2cn = {2400, 3U}; // Supported in C++11

Nittie-gritties:

If a class has a constructor whose argument is a `std::initializer_list` template, then only that constructor can use
the list-initialization form.
