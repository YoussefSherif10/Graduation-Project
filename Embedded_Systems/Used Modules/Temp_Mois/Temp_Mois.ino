#include <OneWire.h> //single master system , low transfer rates (up to 16 kbps), long distances (up to 300 meters).
#include <DallasTemperature.h>
#include <Wire.h>

#define msensor A0 // moisture sensor is connected with the analog pin A0 
#define ONE_WIRE_BUS 5 // Data wire is plugged into digital pin D0 

// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(ONE_WIRE_BUS);  

// Pass oneWire reference to DallasTemperature library
DallasTemperature sensors(&oneWire);


/********************MACROS*******************************/

/********************GLOBAL VARIABLES*********************/
int msvalue = 0; // moisture sensor value. The value is high(1024) at maximum humidity and decreases by moisture

//Definitions

void temp_ms_init(char ms_pin){
  sensors.begin();  
  pinMode(ms_pin, INPUT);
  
}

 int temp_read(void){
  sensors.requestTemperatures();              // Activate Data Line
  /* -55°C to+125°C temperature range , ±0.5°C accuracy from -10°C to +85°C , 
  Each  DS18B20  has  a  unique  64-bit  serial  code */
  return sensors.getTempCByIndex(0);          
}

int ms_read(void){
  return analogRead(msensor);              // <500 is too wet , >750 is dry enough to be watered , Detection depth: 38mm
}

void temp_Smonitor(int temp){
  Serial.print("Temprature : ");
  Serial.print(temp);
  Serial.println(" C");   
}

void ms_Smonitor(int msvalue){
  Serial.print("moisture : ");
  Serial.println(msvalue);
}






void setup() {
  Serial.begin(9600);
temp_ms_init(A0);
}

void loop() {
int x = temp_read();
temp_Smonitor(x);

ms_Smonitor(ms_read());
  
  delay(500);

}
