#include "WiFi.h"
#include "ESPAsyncWebServer.h"
#include "SPIFFS.h"
// Replace with your network credentials
const char* ssid = "HAMSON";
const char* password = "12345678";
// Create AsyncWebServer object on port 80
AsyncWebServer server(80);
void setup() {
  Serial.begin(9600);
  // Initialize SPIFFS
  if(!SPIFFS.begin(true)){
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }
  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
  // Print ESP32 Local IP Address
  Serial.println(WiFi.localIP());
  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/index.html", String(), false);
  });
  // Route to load style.css file
  server.on("/styles.css", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/styles.css", "text/css");
  });
  // Route for root / web page
  server.on("/main.js", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(SPIFFS, "/main.js", String(), false);
  });
  // Start server
  server.begin();
}
void loop() {
}

//primero debemos compilar//
// inferior izquierda el chulito para compilar //

// la flecha que esta apuntando a la derecha "upload" para cargar a la esp32//

//para ver lo que esta ejecutando la esp32 el boton enchufe//

//el delay (3000); esto es una orden para que en este caso muetsre el mensaje cda 3 segundos//

//abrir hormiga ir  alibraries he instalar la  libreria,ESPAsyncWebServer se descarga y se instala en la carpeta creada//
