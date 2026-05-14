# Water Level Sensor — Arduino Connections

## Components
- Arduino Uno
- Water Level Sensor (analog)
- Yellow LED (Low)
- Green LED (Average)
- Red LED (High)
- 3x 220Ω Resistors

## Wiring Diagram

```mermaid
graph TD
    ARDUINO[Arduino Uno]

    subgraph Water Level Sensor
        WLS_VCC[VCC]
        WLS_GND[GND]
        WLS_SIG[Signal - Analog Out]
    end

    subgraph LEDs
        LED_Y[Yellow LED + 220Ω]
        LED_G[Green LED + 220Ω]
        LED_R[Red LED + 220Ω]
        LED_GND[GND Cathodes]
    end

    ARDUINO -- 5V --> WLS_VCC
    ARDUINO -- GND --> WLS_GND
    WLS_SIG -- A0 --> ARDUINO

    ARDUINO -- Pin 9 --> LED_Y
    ARDUINO -- Pin 10 --> LED_G
    ARDUINO -- Pin 11 --> LED_R
    LED_Y -- GND --> LED_GND
    LED_G -- GND --> LED_GND
    LED_R -- GND --> LED_GND
    LED_GND --> ARDUINO
```

## Pin Reference Table

| Component | Component Pin | Arduino Pin |
|-----------|--------------|-------------|
| Water Level Sensor | VCC | 5V |
| Water Level Sensor | GND | GND |
| Water Level Sensor | Signal | A0 |
| Yellow LED (Low) | Anode via 220Ω | Pin 9 |
| Green LED (Average) | Anode via 220Ω | Pin 10 |
| Red LED (High) | Anode via 220Ω | Pin 11 |
| All LEDs | Cathode | GND |
