/*************************************************************************************************
  ESP32 Web Server
  Ejemplo de creación de Web server
  Basándose en los ejemplos de:
  https://lastminuteengineers.com/creating-esp32-web-server-arduino-ide/
  https://electropeak.com/learn
**************************************************************************************************/
//************************************************************************************************
// Librerías
//************************************************************************************************
#include <WiFi.h>
#include <WebServer.h>
//************************************************************************************************
// Variables globales
//************************************************************************************************


// SSID & Password
const char* ssid = "DIGITAL2";  // Enter your SSID here
const char* password = "digital2";  //Enter your Password here

WebServer server(80);  // Object of WebServer(HTTP port, 80 is defult)


uint8_t cont;

//************************************************************************************************
// Configuración
//************************************************************************************************
void setup() {

  Serial.begin(115200);
  Serial.println("Try Connecting to ");
  Serial.println(ssid);
  // Connect to your wi-fi modem
  WiFi.begin(ssid, password);

  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(21, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT); .
  pinMode(34, OUTPUT);
  pinMode(35, OUTPUT);


  // Check wi-fi is connected to wi-fi network
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected successfully");
  Serial.print("Got IP: ");
  Serial.println(WiFi.localIP());  //Show ESP32 IP on serial

  server.on("/", handle_OnConnect); // Directamente desde e.g. 192.168.0.8
  server.on("/led1on", handle_led1on);
  server.on("/led1off", handle_led1off);

  server.onNotFound(handle_NotFound);

  server.begin();
  Serial.println("HTTP server started");
  delay(100);
}
//************************************************************************************************
// loop principal
//************************************************************************************************
void loop() {
  server.handleClient();
  if (LED1status)
  {
    digitalWrite(LED1pin, HIGH);
  }
  else
  {
    digitalWrite(LED1pin, LOW);
  }
}
//************************************************************************************************
// Handler de Inicio página
//************************************************************************************************
void handle_OnConnect() {
  LED1status = LOW;
  Serial.println("GPIO2 Status: OFF");
  server.send(200, "text/html", SendHTML(LED1status));
}
//************************************************************************************************
// Handler de led1on
//************************************************************************************************
void handle_led1on() {
  LED1status = HIGH;
  Serial.println("GPIO2 Status: ON");
  server.send(200, "text/html", SendHTML(LED1status));
}
//************************************************************************************************
// Handler de led1off
//************************************************************************************************
void handle_led1off() {
  LED1status = LOW;
  Serial.println("GPIO2 Status: OFF");
  server.send(200, "text/html", SendHTML(LED1status));
}
//************************************************************************************************
// Procesador de HTML
//************************************************************************************************
String SendHTML(uint8_t led1stat) {
  String ptr = "<!DOCTYPE html> <html>\n";
  ptr += "<head><meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0, user-scalable=no\">\n";
  ptr += "<title>LED Control</title>\n";
  ptr += "<style>html { font-family: Helvetica; display: inline-block; margin: 0px auto; text-align: center;}\n";
  ptr += "body{margin-top: 50px;} h1 {color: #444444;margin: 50px auto 30px;} h3 {color: #444444;margin-bottom: 50px;}\n";
  ptr += ".button {display: block;width: 80px;background-color: #3498db;border: none;color: white;padding: 13px 30px;text-decoration: none;font-size: 25px;margin: 0px auto 35px;cursor: pointer;border-radius: 4px;}\n";
  ptr += ".button-on {background-color: #3498db;}\n";
  ptr += ".button-on:active {background-color: #2980b9;}\n";
  ptr += ".button-off {background-color: #34495e;}\n";
  ptr += ".button-off:active {background-color: #2c3e50;}\n";
  ptr += "p {font-size: 14px;color: #888;margin-bottom: 10px;}\n";
  ptr += "</style>\n";
  ptr += "</head>\n";
  ptr += "<body>\n";
  ptr += "<h1>ESP32 Web Server &#128664</h1>\n";
  ptr += "<h3>Ejemplo de Web Server</h3>\n";

  if (led1stat)
  {
    ptr += "<p>LED1 Status: ON</p><a class=\"button button-off\" href=\"/led1off\">OFF</a>\n";
  }
  else
  {
    ptr += "<p>LED1 Status: OFF</p><a class=\"button button-on\" href=\"/led1on\">ON</a>\n";
  }

  ptr += "</body>\n";
  ptr += "</html>\n";
  return ptr;
}
//************************************************************************************************
// Handler de not found
//************************************************************************************************
void handle_NotFound() {
  server.send(404, "text/plain", "Not found");
}


void 7SEG() {
  void display(uint8_t segment) {

    switch (segment) {

      case 0: //0
        digitalWrite(35, LOW); //a
        digitalWrite(34, LOW); //b
        digitalWrite(18, LOW); //c
        digitalWrite(21, LOW); //d
        digitalWrite(19, LOW); //e
        digitalWrite(32, LOW); //f
        digitalWrite(33, HIGH); //g
        break;

      case 1: //1
        digitalWrite(35, HIGH); //a
        digitalWrite(34, LOW); //b
        digitalWrite(18, LOW); //c
        digitalWrite(21, HIGH); //d
        digitalWrite(19, HIGH); //e
        digitalWrite(32, HIGH); //f
        digitalWrite(33, HIGH); //g
        break;
      case 2: //2
        digitalWrite(35, LOW); //a
        digitalWrite(34, LOW); //b
        digitalWrite(18, HIGH); //c
        digitalWrite(21, LOW); //d
        digitalWrite(19, LOW); //e
        digitalWrite(32, HIGH); //f
        digitalWrite(33, LOW); //g
        break;
      case 3: //3
        digitalWrite(35, LOW); //a
        digitalWrite(34, LOW); //b
        digitalWrite(18, LOW); //c
        digitalWrite(21, LOW); //d
        digitalWrite(19, HIGH); //e
        digitalWrite(32, HIGH); //f
        digitalWrite(33, LOW); //g
        break;
      case 4: //4
        digitalWrite(35, LOW); //a
        digitalWrite(34, LOW); //b
        digitalWrite(18, LOW); //c
        digitalWrite(21, LOW); //d
        digitalWrite(19, LOW); //e
        digitalWrite(32, LOW); //f
        digitalWrite(33, HIGH); //g
        break;

      default:
        digitalWrite(35, HIGH); //a
        digitalWrite(34, LOW); //b
        digitalWrite(18, LOW); //c
        digitalWrite(21, HIGH); //d
        digitalWrite(19, HIGH); //e
        digitalWrite(32, LOW); //f
        digitalWrite(33, LOW); //g
        break;

    }
