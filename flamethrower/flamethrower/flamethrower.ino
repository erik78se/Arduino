
#include <ESP8266WiFi.h>

//////////////////////
// WiFi Definitions //
//////////////////////
const char WiFiAPPSK[] = "sparkfun";

/////////////////////
// Pin Definitions //
/////////////////////
const int VENT1_PIN = 4; // 
const int VENT2_PIN = 0; // 
const int IGNITION_PIN = 13; // 
const int ESP8266_LED = 5;

// Webserver on 192.168.4.1 port 80
WiFiServer server(80);

void setup() 
{
  initHardware();
  setupWiFi();
  server.begin();
}

void loop() 
{
  // Check if a client has connected
  WiFiClient client = server.available();
  if (!client) {
    return;
  }

  // Read the first line of the request
  String req = client.readStringUntil('\r');
  Serial.println(req);
  client.flush();

  // Match the request
  int val = -1;
  if (req.indexOf("/vent1/1") != -1)
    val = 0; 
  else if (req.indexOf("/vent2/1") != -1)
    val = 2; 
  else if (req.indexOf("/vent_all/1") != -1)
    val = 3;
  else if (req.indexOf("/ignition/1") != -1)
    val = 4; 
  else if (req.indexOf("/ignition/0") != -1)
    val = 5;

  // Set GPIO according to the request

  if (val == 0){
    digitalWrite(VENT1_PIN, 1);
    delay(500);
    digitalWrite(VENT1_PIN, 0);}

  else if (val == 2){
    digitalWrite(VENT2_PIN, 1);
    delay(500);
    digitalWrite(VENT2_PIN, 0);}

  else if (val == 3){
    digitalWrite(VENT1_PIN, 1);
    digitalWrite(VENT2_PIN, 1);
    delay(500);
    digitalWrite(VENT1_PIN, 0);
    digitalWrite(VENT2_PIN, 0);}

  else if (val == 4){
    digitalWrite(IGNITION_PIN, 1);
    digitalWrite(ESP8266_LED, HIGH);
    }

  else if (val == 5){
    digitalWrite(IGNITION_PIN, 0);
    digitalWrite(ESP8266_LED, LOW);
    }

  client.flush();

  // Prepare the response. Start with the common header:
  String s = "HTTP/1.1 200 OK\r\n";
  s += "Content-Type: text/html\r\n\r\n";
  s += "<!DOCTYPE HTML>\r\n<html>\r\n";

  if ( digitalRead(IGNITION_PIN) == 0 ){
  s += "Ignitior is currently turned OFF.";}
  else{
  s += "Ignitior is currently turned ON.";}
  s += "<br><br>\r\n"; // Go to the next line.

  s += "<a href = \"/ignition/1\">Glow Ingition On</a><br>\r\n";
  s += "<a href = \"/ignition/0\">Glow Ingition Off</a><br>\r\n";
  s += "<a href = \"/vent1/1\">Vent Tank 1 (500ms)</a><br>\r\n";
  s += "<a href = \"/vent2/1\">Vent Tank 2 (500ms)</a><br>\r\n";
  s += "<a href = \"/vent_all/1\">Vent Both Tanks (500ms)</a><br>\r\n";

  s += "</html>\n";

  // Send the response to the client
  client.print(s);
  delay(1);
  Serial.println("Client disonnected");

  // The client will actually be disconnected 
  // when the function returns and 'client' object is detroyed
}

void setupWiFi()
{
  WiFi.mode(WIFI_AP);

  // Do a little work to get a unique-ish name. Append the
  // last two bytes of the MAC (HEX'd) to "Thing-":
  uint8_t mac[WL_MAC_ADDR_LENGTH];
  WiFi.softAPmacAddress(mac);
  String macID = String(mac[WL_MAC_ADDR_LENGTH - 2], HEX) +
                 String(mac[WL_MAC_ADDR_LENGTH - 1], HEX);
  macID.toUpperCase();
  String AP_NameString = "ESP8266 Flame Cannon " + macID;

  char AP_NameChar[AP_NameString.length() + 1];
  memset(AP_NameChar, 0, AP_NameString.length() + 1);

  for (int i=0; i<AP_NameString.length(); i++)
    AP_NameChar[i] = AP_NameString.charAt(i);

  WiFi.softAP(AP_NameChar, WiFiAPPSK);
}

void initHardware()
{
  Serial.begin(115200);
  Serial.println("Hardware init");
  pinMode(ESP8266_LED, OUTPUT);

  pinMode(VENT1_PIN, OUTPUT);
  digitalWrite(VENT1_PIN, LOW);
  pinMode(VENT2_PIN, OUTPUT);
  digitalWrite(VENT2_PIN, LOW);
  pinMode(IGNITION_PIN, OUTPUT);
  digitalWrite(IGNITION_PIN, LOW);

}

