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
const int greenDuration = 5000; // 5 seconds
const int yellowDuration = 2000; // 2 seconds
const int redDuration = 5000; // 5 seconds

void setup() {
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
}

void loop() {
  // Road 1: Green, Others Red
  digitalWrite(greenPin1, HIGH);
  digitalWrite(redPin1, LOW);
  digitalWrite(yellowPin1, LOW);
  digitalWrite(redPin2, HIGH);
  digitalWrite(redPin3, HIGH);
  digitalWrite(redPin4, HIGH);
  delay(greenDuration);

  // Road 1: Yellow
  digitalWrite(greenPin1, LOW);
  digitalWrite(redPin1, LOW);
  digitalWrite(yellowPin1, HIGH);
  delay(yellowDuration);

  // Road 1: Red
  digitalWrite(greenPin1, LOW);
  digitalWrite(redPin1, HIGH);
  digitalWrite(yellowPin1, LOW);
  delay(redDuration);

  // Road 2: Green, Others Red
  digitalWrite(greenPin2, HIGH);
  digitalWrite(redPin1, HIGH);
  digitalWrite(redPin2, LOW);
  digitalWrite(yellowPin2, LOW);
  digitalWrite(redPin3, HIGH);
  digitalWrite(redPin4, HIGH);
  delay(greenDuration);

  // Road 2: Yellow
  digitalWrite(greenPin2, LOW);
  digitalWrite(redPin1, HIGH);
  digitalWrite(redPin2, LOW);
  digitalWrite(yellowPin2, HIGH);
  digitalWrite(redPin3, HIGH);
  digitalWrite(redPin4, HIGH);
  delay(yellowDuration);

  // Road 2: Red
  digitalWrite(greenPin2, LOW);
  digitalWrite(redPin1, HIGH);
  digitalWrite(redPin2, HIGH);  digitalWrite(yellowPin2, LOW);
  digitalWrite(redPin3, HIGH);
  digitalWrite(redPin4, HIGH);
  delay(redDuration);

  // Road 3: Green, Others Red
  digitalWrite(greenPin3, HIGH);
  digitalWrite(redPin1, HIGH);
  digitalWrite(redPin2, HIGH);
  digitalWrite(redPin3, LOW);
  digitalWrite(yellowPin3, LOW);
  digitalWrite(redPin4, HIGH);
  delay(greenDuration);

  // Road 3: Yellow
  digitalWrite(greenPin3, LOW);
  digitalWrite(redPin1, HIGH);
  digitalWrite(redPin2, HIGH);
  digitalWrite(redPin3, LOW);
  digitalWrite(yellowPin3, HIGH);
  digitalWrite(redPin4, HIGH);
  delay(yellowDuration);

  // Road 3: Red
  digitalWrite(greenPin3, LOW);
  digitalWrite(redPin1, HIGH);
  digitalWrite(redPin2, HIGH);
  digitalWrite(redPin3, HIGH);
  digitalWrite(yellowPin3, LOW);
  digitalWrite(redPin4, HIGH);
  delay(redDuration);

  // Road 4: Green, Others Red
  digitalWrite(greenPin4, HIGH);
  digitalWrite(redPin1, HIGH);
  digitalWrite(redPin2, HIGH);
  digitalWrite(redPin3, HIGH);
  digitalWrite(redPin4, LOW);
  digitalWrite(yellowPin4, LOW);
  delay(greenDuration);

  // Road 4: Yellow
  digitalWrite(greenPin4, LOW);
  digitalWrite(redPin1, HIGH);
  digitalWrite(redPin2, HIGH);
  digitalWrite(redPin3, HIGH);
  digitalWrite(redPin4, LOW);
  digitalWrite(yellowPin4, HIGH);
  delay(yellowDuration);

  // Road 4: Red
  digitalWrite(greenPin4, LOW);
  digitalWrite(redPin1, HIGH);
  digitalWrite(redPin2, HIGH);
  digitalWrite(redPin3, HIGH);
  digitalWrite(redPin4, HIGH);
  digitalWrite(yellowPin4, LOW);
  delay(redDuration);
}


