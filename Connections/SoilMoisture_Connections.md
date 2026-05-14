# Soil Moisture Sensor — Arduino Connections

## Components
- Arduino Uno
- Soil Moisture Sensor (analog)
- 16x2 LCD Display (I2C module, address 0x20 — MCP23008-based)

## Wiring Diagram

```mermaid
graph TD
    ARDUINO[Arduino Uno]

    subgraph Soil Moisture Sensor
        SMS_VCC[VCC]
        SMS_GND[GND]
        SMS_AO[AO - Analog Out]
    end

    subgraph LCD 16x2 I2C
        LCD_VCC[VCC]
        LCD_GND[GND]
        LCD_SDA[SDA]
        LCD_SCL[SCL]
    end

    ARDUINO -- 5V --> SMS_VCC
    ARDUINO -- GND --> SMS_GND
    SMS_AO -- A0 --> ARDUINO

    ARDUINO -- 5V --> LCD_VCC
    ARDUINO -- GND --> LCD_GND
    LCD_SDA -- A4/SDA --> ARDUINO
    LCD_SCL -- A5/SCL --> ARDUINO
```

## Pin Reference Table

| Component | Component Pin | Arduino Pin |
|-----------|--------------|-------------|
| Soil Moisture Sensor | VCC | 5V |
| Soil Moisture Sensor | GND | GND |
| Soil Moisture Sensor | AO | A0 |
| LCD I2C Module | VCC | 5V |
| LCD I2C Module | GND | GND |
| LCD I2C Module | SDA | A4 (SDA) |
| LCD I2C Module | SCL | A5 (SCL) |
