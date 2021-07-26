#include <Wire.h>
# define I2C_SLAVE_ADDRESS 0x04

int analogPin1 = A3; 
int analogPin2 = A2; 
int val1 = 0;  
int val2 = 0;  

void setup()
{
  Wire.begin(I2C_SLAVE_ADDRESS);
  Serial.begin(9600); 
  delay(1000);               
  Wire.onRequest(requestEvents);
}

void loop() 
{
  val1 = analogRead(analogPin1);  // read the input pin
  val2 = analogRead(analogPin2);  // read the input pin
  Serial.println(val1);
  Serial.println(val2);

}

void requestEvents()
{
  Wire.write(val1);
  Wire.write(val2);
}
