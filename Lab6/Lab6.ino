const int ledPin = 13;
const int sensorPin1 = 0;
const int sensorPin2 = 1;


const int ID_FSR= 0x10;
const int ID_Pot = 0x20;


int period = 50;
int state = LOW;
volatile int senseVal = 0;

int FSRVal_H;
int FSRVal_L;
int potVal_H;
int potVal_L;

void setup(){
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);

}
void loop(){
  FSRVal_L = analogRead(sensorPin1);
  potVal_L = analogRead(sensorPin2);
  
  FSRVal_H = FSRVal_L >> 8;
  potVal_H = potVal_L >> 8;
  delay(200);
  transmit();
}
void toggleLED(){
  state = !state;
  
  if(state){
    digitalWrite(ledPin, state);
  }else{
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
