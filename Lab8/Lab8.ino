An Arduino code example for interfacing with the HMC5883

by: Jordan McConnell
 SparkFun Electronics
 created on: 6/30/11
 license: OSHW 1.0, http://freedomdefined.org/OSHW

Analog input 4 I2C SDA
Analog input 5 I2C SCL
*/

#include <Wire.h> //I2C Arduino Library

#define address 0x1E //0011110b, I2C 7bit address of HMC5883


unsigned XH;
unsigned XL;
unsigned YH;
unsigned YL;
unsigned ZH;
unsigned ZL;


void setup(){
  //Initialize Serial and I2C communications
  Serial.begin(9600);
  Wire.begin();
  
  //Put the HMC5883 IC into the correct operating mode
  Wire.beginTransmission(address); //open communication with HMC5883
  Wire.send(0x02); //select mode register
  Wire.send(0x00); //continuous measurement mode
  Wire.endTransmission();
}

void loop(){
  
  int x,y,z; //triple axis data

  //Tell the HMC5883 where to begin reading data
  Wire.beginTransmission(address);
  Wire.send(0x03); //select register 3, X MSB register
  Wire.endTransmission();
  
 
 //Read data from each axis, 2 registers per axis
  Wire.requestFrom(address, 6);
  if(6<=Wire.available()){
    XH =0x80 + Wire.read()<<8; //X msb
    XL |= Wire.read(); //X lsb
    ZH = Wire.receive()<<8; //Z msb
    ZL |= Wire.receive(); //Z lsb
    ZH = Wire.receive()<<8; //Y msb
    ZL  |= Wire.receive(); //Y lsb
  }
  
  //Print out values of each axis
  Serial.write(XH);
  Serial.write(XL);
  Serial.write(YH);
  Serial.write(YL);
  Serial.write(ZH);
  Serial.write(ZL);
  
  delay(67);
}
