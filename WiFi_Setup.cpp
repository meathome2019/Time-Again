#include <Arduino.h>
#include "Wifi_Setup.h"

IPAddress ip(192, 168, 1, 210);
IPAddress gateway(192, 168, 1, 254);    // Set your network Gateway usually your Router base address
IPAddress subnet(255, 255, 255, 0); 
IPAddress dns(192,168,1,254); 
const char* WLAN_SSID = "BTHub6-3CXG";
const char* WLAN_PASSWD = "JL4qtNuDHwp4";
//#####################################################################################################
void WiFi_ON(){
WiFi.forceSleepWake();
  delay( 1 );
  WiFi.config(ip, dns, gateway, subnet);
  WiFi.persistent( false );   // Disable the WiFi persistence.  The ESP8266 will not load and save WiFi settings unnecessarily in the flash memory.
  WiFi.begin(WLAN_SSID,WLAN_PASSWD);
  rssi = WiFi.RSSI();             //Detect and print signal strength
  Serial.print("RSSI:");
  Serial.println(rssi);
}