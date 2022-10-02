void setup(){
  Serial.begin(9600);
  Ultra_Init();
  DHT_init();
  RTC_Init();
  temp_ms_init();
  s.begin(9600);
  Timing_Init();
  WiFi_Init();

  Serial.println("HI Display_Time");
}

void loop(){

//Stage 1 code
Serial.println(second_now());
  if(stage == 1)
  {
    Take_image();     //Every 24 hours
    DHT_read();
    check_level();    //boolean level true or false
    Water_Control();  //Fill every 18hrs, Reduce every 6hrs
    Temperature = temp_read();
    LED_Control(stage);    //Turn on 14hrs, turn off 10hrs
    //Here the GET request....
    Get_Data();
    Time_Upload();
  }

//Stage 2 code
if (stage == 2)
{
    Take_image();
    check_level();
    if (level == true)
    Temperature = temp_read();
    else{
      s.write("Pump 1 on");
      delay(1000);
      while(Ultra_read() > 10);
      s.write("Pump 1 off");
      delay(1000);
    }
    EC = ms_read();
    EC_control();
    Temperature = temp_read();
    LED_Control(stage);
    DHT_read();
    Time_Upload();
}

}
