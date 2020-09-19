#include "dht.h"

//ORGANIZAÇÃO DOS PINOS (DHT)

//PINO 1: FORÇA (5V)
//PINO 2: SERIAL INPUT
//PINO 3: 
//PINO 4: GND

const int LED_VERMELHO = LED_BUILTIN; //Entrada 13
const int LED_AMARELO = 12;
const int LED_VERDE = 11;

char VERMELHO[]  = "vermelho";
char AMARELO[]  = "amarelo";
char VERDE[]  = "verde";

const int UMIDADE_BAIXA = 50;
const int UMIDADE_ALTA = 80;

const int pinoDHT11 = A2;
dht DHT;

void setup() {
  pinMode(LED_VERMELHO, OUTPUT);
  pinMode(LED_AMARELO, OUTPUT);
  pinMode(LED_VERDE, OUTPUT);
  
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

  if(DHT.humidity <= UMIDADE_BAIXA){
    acendeLed(VERMELHO);
  }else if(DHT.humidity > UMIDADE_BAIXA && DHT.humidity <= UMIDADE_ALTA){
    acendeLed(AMARELO);
  }else if(DHT.humidity > UMIDADE_ALTA){
    acendeLed(VERDE);
  }

  delay(2000);

}

void acendeLed(char corLed[]){
  if(corLed == VERMELHO){
    digitalWrite(LED_VERMELHO, HIGH);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERDE, LOW);
  }
  if(corLed == AMARELO){
     digitalWrite(LED_VERMELHO, LOW);
    digitalWrite(LED_AMARELO, HIGH);
    digitalWrite(LED_VERDE, LOW);
  }
  if(corLed == VERDE){
     digitalWrite(LED_VERMELHO, LOW);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_VERDE, HIGH);
  }
}
