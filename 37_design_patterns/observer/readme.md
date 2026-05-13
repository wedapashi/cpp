The Observer Pattern is a behavioral design pattern that establishes a one-to-many relationship between objects. A Subject maintains a list of Observers and notifies them automatically whenever its state changes.

#### Fundamental of Factory Pattern:
Typical components:

| Role              | Responsibility                       |
| ----------------- | ------------------------------------ |
| Subject           | Generates events/data                |
| Observer          | Interested in updates                |
| Concrete Subject  | Actual sensor/module                 |
| Concrete Observer | Logger, monitor, PWM controller, etc |

### Embedded Scenario

Suppose we are building a classic firmware that may have the following functionality:
- Temperature Sensor
- Pressure Sensor
- A PWM interface
- An ADC module
- battery Monitor
- Data logging module

---
This example demonstrates:
- How to implement the builder pattern
- How to follow SOLID principles while at it
- No dynamic polymorphism abuse
- Easy to extend

### Architecture:

#### Subjects:
- Temperature Sensor
- Pressure Sensor
- Battery Monitor

#### Observers:
- PWM Controller
- Data Logger
- ADC Monitor

---
### Design:

```mermaid
sequenceDiagram

    participant Main
    participant TemperatureSensor
    participant PressureSensor
    participant BatteryMonitor
    participant PWMController
    participant ADCModule
    participant DataLogger

    %% Observer Registration

    Main->>TemperatureSensor: attach(PWMController)
    Main->>TemperatureSensor: attach(DataLogger)

    Main->>PressureSensor: attach(ADCModule)
    Main->>PressureSensor: attach(DataLogger)

    Main->>BatteryMonitor: attach(DataLogger)

    %% Temperature Event

    Main->>TemperatureSensor: readTemperature(42.5)

    TemperatureSensor->>PWMController: onNotify(TemperatureChanged)
    PWMController-->>TemperatureSensor: Fan PWM adjusted

    TemperatureSensor->>DataLogger: onNotify(TemperatureChanged)
    DataLogger-->>TemperatureSensor: Temperature logged

    %% Pressure Event

    Main->>PressureSensor: readPressure(88.2)

    PressureSensor->>ADCModule: onNotify(PressureChanged)
    ADCModule-->>PressureSensor: ADC processed

    PressureSensor->>DataLogger: onNotify(PressureChanged)
    DataLogger-->>PressureSensor: Pressure logged

    %% Battery Event

    Main->>BatteryMonitor: updateBattery(15)

    BatteryMonitor->>DataLogger: onNotify(BatteryLow)
    DataLogger-->>BatteryMonitor: Warning logged

```