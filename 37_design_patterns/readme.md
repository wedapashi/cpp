# C++ Design Patterns — Quick Summary

## Builder

### Purpose:
Constructs complex objects step-by-step while separating construction logic from the final representation.

### When to Use:
- Object creation requires many steps
- Different configurations are possible
- Construction order matters
- Constructors would otherwise become huge

### Example:
Building a sensor packet:
- Add timestamp
- Add ADC readings
- Add checksum
- Add battery status

### Core idea:
Instead of:
```
Packet p(a, b, c, d, e, f, g);
```
Use:
```
PacketBuilder builder;
builder.addTimestamp();
builder.addADC();
builder.addChecksum();

Packet p = builder.build();

```

### Key Compoments
| Component           | Responsibility          |
| ------------------- | ----------------------- |
| Product             | Final complex object    |
| Builder             | Defines build steps     |
| Concrete Builder    | Implements build logic  |
| Director (optional) | Controls build sequence |

### Advantages
- Cleaner object construction
- Easier configuration handling
- Follows Single Responsibility Principle
- Reusable build steps

### Drawbacks
- More classes
- Overkill for simple objects

## Factory

### Purpose:
Creates objects without exposing exact creation logic to the client.

### When to Use:
- Multiple derived classes exist
- Runtime selection is needed
- You want loose coupling

### Example:
Creating different sensors:

- Temperature Sensor
- Pressure Sensor
- Battery Monitor

### Core idea:
Instead of:
```
TemperatureSensor sensor;
```
Use:
```
auto sensor = SensorFactory::create(SensorType::Temperature);

```

### Key Compoments
| Component         | Responsibility         |
| ----------------- | ---------------------- |
| Product Interface | Common API             |
| Concrete Products | Actual implementations |
| Factory           | Creates objects        |

### Advantages
- Loose coupling
- Easier extensibility
- Centralized object creation
- Supports Open/Closed Principle

### Drawbacks
- Additional abstraction layer
- More classes

## Observer

### Purpose:
Defines a one-to-many dependency where observers are automatically notified when a subject changes state.

### When to Use:
- Multiple modules depend on same data
- Event-driven architecture is needed
- Publish/subscribe behavior is useful

### Example:
Temperature sensor notifies:

- Logger
- Display
- PWM controller
- Alarm module

### Core idea:
Instead of:
```
if(temperatureSensor.someFlag) {
    // Do this
}
```
Use:
```
sensor.attach(logger);
sensor.attach(display);

sensor.notify();

```

### Key Compoments
| Component         | Responsibility        |
| ----------------- | --------------------- |
| Subject           | Generates events/data |
| Observer          | Receives updates      |
| Concrete Subject  | Real sensor/module    |
| Concrete Observer | Logger, display, etc. |

### Advantages
- Decouples modules
- Easy scalability
- Event-driven architecture
- Reusable observers

### Drawbacks
- Notification chains can become complex
- Potential performance overhead

## Adapter

### Purpose:
Allows incompatible interfaces to work together.

### When to Use:
- Integrating legacy code
- Wrapping third-party APIs
- Standardizing interfaces

### Example:
A legacy ADC driver implementation that exposes APIs binding to an HAL call.
```
readRawValue();
```
But new firmware expects:
```
readVoltage();
```
Adapter converts one interface into another.

### Core idea:

```
class ADCAdapter : public IVoltageReader {
    LegacyADC adc;
};

```

### Key Compoments
| Component        | Responsibility              |
| ---------------- | --------------------------- |
| Target Interface | Expected interface          |
| Adaptee          | Existing incompatible class |
| Adapter          | Converts interface          |

### Advantages
- Reuse legacy code
- Avoid rewriting old modules
- Improves interoperability

### Drawbacks
- Extra abstraction layer
- Can hide poor architecture

## Decorator

### Purpose:
Adds functionality dynamically without modifying original classes.

