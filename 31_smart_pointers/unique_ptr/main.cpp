#include <iostream>
#include <memory>
using namespace std;

class sensor {
private:
    unsigned int rawValue;
    bool bReady;
public:
    unsigned int getRawValue() { return rawValue; }
    bool isReady() { return bReady; }
    void startMeasurement(unsigned int offset) { 
        // some code
        bReady = false;
        rawValue += offset;
    }
    sensor() { std::cout << "default constructor of sensor class" << std::endl; }
    ~sensor() { std::cout << "default destructor of sensor class" << std::endl; }
};

class sensorHandlePtr {
    sensor *m_ptr; // Pointer to sensor class
public:
    // Constructor delegation
    sensorHandlePtr(sensor *p = nullptr):m_ptr(p) { }
    // Destructor
    ~sensorHandlePtr() { 
        cout << "Returning the memory borrowed.." << endl;
        delete m_ptr; 
    }
    // Overloading the dereferencing operator
    sensor& operator *() {
        return *m_ptr;
    }
    // Overloading the arrow operator
    sensor* operator ->() {
        return m_ptr;
    }
};

void transfer(std::unique_ptr<sensor> ptr)
{
    // some code
    std::cout << ptr->getRawValue() << std::endl;
}

void createSensorHandle()
{
    std::unique_ptr<sensor> sensPtr(new sensor);
    (*sensPtr).startMeasurement(50);
    // The line below causes a compilation error -- as it tries to create a copy of a unique pointer
    //auto tempPtr(sensPtr);
    std::cout << sensPtr->getRawValue() << std::endl;
    // The line below causes a compilation error -- as it tries to create a copy of a unique pointer
    //transfer(sensPtr);
    transfer(std::move(sensPtr));
}

int main()
{
    createSensorHandle();
    return EXIT_SUCCESS;
}
