#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <chrono>

// ======================================================
// Component Interface
// ======================================================

class IModule {
public:
    virtual ~IModule() = default;

    virtual void initialize() = 0;
    virtual void execute() = 0;
    virtual std::string getName() const = 0;
};

// ======================================================
// Concrete Components
// ======================================================

class TemperatureSensor : public IModule {
public:
    void initialize() override {
        std::cout << "[TemperatureSensor] Initialized" << std::endl;
    }

    void execute() override {
        std::cout << "[TemperatureSensor] Reading temperature: 36.5 C" << std::endl;
    }

    std::string getName() const override {
        return "TemperatureSensor";
    }
};

class PressureSensor : public IModule {
public:
    void initialize() override {
        std::cout << "[PressureSensor] Initialized" << std::endl;
    }

    void execute() override {
        std::cout << "[PressureSensor] Reading pressure: 1.02 bar" << std::endl;
    }

    std::string getName() const override {
        return "PressureSensor";
    }
};

class PWMController : public IModule {
public:
    void initialize() override {
        std::cout << "[PWMController] Initialized" << std::endl;
    }

    void execute() override {
        std::cout << "[PWMController] Setting PWM duty cycle to 60%" << std::endl;
    }

    std::string getName() const override {
        return "PWMController";
    }
};

class ADCModule : public IModule {
public:
    void initialize() override {
        std::cout << "[ADCModule] Initialized" << std::endl;
    }

    void execute() override {
        std::cout << "[ADCModule] ADC value = 2048" << std::endl;
    }

    std::string getName() const override {
        return "ADCModule";
    }
};

class BatteryMonitor : public IModule {
public:
    void initialize() override {
        std::cout << "[BatteryMonitor] Initialized" << std::endl;
    }

    void execute() override {
        std::cout << "[BatteryMonitor] Battery voltage = 12.1V" << std::endl;
    }

    std::string getName() const override {
        return "BatteryMonitor";
    }
};

// ======================================================
// Base Decorator
// ======================================================

class ModuleDecorator : public IModule {
protected:
    std::shared_ptr<IModule> module_;

public:
    explicit ModuleDecorator(std::shared_ptr<IModule> module)
        : module_(module) {}

    void initialize() override {
        module_->initialize();
    }

    void execute() override {
        module_->execute();
    }

    std::string getName() const override {
        return module_->getName();
    }
};

// ======================================================
// Concrete Decorators
// ======================================================

// ----------------------------------------------
// Logging Decorator
// ----------------------------------------------

class LoggingDecorator : public ModuleDecorator {
public:
    explicit LoggingDecorator(std::shared_ptr<IModule> module)
        : ModuleDecorator(module) {}

    void initialize() override {
        std::cout << "[LOG] Initializing " << getName() << "" << std::endl;
        module_->initialize();
    }

    void execute() override {
        std::cout << "[LOG] Executing " << getName() << "" << std::endl;
        module_->execute();
    }
};

// ----------------------------------------------
// Diagnostic Decorator
// ----------------------------------------------

class DiagnosticDecorator : public ModuleDecorator {
public:
    explicit DiagnosticDecorator(std::shared_ptr<IModule> module)
        : ModuleDecorator(module) {}

    void execute() override {
        auto start = std::chrono::high_resolution_clock::now();

        module_->execute();

        auto end = std::chrono::high_resolution_clock::now();

        auto duration =
            std::chrono::duration_cast<std::chrono::microseconds>(
                end - start);

        std::cout << "[DIAGNOSTIC] "
                  << getName()
                  << " execution time: "
                  << duration.count()
                  << " us" << std::endl;
    }
};

// ----------------------------------------------
// Filter Decorator
// ----------------------------------------------

class FilterDecorator : public ModuleDecorator {
public:
    explicit FilterDecorator(std::shared_ptr<IModule> module)
        : ModuleDecorator(module) {}

    void execute() override {
        std::cout << "[FILTER] Applying digital filter on "
                  << getName()
                  << "" << std::endl;

        module_->execute();
    }
};

// ======================================================
// Data Logger Module
// ======================================================

class DataLogger {
public:
    void logSystemEvent(const std::string& event) {
        std::cout << "[DataLogger] " << event << "" << std::endl;
    }
};

// ======================================================
// Main Firmware
// ======================================================

int main() {

    DataLogger logger;

    // ------------------------------------------
    // Temperature Sensor with Logging + Filter
    // ------------------------------------------

    std::shared_ptr<IModule> tempSensor =
        std::make_shared<TemperatureSensor>();

    tempSensor =
        std::make_shared<LoggingDecorator>(tempSensor);

    tempSensor =
        std::make_shared<FilterDecorator>(tempSensor);

    // ------------------------------------------
    // ADC with Diagnostics
    // ------------------------------------------

    std::shared_ptr<IModule> adc =
        std::make_shared<ADCModule>();

    adc =
        std::make_shared<DiagnosticDecorator>(adc);

    // ------------------------------------------
    // PWM with Logging
    // ------------------------------------------

    std::shared_ptr<IModule> pwm =
        std::make_shared<PWMController>();

    pwm =
        std::make_shared<LoggingDecorator>(pwm);

    // ------------------------------------------
    // Battery Monitor
    // ------------------------------------------

    std::shared_ptr<IModule> battery =
        std::make_shared<BatteryMonitor>();

    // ------------------------------------------
    // Firmware Startup
    // ------------------------------------------

    logger.logSystemEvent("Firmware Boot");

    tempSensor->initialize();
    adc->initialize();
    pwm->initialize();
    battery->initialize();

    std::cout << "=== Scheduler Loop ===" << std::endl << std::endl;

    tempSensor->execute();
    std::cout << std::endl;

    adc->execute();
    std::cout << std::endl;

    pwm->execute();
    std::cout << std::endl;

    battery->execute();

    return 0;
}