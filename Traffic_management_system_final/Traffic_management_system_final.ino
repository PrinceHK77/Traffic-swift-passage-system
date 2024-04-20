#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // Address 0x27, 16 columns, 2 rows

// Define the pins for the traffic light modules for each road 
// Road 1 (North)
const int redPin1 = 2;
const int yellowPin1 = 3;
const int greenPin1 = 4;
// Road 2 (East)
const int redPin2 = 5;
const int yellowPin2 = 6;
const int greenPin2 = 7;
// Road 3 (South)
const int redPin3 = 8;
const int yellowPin3 = 9;
const int greenPin3 = 10;
// Road 4 (West)
const int redPin4 = 11;
const int yellowPin4 = 12;
const int greenPin4 = 13;

// Define the durations for each state (in milliseconds)
const int greenDuration =4000; // 8 seconds
const int yellowDuration = 2000; // 4 seconds
const int redDuration = 4000; // 4 seconds
const int Emergency = 4000;
const int Message = 3000;

void setup() {

  // Initialize serial communication
  Serial.begin(9600);
  // Initialize the traffic light pins as outputs
  pinMode(redPin1, OUTPUT);
  pinMode(yellowPin1, OUTPUT);
  pinMode(greenPin1, OUTPUT);
  pinMode(redPin2, OUTPUT);
  pinMode(yellowPin2, OUTPUT);
  pinMode(greenPin2, OUTPUT);
  pinMode(redPin3, OUTPUT);
  pinMode(yellowPin3, OUTPUT);
  pinMode(greenPin3, OUTPUT);
  pinMode(redPin4, OUTPUT);
  pinMode(yellowPin4, OUTPUT);
  pinMode(greenPin4, OUTPUT);


  // Initialize the LCD
  lcd.init();
  lcd.backlight(); // Turn on backlight
  lcd.setCursor(0, 0);
  lcd.print("Traffic Control");
}

void handleEmergency() {
  delay(1000);

  // Handle emergency signal
  // Set specific traffic lights to handle the emergency
  digitalWrite(greenPin1, HIGH); // Only module 1 is green
  digitalWrite(redPin2, HIGH);
  digitalWrite(redPin3, HIGH);
  digitalWrite(redPin4, HIGH);
  delay(Emergency);

  // After the emergency duration, resume normal traffic flow
  resumeNormal();
  
  // Print emergency message on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Ambulance passing!");
  delay(Message);
}


void resumeNormal() {
  // Resume normal traffic flow
  normalTrafficFlow();
  
  // Print normal message on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Normal signal!");
  delay(Message);
}

void loop() {
  if (Serial.available()) {
    char signal = Serial.read();
    switch (signal) {
      case 'E': // Emergency signal from Python
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Alert changing signals");
        handleEmergency();
        break;
      case 'N': // Normal signal from Python
        resumeNormal();
        break;
    }
  }
  // Normal traffic flow
  normalTrafficFlow();
}

