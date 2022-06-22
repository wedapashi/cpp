# Default functions

We have seen that if no constructor is specified, then the compiler sysnthesizes a default constructor. However, if
default initiazation is used with data members during the declaration itself, the compiler does not synthesize a
default constructor.

Look at the code:

    class foo {
    private:
        uint32_t bar {0};
        uint32_t baz {0};
    public:
        foo(uint32_t Bar, uint32_t Baz){
            bar = Bar;
            baz = Baz;
        }
    }

    int main(void)
    {
        foo f;
    }

Will not compile:

    main.cpp:24:9: error: no matching function for call to ‘foo::foo()’
       24 |     foo f1;
          |         ^~

We didn't write a default constructor as it won't be doing anything significant apart from initialization of data
members, which we think we have dealt with in the variable declaration itself. 

To work with this, `C++11` provides a feature of requesting compiler to generate `default` functions for such
requirements.

    foo() = default;

does the trick. This instructs compiler to generate a default constructor to allow variable initialization without
having to write a code for it.

***

### Program output:

    bar = 0, baz = 0
    bar = 10, baz = 5
    bar = 10, baz = 5
