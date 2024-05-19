#include <ESP32Servo.h>

// Pin definitions
#define LDR_PIN 2
#define LED_PIN 5
#define SERVO_PIN 18

// Constants
const float gama = 0.7;
const float rl10 = 50;
const int threshold = 200; // Example threshold for LDR to turn on LED

// Variables
int pos = 0;
Servo servo;
bool servoState = false;
unsigned long servoOnTime = 0;

void setup() {
  // Initialize serial communication
  Serial.begin(115200);
  Serial.println("Hello, ESP32!");

  // Initialize LED pin
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);

  // Initialize servo
  servo.attach(SERVO_PIN, 500, 2400);
  servo.write(0); // Initialize to 0 degrees
}

void loop() {
  // Read LDR value
  int nilaiLDR = analogRead(LDR_PIN);
  nilaiLDR = map(nilaiLDR, 4095, 0, 1024, 0); // Convert ADC value for ESP32
  float voltage = nilaiLDR / 1024.0 * 5.0;
  float resistance = 2000 * voltage / (1 - voltage / 5.0);
  float brightness = pow(rl10 * 1e3 * pow(10, gama) / resistance, (1 / gama));

  // Print brightness value for debugging
  Serial.print("Nilai LDR: ");
  Serial.println(nilaiLDR);
  
  // Determine if it's bright or dark and control the LED
  if (brightness < threshold) {
    digitalWrite(LED_PIN, HIGH); // Turn on LED if it's dark
    Serial.println("Redup");
    Serial.println("LED Menyala");
  } else {
    digitalWrite(LED_PIN, LOW); // Turn off LED if it's bright
    Serial.println("Terang");
    Serial.println("LED Mati");
  }

  // Control Servo based on command
  if (Serial.available() > 0) {
    String command = Serial.readStringUntil('\n');
    command.trim();
    
    if (command == "servo: on" && !servoState) {
      servoState = true;
      servoOnTime = millis();
      servo.write(180); // Open servo
      Serial.println("Servo On");
    } else if (command == "servo: off" && servoState) {
      servoState = false;
      servo.write(0); // Close servo
      Serial.println("Servo Off");
    }
  }

  // Auto-close servo after 3 seconds if it's open
  if (servoState && (millis() - servoOnTime > 3000)) {
    servoState = false;
    servo.write(0); // Close servo
    Serial.println("Servo closed automatically after 3 seconds");
  }

  delay(10); // Short delay for stability
}
