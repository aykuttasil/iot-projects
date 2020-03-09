// https://www.javacodegeeks.com/2019/07/esp8266-esp32-firebase-realtime-database-iot.html

#include <FirebaseESP8266.h>
#include <ESP8266WiFi.h>

#define PIN_WIRE_SDA (4)
#define PIN_WIRE_SCL (5)
 
static const uint8_t SDA = PIN_WIRE_SDA;
static const uint8_t SCL = PIN_WIRE_SCL;
 
static const uint8_t LED_BUILTIN = 16;
static const uint8_t BUILTIN_LED = 16;
 
static const uint8_t D0   = 16;
static const uint8_t D1   = 5;
static const uint8_t D2   = 4;
static const uint8_t D3   = 0;
static const uint8_t D4   = 2;
static const uint8_t D5   = 14;
static const uint8_t D6   = 12;
static const uint8_t D7   = 13;
static const uint8_t D8   = 15;
static const uint8_t D9   = 3;
static const uint8_t D10 = 1;

int ledPin = 13;
const char *ssid = "a2a";
const char *password = "aaAA1244*";

FirebaseData firebaseData;

void setup()
{
    Serial.begin(115200);
    pinMode(ledPin, OUTPUT);
    connectWifi();
    Firebase.begin("https://playgroundprojects-fe804.firebaseio.com/", "C0bYvtq8RE8bgoJcVBRiP8DiRTHqdwE4chkjmh0V");
}

void loop()
{

    if (Firebase.getInt(firebaseData, "/open"))
    {
        if (firebaseData.dataType() == "int")
        {
            int val = firebaseData.intData();
            if (val == 1)
            {
                digitalWrite(ledPin, HIGH);
            }
            else
            {
                digitalWrite(ledPin, LOW);
            }
        }
    }

    /*
    if (Firebase.getInt(firebaseData, "/red"))
    {
        if (firebaseData.dataType() == "int")
        {
            int val = firebaseData.intData();
            if (val != redValue)
            {
                redValue = val;
                setLedColor();
            }
        }
    }

    if (Firebase.getInt(firebaseData, "/green"))
    {
        if (firebaseData.dataType() == "int")
        {
            int val = firebaseData.intData();
            if (val != greenValue)
            {
                greenValue = val;
                setLedColor();
            }
        }
    }

    if (Firebase.getInt(firebaseData, "/blue"))
    {
        if (firebaseData.dataType() == "int")
        {
            int val = firebaseData.intData();
            if (val != blueValue)
            {
                blueValue = val;
                setLedColor();
            }
        }
    }
    */
}

void connectWifi()
{
    // Let us connect to WiFi
    WiFi.begin(ssid, password);

    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.print(".");
    }

    Serial.println(".......");
    Serial.println("WiFi Connected....IP Address:");
    Serial.println(WiFi.localIP());
}