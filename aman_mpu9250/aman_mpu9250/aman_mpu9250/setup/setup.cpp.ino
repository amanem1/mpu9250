#include <Wire.h>


long accelX, accelY, accelZ;
float gForceX, gForceY, gForceZ;

long gyroX, gyroY, gyroZ;
float rotX, rotY, rotZ;
float x[]={};
long magx,magy,magz;
void setup() {
  Serial.begin(115200);
  Wire.begin();

}

void mpusetup(){
  Wire.beginTransmission(0x68);
  Wire.write(0x6B);
  Wire.write(0b00000000);
  Wire.endTransmission();
  Wire.beginTransmission(0x68);
  Wire.write(0x1C);//accelerometer
  Wire.write(0b00000000);
  Wire.endTransmission();
  Wire.beginTransmission(0x68);
  Wire.beginTransmission(0x1B);
  Wire.write(0x00000000);
  Wire.endTransmission();
  
  
}
void recordAccelRegisters() {
  Wire.beginTransmission(0b1101000); //I2C address of the MPU
  Wire.write(0x3B); //Starting register for Accel Readings
  Wire.endTransmission();
  Wire.requestFrom(0b1101000,6); //Request Accel Registers (3B - 40)
  while(Wire.available() < 6);
  accelX = Wire.read()<<8|Wire.read(); //Store first two bytes into accelX
  accelY = Wire.read()<<8|Wire.read(); //Store middle two bytes into accelY
  accelZ = Wire.read()<<8|Wire.read(); //Store last two bytes into accelZ

}
void recordgyroRegisters(){
  Wire.beginTransmission(0x68);
  Wire.write(0x43);
  Wire.endTransmission();
  Wire.requestFrom(0x68,6);
  while(Wire.available()<6);
   gyroX =Wire.read()<<8|Wire.read();
   gyroY=Wire.read()<<8|Wire.read();
   gyroZ= Wire.read()<<8|Wire.read();
  
}
