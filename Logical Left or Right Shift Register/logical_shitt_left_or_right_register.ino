int latchPin = 11;
int clockPin = 9;
int dataPin = 12;

byte myByte = 0xF0; 
byte myByteFlipped;
void setup() {
  
  Serial.begin(9600);
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
}

void loop() {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, myByte);
  digitalWrite(latchPin, HIGH);
  delay(1000);
  myByteFlipped = 255 - myByte;

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, myByteFlipped);
  digitalWrite(latchPin, HIGH);
  delay(1000);
}