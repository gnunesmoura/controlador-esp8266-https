#include <Notifier.h>

using namespace nunes;

int Notifier::post()
{
  WiFiClient client;

  HTTPClient http;

  Serial.print("[HTTP] begin...\n");
  // configure traged server and url

  http.begin(client, this->url);
  http.addHeader("Content-Type", "application/json");

  Serial.print("[HTTP] POST...\n");
  int httpCode = http.POST(this->getBody().c_str());
  
  // httpCode will be negative on error
  if (httpCode > 0)
  {
    // HTTP header has been send and Server response header has been handled
    Serial.printf("[HTTP] POST... code: %d\n", httpCode);

    // file found at server
    if (httpCode == HTTP_CODE_OK)
    {
      String payload = http.getString();
      Serial.println(payload);
    }
  }
  else
  {
    Serial.printf("[HTTP] POST... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }

  http.end();

  return httpCode;
}
