                          //      INCLUDES        //

#include <Wire.h> // Library for I2C communication
#include <SPI.h>  // not used here, but needed to prevent a RTClib compile error
#include "RTClib.h"
//#include <LiquidCrystal_I2C.h> // Library for LCD
#include "DHT.h"        // including the library of DHT11 temperature and humidity sensor
#include <OneWire.h> //single master system , low transfer rates (up to 16 kbps), long distances (up to 300 meters).
#include <DallasTemperature.h>
#include<SoftwareSerial.h> //Included SoftwareSerial Library


#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecureBearSSL.h>


//      Definitions       //

#define DHTTYPE DHT11   // DHT 11
#define dht_dpin 2
#define Switch_pin 14
#define msensor A0 // moisture sensor is connected with the analog pin A0 
#define ONE_WIRE_BUS 0 // Data wire is plugged into digital pin D0 
#define PH_Pin  A0               //PH pin is A0
#define ms_pin A0
#define RED_LED 12
#define GREEN_LED 13
#define BLUE_LED 15
#define wifi_name "TROY"
#define wifi_password "norton1998"

//        GLOBALS         //

const uint8_t fingerprint[20] = {0x96, 0xbe, 0x79, 0x0a, 0xb3, 0x6e, 0x38, 0x87, 0xcb, 0x5b, 0x8a, 0x58, 0xa9, 0xf5, 0xc9, 0x92, 0x99, 0x3f, 0xdf, 0xc0};

const int trigPin = 14; 
const int echoPin = 16; 

int gBright = 0;
int rBright = 0;
int bBright = 0;


unsigned long int Avg_Value;
int PH_Buf[10],temp;
float PH_Value = 0;
float Cal = 0;
int PH_Ref;
int msvalue = 0; // moisture sensor value. The value is high(1024) at maximum humidity and decreases by moisture
float h;
float t;

int Temperature;
float PH;
int EC;

int LED_hour;
int LED_minute;
int image_time;
int water_hour;
int water_minute;
int water_second;
int current_day;
int seconds_counter;
int minutes_counter;
int EC_minute;

int PH_hour;
int Temp_hour;
int EC_hour;
int DHT_hour;

float max_EC = 3;
float min_EC = 2;
float pure_max = 0.7;
float pure_min = 0.1;

int stage = 1;

boolean level = false;
//-------------- "ADC initialize"
int ADC_val = 0;


long duration;
int distance;

DHT dht(dht_dpin, DHTTYPE); 
 
RTC_DS1307 RTC;     // Setup an instance of DS1307 naming it RTC

// Setup a oneWire instance to communicate with any OneWire device
OneWire oneWire(ONE_WIRE_BUS);  

// Pass oneWire reference to DallasTemperature library
DallasTemperature sensors(&oneWire);

SoftwareSerial s(3,1);  //Started SoftwareSerial at RX and TX pin of ESP8266/NodeMCU

ESP8266WiFiMulti WiFiMulti;
