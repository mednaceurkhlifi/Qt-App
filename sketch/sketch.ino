#include <DHT_U.h> 
#include <DHT.h>;

#define DHTPIN 2
#define DHTTYPE DHT11

#define ventilateurpin 3

DHT dht(DHTPIN, DHTTYPE);

float temp, hum;

void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(ventilateurpin, OUTPUT);
}

void loop() {
   
  temp = dht.readTemperature();
  char temp2[5];

 dtostrf(temp, 2, 2, temp2);
  hum = dht.readHumidity();
 
  //Serial.write(temp2);
   
  Serial.print(temp);
 
  Serial.print("-");
  //Serial.print(hum);
  //Serial.println(" %");
 delay(3000);
  if (temp >= 26) {
    analogWrite(ventilateurpin, 255);
  }
  else {
    analogWrite(ventilateurpin, 0);
  }
}
