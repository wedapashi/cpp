#include <iostream>
#include <memory>

class sensor {
private:
    unsigned int rawValue;
public:
    unsigned int getRawValue() { return rawValue; }
    void print(void) { std::cout << this->getRawValue() << std::endl; }
    sensor(unsigned int value) : rawValue(value) { std::cout << "sensor()" << std::endl; }
    ~sensor() { std::cout << "~sensor()" << std::endl; }
};

class DeleterForSensor {
public:
    void operator()(sensor *p)  {
        free(p);
        std::cout << "Deleter upon class object is called!" << std::endl;
    }
};

void sensorDeleter(sensor *p)  {
    free(p);
    std::cout << "Deleter function is called!" << std::endl;
}

int main()
{
    //std::unique_ptr<sensor> sensPtr(new sensor(100));
    std::unique_ptr<sensor, DeleterForSensor> sensPtr(new sensor(100), DeleterForSensor{});
    std::unique_ptr<sensor, void (*)(sensor*)> sensPtr2(new sensor(200), sensorDeleter);

    std::shared_ptr<sensor> sensPtr3(new sensor(300), DeleterForSensor{});
    std::shared_ptr<sensor> sensPtr4(new sensor(400), sensorDeleter);

    sensPtr.get()->print();
    sensPtr2.get()->print();
    sensPtr3.get()->print();
    sensPtr4.get()->print();

    return EXIT_SUCCESS;
}
