#include "dht.h"

//ORGANIZAÇÃO DOS PINOS

//PINO 1: FORÇA (5V)
//PINO 2: SERIAL INPUT
//PINO 3: 
//PINO 4: GND

const int pinoDHT11 = A2;
dht DHT;

void setup() {
  Serial.begin(9600);
  delay(2000);
}

void loop() {

  DHT.read11(pinoDHT11);

  Serial.print("Umidade: ");
  Serial.print(DHT.humidity);
  Serial.print("%");

  Serial.print(" / Temperatura: ");
  Serial.print(DHT.temperature, 0);
  Serial.println("*C");

  delay(2000);
}
