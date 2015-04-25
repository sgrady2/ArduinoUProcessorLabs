/*
Example 6.2 Arduino Cookbook Code
For Lab 3 Part II
*/
#include <MsTimer2.h>
const int ledPin = 13; // LED connected to digital pin 13
const int sensorPin1 = 0;// connect sensor to analog input 0
const int sensorPin2 = 1;
const int buttPin = 3;
const int switchPin = 2;
int period = 50;
int state = LOW;
boolean timer = LOW;
int COUNT = 0;
int FSRVal_L = 0;
int potVal_L = 0;
int FSRVal_H = 0;
int potVal_H = 0;
const int ID_FSR= 0x10;
const int ID_Pot = 0x20;


void setup()
{
  MsTimer2::set(period, transmit);
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT); // enable output on the led pin
  pinMode(switchPin, INPUT_PULLUP);
  pinMode(buttPin, INPUT_PULLUP);
  attachInterrupt(0, watchEn, CHANGE);
  attachInterrupt(1, clearCount, FALLING);
}

void loop() {

  digitalWrite(ledPin, HIGH); // set the LED on
  //delay(rate); // wait duration dependent on light level
  digitalWrite(ledPin, LOW); // set the LED off
  //delay(rate);
  FSRVal_L = analogRead(sensorPin1);
  potVal_L = analogRead(sensorPin2);
  //from in class to adapt to voltage divider
  //bitwise right shift to create the high value
  
  FSRVal_H = FSRVal_L >> 8;
  potVal_H = potVal_L >> 8;

}

void watchEn(){
  //debounce
  delay(30);
  if (timer == LOW){
    MsTimer2::start();
    timer = HIGH;
    
}else {
  MsTimer2::stop();
  timer = LOW;
}
  
}
void clearCount(){
  COUNT = 1;
  Serial.println("0");
}

void toggleLED(){
  if(state == LOW){
    state = HIGH;
    digitalWrite(ledPin, state);
  }else{
    state = LOW;
    digitalWrite(ledPin, state);
  }

}
void transmit(){
  Serial.write(ID_FSR);
  Serial.write(FSRVal_H);
  Serial.write(FSRVal_L);
  Serial.write(ID_Pot);
  Serial.write(potVal_H);
  Serial.write(potVal_L);
  toggleLED();
}
