#include <iostream>
#include <vector>
#include <memory>
#include <string>

//////////////////////////////////////////////////////////////
// Target Interface (Expected by Firmware)
//////////////////////////////////////////////////////////////

class IModule {
public:
    virtual ~IModule() = default;

    virtual void init() = 0;
    virtual float read() = 0;
    virtual std::string name() const = 0;
};

//////////////////////////////////////////////////////////////
// Existing / Legacy Vendor Drivers (Incompatible APIs)
//////////////////////////////////////////////////////////////

// Vendor Temperature Sensor
class VendorTemperatureSensor {
public:
    void configure() {
        std::cout << "[VendorTemp] Configured" << std::endl;
    }

    float fetchTemperature() {
        return 36.5f;
    }
};

// Vendor Pressure Sensor
class VendorPressureSensor {
public:
    void startup() {
        std::cout << "[VendorPressure] Started" << std::endl;
    }

    float getPressureValue() {
        return 101.3f;
    }
};

// Legacy ADC Module
class LegacyADC {
public:
    void adcInit() {
        std::cout << "[LegacyADC] Initialized" << std::endl;
    }

    int sampleADC() {
        return 2048;
    }
};

// PWM Driver
class PWMDriver {
public:
    void beginPWM() {
        std::cout << "[PWM] Ready" << std::endl;
    }

    float getDutyCycle() {
        return 75.0f;
    }
};

// Battery Monitor
class BatteryHardware {
public:
    void powerInit() {
        std::cout << "[Battery] Monitoring Started" << std::endl;
    }

    int readBatteryMillivolts() {
        return 3720;
    }
};

// Data Logger
class SDCardLogger {
public:
    void mountCard() {
        std::cout << "[Logger] SD Card Mounted" << std::endl;
    }

    int logCount() {
        return 150;
    }
};

//////////////////////////////////////////////////////////////
// Adapter Classes
//////////////////////////////////////////////////////////////

class TemperatureAdapter : public IModule {
private:
    VendorTemperatureSensor sensor_;

public:
    void init() override {
        sensor_.configure();
    }

    float read() override {
        return sensor_.fetchTemperature();
    }

    std::string name() const override {
        return "Temperature Sensor";
    }
};

class PressureAdapter : public IModule {
private:
    VendorPressureSensor sensor_;

public:
    void init() override {
        sensor_.startup();
    }

    float read() override {
        return sensor_.getPressureValue();
    }

    std::string name() const override {
        return "Pressure Sensor";
    }
};

class ADCAdapter : public IModule {
private:
    LegacyADC adc_;

public:
    void init() override {
        adc_.adcInit();
    }

    float read() override {
        return static_cast<float>(adc_.sampleADC());
    }

    std::string name() const override {
        return "ADC Module";
    }
};

class PWMAdapter : public IModule {
private:
    PWMDriver pwm_;

public:
    void init() override {
        pwm_.beginPWM();
    }

    float read() override {
        return pwm_.getDutyCycle();
    }

    std::string name() const override {
        return "PWM Interface";
    }
};

class BatteryAdapter : public IModule {
private:
    BatteryHardware battery_;

public:
    void init() override {
        battery_.powerInit();
    }

    float read() override {
        return static_cast<float>(battery_.readBatteryMillivolts());
    }

    std::string name() const override {
        return "Battery Monitor";
    }
};

class LoggerAdapter : public IModule {
private:
    SDCardLogger logger_;

public:
    void init() override {
        logger_.mountCard();
    }

    float read() override {
        return static_cast<float>(logger_.logCount());
    }

    std::string name() const override {
        return "Data Logger";
    }
};

//////////////////////////////////////////////////////////////
// Firmware Manager
//////////////////////////////////////////////////////////////

class FirmwareSystem {
private:
    std::vector<std::unique_ptr<IModule>> modules_;

public:
    void addModule(std::unique_ptr<IModule> module) {
        modules_.push_back(std::move(module));
    }

    void initializeAll() {
        std::cout << "=== Initializing Modules ===" << std::endl;

        for (auto& module : modules_) {
            std::cout << "Init: " << module->name() << "" << std::endl;
            module->init();
        }
    }

    void pollAll() {
        std::cout << "=== Polling Modules ===" << std::endl;

        for (auto& module : modules_) {
            std::cout
                << module->name()
                << " Reading = "
                << module->read()
                << "" << std::endl;
        }
    }
};

//////////////////////////////////////////////////////////////
// Main
//////////////////////////////////////////////////////////////

int main() {

    FirmwareSystem firmware;

    firmware.addModule(std::make_unique<TemperatureAdapter>());
    firmware.addModule(std::make_unique<PressureAdapter>());
    firmware.addModule(std::make_unique<ADCAdapter>());
    firmware.addModule(std::make_unique<PWMAdapter>());
    firmware.addModule(std::make_unique<BatteryAdapter>());
    firmware.addModule(std::make_unique<LoggerAdapter>());

    firmware.initializeAll();

    firmware.pollAll();

    return 0;
}