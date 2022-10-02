
void WiFi_Init(void)
{ WiFi.begin(ssid, password);
 WiFi.mode(WIFI_STA);
 
  Serial.print("Connecting");
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(500);
    Serial.print(".");
  }
  Serial.println();

  Serial.print("Connected, IP address: ");
  Serial.println(WiFi.localIP());
}
/////////////////////////////////////////////////////////////////////
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

////////////////////////////////////////////////////////////////////////////////////////////////////////

void pump1_on(void)
{ digitalWrite(pump1 , HIGH);}
void pump1_off(void)
{ digitalWrite(pump1 , LOW );}

void pump2_on(void)
{ digitalWrite(pump2 , HIGH);}
void pump2_off(void)
{ digitalWrite(pump2 , LOW );}

void pumpA_on(void)
{ digitalWrite(pumpA , HIGH);}
void pumpA_off(void)
{ digitalWrite(pumpA , LOW));}

void pumpB_on(void)
{ digitalWrite(pumpB , HIGH);}

void pumpB_off(void)
{ digitalWrite(pumpB , LOW));}
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
 void Camera_init (void)
 { esp_err_t err = esp_camera_init(&config);
  if (err != ESP_OK) {
    Serial.printf("Camera init failed with error 0x%x", err);
    ESP.restart();
  } }

 /*void capture()
 {camera_fb_t * fb = NULL;
  fb = esp_camera_fb_get();
  if(!fb) 
  { Serial.println("Camera capture failed");
    delay(1000);
    ESP.restart();}
  uint32_t imageLen = fb->len;
  String im = String(imageLen);
  Serial.println("Image Length: "+im+" Bytes");
  esp_camera_fb_return(fb);
}*/
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////
String take_send_photo() {
  String getAll;
  String getBody;

  camera_fb_t * fb = NULL;
  fb = esp_camera_fb_get();
  if(!fb) {
    Serial.println("Camera capture failed");
    delay(1000);
    ESP.restart();
  }
  
  Serial.println("Connecting to server: " + YousefServer);

  if (espClient.connect(YousefServer.c_str(), httpPort)) {
    Serial.println("Connection successful!");    
    String head = "----GraduationProject\r\nContent-Disposition: form-data; name=\"imageFile\"; filename=\"esp32-cam.jpg\"\r\nContent-Type: image/jpeg\r\n\r\n";
    String tail = "\r\n----GraduationProject\r\n";

    uint32_t imageLen = fb->len;
    uint32_t extraLen = head.length() + tail.length();
    uint32_t totalLen = imageLen + extraLen;
  
    espClient.println("POST " + imgPath + " HTTP/1.1");
    espClient.println("Host: " + YousefServer);
    espClient.println("Content-Length: " + String(totalLen));
    espClient.println("Content-Type: multipart/form-data; boundary=----GraduationProject");
    espClient.println();
    espClient.print(head);
  
    uint8_t *fbBuf = fb->buf;
    size_t fbLen = fb->len;
    /*for (size_t n=0; n<fbLen; n=n+1024) {
      if (n+1024 < fbLen) {
        espClient.write(fbBuf, 1024);
        fbBuf += 1024;
      }
      else if (fbLen%1024>0) {
        size_t remainder = fbLen%1024;
        espClient.write(fbBuf, remainder);
      }
    }*/
    espClient.write(fbBuf, fbLen);
    
    espClient.print(tail);
    
    esp_camera_fb_return(fb);
    
    int timoutTimer = 10000;
    long startTimer = millis();
    boolean state = false;
    
    while ((startTimer + timoutTimer) > millis()) {
      Serial.print(".");
      delay(100);      
      while (espClient.available()) {
        char c = espClient.read();
        if (c == '\n') {
          if (getAll.length()==0) { state=true; }
          getAll = "";
        }
        else if (c != '\r') { getAll += String(c); }
        if (state==true) { getBody += String(c); }
        startTimer = millis();
      }
      if (getBody.length()>0) { break; }
    }
    Serial.println();
    espClient.stop();
    Serial.println(getBody);
  }
  else {
    getBody = "Connection to " + YousefServer +  " failed.";
    Serial.println(getBody);
  }
  return getBody;
}
///////////////////////////////////////////////////////////////////////////
