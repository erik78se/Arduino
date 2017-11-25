#include <ESP8266WiFi.h>

//////////////////////
// WiFi Definitions //
//////////////////////
const char WiFiAPPSK[] = "sparkfun";

#define ESP8266_LED 5

WiFiServer server(80);

void setup() 
{
  pinMode(ESP8266_LED, OUTPUT);
  initHardware();
  setupWiFi();
  server.begin();
}

void loop() 
{
  digitalWrite(ESP8266_LED, HIGH);
  delay(500);
  digitalWrite(ESP8266_LED, LOW);
  delay(500);
}
