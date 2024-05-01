#include <memory>
#include <iostream>
#include <iomanip>
#include <random>
#include <cstdlib>

class Sensor {
private:
    double gain;
    double offset;
public:
    Sensor() { std::cout << "Sensor()" << std::endl; }
    Sensor(double m, double c) { 
        std::cout << "Sensor(double, double)" << std::endl; 
        gain = m;
        offset = c;
    }
    double getRandomDouble(double min, double max, int precision) {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_real_distribution<double> dis(min, max);
        double randomValue = dis(gen);
        // Round to the specified precision
        randomValue = std::round(randomValue * std::pow(10, precision)) / std::pow(10, precision);
        return randomValue;
    }
    double getRawValue() { 
        return getRandomDouble(0.1, 64.0, 2);
    }
    double getMeasurement() { 
        return getRawValue() * gain + offset; 
    }
    void display(void) {
        std::cout << getMeasurement() << std::endl;
    }   
    ~Sensor() { std::cout << "~Sensor()" << std::endl; }
};

int main(void) {
    // std::unique_ptr<Sensor> sensPtr { new Sensor {1.021, 0.217} }; // << This is bad practise
    auto sensPtr = std::make_unique<Sensor>(1.021, 0.217); // << This is recommended way to allocate for smart pointers
    sensPtr->display();

    return EXIT_SUCCESS;
}
