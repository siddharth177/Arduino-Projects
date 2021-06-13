int motor_EN_1_2 = 5;  
int motor_IN1 = 4;
int motor_IN2 = 3;
int motorSpeed = 0;
int pButtonL = 7;
int pButtonR = 2;
int pButtonLReadOld = 1;
int pButtonRReadOld = 1;
int pButtonRReadNew, pButtonLReadNew;  
int motorDir = 1;
void setup() {
  pinMode(motor_EN_1_2, OUTPUT);
  pinMode(motor_IN1, OUTPUT);
  pinMode(motor_IN2, OUTPUT);
  
  pinMode(pButtonL, INPUT);
  digitalWrite(pButtonL, HIGH);
  pinMode(pButtonR, INPUT);
  digitalWrite(pButtonR, HIGH);
  Serial.begin(9600);
}

void loop() {
  pButtonLReadNew = digitalRead(pButtonL);
  pButtonRReadNew = digitalRead(pButtonR);

  if(pButtonLReadNew == 0 && pButtonLReadOld == 1) {
      if(motorDir == -1 && motorSpeed > 0) {
      motorSpeed -= 5;
      if(motorSpeed < 0) {
        motorDir = 1;
        motorSpeed = 0;
      }
    }

    if(motorSpeed <= 0 || motorDir == 1) {
      motorSpeed += 5;
      if(motorSpeed > 255) {
        motorSpeed = 255;
      }
    }
    
    
  }

  if(pButtonRReadNew == 0 && pButtonRReadOld == 1) {

    if(motorDir == 1 && motorSpeed > 0) {
      motorSpeed -= 5;
      if(motorSpeed < 0) {
        motorDir = -1;
        motorSpeed = 0;
      }
    }

    if(motorSpeed <= 0 || motorDir == -1) {
      motorSpeed += 5;
      if(motorSpeed > 255) {
        motorSpeed = 255;
      }
    }
    
  }

  if(motorDir == 1) {
    digitalWrite(motor_IN1, LOW);
    digitalWrite(motor_IN2, HIGH);
  } else {
    digitalWrite(motor_IN1, HIGH);
    digitalWrite(motor_IN2, LOW);
  }

  analogWrite(motor_EN_1_2, motorSpeed);
}