#include <iostream>
#include <memory>
#include <vector>
#include <string>

//
// Interface Definitions
//

class ISensor {
public:
    virtual ~ISensor() = default;
    virtual void initialize() = 0;
    virtual void read() = 0;
};

class IPeripheral {
public:
    virtual ~IPeripheral() = default;
    virtual void initialize() = 0;
    virtual void act() = 0;
};

//
// Concrete Modules
//

class TemperatureSensor : public ISensor {
public:
    void initialize() override {
        std::cout << "[TemperatureSensor] Initialized" << std::endl;
    }

    void read() override {
        std::cout << "[TemperatureSensor] Reading temperature" << std::endl;
    }
};

class PressureSensor : public ISensor {
public:
    void initialize() override {
        std::cout << "[PressureSensor] Initialized" << std::endl;
    }

    void read() override {
        std::cout << "[PressureSensor] Reading pressure" << std::endl;
    }
};

class PWMModule : public IPeripheral {
public:
    int dutyCycle { 80 };
    void initialize() override {
        std::cout << "[PWM] Initialized" << std::endl;
    }
    void act () override {
        drive();
    }
    void drive() {
        std::cout << "[PWM] Duty Cycle = " << dutyCycle << std::endl;
    }
};

class ADCModule : public IPeripheral {
public:
    void initialize() override {
        std::cout << "[ADC] Initialized" << std::endl;
    }

    void act() override {
        // May be --
        // sample();
        std::cout << "[ADC] Sample the data" << std::endl;
    }
};

class BatteryMonitor : public IPeripheral {
public:
    void initialize() override {
        std::cout << "[BatteryMonitor] Initialized" << std::endl;
    }
    void act () override { 
        checkBattery();
    }

    void checkBattery() {
        std::cout << "[BatteryMonitor] Battery OK" << std::endl;
    }
};

class DataLogger : public IPeripheral {
public:
    void initialize() override {
        std::cout << "[DataLogger] Initialized" << std::endl;
    }

    void act () override { 
        log("Whetever");
    }

    void log(const std::string& msg) {
        std::cout << "[LOG] " << msg << "" << std::endl;
    }
};

//
// Firmware System
//

class FirmwareSystem {
private:
    std::vector<std::shared_ptr<ISensor>> sensors_;
    std::vector<std::shared_ptr<IPeripheral>> peripherals_;

public:
    void addSensor(std::shared_ptr<ISensor> sensor) {
        sensors_.push_back(sensor);
    }

    void addPeripheral(std::shared_ptr<IPeripheral> peripheral) {
        peripherals_.push_back(peripheral);
    }

    void initialize() {
        std::cout << std::endl << "=== Firmware Initialization ===" << std::endl;

        for (auto& peripheral : peripherals_) {
            peripheral->initialize();
        }

        for (auto& peripheral : peripherals_) {
            peripheral->initialize();
        }
    }

    void run() {
        std::cout << std::endl << "=== Firmware Running ===" << std::endl;

        // This is where the state-machine is!

        for (auto& sensor : sensors_) {
            sensor->read();
        }

        for (auto& peripheral : peripherals_) {
            peripheral->act();
        }
    }
};

//
// Builder Interface
//

class IFirmwareBuilder {
public:
    virtual ~IFirmwareBuilder() = default;

    virtual IFirmwareBuilder& addTemperatureSensor() = 0;
    virtual IFirmwareBuilder& addPressureSensor() = 0;
    virtual IFirmwareBuilder& addPWM() = 0;
    virtual IFirmwareBuilder& addADC() = 0;
    virtual IFirmwareBuilder& addBatteryMonitor() = 0;
    virtual IFirmwareBuilder& addDataLogger() = 0;

    virtual std::unique_ptr<FirmwareSystem> build() = 0;
};

//
// Concrete Builder
//

class FirmwareBuilder : public IFirmwareBuilder {
private:
    std::unique_ptr<FirmwareSystem> firmware_;

public:
    FirmwareBuilder()
        : firmware_(std::make_unique<FirmwareSystem>()) {
    }

    IFirmwareBuilder& addTemperatureSensor() override {
        firmware_->addSensor(
            std::make_shared<TemperatureSensor>());
        return *this;
    }

    IFirmwareBuilder& addPressureSensor() override {
        firmware_->addSensor(
            std::make_shared<PressureSensor>());
        return *this;
    }

    IFirmwareBuilder& addPWM() override {
        firmware_->addPeripheral(
            std::make_shared<PWMModule>());
        return *this;
    }

    IFirmwareBuilder& addADC() override {
        firmware_->addPeripheral(
            std::make_shared<ADCModule>());
        return *this;
    }

    IFirmwareBuilder& addBatteryMonitor() override {
        firmware_->addPeripheral(
            std::make_shared<BatteryMonitor>());
        return *this;
    }

    IFirmwareBuilder& addDataLogger() override {
        firmware_->addPeripheral(
            std::make_shared<DataLogger>());
        return *this;
    }

    std::unique_ptr<FirmwareSystem> build() override {
        return std::move(firmware_);
    }
};

//
// Director
//

class ProductionFirmwareDirector {
public:
    static std::unique_ptr<FirmwareSystem>
        createFullSystem(IFirmwareBuilder& builder) {

            return builder
                .addTemperatureSensor()
                .addPressureSensor()
                .addADC()
                .addPWM()
                .addBatteryMonitor()
                .addDataLogger()
                .build();
        }

    static std::unique_ptr<FirmwareSystem>
        createLowPowerSystem(IFirmwareBuilder& builder) {

            return builder
                .addTemperatureSensor()
                .addADC()
                .addBatteryMonitor()
                .build();
        }
};

//
// Main
//

int main() {
    FirmwareBuilder builder;
    auto firmware { ProductionFirmwareDirector::createFullSystem(builder) };
    firmware->initialize();
    firmware->run();

    return 0;
}