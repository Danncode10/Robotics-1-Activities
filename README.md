# Robotics 1 — May 14 Activities

Arduino prototyping activities for Robotics 1, covering sensor integration and output display.

---

## Folder Structure

```
May14/
├── Activity/       # Task descriptions for each activity
├── Connections/    # Mermaid diagrams visualizing Arduino wiring/connections
└── Sketches/       # Arduino C++ sketch files (.ino)
```

### Activity/

Contains the task briefs for each activity.

| File | Description |
|------|-------------|
| [Activity Soil Moisture.md](Activity/Activity%20Soil%20Moisture.md) | Measure soil moisture using a sensor and display the result on an LCD |
| [Activity Water level.md](Activity/Activity%20Water%20level.md) | Detect water level (low/average/high) and indicate it via colored LEDs |

### Connections/

Markdown files using [Mermaid](https://mermaid.js.org/) diagrams to document the wiring between Arduino pins and components (sensors, LCD, LEDs, etc.).

### Sketches/

Arduino C++ source files (`.ino`) implementing the logic for each activity.

---

## Activities

### Activity 1 — Soil Moisture Sensor

Build an Arduino prototype that reads soil moisture from a sensor placed in a soil sample. The reading is processed through a function and the result is shown on an LCD display.

**Components:** Arduino, soil moisture sensor, LCD display

### Activity 2 — Water Level Indicator

Build an Arduino prototype that measures water level in a container and uses an RGB or three separate LEDs to indicate the level:

| Level | LED Color |
|-------|-----------|
| Low | Yellow |
| Average | Green |
| High | Red |

**Components:** Arduino, water level sensor, LEDs (yellow, green, red)