void normalTrafficFlow() {
  // Road 1: Green, Others Red
  digitalWrite(greenPin1, HIGH);
  digitalWrite(redPin1, LOW);
  digitalWrite(yellowPin1, LOW);
  digitalWrite(redPin2, HIGH);
  digitalWrite(redPin3, HIGH);
  digitalWrite(redPin4, HIGH);
  delay(greenDuration);

  // Check for emergency message during transition
  if (checkEmergencyDuringTransition()) return;

  // Road 1: Yellow
  digitalWrite(greenPin1, LOW);
  digitalWrite(redPin1, LOW);
  digitalWrite(yellowPin1, HIGH);
  delay(yellowDuration);

  // Check for emergency message during transition
  if (checkEmergencyDuringTransition()) return;

  // Road 1: Red
  digitalWrite(greenPin1, LOW);
  digitalWrite(redPin1, HIGH);
  digitalWrite(yellowPin1, LOW);
  delay(redDuration);

  // Check for emergency message during transition
  if (checkEmergencyDuringTransition()) return;

  // Road 2: Green, Others Red
  digitalWrite(greenPin2, HIGH);
  digitalWrite(redPin1, HIGH);
  digitalWrite(redPin2, LOW);
  digitalWrite(yellowPin2, LOW);
  digitalWrite(redPin3, HIGH);
  digitalWrite(redPin4, HIGH);
  delay(greenDuration);

  // Check for emergency message during transition
  if (checkEmergencyDuringTransition()) return;

  // Road 2: Yellow
  digitalWrite(greenPin2, LOW);
  digitalWrite(redPin1, HIGH);
  digitalWrite(redPin2, LOW);
  digitalWrite(yellowPin2, HIGH);
  digitalWrite(redPin3, HIGH);
  digitalWrite(redPin4, HIGH);
  delay(yellowDuration);

  // Check for emergency message during transition
  if (checkEmergencyDuringTransition()) return;

  // Road 2: Red
  digitalWrite(greenPin2, LOW);
  digitalWrite(redPin1, HIGH);
  digitalWrite(redPin2, HIGH);
  digitalWrite(yellowPin2, LOW);
  digitalWrite(redPin3, HIGH);
  digitalWrite(redPin4, HIGH);
  delay(redDuration);

  // Check for emergency message during transition
  if (checkEmergencyDuringTransition()) return;

  // Road 3: Green, Others Red
  digitalWrite(greenPin3, HIGH);
  digitalWrite(redPin1, HIGH);
  digitalWrite(redPin2, HIGH);
  digitalWrite(redPin3, LOW);
  digitalWrite(yellowPin3, LOW);
  digitalWrite(redPin4, HIGH);
  delay(greenDuration);

  // Check for emergency message during transition
  if (checkEmergencyDuringTransition()) return;

  // Road 3: Yellow
  digitalWrite(greenPin3, LOW);
  digitalWrite(redPin1, HIGH);
  digitalWrite(redPin2, HIGH);
  digitalWrite(redPin3, LOW);
  digitalWrite(yellowPin3, HIGH);
  digitalWrite(redPin4, HIGH);
  delay(yellowDuration);

  // Check for emergency message during transition
  if (checkEmergencyDuringTransition()) return;

  // Road 3: Red
  digitalWrite(greenPin3, LOW);
  digitalWrite(redPin1, HIGH);
  digitalWrite(redPin2, HIGH);
  digitalWrite(redPin3, HIGH);
  digitalWrite(yellowPin3, LOW);
  digitalWrite(redPin4, HIGH);
  delay(redDuration);

  // Check for emergency message during transition
  if (checkEmergencyDuringTransition()) return;

  // Road 4: Green, Others Red
  digitalWrite(greenPin4, HIGH);
  digitalWrite(redPin1, HIGH);
  digitalWrite(redPin2, HIGH);
  digitalWrite(redPin3, HIGH);
  digitalWrite(redPin4, LOW);
  digitalWrite(yellowPin4, LOW);
  delay(greenDuration);

  // Check for emergency message during transition
  if (checkEmergencyDuringTransition()) return;

  // Road 4: Yellow
  digitalWrite(greenPin4, LOW);
  digitalWrite(redPin1, HIGH);
  digitalWrite(redPin2, HIGH);
  digitalWrite(redPin3, HIGH);
  digitalWrite(redPin4, LOW);
  digitalWrite(yellowPin4, HIGH);
  delay(yellowDuration);

  // Check for emergency message during transition
  if (checkEmergencyDuringTransition()) return;

  // Road 4: Red
  digitalWrite(greenPin4, LOW);
  digitalWrite(redPin1, HIGH);
  digitalWrite(redPin2, HIGH);
  digitalWrite(redPin3, HIGH);
  digitalWrite(redPin4, HIGH);
  digitalWrite(yellowPin4, LOW);
  delay(redDuration);

  // Check for emergency message during transition
  checkEmergencyDuringTransition();
}


bool checkEmergencyDuringTransition() {
  // Check for emergency message during transition
  while (Serial.available()) {
    char signal = Serial.read();
    if (signal == 'E') {
      // Emergency signal received, switch to emergency mode
      turnOffLights();
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Ambulance Arrival!");
      handleEmergency();
      return true; // Return true to stop the current traffic flow
      
    }
  }
  return false; // Return false if no emergency signal received
}

// Function to turn off all traffic lights
void turnOffLights() {
  digitalWrite(redPin1, LOW);
  digitalWrite(yellowPin1, LOW);
  digitalWrite(greenPin1, LOW);
  digitalWrite(redPin2, LOW);
  digitalWrite(yellowPin2, LOW);
  digitalWrite(greenPin2, LOW);
  digitalWrite(redPin3, LOW);
  digitalWrite(yellowPin3, LOW);
  digitalWrite(greenPin3, LOW);
  digitalWrite(redPin4, LOW);
  digitalWrite(yellowPin4, LOW);
  digitalWrite(greenPin4, LOW);
}