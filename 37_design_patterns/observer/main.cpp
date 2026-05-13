#include <iostream>
#include <vector>
#include <string>
#include <memory>
#include <algorithm>

///////////////////////////////////////////////////////////
// EVENT TYPES
///////////////////////////////////////////////////////////

enum class EventType {
    TemperatureChanged,
    PressureChanged,
    BatteryLow
};

///////////////////////////////////////////////////////////
// EVENT DATA
///////////////////////////////////////////////////////////

struct Event {
    EventType type;
    float value;
};

///////////////////////////////////////////////////////////
// OBSERVER INTERFACE
///////////////////////////////////////////////////////////

class IObserver {
public:
    virtual ~IObserver() = default;
    virtual void onNotify(const Event& event) = 0;
};

///////////////////////////////////////////////////////////
// SUBJECT INTERFACE
///////////////////////////////////////////////////////////

class ISubject {
public:
    virtual ~ISubject() = default;

    virtual void attach(IObserver* observer) = 0;
    virtual void detach(IObserver* observer) = 0;
    virtual void notify(const Event& event) = 0;
};

///////////////////////////////////////////////////////////
// BASE SUBJECT IMPLEMENTATION
///////////////////////////////////////////////////////////

class Subject : public ISubject {
private:
    std::vector<IObserver*> observers_;

public:
    void attach(IObserver* observer) override {
        observers_.push_back(observer);
    }

    void detach(IObserver* observer) override {
        observers_.erase(
            std::remove(observers_.begin(),
                        observers_.end(),
                        observer),
            observers_.end());
    }

    void notify(const Event& event) override {
        for (auto* observer : observers_) {
            observer->onNotify(event);
        }
    }
};

///////////////////////////////////////////////////////////
// TEMPERATURE SENSOR
///////////////////////////////////////////////////////////

class TemperatureSensor : public Subject {
private:
    float temperature_ = 0.0f;

public:
    void readTemperature(float value) {
        temperature_ = value;

        std::cout << "[TemperatureSensor] New Temperature: "
                  << temperature_ << " C" << std::endl;

        Event event {
            EventType::TemperatureChanged,
            temperature_
        };

        notify(event);
    }
};

///////////////////////////////////////////////////////////
// PRESSURE SENSOR
///////////////////////////////////////////////////////////

class PressureSensor : public Subject {
private:
    float pressure_ = 0.0f;

public:
    void readPressure(float value) {
        pressure_ = value;

        std::cout << "[PressureSensor] New Pressure: "
                  << pressure_ << " PSI" << std::endl;

        Event event {
            EventType::PressureChanged,
            pressure_
        };

        notify(event);
    }
};

///////////////////////////////////////////////////////////
// BATTERY MONITOR
///////////////////////////////////////////////////////////

class BatteryMonitor : public Subject {
private:
    float batteryLevel_ = 100.0f;

public:
    void updateBattery(float value) {
        batteryLevel_ = value;

        std::cout << "[BatteryMonitor] Battery Level: "
                  << batteryLevel_ << "%" << std::endl;

        if (batteryLevel_ < 20.0f) {
            Event event {
                EventType::BatteryLow,
                batteryLevel_
            };

            notify(event);
        }
    }
};

///////////////////////////////////////////////////////////
// PWM CONTROLLER OBSERVER
///////////////////////////////////////////////////////////

class PWMController : public IObserver {
public:
    void onNotify(const Event& event) override {
        if (event.type == EventType::TemperatureChanged) {
            std::cout
                << "[PWMController] Adjusting fan speed for temperature: "
                << event.value
                << " C" << std::endl;
        }
    }
};

///////////////////////////////////////////////////////////
// ADC MODULE OBSERVER
///////////////////////////////////////////////////////////

class ADCModule : public IObserver {
public:
    void onNotify(const Event& event) override {
        if (event.type == EventType::PressureChanged) {
            std::cout
                << "[ADCModule] Processing pressure ADC value: "
                << event.value
                << "" << std::endl;
        }
    }
};

///////////////////////////////////////////////////////////
// DATA LOGGER OBSERVER
///////////////////////////////////////////////////////////

class DataLogger : public IObserver {
public:
    void onNotify(const Event& event) override {

        switch (event.type) {

            case EventType::TemperatureChanged:
                std::cout
                    << "[DataLogger] Logged Temperature: "
                    << event.value
                    << " C" << std::endl;
                break;

            case EventType::PressureChanged:
                std::cout
                    << "[DataLogger] Logged Pressure: "
                    << event.value
                    << " PSI" << std::endl;
                break;

            case EventType::BatteryLow:
                std::cout
                    << "[DataLogger] WARNING: Battery Low: "
                    << event.value
                    << "%" << std::endl;
                break;
        }
    }
};

///////////////////////////////////////////////////////////
// MAIN
///////////////////////////////////////////////////////////

int main() {

    TemperatureSensor temperatureSensor;
    PressureSensor pressureSensor;
    BatteryMonitor batteryMonitor;

    PWMController pwmController;
    ADCModule adcModule;
    DataLogger dataLogger;

    ///////////////////////////////////////////////////////
    // REGISTER OBSERVERS
    ///////////////////////////////////////////////////////

    temperatureSensor.attach(&pwmController);
    temperatureSensor.attach(&dataLogger);

    pressureSensor.attach(&adcModule);
    pressureSensor.attach(&dataLogger);

    batteryMonitor.attach(&dataLogger);

    ///////////////////////////////////////////////////////
    // SIMULATION
    ///////////////////////////////////////////////////////

    temperatureSensor.readTemperature(42.5f);

    std::cout << std::endl;

    pressureSensor.readPressure(88.2f);

    std::cout << std::endl;

    batteryMonitor.updateBattery(15.0f);

    return 0;
}