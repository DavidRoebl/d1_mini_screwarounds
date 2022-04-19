#include <Arduino.h>
#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>
#include "./my_local_wifi.h"
#include "./my_local_server.h"

#define LED 5

int count = 0;

void setup() {
  Serial.begin(115200);
  Serial.println("init");
  pinMode(LED, OUTPUT);
  digitalWrite(LED, HIGH);

  WiFi.begin(ssid, password);
  // Connecting to WiFi...
  Serial.print("Connecting to ");
  Serial.print(ssid);
  // Loop continuously while WiFi is not connected
  while (WiFi.status() != WL_CONNECTED)
  {
    delay(100);
    Serial.print(".");
  }
   
  // Connected to WiFi
  Serial.println();
  Serial.print("Connected! IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  digitalWrite(LED, HIGH);
  Serial.println("high");
  delay(1000);
  digitalWrite(LED, LOW);
  Serial.println("low");
  delay(1000);
  count += 1;

  if(count > 10) {
    count = 0;
    WiFiClient client;
    HTTPClient http;
    
    http.begin(client, serverName);
    http.addHeader("Content-Type", "text/plain");
    String message = "I'm still alive";
    int httpResponseCode = http.POST(message);

    Serial.print("HTTP Response code: ");
    Serial.println(httpResponseCode);
    String payload = http.getString();
    Serial.println(payload);

    http.end();
  }
}
