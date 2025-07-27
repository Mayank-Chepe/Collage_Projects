// Soil pH Sensor connected to A0
const int pHSensorPin = A0;
float pHValue = 0.0;
int sensorValue = 0;

// Function to map analog value to pH (approximation, adjust as needed)
float analogToPH(int analogValue) {
  // Assuming 0-14 pH range corresponds to 0-1023 analog value
  return map(analogValue, 0, 1023, 0, 1400) / 100.0;
}

// Setup Serial
void setup() {
  Serial.begin(9600);
  delay(2000); // Allow time for sensor to stabilize
  Serial.println("Soil Nutrient Analysis System");
}

// Main loop
void loop() {
  sensorValue = analogRead(pHSensorPin);
  pHValue = analogToPH(sensorValue);

  Serial.print("pH Value: ");
  Serial.println(pHValue);

  // Recommend crops based on pH ranges (simplified)
  if (pHValue < 5.5) {
    Serial.println("Soil is acidic. Recommended: Potato, Sweet Potato, Blueberry.");
  }
  else if (pHValue >= 5.5 && pHValue < 6.5) {
    Serial.println("Soil is slightly acidic. Recommended: Rice, Maize, Peanuts.");
  }
  else if (pHValue >= 6.5 && pHValue <= 7.5) {
    Serial.println("Soil is neutral. Recommended: Wheat, Barley, Tomatoes.");
  }
  else if (pHValue > 7.5) {
    Serial.println("Soil is alkaline. Recommended: Spinach, Beets, Cabbage.");
  }

  Serial.println("-----------------------------------");
  delay(5000); // Wait 5 seconds before next reading
}
