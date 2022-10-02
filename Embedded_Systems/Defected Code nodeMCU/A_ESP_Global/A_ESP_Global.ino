//INCLUDES
#include <OneWire.h>
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <DHT.h>
#include "RTClib.h"
#include <DallasTemperature.h>




//------ ( Values to be edited )

//DIFINITIONS

#define DHTPIN 6             // DHT11 data pin is connected to Arduino pin 8
#define DHTTYPE DHT11        // DHT11 sensor is used
#define Temp_row 0           // Display Temperature value in the first row
#define Humidity_row 0       // Display Humidity value in the second row
#define UI_pin 6             // Switch pin to enter the UI mode
#define ONE_WIRE_BUS 7


//GLOBALS

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
LiquidCrystal_I2C lcd(0x20,20,4);   //0x20 means 3 pins of I2C address connected to ground


//PH

const int PH_Pin = A0;               //PH pin is A0
unsigned long int Avg_Value; 
int PH_Buf[10],temp;
float PH_Value = 0;
float Cal = 0;
int PH_Ref;
int ms_pin = A0;
//RTC

RTC_DS1307 rtc;
char daysOfTheWeek[7][12] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};

//-------------- "DHT"
DHT dht(DHTPIN, DHTTYPE);   // Initialize DHT library
byte RH;
byte Temp;

//-------------- "ADC initialize"
int ADC_val = 0;

//-------------- Led Strip
const int Red = 2;
const int Green = 3;
const int Blue = 4;

int R_Duty;
int G_Duty;
int B_Duty;
//-------------- Ultrasonic
const int echoPin = 10; // Echo Pin of Ultrasonic Sensor
const int pingPin = 9; // Trigger Pin of Ultrasonic Sensor
long duration, inches, cm;


//___________________________________


//FUNCTIONS

void RTC_Init(void);
void LCD_Init(void);
void DHT_Init(void);
void RT_RH(void);
void Check_Error(void);
//void DHT_Calc(void);
void DHT_Display(void);

void Menu(void);
void Read(void);

void UI_sw(void); // To be created

void ultra_Init(void);
void Read_Ultra(void);

long microsecondsToInches(long microseconds);
long microsecondsToCentimeters(long microseconds);
void Distace_Calc(void);
void Ultra_Display(void);

void Led_Strip();

float PH_Read(void);
void PH_Display(void);
void PH_Cal(void);

void Temp_init();
int temp_read(void);
