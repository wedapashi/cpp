The Facade Design Pattern is a structural design pattern that provides a simple unified interface to a complex subsystem, instead of exposing many complicated classes directly to the client, a facade wraps them behind one easier interface.

## Core idea

Without Facade:
```
Client
  |
  +--> Class A
  +--> Class B
  +--> Class C
  +--> Class D
```
The client must:
- understand subsystem details
- call modules in correct order
- handle interactions manually

With Facade:
```
Client
   |
   v
Facade
   |
   +--> Class A
   +--> Class B
   +--> Class C
   +--> Class D
```
Client only talks to the facade. And the facade handles:
- coordination
- sequencing
- simplification
- delegation

## Typical Components

| Component              | Purpose                                       | Embedded Example                     |
| ---------------------- | --------------------------------------------- | ------------------------------------ |
| Facade                 | Provides simplified high-level interface      | `FirmwareFacade`                     |
| Subsystem Classes      | Actual functional modules                     | ADC, PWM, Sensors                    |
| Client                 | Uses the facade instead of subsystem directly | Main application                     |
| Coordination Logic     | Workflow/orchestration inside facade          | Sensor read → decision → PWM control |
| Initialization Manager | Handles startup order                         | ADC before sensor usage              |
| Error Handling Layer   | Centralized fault handling                    | Battery low detection                |
| Logging/Diagnostics    | Unified monitoring                            | DataLogger                           |
| Resource Manager       | Manages shared HW resources                   | Shared ADC                           |
| State Controller       | Controls firmware states                      | INIT/RUN/FAULT                       |

## Architecture:

```mermaid
classDiagram

class FirmwareFacade {
    -ADC adc
    -PWM pwm
    -TemperatureSensor tempSensor
    -PressureSensor pressureSensor
    -BatteryMonitor batteryMonitor
    -DataLogger logger

    +initialize()
    +executeCycle()
    +shutdown()
}

class ADC {
    +initialize()
    +readChannel(channel : int) int
}

class PWM {
    +initialize()
    +setDutyCycle(duty : int)
    +stop()
}

class TemperatureSensor {
    -ADC& adc

    +TemperatureSensor(adc : ADC&)
    +readTemperature() float
}

class PressureSensor {
    -ADC& adc

    +PressureSensor(adc : ADC&)
    +readPressure() float
}

class BatteryMonitor {
    -ADC& adc

    +BatteryMonitor(adc : ADC&)
    +getBatteryVoltage() float
    +isBatteryLow() bool
}

class DataLogger {
    +log(message : string)
}

FirmwareFacade *-- ADC
FirmwareFacade *-- PWM
FirmwareFacade *-- TemperatureSensor
FirmwareFacade *-- PressureSensor
FirmwareFacade *-- BatteryMonitor
FirmwareFacade *-- DataLogger

TemperatureSensor --> ADC : uses
PressureSensor --> ADC : uses
BatteryMonitor --> ADC : uses
```
