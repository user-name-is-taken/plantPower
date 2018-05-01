//#include <avr/interrupt.h>
#include <stdarg.h>

int SOL = 11;
int LED = 13;
int inputPin = 2;//pin 2 (interrupts)
int solar = 0;
int sensorValue=0;
//digitalPinToInterrupt wasn't working 
//https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/

void setup(){
  pinMode(LED, OUTPUT);
    pinMode(SOL, OUTPUT);
  //int pin = digitalPinToInterrupt(inputPin);
  int pin = 0;
  pinMode(inputPin, INPUT_PULLUP);//the interrupt, low when pressed)
  attachInterrupt(pin, buttonPressed, CHANGE);
  Serial.begin(9600);
}

void loop(){
  delay(5000);
  sensorValue = analogRead(solar);
  Serial.print("hello"+ String(sensorValue) + "\n");
}


void buttonPressed(){
  //detachInterrupt(inputPin);
  noInterrupts();
  digitalWrite(LED, HIGH);
  digitalWrite(SOL,LOW);
  delay(100000);
  digitalWrite(SOL,HIGH);
  digitalWrite(LED, LOW);
  interrupts();
  //attachInterrupt(0, buttonPressed, FALLING);
}
