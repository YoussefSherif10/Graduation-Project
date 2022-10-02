void setup() {
  // set up the LCD's number of columns and rows
   lcd.init();
   //pinMode(UI_pin , INPUT_PULLUP);
   //Sets DHT pin and initializes DHT library
   DHT_Init();
   RTC_Init();

}

void loop() {

lcd.clear();
//DHT functions
  RT_RH();           //Read Temp. & Humidity values
  Check_Error();    //checks for missings or errors in DHT readings
  DHT_Display();    //Displays Temp. & Humidity readings on LCD

//UltraSonic Functions
  Read_Ultra();
  Distance_Calc();  
  Ultra_Display();

  
  RTC_Display();
  lcd.setCursor(8,1);
  lcd.print("T_in = ");
  lcd.print(26);
  delay(1000);

}
