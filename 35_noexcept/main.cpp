#include <iostream>
#include <math.h>

class CalibCoeff {
    private:
        double m_gain;
        double m_offset;
    public:
        CalibCoeff(double vGain, double vOffset) noexcept : m_gain(vGain), m_offset(vOffset) { 
        //CalibCoeff(double vGain, double vOffset) : m_gain(vGain), m_offset(vOffset) { 
            if(vGain <= 0.5) {
                throw std::logic_error("Gain too low to be correct");
            }
        }
        double getGain(void) { return m_gain; }
        double getOffset(void) { return m_offset; }
        void setGain(double value) { m_gain = value; }
        void setOffset(double value) { m_offset = value; }
        void printMe(void) {
            std::cout << "Gain: " << m_gain << ", offset = " << m_offset << std::endl;
        }
};

class Sensor {
    public:
        CalibCoeff m_coefficients;
        bool bEnable;
        unsigned int m_value;
        Sensor(bool state, unsigned int value, CalibCoeff ccValue) : 
            bEnable(state), 
            m_value(value), 
            m_coefficients(ccValue.getGain(), ccValue.getOffset()) { }
        void printMe(void) {
            std::cout << "bEnable: " << (bEnable ? "True" : "False") << ", m_value = " << m_value << std::endl;
            m_coefficients.printMe();
        }
};

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
    std::cout << "Exit" << std::endl;
}