### When to Use:
- Features should be optional
- Runtime behavior extension is needed
- Inheritance would explode into many subclasses

### Example:
Sensor data processing:

- Base Sensor
- Add Logging
- Add Filtering
- Add Calibration

### Core idea:

```
auto sensor =
    std::make_shared<LoggingDecorator>(
        std::make_shared<FilteringDecorator>(
            std::make_shared<TemperatureSensor>()));

```

### Key Compoments
| Component           | Responsibility  |
| ------------------- | --------------- |
| Component Interface | Common API      |
| Concrete Component  | Base object     |
| Decorator           | Wraps component |
| Concrete Decorator  | Adds behavior   |

### Advantages
- Flexible runtime extension
- Avoids deep inheritance
- Composable features

### Drawbacks
- Many small wrapper classes
- Debugging chain may be harder

## Facade

### Purpose:

Provides a simplified high-level interface to a complex subsystem.

### When to Use:
- System has many interconnected modules
- Client code becomes too complicated
- You want a single entry point
- Simplifying initialization/shutdown sequences

### Example:

Firmware subsystem manager controlling:

- Temperature Sensor
- ADC
- PWM
- Battery Monitor
- Data Logger

Instead of client code manually calling all modules individually.

### Core idea:

Instead of:

```
adc.init();
pwm.init();
temperatureSensor.start();
batteryMonitor.enable();
logger.open();

```
Use:
```
FirmwareFacade firmware;

firmware.initializeSystem();
firmware.runCycle();

```
### Key Components:
| Component         | Responsibility                    |
| ----------------- | --------------------------------- |
| Facade            | Simplified high-level interface   |
| Subsystem Classes | Real underlying modules/services  |
| Client            | Uses facade instead of subsystems |

### Advantages:
- Simplifies complex systems
- Reduces coupling
- Easier API usage
- Centralized workflow handling

### Drawbacks:
- Facade can become too large
- May hide subsystem flexibility

## State

### Purpose:
Allows an object to change behavior dynamically based on its internal state.

### When to Use:
- System behavior changes with modes/states
- Large conditional logic exists
- State transitions are well-defined
- Embedded device modes are important

### Example:
Device operating modes:
- Boot State
- Idle State
- Active Monitoring State
- Low Battery State
- Fault State

Each state changes firmware behavior differently.

### Core idea:
Instead of:

```
if(state == BOOT) {
    ...
}
else if(state == IDLE) {
    ...
}
else if(state == LOW_BATTERY) {
    ...
}
```
Use:
```
device.setState(std::make_unique<ActiveState>());
device.handle();
```
### Key Components:
| Component       | Responsibility                  |
| --------------- | ------------------------------- |
| Context         | Maintains current state         |
| State Interface | Common behavior API             |
| Concrete State  | Implements state-specific logic |

### Advantages:
- Cleaner state handling
- Removes huge conditional blocks
- Easier state extension
- Better maintainability

### Drawbacks:
- More classes
- State transition debugging can be harder

# How they all compare?

| Pattern   | Main Goal                    | Typical Embedded Usage           |
| --------- | ---------------------------- | -------------------------------- |
| Builder   | Step-by-step object creation | Packet/message construction      |
| Factory   | Flexible object creation     | Sensor/module instantiation      |
| Observer  | Event notification           | Sensor update propagation        |
| Adapter   | Interface conversion         | Legacy driver integration        |
| Decorator | Dynamic feature extension    | Logging/filtering/calibration    |
| Facade    | Simplified subsystem access  | Firmware subsystem orchestration |
| State     | Behavior based on state      | Device mode management           |


# Can they co-exist?
Hell, yeah!

These patterns are often used together in embedded firmware:

- **Factory** creates sensors
- **Builder** constructs packets/messages
- **Observer** distributes events
- **Adapter** integrates legacy drivers
- **Decorator** adds runtime features like logging/filtering
- **Facade** provides a clean API over complex firmware subsystems
- **State** manages device operating modes and transitions
