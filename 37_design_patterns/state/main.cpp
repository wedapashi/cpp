#include <iostream>
#include <memory>
#include <string>
#include <thread>
#include <chrono>

using namespace std::chrono_literals;

/* ============================================================
   Hardware Modules
   ============================================================ */

class TemperatureSensor {
public:
    float readTemperature() {
        return 36.5f;
    }
};

class PressureSensor {
public:
    float readPressure() {
        return 1.01f;
    }
};

class ADCModule {
public:
    int readADC() {
        return 512;
    }
};

class PWMInterface {
public:
    void enable() {
        std::cout << "[PWM] Enabled\n";
    }

    void disable() {
        std::cout << "[PWM] Disabled\n";
    }
};

class BatteryMonitor {
private:
    int batteryLevel {100};

public:
    int getBatteryLevel() {
        batteryLevel -= 15;
        return batteryLevel;
    }
};

class DataLogger {
public:
    void log(const std::string& message) {
        std::cout << "[LOGGER] " << message << "\n";
    }
};

/* ============================================================
   Forward Declaration
   ============================================================ */

class FirmwareController;

/* ============================================================
   State Interface
   ============================================================ */

class SystemState {
public:
    virtual ~SystemState() = default;

    virtual void handle(FirmwareController& controller) = 0;
    virtual const char* name() const = 0;
};

/* ============================================================
   Firmware Controller (Context)
   ============================================================ */

class FirmwareController {
private:
    std::unique_ptr<SystemState> currentState;

public:
    TemperatureSensor temperatureSensor;
    PressureSensor pressureSensor;
    ADCModule adcModule;
    PWMInterface pwm;
    BatteryMonitor batteryMonitor;
    DataLogger logger;

    void changeState(std::unique_ptr<SystemState> newState) {
        std::cout << "\n=== STATE CHANGE: "
                  << (currentState ? currentState->name() : "NONE")
                  << " -> "
                  << newState->name()
                  << " ===\n\n";

        currentState = std::move(newState);
    }

    void run() {
        if (currentState) {
            currentState->handle(*this);
        }
    }

    const char* getCurrentStateName() const {
        return currentState ? currentState->name() : "NONE";
    }
};

/* ============================================================
   Concrete States
   ============================================================ */

class StartupState : public SystemState {
public:
    void handle(FirmwareController& controller) override;

    const char* name() const override {
        return "StartupState";
    }
};

class NormalOperationState : public SystemState {
public:
    void handle(FirmwareController& controller) override;

    const char* name() const override {
        return "NormalOperationState";
    }
};

class LowPowerState : public SystemState {
public:
    void handle(FirmwareController& controller) override;

    const char* name() const override {
        return "LowPowerState";
    }
};

class FaultState : public SystemState {
public:
    void handle(FirmwareController& controller) override;

    const char* name() const override {
        return "FaultState";
    }
};

/* ============================================================
   State Implementations
   ============================================================ */

void StartupState::handle(FirmwareController& controller) {
    controller.logger.log("Initializing hardware modules...");

    controller.pwm.enable();

    std::this_thread::sleep_for(1s);

    controller.logger.log("System startup completed");

    controller.changeState(
        std::make_unique<NormalOperationState>()
    );
}

void NormalOperationState::handle(FirmwareController& controller) {

    float temperature =
        controller.temperatureSensor.readTemperature();

    float pressure =
        controller.pressureSensor.readPressure();

    int adc =
        controller.adcModule.readADC();

    int battery =
        controller.batteryMonitor.getBatteryLevel();

    controller.logger.log(
        "Temperature: " + std::to_string(temperature)
    );

    controller.logger.log(
        "Pressure: " + std::to_string(pressure)
    );

    controller.logger.log(
        "ADC: " + std::to_string(adc)
    );

    controller.logger.log(
        "Battery: " + std::to_string(battery) + "%"
    );

    if (battery < 30) {
        controller.changeState(
            std::make_unique<LowPowerState>()
        );
        return;
    }

    if (temperature > 80.0f) {
        controller.changeState(
            std::make_unique<FaultState>()
        );
        return;
    }

    std::this_thread::sleep_for(1s);
}

void LowPowerState::handle(FirmwareController& controller) {

    controller.logger.log(
        "Entering LOW POWER mode"
    );

    controller.pwm.disable();

    int battery =
        controller.batteryMonitor.getBatteryLevel();

    controller.logger.log(
        "Battery now at: " +
        std::to_string(battery) + "%"
    );

    if (battery <= 0) {
        controller.changeState(
            std::make_unique<FaultState>()
        );
        return;
    }

    std::this_thread::sleep_for(1s);
}

void FaultState::handle(FirmwareController& controller) {

    controller.logger.log(
        "FAULT detected!"
    );

    controller.pwm.disable();

    controller.logger.log(
        "System halted for protection"
    );
}

/* ============================================================
   Main
   ============================================================ */

int main() {

    FirmwareController firmware;

    firmware.changeState(
        std::make_unique<StartupState>()
    );

    for (int i = 0; i < 10; ++i) {

        std::cout << "\nRunning State: "
                  << firmware.getCurrentStateName()
                  << "\n";

        firmware.run();

        if (std::string(firmware.getCurrentStateName())
            == "FaultState") {

            firmware.run();
            break;
        }
    }

    return 0;
}