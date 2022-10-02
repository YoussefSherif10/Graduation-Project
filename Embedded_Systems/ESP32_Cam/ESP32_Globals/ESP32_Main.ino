void setup(){
 Serial.begin(115200);
 WiFi_Init();
 Ultra_Init();
 Cam_Init();
}



void loop(){
  Serial.print("Received : ");
  if (Serial.available()) {
  Serial.print(char(Serial.read()));
  
  
  if(Serial.read== "Pump1_on"){
  Pump1_on();
  if ( Ultra_read() >= 10)
    {
    Pump1_off();
    }
  }
  else if(Serial.read== "Pump1_off")
  { Pump1_off(); }
  else if(Serial.read== "Pump2_on")
  { Pump2_on(); }
  else if(Serial.read== "Pump2_off")
  { Pump2_off(); }
  else if(Serial.read== "PumpA_on")
  { PumpA_on(); }
  else if(Serial.read== "PumpA_off")
  { PumpA_off(); }
  else if(Serial.read== "PumpB_on")
  { PumpB_on(); }
  else if(Serial.read== "PumpB_off")
  { PumpB_off(); }
  else if (Serial.read== "take_send_photo")
  {  take_send_photo(); }
  }
  /*if(psramFound()){
    config.frame_size = FRAMESIZE_SVGA;
    config.jpeg_quality = 10;  
    config.fb_count = 2;
  } else {
    config.frame_size = FRAMESIZE_CIF;
    config.jpeg_quality = 12;  
    config.fb_count = 1;
  }*/
}
  
