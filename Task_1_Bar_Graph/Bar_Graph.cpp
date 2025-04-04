// Pin definitions
#include <Arduino.h>

#define LDR_PIN 35        // Analog pin for LDR
#define BUTTON_PIN 25       // GPIO for push button
#define BUZZER_PIN 27       // GPIO for buzzer
#define LED1_PIN 14         // GPIO for LED1
#define LED2_PIN 12         // GPIO for LED2
#define LED3_PIN 13         // GPIO for LED3
#define LED4_PIN 26         // GPIO for LED4

int buttonState = 0;       // Variable to store push button state
int lastButtonState = HIGH;   // Variable to store the last button state (initial state is HIGH due to INPUT_PULLUP)

void setup() {
  Serial.begin(115200);           // Start serial communication for debugging
  pinMode(LDR_PIN, INPUT);        // LDR as input (analog)
  pinMode(BUTTON_PIN, INPUT_PULLUP); // Push button with internal pull-up
  pinMode(BUZZER_PIN, OUTPUT);    // Buzzer as output
  pinMode(LED1_PIN, OUTPUT);      // LED1 as output
  pinMode(LED2_PIN, OUTPUT);      // LED2 as output
  pinMode(LED3_PIN, OUTPUT);      // LED3 as output
  pinMode(LED4_PIN, OUTPUT);      // LED4 as output
}

void displayBarGraph(int ldrValue) {
  // Map LDR value (0 to 1023) to a range of 0 to 4 for 4 LEDs
  int ledThreshold = map(ldrValue, 0, 1023, 0, 4); // LDR value to LED count

  // Debugging print to monitor the LDR value and the mapped threshold
  Serial.print("LDR Value: ");
  Serial.print(ldrValue);
  Serial.print(" Mapped LED Threshold: ");
  Serial.println(ledThreshold);

  // Turn LEDs on based on the mapped threshold
  digitalWrite(LED1_PIN, ledThreshold >= 1 ? HIGH : LOW);
  digitalWrite(LED2_PIN, ledThreshold >= 2 ? HIGH : LOW);
  digitalWrite(LED3_PIN, ledThreshold >= 3 ? HIGH : LOW);
  digitalWrite(LED4_PIN, ledThreshold >= 4 ? HIGH : LOW);
}

void checkButton() {
  buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == LOW && lastButtonState == HIGH) {  // Button pressed (assuming active-low button)
    delay(50);  // Debounce delay
    digitalWrite(BUZZER_PIN, HIGH);  // Activate buzzer on button press
    delay(500);  // Buzzer duration
    digitalWrite(BUZZER_PIN, LOW);   // Turn off buzzer
  }
  
  lastButtonState = buttonState;  // Update button state
}

void loop() {
  int ldrValue = analogRead(LDR_PIN);  // Read the LDR value (0 to 1023)
  displayBarGraph(ldrValue);            // Update the bar graph based on LDR value

  // Example of triggering buzzer based on LDR value
  if (ldrValue < 200) {
    digitalWrite(BUZZER_PIN, HIGH);  // Buzzer on for low light
  } else {
    digitalWrite(BUZZER_PIN, LOW);   // Buzzer off for sufficient light
  }

  checkButton();  // Check if button is pressed and toggle LED/buzzer

  delay(100);  // Small delay to stabilize readings
}
