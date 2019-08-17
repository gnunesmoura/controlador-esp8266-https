#pragma once

#include "DHT.h"

#define DHTTYPE DHT22 // DHT 22 (AM2302), AM2321

namespace nunes
{

class Weather
{
public:
    Weather(int pin) : dht(pin, DHT22) {
        this->dht.begin();
    };

    float readHumidity();

    float readTemperature();

private:
    DHT dht;
};

} // namespace nunes
