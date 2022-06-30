# Modern casting types

Theoratically, converting an expression of a given type into another type is known as type-casting. We have already seen some ways to type cast:

#### Implicit conversion

Implicit conversions do not require any operator. They are automatically performed when a value is copied to a compatible type. 
For example:

    uint16_t a = 2000;
    uint32_t b = 0;
    b = a;
    
Here, the value of `a` has been promoted from `uint16_t` to `uint32_t` and we have not had to specify any type-casting operator. This is known as a standard conversion. Standard conversions affect fundamental data types, and allow conversions such as the conversions between numerical types (short to int, int to float, double to int...), to or from bool, and some pointer conversions. 
Some of these conversions may imply a loss of precision, which the compiler can signal with a warning. This warning can be avoided with an explicit conversion.
Implicit conversions also include constructor or operator conversions, which affect classes that include specific constructors or operator functions to perform conversions. For example:

    class A {
        private:
            uint32_t a;
        public:
            A():A(0) {
            }
            A(uint32_t value) { 
                a = value; 
            }
    };
    class B { 
        public: 
            B(A a) {
            } 
    };

    int main(void) {
        A a;
        B b = a;  // This is implicit cast
    }

Here, an implicit conversion happened between objects of class `A` and class `B` at:

    B b = a; 

because `B` has a constructor that takes an object of class `A` as parameter. Therefore implicit conversions from `A` to `B` are allowed.    

#### Explicit conversion

C++ is a strong-typed language. Many conversions, specially those that imply a different interpretation of the value, require an explicit conversion. We have already seen two notations for explicit type conversion: functional and c-like casting:

    uint16_t a = 2000;
    uint32_t b;
    b = (uint32_t) a;    // c-like cast notation
    b = uint32_t (a);    // functional notation

The functionality of these explicit conversion operators is enough for most needs with fundamental data types. However, these operators can be applied indiscriminately on classes and pointers to classes, which can lead to code that while being syntactically correct can cause runtime errors. 
For example, the following code is syntactically correct:    

    #include <iostream>
    #include <cstdint>
    using namespace std;

    class calibration {
        private:
            float m, c;
        public:
            calibration():calibration(1.0f, 1.0f) {
                
            }
            calibration(float a, float b) {
                m = a;
                c = b;
            }
            void setm(float v) { m = v; }
            void setc(float v) { c = v; }
            float getm(void) { return m; }
            float setm(void) { return c; }             
    };

    class coordinates {
        private:
            int32_t x, y;
        public:
        coordinates():coordinates(0, 0) {
        }
        coordinates (int a, int b) { 
            x = a; 
            y = b;
        }
        void setx(int32_t v) { x = v; }
        void sety(int32_t v) { y = v; }
        int32_t getx(void) { return x; }
        int32_t sety(void) { return y; } 
        int64_t result(void) { 
            return (x<<32 | y);
        }
    };

    int main (void) {
        calibration cal;
        coordinates *pCoord;
        pCoord = (calibration*) &cal;
        cout << pCoord->result();
        return EXIT_SUCCESS;
    }

The program declares a pointer to `coordinates`, but then it assigns to it a reference to an object of another incompatible type using explicit type-casting:

    pCoord = (calibration*) &cal;
    
Traditional explicit type-casting allows to convert any pointer into any other pointer type, independently of the types they point to. The subsequent call to member result will produce either a run-time error or a unexpected result.

In order to control these types of conversions between classes, we have four specific casting operators: dynamic_cast, reinterpret_cast, static_cast and const_cast. Their format is to follow the new type enclosed between angle-brackets (<>) and immediately after, the expression to be converted between parentheses.    
