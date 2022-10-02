void WiFi_Init(void)
{
  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP(wifi_name, wifi_password);
}


void Get_Data(void)
{
  if ((WiFiMulti.run() == WL_CONNECTED)) {

    std::unique_ptr<BearSSL::WiFiClientSecure>client(new BearSSL::WiFiClientSecure);

    client->setFingerprint(fingerprint);
    // Or, if you happy to ignore the SSL certificate, then use the following line instead:
    // client->setInsecure();

    HTTPClient https;

    Serial.print("[HTTPS] begin...\n");
    if (https.begin(*client, "https://automated-vegetation-system.piemaker1.repl.co/api/hello")) {  // HTTPS

      Serial.print("[HTTPS] GET...\n");
      // start connection and send HTTP header
      int httpCode = https.GET();

      // httpCode will be negative on error
      if (httpCode > 0) {
        // HTTP header has been send and Server response header has been handled
        Serial.printf("[HTTPS] GET... code: %d\n", httpCode);

        // file found at server
        if (httpCode == HTTP_CODE_OK || httpCode == HTTP_CODE_MOVED_PERMANENTLY) {
          String payload = https.getString();
          Serial.println(payload);

          if(payload == "2")
          Serial.println("Successful");
          stage = 2;
        }
      } else {
        Serial.printf("[HTTPS] GET... failed, error: %s\n", https.errorToString(httpCode).c_str());
      }

      https.end();
    } else {
      Serial.printf("[HTTPS] Unable to connect\n");
    }
  }

  Serial.println("Wait 10s before next round...");
  delay(2000);
}

void Post_Data(String Module, int x)
{
  if ((WiFiMulti.run() == WL_CONNECTED)) {

    std::unique_ptr<BearSSL::WiFiClientSecure>client(new BearSSL::WiFiClientSecure);

    client->setFingerprint(fingerprint);
    // Or, if you happy to ignore the SSL certificate, then use the following line instead:
    // client->setInsecure();

    HTTPClient https;

     String A = "{\"modelName\" : \"";
    String B = Module;
    String F = "\", \"value\" : \"";
    String C = String(x);
    String D = "\" , \"date\" : \"";
    String y= String(year_now());
    String m= String(month_now());
    String d= String(day_now());
    String h= "6";
    String minu = "00";
    String E= "\"}";
    String ALL= A + B + F + C + D + y + "-" + m + "-" + d + " " + h + ":" + minu + E;
    Serial.print(ALL);
       if(https.begin(*client ,"https://automated-vegetation-system.piemaker1.repl.co/api/importData")){
  https.addHeader("Content-Type", "application/json");
  int httpResponseCode = https.POST(ALL);
 
   if(httpResponseCode == 200){
 
    Serial.println("Data Inserted");         
   }
      https.end();
    } else {
      Serial.printf("[HTTPS] Unable to connect\n");
    }
  }

  Serial.println("Wait 2s before next round...");
  delay(2000);  
}
                  //***************** UltraSonic *********************//


void Ultra_Init(void){

  pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
  pinMode(echoPin, INPUT); // Sets the echoPin as an Input

}

int Ultra_read(void){
  
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

// Calculating the distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
return distance;
}


                  //***************** DHT *********************//

void DHT_init(){
  dht.begin();
}

void DHT_read(void)
{
    h = dht.readHumidity();
    t = dht.readTemperature();        
}

                  //***************** RTC *********************//

void RTC_Init(void){
  RTC.begin();  // Init RTC
  RTC.adjust(DateTime(__DATE__, __TIME__));  // Time and date is expanded to date and time on your computer at compiletime
}

void RTC_Display(void){
  DateTime now = RTC.now();
 
  Serial.print(now.year(), DEC);
  Serial.print('/');
  Serial.print(now.month(), DEC);
  Serial.print('/');
  Serial.print(now.day(), DEC);
  Serial.print(' ');
  Serial.print(now.hour(), DEC);
  Serial.print(':');
  Serial.print(now.minute(), DEC);
  Serial.print(':');
  Serial.print(now.second(), DEC);
  Serial.println();
}

int hour_now(){
  DateTime now = RTC.now();
  return now.hour();
}

int minute_now(){
  DateTime now = RTC.now();
  return now.minute();
}

int second_now(){
  DateTime now = RTC.now();
  return now.second();
}

int day_now(){
  DateTime now = RTC.now();
  return now.day();
}

int year_now(){
  DateTime now = RTC.now();
  return now.year();
}

int month_now(){
  DateTime now = RTC.now();
  return now.month();
}

                  //***************** Temp&Moisture *********************//

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

                  //***************** PH sensor *********************//


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

  void PH_Cal(void)
{
  Cal = 7 - PH_Read();
}

                  //***************** LED Strip *********************//


