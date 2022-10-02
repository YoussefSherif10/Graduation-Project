#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClientSecureBearSSL.h>

#define wifi_name "Menem"
#define wifi_password "norton1998"

// Fingerprint for demo URL, expires on June 2, 2021, needs to be updated well before this date
const uint8_t fingerprint[20] = {0x96, 0xbe, 0x79, 0x0a, 0xb3, 0x6e, 0x38, 0x87, 0xcb, 0x5b, 0x8a, 0x58, 0xa9, 0xf5, 0xc9, 0x92, 0x99, 0x3f, 0xdf, 0xc0};
ESP8266WiFiMulti WiFiMulti;
int x = 5;
void setup() {

  Serial.begin(115200);
  // Serial.setDebugOutput(true);

  Serial.println();
  Serial.println();
  Serial.println();

  for (uint8_t t = 4; t > 0; t--) {
    Serial.printf("[SETUP] WAIT %d...\n", t);
    Serial.flush();
    delay(1000);
  }

  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP(wifi_name, wifi_password);
}

void loop() {
  // wait for WiFi connection
  if ((WiFiMulti.run() == WL_CONNECTED)) {

    std::unique_ptr<BearSSL::WiFiClientSecure>client(new BearSSL::WiFiClientSecure);

    client->setFingerprint(fingerprint);
    // Or, if you happy to ignore the SSL certificate, then use the following line instead:
    // client->setInsecure();
//Post_Data("ElectricConductivity", EC25);
    HTTPClient https;

    String A = "{\"modelName\" :";
    String B = "\"ElectricConductivity\", \"value\" : \"";
    String C = String(x);
    String D = "\" , \"date\" : \"";
    String y= "2021";
    String m= "9";
    String d= "25";
    String h= "6";
    String minu = "00";
    String E= "\"}";
    String ALL= A + B + C + D + y + "-" + m + "-" + d + " " + h + ":" + minu + E;
    Serial.print(ALL);
       if(https.begin(*client ,"https://automated-vegetation-system.piemaker1.repl.co/api/importData")){
  https.addHeader("Content-Type", "application/json");
  int httpResponseCode = https.POST(ALL);
  //int httpResponseCode = https.POST("{\"modelName\" : \"PH\", \"value\" : \"4\" , \"date\" : \"2021-12-23 5:30\"}"); //year_now();
 
   if(httpResponseCode>0){
 
    String response = https.getString();   
 
    Serial.println(httpResponseCode);
    Serial.println(response);          
   }
   
   else{
 
    Serial.print("Error on sending POST Request: ");
    Serial.println(httpResponseCode);
 
   }

      https.end();
    } else {
      Serial.printf("[HTTPS] Unable to connect\n");
    }
  }

  Serial.println("Wait 10s before next round...");
  delay(2000);  
}
