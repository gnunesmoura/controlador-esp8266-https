#pragma once

#include <Notifier.h>
#include <Weather.h>
#include <string>

using namespace std;

namespace nunes
{
class WeatherNotifier : public Notifier
{
private:
  Weather sensor;

public:
  WeatherNotifier(char *a_url) : Notifier(a_url), sensor(4){};

  string getBody();
};

} // namespace nunes
