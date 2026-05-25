The Factory Pattern is a creational design pattern whose purpose is to create objects without exposing the exact creation logic to the irrelevant code.

Without the factory pattern the application becomes tightly coupled to every concrete implementation.

#### Fundamental of Factory Pattern:
Typical components:

| Component         | Responsibility         |
| ----------------- | ---------------------- |
| Product Interface | Common abstraction     |
| Concrete Products | Actual implementations |
| Factory           | Creates objects        |
| Client            | Uses objects           |

Core Idea of Factory pattern depends on the fact that, without Factory:

```
Application
   |
   +---- knows TemperatureSensor
   +---- knows PressureSensor
   +---- knows ADCModule
   +---- knows PWMModule
```
With Factory:
```
Application
    |
    +---- knows only IFirmwareModule
                    ^
                    |
              ModuleFactory
                    |
        --------------------------------
        |        |        |            |
      Temp     ADC      PWM       Pressure

```
The application only knows the interface and the factory. It does NOT know concrete implementations.

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

```
#### Class diagram:

```mermaid
classDiagram

    class IFirmwareModule {
        <<interface>>
        +init() void
        +execute() void
        +name() std::string
    }

    class TemperatureSensor {
        +init() void
        +execute() void
        +name() std::string
    }

    class PressureSensor {
        +init() void
        +execute() void
        +name() std::string
    }

    class PWMModule {
        +init() void
        +execute() void
        +name() std::string
    }

    class ADCModule {
        +init() void
        +execute() void
        +name() std::string
    }

    class BatteryMonitor {
        +init() void
        +execute() void
        +name() std::string
    }

    class DataLogger {
        +init() void
        +execute() void
        +name() std::string
    }

    class ModuleFactory {
        +createModule(type : ModuleType) IFirmwareModule*
    }

    class ModuleType {
        <<enumeration>>
        Temperature
        Pressure
        PWM
        ADC
        Battery
        Logger
    }

    IFirmwareModule <|-- TemperatureSensor
    IFirmwareModule <|-- PressureSensor
    IFirmwareModule <|-- PWMModule
    IFirmwareModule <|-- ADCModule
    IFirmwareModule <|-- BatteryMonitor
    IFirmwareModule <|-- DataLogger

    ModuleFactory --> IFirmwareModule : creates
    ModuleFactory --> ModuleType : uses
```

### Architecture:

Instead of the application directly doing:

```
TemperatureSensor sensor;
```
or
```
new TemperatureSensor();
```
the application asks a Factory to create the object:
```
ModuleFactory::createModule(ModuleType::Temperature);

---
### Design:

```mermaid
sequenceDiagram

    participant APP as Application
    participant FACTORY as ModuleFactory
    participant TEMP as TemperatureSensor
    participant PRESS as PressureSensor
    participant PWM as PWMModule
    participant ADC as ADCModule
    participant BATT as BatteryMonitor
    participant LOG as DataLogger

    APP->>FACTORY: createModule(Temperature)
    FACTORY-->>APP: TemperatureSensor

    APP->>FACTORY: createModule(Pressure)
    FACTORY-->>APP: PressureSensor

    APP->>FACTORY: createModule(PWM)
    FACTORY-->>APP: PWMModule

    APP->>FACTORY: createModule(ADC)
    FACTORY-->>APP: ADCModule

    APP->>FACTORY: createModule(Battery)
    FACTORY-->>APP: BatteryMonitor

    APP->>FACTORY: createModule(Logger)
    FACTORY-->>APP: DataLogger

    APP->>TEMP: init()
    TEMP-->>APP: initialized

    APP->>TEMP: execute()
    TEMP-->>APP: temperature value

    APP->>PRESS: init()
    PRESS-->>APP: initialized

    APP->>PRESS: execute()
    PRESS-->>APP: pressure value

    APP->>PWM: init()
    PWM-->>APP: initialized

    APP->>PWM: execute()
    PWM-->>APP: PWM generated

    APP->>ADC: init()
    ADC-->>APP: initialized

    APP->>ADC: execute()
    ADC-->>APP: ADC samples

    APP->>BATT: init()
    BATT-->>APP: initialized

    APP->>BATT: execute()
    BATT-->>APP: battery voltage

    APP->>LOG: init()
    LOG-->>APP: initialized

    APP->>LOG: execute()
    LOG-->>APP: data logged

```