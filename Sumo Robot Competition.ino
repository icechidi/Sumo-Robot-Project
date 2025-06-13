// Pin definitions
// Motor driver pins
const int ENA = 11;  // PWM left motor
const int IN1 = 5;
const int IN2 = 6;
const int ENB = 3;   // PWM right motor
const int IN3 = 9;
const int IN4 = 10;

// Ultrasonic sensor pins
const int trigPin = 7;
const int echoPin = 8;

// IR sensor pin
const int irSensorPin = 4;

// Switch pin
const int switchPin = 12;

// Variables
long duration;
int distance;
bool robotActive = false;

void setup() {
  // Motor pins as output
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  // Ultrasonic sensor pins
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // IR sensor input
  pinMode(irSensorPin, INPUT);

  // Switch input with pullup resistor
  pinMode(switchPin, INPUT_PULLUP);

  Serial.begin(9600);
  stopMotors();
}

void loop() {
  // Read switch - active LOW when pressed
  if (digitalRead(switchPin) == LOW) {
    robotActive = true;
  } else {
    robotActive = false;
    stopMotors();
    return;
  }

  if (!robotActive) {
    stopMotors();
    return;
  }

  // Check edge with IR sensor - if detected edge, reverse and turn
  if (digitalRead(irSensorPin) == LOW) {  // Assuming LOW means edge detected
    reverse();
    delay(500);
    turnRight();
    delay(500);
    return;
  }

  // Read ultrasonic sensor distance
  distance = readUltrasonicDistance();

  if (distance > 0 && distance < 30) {
    // Opponent detected within 30 cm, move forward aggressively
    moveForward(255);
  } else {
    // No opponent detected, rotate to search
    rotateRight(200);
  }
}

int readUltrasonicDistance() {
  // Send trig pulse
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read echo pulse duration
  duration = pulseIn(echoPin, HIGH, 30000); // timeout 30ms

  // Calculate distance in cm
  int dist = duration * 0.034 / 2;
  if (dist == 0) return -1; // no echo received
  return dist;
}

// Motor control functions
void moveForward(int speed) {
  analogWrite(ENA, speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  analogWrite(ENB, speed);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
}

void reverse() {
  analogWrite(ENA, 200);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);

  analogWrite(ENB, 200);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void turnRight() {
  analogWrite(ENA, 200);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  analogWrite(ENB, 200);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void rotateRight(int speed) {
  analogWrite(ENA, speed);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);

  analogWrite(ENB, speed);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
}

void stopMotors() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}