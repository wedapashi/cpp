The State Design Pattern allows an object to change its behavior dynamically when its internal state changes.
Instead of using large switch-case or if-else blocks, each operational mode is represented as a separate state class.

In embedded firmware, this is especially useful for managing modes such as Startup, Normal Operation, Low Power, Fault, or Shutdown.

## Core Idea

The core idea of the State Pattern is:

> An object changes its behavior when its internal state changes.

Instead of writing one huge object containing many:

```
if (state == STARTUP) {
    ...
}
else if (state == IDLE) {
    ...
}
else if (state == FAULT) {
    ...
}
```
the behavior is split into separate state classes.

Each state becomes its own object responsible for:

- what actions are allowed
- how the system behaves
- when transitions occur

## Typical Components

| Component                  | Responsibility                                     |
| -------------------------- | -------------------------------------------------- |
| **Context**                | Main object whose behavior changes based on state  |
| **State Interface**        | Common interface for all concrete states           |
| **Concrete States**        | Individual operational modes implementing behavior |
| **State Transition Logic** | Determines when to switch states                   |
| **Client**                 | Uses the context object                            |


## Architecture

| Component              | Responsibility              | Example Here                                                 |
| ---------------------- | --------------------------- | ------------------------------------------------------------ |
| Context                | Maintains current state     | `FirmwareController`                                         |
| State Interface        | Common behavior interface   | `SystemState`                                                |
| Concrete States        | Specific behavior per state | `StartupState`, `NormalState`, `LowPowerState`, `FaultState` |
| State Transition Logic | Switches states dynamically | `changeState()`                                              |
| Client                 | Uses context                | `main()`                                                     |


```mermaid
classDiagram

class FirmwareController {
    - IFirmwareState* currentState
    - TemperatureSensor tempSensor
    - PressureSensor pressureSensor
    - PWMInterface pwm
    - ADCModule adc
    - BatteryMonitor battery
    - DataLogger logger
    + setState(IFirmwareState*)
    + request()
}

class IFirmwareState {
    <<interface>>
    + handle(FirmwareController&)
}

class StartupState {
    + handle(FirmwareController&)
}

class NormalState {
    + handle(FirmwareController&)
}

class LowPowerState {
    + handle(FirmwareController&)
}

class FaultState {
    + handle(FirmwareController&)
}

class TemperatureSensor {
    + readTemperature()
}

class PressureSensor {
    + readPressure()
}

class PWMInterface {
    + setDutyCycle()
    + stop()
}

class ADCModule {
    + initialize()
    + sample()
}

class BatteryMonitor {
    + getLevel()
}

class DataLogger {
    + log()
}

FirmwareController --> IFirmwareState
IFirmwareState <|.. StartupState
IFirmwareState <|.. NormalState
IFirmwareState <|.. LowPowerState
IFirmwareState <|.. FaultState

FirmwareController --> TemperatureSensor
FirmwareController --> PressureSensor
FirmwareController --> PWMInterface
FirmwareController --> ADCModule
FirmwareController --> BatteryMonitor
FirmwareController --> DataLogger
```