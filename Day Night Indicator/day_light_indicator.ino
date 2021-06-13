#include<Servo.h>
int servoPin = 9;
int lightPin = A4;
int lightVal;
int servoPos = 0;
int M = 5;
int m = 670;
Servo myServo;

void setup() {
  Serial.begin(9600);
  myServo.attach(servoPin);
  pinMode(lightPin, INPUT);
  pinMode(servoPin, OUTPUT);
}

void loop() {
  lightVal = analogRead(lightPin);
  servoPos = ((180.)/(M - m)) * (lightVal - m);
  myServo.write(servoPos);
}