#include <DHT.h>
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN,DHTTYPE);



void setup() {
  Serial.begin(9600);
  dht.begin();
  
}

void loop() {
  int h = dht.readHumidity();
  int t = dht.readTemperature();

  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.println(" °C");


}