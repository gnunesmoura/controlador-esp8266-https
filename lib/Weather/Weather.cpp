#include <Weather.h>

using namespace nunes;

float Weather::readHumidity()
{
  float humidity = this->dht.readHumidity();

  if (isnan(humidity))
  {
    return -1;
  }

  return humidity;
}

float Weather::readTemperature()
{
  float temperature = this->dht.readTemperature();

  if (isnan(temperature))
  {
    return -1;
  }

  return temperature;
}
