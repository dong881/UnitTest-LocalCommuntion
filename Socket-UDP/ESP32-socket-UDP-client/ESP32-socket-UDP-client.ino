#include <WiFi.h>
#include <WiFiUdp.h>

const char *ssid = "Eprotocol";
const char *password = "53734312";
const int localPort = 12345;  // Port to listen on

WiFiUDP udp;

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  Serial.print("Local IP: ");
  Serial.println(WiFi.localIP());


  // Begin UDP
  udp.begin(localPort);
  Serial.printf("UDP server started on port %d\n", localPort);
}

void loop() {
  // Check if data is available to read
  int packetSize = udp.parsePacket();
  if (packetSize) {
    Serial.printf("Received %d bytes from %s, port %d\n", packetSize, udp.remoteIP().toString().c_str(), udp.remotePort());

    // Read the data
    char packetBuffer[255];
    int bytesRead = udp.read(packetBuffer, sizeof(packetBuffer) - 1);
    if (bytesRead > 0) {
      packetBuffer[bytesRead] = '\0';  // Null-terminate the string
      Serial.printf("Message: %s\n", packetBuffer);
    }
  }

  // Add your additional code here

  delay(1000);
}
