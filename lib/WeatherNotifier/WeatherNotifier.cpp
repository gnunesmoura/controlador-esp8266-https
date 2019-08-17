#include <WeatherNotifier.h>

using namespace nunes;
using namespace std;

string WeatherNotifier::getBody()
{
  const int capacity = JSON_OBJECT_SIZE(2);
  StaticJsonDocument<capacity> doc;
  doc["temperature"] = this->sensor.readTemperature();
  doc["humidity"] = this->sensor.readHumidity();
  char output[128];

  serializeJson(doc, output);

  return string(output);
}