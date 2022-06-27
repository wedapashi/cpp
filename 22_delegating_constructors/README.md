# Delegated constructors

We are aware that there are types of constructors: Default, Parameterized and Copy.

From `C++11` onwards, an additional type is provided called Delegating constructor. This feature allows a constructor to invoke another constructor for the same class. This can be used to reduce code duplication.

It is a valid use-case to have some of the data members initialized to a specific value. In such a case, with conventional way, we
would be setting only those data members with a certain desired non-default value during the initialization, while the
other data members are initialized with default values. However, with mulitple constructors, there would a code
duplication to set all other values to default initialization, which can be improved with delegating constructors.

For example, we need an object of class `foo` with `bar` set to 10, we aren't really concerned about `baz` at the
initialization phase, and it is okay to have it initialized to its default value `0`. So, we will need to invoke a
parameterized constructor for this, right! There can be multiple definitions of parameterized constructors such as:

    foo(uint32_t Bar)
    {
        bar = Bar;
    }
    foo(uint32_t Bar, uint32_t Baz)
    {
        bar = Bar;
        baz = Baz;
    }

So, there is code duplication in constructor: `bar = Baz`
Using delegating constructors, this can be avoided by calling the first constructor from the second constructor.

***

### Program outout:

    In foo: In parameterized constructor
    In foo: In parameterized constructor
    bar = 20, baz = 0
    bar = 10, baz = 5
    foo: In destructor
    foo: In destructor

