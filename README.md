# 🌱 Soil Nutrient Analyzer – Arduino Uno Project

This is a college-level Arduino project designed to measure soil pH levels and recommend suitable crops based on the soil’s acidity or alkalinity. It uses a soil pH sensor connected to an Arduino Uno to read and interpret analog values, converting them to pH and printing real-time data via the Serial Monitor.

---

## 🚀 Features

- Reads analog values from a soil pH sensor.
- Converts sensor data to pH scale (0–14).
- Provides **crop recommendations** based on soil pH.
- Displays output every 5 seconds via the Serial Monitor.
- Simple and beginner-friendly project for electronics or agriculture IoT courses.

---

## 🔧 Hardware Required

- Arduino Uno board  
- Soil pH sensor (analog output)  
- Breadboard and jumper wires  
- USB cable (for uploading code and Serial Monitor)

---

## 🖥️ How It Works

1. The soil pH sensor is connected to **analog pin A0** of the Arduino Uno.
2. The analog value is mapped to a pH value using a basic scaling function.
3. Based on the pH, the system classifies the soil condition and suggests crops accordingly.
4. Results are printed on the Serial Monitor at a 5-second interval.

---

## 🧪 pH-Based Crop Recommendations

| pH Range        | Soil Type        | Recommended Crops                          |
|-----------------|------------------|--------------------------------------------|
| < 5.5           | Acidic           | Potato, Sweet Potato, Blueberry            |
| 5.5 – 6.5       | Slightly Acidic  | Rice, Maize, Peanuts                       |
| 6.5 – 7.5       | Neutral          | Wheat, Barley, Tomatoes                    |
| > 7.5           | Alkaline         | Spinach, Beets, Cabbage                    |

---

## 📟 Sample Serial Monitor Output
Soil Nutrient Analysis System
pH Value: 6.73
Soil is neutral. Recommended: Wheat, Barley, Tomatoes.
-----------------------------------
pH Value: 5.22
Soil is acidic. Recommended: Potato, Sweet Potato, Blueberry.
-----------------------------------
pH Value: 7.84
Soil is alkaline. Recommended: Spinach, Beets, Cabbage.
-----------------------------------
pH Value: 6.11
Soil is slightly acidic. Recommended: Rice, Maize, Peanuts.
-----------------------------------


