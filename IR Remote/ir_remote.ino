#include<IRremote.h>

int IRpin = 9;
IRrecv IR(IRpin);
decode_results cmd;

String myCommand;

void setup() {
  Serial.begin(9600);
  IR.enableIRIn();   
}

void loop() {
  while(IR.decode(&cmd) == 0) {
    
  }

  Serial.println(cmd.value, HEX);
  delay(1000);
  IR.resume();

  if(cmd.value == 0xFD30CF) {
    myCommand = "Zero";
  }
  if(cmd.value == 0xFD08F7) {
    myCommand = "One";
  }
  if(cmd.value == 0xFD8877) {
    myCommand = "Two";
  }
  if(cmd.value == 0xFD48B7) {
    myCommand = "Three";
  }
  if(cmd.value == 0xFD28D7) {
    myCommand = "Four";
  }
  if(cmd.value == 0xFDA857) {
    myCommand = "Five";
  }
  if(cmd.value == 0xFD6897) {
    myCommand = "Six";
  }
  if(cmd.value == 0xFD18E7) {
    myCommand = "Seven";
  }
  if(cmd.value == 0xFD9867) {
    myCommand = "Eight";
  }
  if(cmd.value == 0xFD58A7) {
    myCommand = "Nine";
  }

  if(cmd.value == 0xFD00FF) {
    myCommand = "PWR";
  }
  if(cmd.value == 0xFD807F) {
    myCommand = "V+";
  }
  if(cmd.value == 0xFD906F) {
    myCommand = "V-";
  }
  if(cmd.value == 0xFD40BF) {
    myCommand = "FUNC";
  }
  if(cmd.value == 0xFD609F) {
    myCommand = "FWD";
  }
  if(cmd.value == 0xFD20DF) {
    myCommand = "RWD";
  }
  if(cmd.value == 0xFDB04F) {
    myCommand = "EQ";
  }
  if(cmd.value == 0xFD50AF) {
    myCommand = "UP";
  }
  if(cmd.value == 0xFD10EF) {
    myCommand = "DOWN";
  }
  if(cmd.value == 0xFDA05F) {
    myCommand = "PLAY/PAUSE";
  }
  if(cmd.value == 0xFD708F) {
    myCommand = "ST/REPT";
  }
  Serial.println(myCommand);

}