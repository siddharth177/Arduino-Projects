int tiltPin = 2;
int tiltVal;
void setup()
{
  pinMode(tiltPin, INPUT);
  digitalWrite(tiltPin, HIGH);
  Serial.begin(9600);
}

void loop()
{
  tiltVal = digitalRead(tiltPin);
  Serial.println(tiltVal);
}