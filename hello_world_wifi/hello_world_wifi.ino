#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "realmekv";
const char* password = "12341234";

WebServer server(80);

// This function sends the HTML page to your browser
void handleRoot() {
  String html = "<html>"
                "<head><meta name='viewport' content='width=device-width, initial-scale=1'></head>"
                "<body>"
                "<h1>ESP32 Control Panel</h1>"
                "<button onclick=\"fetch('/print')\" style='padding:20px; font-size:20px;'>Print Hello World</button>"
                "</body>"
                "</html>";
  
  server.send(200, "text/html", html);
}

// This function handles the specific request sent by the button
void handlePrint() {
  Serial.println("Hello World"); // This prints to your Serial Monitor
  server.send(200, "text/plain", "Message Printed!"); // This tells the browser it worked
}

void setup() {
  Serial.begin(115200);
  delay(2000); 
  
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) { 
    delay(500); 
    Serial.print("."); 
  }
  
  Serial.print("\nConnected! IP: ");
  Serial.println(WiFi.localIP());

  // Define the routes
  server.on("/", handleRoot);          // Loads the web page
  server.on("/print", handlePrint);    // Triggered when the button is clicked
  
  server.begin();
}

void loop() {
  server.handleClient();
}