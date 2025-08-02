
#include <DHT.h>

#define DHTPIN 2            // DHT sensor data pin
#define DHTTYPE DHT11       // Change to DHT22 if you have that

#define SOIL_MOISTURE_PIN A0 // Analog pin for soil moisture

DHT dht(DHTPIN, DHTTYPE);

// Thresholds
const int SOIL_DRY_THRESHOLD = 30;   // below this percent => too dry
const int SOIL_WET_THRESHOLD = 80;   // above this percent => too wet

void setup() {
  Serial.begin(9600);
  dht.begin();
  delay(2000); // let sensors stabilize

  Serial.println();
  Serial.println("🌱 IoT-Based Smart Agriculture System");
  Serial.println("-------------------------------------");
}

void loop() {
  // Read humidity and temperature
  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature(); // Celsius

  // Read soil moisture (analog 0..1023), map to percentage 0..100
  int rawSoil = analogRead(SOIL_MOISTURE_PIN);
  int soilPercent = map(rawSoil, 1023, 0, 0, 100); // invert if sensor gives higher value for wet

  // Validate DHT readings
  bool validTemp = !isnan(temperature);
  bool validHum = !isnan(humidity);

  Serial.println();

  if (validTemp && validHum) {
    Serial.print("Temperature: ");
    Serial.print(temperature, 1);
    Serial.println(" °C 🌡️");

    Serial.print("Humidity: ");
    Serial.print(humidity, 1);
    Serial.println(" % 💧");
  } else {
    Serial.println("Warning: Failed to read from DHT sensor. Check wiring or sensor. ⚠️");
  }

  Serial.print("Soil Moisture: ");
  Serial.print(soilPercent);
  Serial.println(" % 🌱");

  // Soil condition logic
  if (soilPercent < SOIL_DRY_THRESHOLD) {
    Serial.println("Alert: Soil is too dry! Consider irrigation. 🚨");
  } else if (soilPercent > SOIL_WET_THRESHOLD) {
    Serial.println("Soil is too wet. Check drainage. 🌊");
  } else {
    Serial.println("Soil moisture is optimal. ✅");
  }

  Serial.println("-------------------------------------");

  delay(5000); // wait 5 seconds before next read
}
