#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <stdexcept>

// ============================================================
// Base Interface
// ============================================================

class IFirmwareModule {
public:
    virtual ~IFirmwareModule() = default;

    virtual void init() = 0;
    virtual void execute() = 0;
    virtual std::string name() const = 0;
};

// ============================================================
// Temperature Sensor
// ============================================================

class TemperatureSensor : public IFirmwareModule {
public:

    void init() override {
        std::cout << "[TemperatureSensor] Initialized" << std::endl;
    }

    void execute() override {
        std::cout << "[TemperatureSensor] Reading temperature" << std::endl;
    }

    std::string name() const override {
        return "Temperature Sensor";
    }
};

// ============================================================
// Pressure Sensor
// ============================================================

class PressureSensor : public IFirmwareModule {
public:

    void init() override {
        std::cout << "[PressureSensor] Initialized" << std::endl;
    }

    void execute() override {
        std::cout << "[PressureSensor] Reading pressure" << std::endl;
    }

    std::string name() const override {
        return "Pressure Sensor";
    }
};

// ============================================================
// PWM Module
// ============================================================

class PWMModule : public IFirmwareModule {
public:

    void init() override {
        std::cout << "[PWMModule] PWM initialized" << std::endl;
    }

    void execute() override {
        std::cout << "[PWMModule] Generating PWM signal" << std::endl;
    }

    std::string name() const override {
        return "PWM Module";
    }
};

// ============================================================
// ADC Module
// ============================================================

class ADCModule : public IFirmwareModule {
public:

    void init() override {
        std::cout << "[ADCModule] ADC initialized" << std::endl;
    }

    void execute() override {
        std::cout << "[ADCModule] Sampling ADC channels" << std::endl;
    }

    std::string name() const override {
        return "ADC Module";
    }
};

// ============================================================
// Battery Monitor
// ============================================================

class BatteryMonitor : public IFirmwareModule {
public:

    void init() override {
        std::cout << "[BatteryMonitor] Initialized" << std::endl;
    }

    void execute() override {
        std::cout << "[BatteryMonitor] Checking battery voltage" << std::endl;
    }

    std::string name() const override {
        return "Battery Monitor";
    }
};

// ============================================================
// Data Logger
// ============================================================

class DataLogger : public IFirmwareModule {
public:

    void init() override {
        std::cout << "[DataLogger] Logger initialized" << std::endl;
    }

    void execute() override {
        std::cout << "[DataLogger] Logging sensor data" << std::endl;
    }

    std::string name() const override {
        return "Data Logger";
    }
};

// ============================================================
// Module Types
// ============================================================

enum class ModuleType
{
    Temperature,
    Pressure,
    PWM,
    ADC,
    Battery,
    Logger
};

// ============================================================
// Factory Class
// ============================================================

class ModuleFactory
{
public:

    static std::unique_ptr<IFirmwareModule>
    createModule(ModuleType type)
    {
        switch (type)
        {
            case ModuleType::Temperature:
                return std::make_unique<TemperatureSensor>();

            case ModuleType::Pressure:
                return std::make_unique<PressureSensor>();

            case ModuleType::PWM:
                return std::make_unique<PWMModule>();

            case ModuleType::ADC:
                return std::make_unique<ADCModule>();

            case ModuleType::Battery:
                return std::make_unique<BatteryMonitor>();

            case ModuleType::Logger:
                return std::make_unique<DataLogger>();

            default:
                throw std::runtime_error("Unknown module type");
        }
    }
};

// ============================================================
// Main Application
// ============================================================

int main()
{
    std::vector<std::unique_ptr<IFirmwareModule>> modules;

    modules.push_back(
        ModuleFactory::createModule(ModuleType::Temperature));

    modules.push_back(
        ModuleFactory::createModule(ModuleType::Pressure));

    modules.push_back(
        ModuleFactory::createModule(ModuleType::PWM));

    modules.push_back(
        ModuleFactory::createModule(ModuleType::ADC));

    modules.push_back(
        ModuleFactory::createModule(ModuleType::Battery));

    modules.push_back(
        ModuleFactory::createModule(ModuleType::Logger));

    std::cout << "=========== SYSTEM START ===========" << std::endl;

    for (auto& module : modules)     {
        std::cout << "-----------------------------------" << std::endl;
        std::cout << "Module : " << module->name() << std::endl;
        std::cout << "-----------------------------------" << std::endl;

        module->init();
        module->execute();
    }

    std::cout << "=========== SYSTEM END =============" << std::endl;

    return 0;
}