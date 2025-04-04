#include <Arduino.h>
#include <ESP32Servo.h>

#define IR_SENSOR_PIN 34    // IR sensor signal pin
#define SERVO_PIN 13       // Servo signal pin
#define DETECTION_THRESHOLD 500  // Adjust based on your sensor
#define DOOR_OPEN_DELAY 5000     // 5 seconds open time
#define SERVO_OPEN_ANGLE 180     // Open position
#define SERVO_CLOSED_ANGLE 0     // Closed position

// Function prototypes
void openDoor();
void closeDoor();

Servo doorServo;
bool doorOpen = false;
unsigned long doorOpenTime = 0;

void setup() {
  Serial.begin(115200);  // Start Serial communication at 115200 baud
  delay(1000);           // Wait for Serial to initialize
  Serial.println("IR Sensor Test Started");  // Changed to test message

  
  doorServo.attach(SERVO_PIN);
  doorServo.write(SERVO_CLOSED_ANGLE);  // Start closed
  Serial.println("Smart Door System Initialized");
}

void loop() {
  int irValue = analogRead(IR_SENSOR_PIN);  // Read the IR sensor value (0-4095)
  Serial.print("IR Value: ");
  Serial.println(irValue);                  // Print the value

  if (irValue > DETECTION_THRESHOLD && !doorOpen) {
    openDoor();
  }
  else if (doorOpen && (millis() - doorOpenTime >= DOOR_OPEN_DELAY)) {
    if (irValue <= DETECTION_THRESHOLD) {
      closeDoor();
    }
  }
  

  delay(500);  // Wait 0.5 seconds between readings (changed from 100ms)
}

// Keep these functions but they won't be called during testing
void openDoor() {
  Serial.println("Opening door...");
  for (int pos = SERVO_CLOSED_ANGLE; pos <= SERVO_OPEN_ANGLE; pos += 1) {
    doorServo.write(pos);
    delay(15);
  }
  doorOpen = true;
  doorOpenTime = millis();
  Serial.println("Door opened");
}

void closeDoor() {
  Serial.println("Closing door...");
  for (int pos = SERVO_OPEN_ANGLE; pos >= SERVO_CLOSED_ANGLE; pos -= 1) {
    doorServo.write(pos);
    delay(15);
  }
  doorOpen = false;
  Serial.println("Door closed");
}