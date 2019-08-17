#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include <ESP8266HTTPClient.h>

#include <WiFiClient.h>
#include <ArduinoJson.h>

#include <WeatherNotifier.h>

ESP8266WiFiMulti WiFiMulti;

void setup()
{

  Serial.begin(9600);
  // Serial.setDebugOutput(true);

  Serial.println();
  Serial.println();
  Serial.println();

  for (uint8_t t = 4; t > 0; t--)
  {
    Serial.printf("[SETUP] WAIT %d...\n", t);
    Serial.flush();
    delay(1000);
  }

  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP("Casa da Arvore", "g2996a1111");
}

nunes::WeatherNotifier notifier("http://10.0.0.101:8080/");

void loop()
{
  // wait for WiFi connection

  if ((WiFiMulti.run() == WL_CONNECTED))
  {
    notifier.post();
  }

  delay(1000);
}
