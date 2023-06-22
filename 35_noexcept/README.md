# noexcept 

The noexcept keyword is used to indicate that a function doesn’t throw an exception. It also can be used as an operator that determines whether its operand (an expression) potentially could throw an exception. It returns false if the operand could throw an exception and true otherwise. 

For example, consider the following declarations:

    int foo(void);

It can't be predicted if the function `foo()` throws an exception or not. However,

    int bar(void) noexcept;

indicates that it is ensured that a user code in the function `bar()` does not throw an exception that needs to be handled by the user code.
However, if an exception is thrown from a piece of code such as a library function for example, then the execution lands
at `std::terminate()`.


***

### Example usage

Refer the example code. It has a class `CalibCoeff`. There is a constructor which initializes the values of the data members `m_gain` and `m_offset`.
Contexually, it is a class that has calibration coefficients for a linear senso. The linear sensor follows a stright line equation, *y = mx + c* where *m* is gain and *c* is offset. An ideal system should have unity gain (gain = 1) and zero offset. 

    CalibCoeff(double vGain, double vOffset) : m_gain(vGain), m_offset(vOffset) {
        if(vGain <= 0.5) {
            throw std::logic_error("Gain too low to be correct");
        }
    }

The gain practically the gain can't be negative, zero or lower than half. So, we will throw a `std::invalid_arguments` exception if such a case. 

Lets say, there is a upper-level class `class Sensor` which has an obejct of `class CalibCoeff`. For the sake of
simplicity, lets not crowd the class with other members, just assume that they are there!

    class Sensor {
        public:
            CalibCoeff m_coefficients;
            Sensor(bool state, unsigned int value, CalibCoeff ccValue) : 
                bEnable(state), 
                m_value(value), 
                m_coefficients(ccValue.getGain(), ccValue.getOffset()) { }
    };

And, its used in the following way -

    int main(void)
    {
        try {
            CalibCoeff coefficients(-1.000789, -0.002386);
            Sensor Probe(true, 25, coefficients);
            Probe.printMe();
        }
        catch(std::logic_error& e) {
            std::cout << e.what() << std::endl;
        }
    }

If you notice, the value -1.000789 should cause an exception. And you'd see:

    Gain too low to be correct

If the constructor is marked as `noexcept` then, when the exception is thrown - the execution lands in `std::terminate`.

    terminate called after throwing an instance of 'std::logic_error'
     what():  Gain too low to be correct
    Aborted (core dumped)



