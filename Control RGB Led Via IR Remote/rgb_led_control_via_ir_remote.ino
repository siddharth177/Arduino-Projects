#include<IRremote.h>

int red_pin = 11;
int blue_pin = 10;
int green_pin = 9;
int red_value = 255;
int green_value = 255;
int blue_value = 255;
float dFact = 1;

int IRpin = 3;
IRrecv IR(IRpin);
decode_results cmd;

void setup() {
  Serial.begin(9600);
  IR.enableIRIn();   
  
  pinMode(red_pin, OUTPUT);
  pinMode(green_pin, OUTPUT);
  pinMode(blue_pin, OUTPUT);
  
}

void loop() {
  while(IR.decode(&cmd) == 0) {
    
  }
  delay(1000);
  IR.resume();

  Serial.println(cmd.value, HEX);
  if(cmd.value == 0xFD30CF) {
    white();
  }
  if(cmd.value == 0xFD08F7) {
    red();
  }
  if(cmd.value == 0xFD8877) {
    green();
  }
  if(cmd.value == 0xFD48B7) {
    blue();
  }
  if(cmd.value == 0xFD28D7) {
    cyan();
  }
  if(cmd.value == 0xFDA857) {
   magenta();
  }
  if(cmd.value == 0xFD6897) {
    yellow();
  }

  if(cmd.value == 0xFD00FF) {
    ledON();
  }

  if(cmd.value == 0xFD40BF) {
    ledOFF();
  }
  if(cmd.value == 0xFD50AF) {
    brightnessUP();
  }
  if(cmd.value == 0xFD10EF) {
    brightnessDOWN();
  } 

  analogWrite(red_pin, red_value * dFact);  
  analogWrite(green_pin, green_value * dFact);  
  analogWrite(blue_pin, blue_value * dFact);
}


void ledON(){
  red_value = 255;
  green_value = 255;
  blue_value = 255;
  dFact = 1;
}

void ledOFF(){
  red_value = 0;
  green_value = 0;
  blue_value = 0;
  dFact = 0;
}

void brightnessUP(){
  dFact *= 1.75;

  if(dFact > 1) {
    dFact = 1;
  }
}

void brightnessDOWN() {
    dFact *= .975;
}

void white(){
  red_value = 255;
  green_value = 255;
  blue_value = 255;
}

void red() {
  red_value = 255;
  green_value = 0;
  blue_value = 0;
}

void green() {
  red_value = 0;
  green_value = 255;
  blue_value = 0;  
}

void blue() {
  red_value = 0;
  green_value = 0;
  blue_value = 255;
}
void cyan () {
  red_value = 0;
  green_value = 255;
  blue_value = 255; 
}
void magenta() {
  red_value = 255;
  green_value = 0;
  blue_value = 255;
}

void yellow(){
  red_value = 255;
  green_value = 255;
  blue_value = 0;
}
