#include "DHT.h"
#include <ESP8266WiFi.h>
#include <Weather.h>

#define DHTPIN 4      // IMPORTANT D2 on NodeMCU is GPIO 4
#define DHTTYPE DHT22 // DHT 22 (AM2302), AM2321

nunes::Weather dht22(DHTPIN);

void setup()
{
    // put your setup code here, to run once:
    Serial.begin(9600);

    // Serial.println("");
    // Serial.println("WiFi connected");
    // Serial.println("IP address: ");
    // Serial.println(WiFi.localIP());
}

void loop()
{
    // put your main code here, to run repeatedly:
    delay(2000);

    Serial.print("Humidity: ");
    Serial.print(dht22.readHumidity());
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(dht22.readTemperature());
    Serial.print(" *C \n");
}