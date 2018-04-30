#include <avr/interrupt.h>

int LED = 11;
int inputPin = 2;//pin 2
//digitalPinToInterrupt wasn't working 
//https://www.arduino.cc/reference/en/language/functions/external-interrupts/attachinterrupt/
volatile boolean LED_ON = false;

void setup(){
  //pass
  pinMode(LED, OUTPUT);
  pinMode(inputPin, INPUT_PULLUP);//the interrupt, low when pressed)
  attachInterrupt(0, buttonPressed, FALLING);
}

void loop(){
  //pass
  //digitalWrite(LED, HIGH);
  delay(50000);
 // digitalWrite(LED, LOW);
  //delay(500);
}

void buttonPressed(){
  detachInterrupt(0);
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
  delay(1000);
  attachInterrupt(0, buttonPressed, FALLING);

  
  /*
  if(LED_ON == true){
    digitalWrite(LED, LOW);
    LED_ON = false;
  }else{
    digitalWrite(LED, HIGH);
    LED_ON = true;
  }
  */
}