void Set_Led(int gBright,int rBright,int bBright)
{
  analogWrite(RED_LED, rBright);
  analogWrite(BLUE_LED, bBright);
  analogWrite(GREEN_LED, gBright);
}


void Take_image(void)
{
  //Take image every 24 hours
if(image_time == hour_now() && (current_day != day_now()))
{
  s.write("Take image");
  delay(1000);
  image_time = hour_now();
  current_day = day_now();
  image_time = (image_time + 24) % 24;
}
}

                  //***************** Level Check *********************//


void check_level(void)
{
if(Ultra_read() <= 10)
  {
    level = true;
  }
  else if (Ultra_read() > 15)
  {level = false;}
}

                  //***************** Water Filling or decreasing *********************//


void Water_Control(void)
{
  if ((water_hour == hour_now()) && (level == false))
  {
    s.write("pump_1 on");
    delay(1000);
    while(Ultra_read() < 25);
    s.write("pump_1 off");
    delay(1000);
    water_hour = hour_now();
    water_minute = minute_now() - 1;
    water_hour = (water_hour + 18) % 24;
    level = true;
  }
  else if((water_hour == hour_now()) && (level == true))
    {
      s.write("pump_2 on");
      delay(1000);
      while(Ultra_read() > 20);
      s.write("pump_2 off");
      delay(1000);
      water_hour = hour_now();
      water_minute = minute_now() - 1;
      water_hour = (water_hour + 6) % 24;
      level = false;
    }
}

                  //***************** LED timing and setting *********************//


void LED_Control(int stage)
{
  if(hour_now() == 5 && minute_now() == 0)
  {
    if (stage == 1)
    {
    Set_Led(255, 255, 255); 
    }
    else
    Set_Led(150,200,50);
  } 
  else if (hour_now() == 19 && minute_now() == 0)
  {
    Set_Led(0,0,0);
  }

}

                  //***************** Setting initial timings *********************//


void Timing_Init(void)
{
  image_time = water_hour = hour_now();
  water_minute = minute_now();
  current_day = 1 + day_now();
  image_time = (image_time + 24) % 24;
  EC_minute = minute_now();
}

                  //***************** EC actions *********************//


void EC_control(void)
{
  if(minute_now() == EC_minute)
    {
    if(EC >= pure_min && EC <= pure_max)
    {
      s.write("Pump A on");
      delay(1000);
      seconds_counter = (second_now() + 7) % 60;
      while(seconds_counter != second_now());
      s.write("Pump A off");
      minutes_counter = (minute_now() + 5) % 60;
      while(minutes_counter != minute_now());
      s.write("Pump B on");
      delay(1000);
      seconds_counter = (second_now() + 7) % 60;
      while(seconds_counter != second_now());
      s.write("Pump B off");
      delay(1000);
      EC_minute = (minute_now() + 59) % 60;
    }
    else if(EC < min_EC)
    {
      s.write("Pump A on");
      delay(1000);
      seconds_counter = (second_now() + 2) % 60;
      while(seconds_counter != second_now());
      s.write("Pump A off");
      minutes_counter = (minute_now() + 5) % 60;
      while(minutes_counter != minute_now());
      s.write("Pump B on");
      delay(1000);
      seconds_counter = (second_now() + 2) % 60;
      while(seconds_counter != second_now());
      s.write("Pump B off");
      delay(1000);
      EC_minute = (minute_now() + 30) % 60;
    }
    else if (EC > max_EC)
    {
      s.write("Pump 2 on");
      delay(1000);
      while(Ultra_read() < 15);
      s.write("Pump 2 off");
      delay(1000);

      s.write("Pump 1 on");
      delay(1000);
      while(Ultra_read() > 10);
      s.write("Pump 1 off");
      delay(1000);
      EC_minute = (minute_now() + 30) % 60;
    }
  else{
    EC_minute = (minute_now() + 59) % 60;
  }
    }
}

                  //***************** Checking time to upload *********************//


void Time_Upload(void)
{
  if(hour_now() == PH_hour)
  {
    Post_Data("PH",PH);
    PH_hour = (PH_hour + 4) % 24;
  }

  if(hour_now() == EC_hour)
  {
    Post_Data("ElectricConductrivity",EC);
    EC_hour = (EC_hour + 4) % 24;
  }

  if(hour_now() == DHT_hour)
  {
    DHT_read();
    Post_Data("OuterTemp",t);
    delay(1000);
    Post_Data("Humidity",h);
    DHT_hour = (DHT_hour + 1) % 24;
  }

  if(hour_now() == Temp_hour)
  {
    Post_Data("Temperature", temp_read());
    Temp_hour = (Temp_hour + 1) % 24;
  }
}
