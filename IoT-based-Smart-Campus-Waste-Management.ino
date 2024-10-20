
#define BLYNK_TEMPLATE_ID "TMPL3mAMGqfI4"
#define BLYNK_TEMPLATE_NAME "smart waste management system"
#define BLYNK_AUTH_TOKEN "cgyTcImjnCS-YDuzF1Uzs2_e6pn8Wg1q"


#include <WiFi.h>
#include <BlynkSimpleEsp32.h>


#define TRIGGER_PIN 22   // Ultrasonic sensor trigger pin
#define ECHO_PIN    23   // Ultrasonic sensor echo pin

const int potPin = 35;
const float BETA = 3950;

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

void setup() {
  Serial.begin(9600);
  
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  pinMode(TRIGGER_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  

  while (WiFi.status() != WL_CONNECTED) {
    Serial.print("Connecting to WiFi...");
    delay(500);
  }
  Serial.println("WiFi connected");
}

void loop() {
  Blynk.run();
  
  int distance = getDistance();
  int temperature = getTemperature();
  int moisture = getMoisture();

  Blynk.virtualWrite(V0, distance);     // Send waste level to Blynk app
  Blynk.virtualWrite(V2, temperature);  // Send temperature to Blynk app
  Blynk.virtualWrite(V1, moisture);     // Send moisture level to Blynk app

  delay(1000); // Adjust delay as needed
}

float getDistance() {
  digitalWrite(TRIGGER_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  float distance_cm = duration * 0.034 / 2; // Convert time to distance in cm
  float max_distance_cm = 400.0;            // Maximum distance your sensor can measure in cm
  float distance_percentage = (distance_cm / max_distance_cm) * 100.0; // Calculate percentage

  return distance_percentage;
}

float getTemperature() {
  int analogValue = analogRead(potPin);
  float kelvins = 1 / (log(1 / (4095. / analogValue - 1)) / BETA + 1.0 / 298.15);
  int celsius = kelvins - 273.15;
  return celsius;
}
int getMoisture() {
    int16_t i = analogRead(34);
    int moisture = map(i, 0, 4095, 0, 100);// Map ADC value to moisture percentage
  return moisture;
}

