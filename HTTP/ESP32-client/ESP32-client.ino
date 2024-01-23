#include <WiFi.h>
#include <ESPAsyncWebServer.h>

const char* ssid = "Eprotocol";
const char* password = "53734312";

AsyncWebServer server(8888);

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Handle HTTP requests
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    // Print request method
    Serial.print("HTTP Method: ");
    Serial.println(request->methodToString());

    // Print URI
    Serial.print("URI: ");
    Serial.println(request->url());

    // Print headers
    Serial.println("Headers:");
    int headers = request->headers();
    for(int i=0; i<headers; i++){
      AsyncWebHeader* h = request->getHeader(i);
      Serial.print(h->name());
      Serial.print(": ");
      Serial.println(h->value());
    }

    // Send response
    request->send(200, "text/plain", "Hello, ESP32!");
  });

  // Start server
  server.begin();
}

void loop() {
  // Nothing to do here
}
