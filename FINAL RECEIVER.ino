#include "FirebaseESP8266.h"
#include <ESP8266WiFi.h>

String apiKey = "9OW9IHEU4VBFV860"; 
const char* server = "api.thingspeak.com";
WiFiClient client;


#define FIREBASE_HOST "lifi-bc814-default-rtdb.firebaseio.com/" 
#define FIREBASE_AUTH "neqeIvidE4vUqtHl3QmSOywscBgNPja764UKyyyh"
#define WIFI_SSID "Honor"
#define WIFI_PASSWORD "12345123"


FirebaseData firebaseData;
FirebaseData ledData;

FirebaseJson json;

#define SOLARPIN A0
#define THRESHOLD 10
int count = 0;
int ambientReading = 0;
int flag = 0;
int pos = 0;

void setup() {
  pinMode(SOLARPIN, INPUT);
  Serial.begin(9600);

  ambientReading  = analogRead(SOLARPIN);
  //average = sensorValue;

    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(300);
  }
  Serial.println();
  Serial.print("Connected with IP: ");
  Serial.println(WiFi.localIP());
  Serial.println();

  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

}

void loop() {

  int reading = analogRead(SOLARPIN);
  int bits[8];



  if (reading > ambientReading + THRESHOLD) {
    count++;
    for (int i = 0; i < 8; i++) {
      if (analogRead(SOLARPIN) > ambientReading + THRESHOLD) {
        bits[i] = 1;
        flag++;
      }
      else {
        bits[i] = 0;
      }
      delay(10);
    }

    //for (int i = 0; i < 8; i++) {
    // Serial.print(bits[i]);
    //}
    if (count % 10 == 0) {
    //  if ( flag < 8 ) {
    //    pos = 0;
     //   Serial.println(pos);
     //   Firebase.setFloat(firebaseData, "/FirebaseIOT/pos", pos);
      //  flag = 0;
      //}
      if ( (flag >= 9) && (flag < 21) ) {
        pos = 1;
        Serial.println(pos);
         if (Firebase.setFloat(firebaseData, "/FirebaseIOT/pos", pos))
              {
                   Serial.println("PASSED");
                   Serial.println("------------------------------------");
                   Serial.println();
                   flag = 0;

              }
         else
              {
                   Serial.println("FAILED");
                   Serial.println("REASON: " + firebaseData.errorReason());
                  Serial.println("------------------------------------");
                  Serial.println();
                  flag = 0;

              }
          if (client.connect(server,80)) {
              String postStr = apiKey;
              postStr +="&field1=";
              postStr += String(pos);
              postStr += "\r\n\r\n";
 
              client.print("POST /update HTTP/1.1\n");
              client.print("Host: api.thingspeak.com\n");
              client.print("Connection: close\n");
              client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
              client.print("Content-Type: application/x-www-form-urlencoded\n");
              client.print("Content-Length: ");
              client.print(postStr.length());
              client.print("\n\n");
              client.print(postStr);
              Serial.println("ok");
          }
         client.stop();

      }
      if ( (flag >= 21) && (flag < 43) ) {
        pos = 2;
        Serial.println(pos);
        if (Firebase.setFloat(firebaseData, "/FirebaseIOT/pos", pos))
              {
                   Serial.println("PASSED");
                   Serial.println("------------------------------------");
                   Serial.println();
                   flag = 0;

              }
         else
              {
                   Serial.println("FAILED");
                   Serial.println("REASON: " + firebaseData.errorReason());
                  Serial.println("------------------------------------");
                  Serial.println();
                  flag = 0;

              }
         if (client.connect(server,80)) {
              String postStr = apiKey;
              postStr +="&field1=";
              postStr += String(pos);
              postStr += "\r\n\r\n";
 
              client.print("POST /update HTTP/1.1\n");
              client.print("Host: api.thingspeak.com\n");
              client.print("Connection: close\n");
              client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
              client.print("Content-Type: application/x-www-form-urlencoded\n");
              client.print("Content-Length: ");
              client.print(postStr.length());
              client.print("\n\n");
              client.print(postStr);
              Serial.println("ok");

          }
         client.stop();

      }
     // if ( (flag > 54) && (flag < 75) ) {
       //pos = 3;
        //Serial.println(pos);
        //if (Firebase.setFloat(firebaseData, "/FirebaseIOT/pos", pos))
          //    {
            //       Serial.println("PASSED");
              //     Serial.println("------------------------------------");
                //   Serial.println();
              //}
         //else
           //   {
             //      Serial.println("FAILED");
              //     Serial.println("REASON: " + firebaseData.errorReason());
               //   Serial.println("------------------------------------");
                //  Serial.println();
              //}
        //flag = 0;

      //}
      if ( flag > 46 ) {
        pos = 3;
        Serial.println(pos);
        if (Firebase.setFloat(firebaseData, "/FirebaseIOT/pos", pos))
              {
                   Serial.println("PASSED");
                   Serial.println("------------------------------------");
                   Serial.println();
                   flag = 0;

              }
         else
              {
                   Serial.println("FAILED");
                   Serial.println("REASON: " + firebaseData.errorReason());
                  Serial.println("------------------------------------");
                  Serial.println();
                  flag = 0;

              }

        if (client.connect(server,80)) {
              String postStr = apiKey;
              postStr +="&field1=";
              postStr += String(pos);
              postStr += "\r\n\r\n";
 
              client.print("POST /update HTTP/1.1\n");
              client.print("Host: api.thingspeak.com\n");
              client.print("Connection: close\n");
              client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n");
              client.print("Content-Type: application/x-www-form-urlencoded\n");
              client.print("Content-Length: ");
              client.print(postStr.length());
              client.print("\n\n");
              client.print(postStr);
              Serial.println("ok");

          }
         client.stop();
      }
  }
  }
}
