#include <Wire.h> 
#include <LiquidCrystal_I2C.h>



LiquidCrystal_I2C lcd(0x20,20,4);

const int PH_Pin = A1; 
int sensorValue = 0; 
unsigned long int avgValue; 
float b;
int buf[10],temp;
void setup() {
lcd.init();
}
void loop() {
  
for(int i=0;i<10;i++) 
{ 
 buf[i]=analogRead(PH_Pin);
 delay(10);
}
for(int i=0;i<9;i++)
{
 for(int j=i+1;j<10;j++)
 {
 if(buf[i]>buf[j])
 {
 temp=buf[i];
 buf[i]=buf[j];
 buf[j]=temp;
 }
 }}
avgValue=0;
for(int i=2;i<8;i++)
avgValue+=buf[i];
float pHVol=(float)avgValue*5.0/1024/6;
float phValue = -5.70 * pHVol + 21.34;
lcd.setCursor(0,3);
lcd.print("sensor = ");
lcd.print(phValue);
delay(20);
}
