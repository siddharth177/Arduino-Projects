#include<IRremote.h>

int motor_EN_1_2 = 5;  
int motor_IN1 = 4;
int motor_IN2 = 3;
int motorSpeed = 255;

int IRpin = 9;
IRrecv IR(IRpin);
decode_results cmd;

void setup() {
  pinMode(motor_EN_1_2, OUTPUT);
  pinMode(motor_IN1, OUTPUT);
  pinMode(motor_IN2, OUTPUT);

  Serial.begin(9600);
  IR.enableIRIn();   

  digitalWrite(motor_IN1, HIGH);
  digitalWrite(motor_IN2, LOW);
}

void loop() {

  while(IR.decode(&cmd) == 0) {
    
  }
  delay(1500);
  IR.resume();


  if(cmd.value == 0xFD00FF) {
      digitalWrite(motor_IN1, LOW);
      digitalWrite(motor_IN2, HIGH);
      analogWrite(motor_EN_1_2, 255);
  }
  
  if(cmd.value == 0xFD807F) {
      motorSpeed += 10;
      if(motorSpeed > 255) {
        motorSpeed = 255;
      }

      analogWrite(motor_EN_1_2, motorSpeed);
  }
  
  if(cmd.value == 0xFD906F) {
    motorSpeed -= 10;
    if(motorSpeed < 0) {
      motorSpeed = 0;
    }

    analogWrite(motor_EN_1_2, motorSpeed);
  }
 
  if(cmd.value == 0xFD609F) {
    digitalWrite(motor_IN1, LOW);
    digitalWrite(motor_IN2, HIGH);
    analogWrite(motor_EN_1_2, motorSpeed);
  }
  if(cmd.value == 0xFD20DF) {
    digitalWrite(motor_IN1, HIGH);
    digitalWrite(motor_IN2, LOW);
    analogWrite(motor_EN_1_2, motorSpeed);
  }
  analogWrite(motor_EN_1_2, motorSpeed);

}