#pragma once

#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include <ArduinoJson.h>
#include <string>

using namespace std;

namespace nunes
{
class Notifier
{
private:
  char *url;

public:
  Notifier(char *a_url) : url(a_url){};
  ~Notifier(){};

  virtual string getBody() = 0;

  int post();
};

} // namespace nunes
