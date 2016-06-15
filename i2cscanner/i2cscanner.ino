/* Version 1
    This program (or code that looks like it)
    can be found in many places.
    For example on the Arduino.cc forum.
    The original author is not known.

 Orginal I2C Scanner code Written by Nick Gammon
 Date: 20th April 2011

 Version 1.2
 Updated to include device names and modules if known
 Updated to include unknown devices
 May 4 2016 by Craig Worden

 Version 1.3
 Added new sensors and descriptions
 May 28 2016 by Craig Worden
  
 */
#include <Wire.h>

void setup() {
  Serial.begin (9600);
  // Leonardo: wait for serial port to connect
  while (!Serial) {
    }
  Serial.println ();
  Serial.println ("I2C scanner. Scanning ...");
  byte count = 0;
  
  Wire.begin();
  for (byte i = 1; i < 127; i++) {
    Wire.beginTransmission (i);
    if (Wire.endTransmission () == 0) {
      Serial.print ("Found address: DEC:(");
      Serial.print (i, DEC);
      Serial.print (") Hex (0x");
      Serial.print (i, HEX);
      Serial.print (") ");
if (i == 30){
      Serial.println("HMC5883L/HMC5983 (Mag) (GY-801)(GY-271)/(GY-282)");
}
else if (i == 39){
      Serial.println("4x20 (LCD)");
}
else if (i == 63){
      Serial.println("IIC/I2C Serial Interface Adapter Board for LCD");
}
else if (i == 83){
      Serial.println("ADXL345 (Accl) (GY-291)/(GY-801)");
}
else if (i == 87){
      Serial.println("AT24C32 (RTC EEProm) (GS-042)");
}
else if (i == 96){
      Serial.println("TEA5767 (FM Radio Module) (V4.0)");
}
else if (i == 104){
      Serial.println("DS1307 (RTC) or MPU6050 (GY-521)");
}
else if (i == 105){
      Serial.println("L3G4200D (Gyro)(GY-801)");
}
else if (i == 119){
      Serial.println("BMP085/BMP180 (Baro)(GY-801)/(GY-65)/(GY-68)");
}

else if (i != 30 and i != 39 and i != 63 and i != 83 and i != 87 and i != 96 and i != 104 and i != 105 and i != 119){
      Serial.println("Unknown Device");
}

      count++;
      }
  }
  Serial.print("Done.");
  Serial.print("Found ");
  Serial.print(count, DEC);
  Serial.print(" device(s).");
}

void loop(){
  }

