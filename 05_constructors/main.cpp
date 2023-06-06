    #include <iostream>
    using namespace std;

    class foo
    {
    private:
        uint32_t bar;
    public:
        // Parameterized constructor, can't return anything! This also acts as default argument constructor
        // If default arguments are provided, the deault constructor is no longer required.
        foo(uint32_t a=1)
        {
            cout<<"foo: In parameterized constructor"<<endl;
            bar = a;
        }
        // Copy constructor
        foo(foo &f)
        {
            cout<<"foo: In copy constructor"<<endl;
            bar = f.bar;
        }
        uint32_t getBar(void) { return bar; }
    };

    void print(foo fTemp) {
        std::cout << fTemp.getBar() << std::endl;
    }

    int main(void)
    {
        foo f1(10); // Invokes paramterized constructor
        foo f2(f2); // Invokes copy constructor
        foo f3 = 144U; 
        // The following results in a compilation error as a compatible parameterized constructor is not found.
        //foo f4 = "stupid";
        print(f3);   // invokes copy constructor
        print(250U); // invokes parameterized constructor
        return 0;
    }
