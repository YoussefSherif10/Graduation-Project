//Decide how many rows and columns in the LCD
void LCD_Init()
{
  lcd.begin(20, 4);
}

//______________________________________________________________________________________________

//Gives the Controller which pin to use for DHT sensor and start initializes the DHT code
void DHT_Init()           //SETUP
{
  pinMode(DHTPIN,INPUT);
  dht.begin();
}

//______________________________________________________________________________________________

//Reads Temperature and Humidity and assigns the reads to variables
void RT_RH()            //LOOP
{
  delay(200);           // wait 0.2 between readings
  // Read humidity
   RH = dht.readHumidity();
  //Read temperature in degree Celsius
   Temp = dht.readTemperature();
}


// Check if any reads failed and exit early (to try again)
void Check_Error()
{
if (isnan(RH) || isnan(Temp)) {
    lcd.clear();
    lcd.setCursor(5, 0);
    lcd.print("Error");   //For Debugging
    return;
  }
}

//______________________________________________________________________________________________

//Displaying readable values to the LCD for the user
void DHT_Display()
{
  lcd.setCursor(0, Temp_row);
  lcd.print("T = ");
  lcd.print(Temp);
  lcd.print("C");
  lcd.setCursor(10, Humidity_row);
  lcd.print("H = ");
  lcd.print(RH);
  lcd.print("%");
}


//_______________________________________________________________________________________________

void Read(void)
{
  ADC_val = analogRead(A0);
}

/*.............................................................*/

void Menu(void)
{
  lcd.clear();
  lcd.print("UI MODE");  
  Read();
while((ADC_val != 1023)&&(ADC_val != 146))             //BIG NOTE*** Second value should be optimized
{
          Read();
          lcd.setCursor(0,3);
          lcd.print(ADC_val);
}

   if (ADC_val == 1023)
      {
        lcd.clear();
        lcd.setCursor(0,0);
        lcd.print("Callibration ");
        lcd.setCursor(18,0);
        lcd.print("<<");
        lcd.setCursor(0,1);
        lcd.print("Plants");

    while(ADC_val != 0)
    {
        Read();
        while(ADC_val == 0)
        {
          Read();
        }
       
        if((ADC_val < 1000) && (ADC_val > 600))
        {
        
        lcd.setCursor(18,1);
        lcd.print("<<");
        lcd.setCursor(18,0);
        lcd.print("  ");
        }
        
        else if((ADC_val < 600) && (ADC_val > 300))
        {
        lcd.setCursor(18,1);
        lcd.print("  ");
        lcd.setCursor(18,0);
        lcd.print("<<");
        }
        
        else if((ADC_val < 300) && (ADC_val > 100))
        {
          ADC_val = 0;
        }
        
      }
  
    }

    lcd.clear();
}
/*..........................................................................*/

void ultra_Init(void)  // SETUP
{
  pinMode(pingPin, OUTPUT); // initialising pin 3 as output
  pinMode(echoPin, INPUT); // initialising pin 2 as input
}

void Read_Ultra(void)   //LOOP
{
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(10);
  
  digitalWrite(pingPin, LOW);
}


//These functions for converting the read value to INCHES and CM

long microsecondsToInches(long microseconds) // method to covert microsec to inches 
{
 return microseconds / 74 / 2;
}
long microsecondsToCentimeters(long microseconds) // method to covert microsec to centimeters
{
   return microseconds / 29 / 2;
}


void Distance_Calc(void)
{
  duration = pulseIn(echoPin, HIGH); // using pulsin function to determine total time
  inches = microsecondsToInches(duration); // calling method
  cm = microsecondsToCentimeters(duration); // calling method
}



void Ultra_Display(void)
{
  lcd.setCursor(6,1);
  lcd.print(":");
  //lcd.setCursor(8,1);
  //lcd.print(inches);
  //lcd.print("in");
  lcd.setCursor(0,1);
  lcd.print(cm);
  lcd.print("cm");
}


//______________________________________________________________________________________________


void Led_Strip()
{
  R_Duty = (R_Duty * 1023) / 255;
  G_Duty = (G_Duty * 1023) / 255;
  B_Duty = (B_Duty * 1023) / 255;
  
  analogWrite(Red , R_Duty);
  delay(1);
  analogWrite(Green , G_Duty);
  delay(1);
  analogWrite(Blue , B_Duty);
  delay(1);
}

//______________________________________________________________________________________________

float PH_Read(void)
  {
    for(int i=0;i<10;i++) 
  { 
   PH_Buf[i]=analogRead(PH_Pin);
   delay(10);
  }
  for(int i=0;i<9;i++)
  {
   for(int j=i+1;j<10;j++)
    {
     if(PH_Buf[i]>PH_Buf[j])
     {
       temp      = PH_Buf[i];
       PH_Buf[i] = PH_Buf[j];
       PH_Buf[j] = temp;
     }
    }
   }
   
  Avg_Value=0;
  
  for(int i=2;i<8;i++)
    {Avg_Value += PH_Buf[i]/6;}
    
   float PH_Vol= ((float)Avg_Value*5.0) / 1024;
   PH_Value = -5.70 * PH_Vol + (21.34 + Cal);

   return PH_Value;
    
  }

/*..........................................................................*/

void PH_Cal(void)
{
  lcd.clear();
  lcd.print("Calibrating PH .....");
 
  Cal = 7 - PH_Read();
}
  
/*..........................................................................*/

void PH_Display(void)
{
  lcd.setCursor(0,0);
  lcd.print("PH = ");
  lcd.print(PH_Value);
}

/*..........................................................................*/

void Temp_init()
{
sensors.begin();
}

/*..........................................................................*/

 void temp_ms_init(void){
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
  return analogRead(ms_pin);              // <500 is too wet , >750 is dry enough to be watered , Detection depth: 38mm
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


//______________________________________________________________________________________________

void RTC_Init()
{
if (! rtc.begin()) 
  {
    lcd.print("Couldn't find RTC");
    while (1);
  }
  if (! rtc.isrunning()) 
  {
    lcd.print("RTC is NOT running!");
  }
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));//auto update from computer time
    //rtc.adjust(DateTime(2021, 4, 27, 6, 06, 0));// to set the time manualy 
}

void RTC_Display()
{
      DateTime now = rtc.now();
    lcd.setCursor(0, 3);
    lcd.print("TIME");
    lcd.print(" ");
    lcd.print(now.hour());
    lcd.print(':');
    lcd.print(now.minute());
    lcd.print(':');
    lcd.print(now.second());
    lcd.print("  ");

    lcd.setCursor(0, 2);
    lcd.print("DATE");
    lcd.print(" ");
    //lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
    //lcd.print(" ");
    lcd.print(now.day());
    lcd.print('/');
    lcd.print(now.month());
    lcd.print('/');
    lcd.print(now.year());
    lcd.print("  ");
}
//______________________________________________________________________________________________
