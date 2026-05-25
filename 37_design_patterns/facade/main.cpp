#include <iostream>
#include <string>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

class ADC {
public:
    void initialize() {
        std::cout << "[ADC] Initialized\n";
    }

    int readChannel(int channel) {
        return 1000 + (channel * 100);
    }
};

class PWM {
public:
    void initialize() {
        std::cout << "[PWM] Initialized\n";
    }

    void setDutyCycle(int dutyCycle) {
        std::cout << "[PWM] Duty Cycle set to "
                  << dutyCycle
                  << "%\n";
    }

    void stop() {
        std::cout << "[PWM] Stopped\n";
    }
};

class TemperatureSensor {
public:
    explicit TemperatureSensor(ADC& adcRef)
        : adc(adcRef) {
    }

    float readTemperature() {
        int raw = adc.readChannel(0);

        return raw * 0.01f;
    }

private:
    ADC& adc;
};

class PressureSensor {
public:
    explicit PressureSensor(ADC& adcRef)
        : adc(adcRef) {
    }

    float readPressure() {
        int raw = adc.readChannel(1);

        return raw * 0.02f;
    }

private:
    ADC& adc;
};

class BatteryMonitor {
public:
    explicit BatteryMonitor(ADC& adcRef)
        : adc(adcRef) {
    }

    float getBatteryVoltage() {
        int raw = adc.readChannel(2);

        return raw * 0.001f;
    }

    bool isBatteryLow() {
        return getBatteryVoltage() < 3.3f;
    }

private:
    ADC& adc;
};

class DataLogger {
public:
    void log(const std::string& message) {
        std::cout << "[LOGGER] "
                  << message
                  << '\n';
    }
};

class FirmwareFacade {
public:
    FirmwareFacade()
        : tempSensor(adc),
          pressureSensor(adc),
          batteryMonitor(adc) {
    }

    void initialize() {
        logger.log("Firmware initialization started");

        adc.initialize();
        pwm.initialize();

        logger.log("Firmware initialization complete");
    }

    void executeCycle() {
        float temperature = tempSensor.readTemperature();
        float pressure = pressureSensor.readPressure();
        float battery = batteryMonitor.getBatteryVoltage();

        logger.log("Temperature = "
                   + std::to_string(temperature));

        logger.log("Pressure = "
                   + std::to_string(pressure));

        logger.log("Battery Voltage = "
                   + std::to_string(battery));

        if (batteryMonitor.isBatteryLow()) {
            logger.log("WARNING: Battery Low");
        }

        if (temperature > 12.0f) {
            pwm.setDutyCycle(75);
        } else {
            pwm.setDutyCycle(40);
        }
    }

    void shutdown() {
        pwm.stop();

        logger.log("Firmware shutdown complete");
    }

private:
    ADC adc;
    PWM pwm;

    TemperatureSensor tempSensor;
    PressureSensor pressureSensor;
    BatteryMonitor batteryMonitor;

    DataLogger logger;
};

int main() {

    FirmwareFacade firmware;

    firmware.initialize();

    for (int i = 0; i < 5; ++i) {

        firmware.executeCycle();

        std::this_thread::sleep_for(1s);
    }

    firmware.shutdown();

    return 0;
}