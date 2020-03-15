// https://www.javacodegeeks.com/2019/07/esp8266-esp32-firebase-realtime-database-iot.html

#include <ESP8266WiFi.h>
#include "FirebaseESP8266.h"

#define PIN D1
#define NUM_LEDS 8

int d3 = 0;
int d4 = 2;
 
const char* ssid = "COT-1";
const char* password = "cot123456";
 
FirebaseData firebaseData;
 
void setup() {  
  Serial.begin(115200);
  delay(10);  
  pinMode(d3, OUTPUT);
  digitalWrite(d3, LOW);
  
  connectWifi();
  Firebase.begin("https://playgroundprojects-fe804.firebaseio.com/", "C0bYvtq8RE8bgoJcVBRiP8DiRTHqdwE4chkjmh0V");
}

void loop() {

  if (Firebase.getInt(firebaseData, "/open")) {
   if  (firebaseData.dataType() == "int") {
      int val = firebaseData.intData();
      if (val == 0) {
        digitalWrite(d3, HIGH);
      } else
      {
        digitalWrite(d3, LOW);
      }
    }
  }
 /*
  if (Firebase.getInt(firebaseData, "/red")) {
   if  (firebaseData.dataType() == "int") {
      int val = firebaseData.intData();
      if (val != redValue) {
        redValue = val;
        setLedColor();
      }
    }
  }
 
  if (Firebase.getInt(firebaseData, "/green")) {
   if  (firebaseData.dataType() == "int") {
      int val = firebaseData.intData();
      if (val != greenValue) {
        greenValue = val;
        setLedColor();
      }
    }
  }
 
  if (Firebase.getInt(firebaseData, "/blue")) {
   if  (firebaseData.dataType() == "int") {
      int val = firebaseData.intData();
      if (val != blueValue) {
        blueValue = val;
        setLedColor();
      }
    }
  }
  */
}

void connectWifi() {
  // Let us connect to WiFi
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
 
  Serial.println(".......");
  Serial.println("WiFi Connected....IP Address:");
  Serial.println(WiFi.localIP());
}
