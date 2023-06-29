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
    sensor() { std::cout << "sensor()" << std::endl; }
    ~sensor() { std::cout << "~sensor()" << std::endl; }
};

void display(sensor* ptr)
{
    // some code
    std::cout << ptr->getRawValue() << std::endl;
}

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
    display(sensPtr.get());
    // The line below causes a compilation error -- as it tries to create a copy of a unique pointer
    //transfer(sensPtr);
    transfer(std::move(sensPtr));
}

int main()
{
    createSensorHandle();
    return EXIT_SUCCESS;
}
