#include <LiquidCrystal.h>
int rs=7;
int en=8;
int d4=9;
int d5=10;
int d6=11;
int d7=12;

float firstNum;
float secNum;
float answer;

String op;

LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
void setup() {
  // put your setup code here, to run once:
lcd.begin(16,2);
Serial.begin(9600);
}

void loop() {
lcd.setCursor(0,0);
lcd.print("Input 1st Number");
while (Serial.available()==0){
  
}
firstNum=Serial.parseFloat();
lcd.clear();
lcd.setCursor(0,0);
lcd.print("Input 2nd Number");
while (Serial.available()==0){
}
secNum=Serial.parseFloat();

lcd.clear();
lcd.setCursor(0,0);
lcd.print("Input(+,-,*,/)");
while (Serial.available()==0){
  
}
op=Serial.readString();

if (op=="+"){
  answer=firstNum+secNum;
}
if (op=="-"){
  answer=firstNum-secNum;
}
if (op=="*"){
  answer=firstNum*secNum;
}
if (op=="/") {
  answer=firstNum/secNum;
}
lcd.clear();
lcd.setCursor(0,0);
lcd.print(firstNum);
lcd.print(op);
lcd.print(secNum);
lcd.print(" = ");
lcd.print(answer);
lcd.setCursor(0,1);
lcd.print("Thank You");
delay(5000);
lcd.clear();
}