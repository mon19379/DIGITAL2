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
const char* ssid = "CLARO1_130838";  // Enter your SSID here
const char* password = "664fZCnapc";  //Enter your Password here

WebServer server(80);  // Object of WebServer(HTTP port, 80 is defult)


uint8_t cont;
char recib[4];
uint8_t x;


//************************************************************************************************
// Configuración
//************************************************************************************************
void setup() {

  Serial.begin(115200);
  Serial.println("Try Connecting to ");
  Serial.println(ssid);
  Serial2.begin(115200, SERIAL_8N1, 16, 17);
  // Connect to your wi-fi modem
  WiFi.begin(ssid, password);

  pinMode(18, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(21, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);


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
  disp(x);
  if (Serial2.available() > 0) {
    Serial2.readBytesUntil(10, recib, 4);

    cont = 4;
    x = cont;

    if (recib[0] == 48) {
      cont = x;

    }

    else if (recib[0] == 49) {
      x --;


    }

    if (recib[1] == 48) {
      cont = x;

    }

    else if (recib[1] == 50) {
      x --;

    }

    if (recib[2] == 48) {
      cont = x;

    }

    else if (recib[2] == 51) {
      x --;

    }

    if (recib[3] == 48) {
      cont = x;

    }

    else if (recib[3] == 52) {
      x --;

    }


  }
}
//************************************************************************************************
// Handler de Inicio página
//************************************************************************************************
void handle_OnConnect() {
  server.send(200, "text/html", SendHTML());
}

//************************************************************************************************
// Procesador de HTML
//************************************************************************************************
String SendHTML(void) {
  String ptr = "<!DOCTYPE html> <html>\n";

  ptr += "  <head>\n";
  ptr += "    <meta chatset=\"utf_8\">\n";
  ptr += "    <title>PROYECTO4</title>\n";
  ptr += "    <script>\n";
  ptr += "  <!--\n";
  ptr += "  function timedRefresh(timeoutPeriod) {\n";
  ptr += "  \tsetTimeout(\"location.reload(true);\",timeoutPeriod);\n";
  ptr += "  }\n";
  ptr += "\n";
  ptr += "  window.onload = timedRefresh(5000);\n";
  ptr += "\n";
  ptr += "  //   -->\n";
  ptr += "  </script>\n";
  ptr += "\n";
  ptr += "    <style>\n";
  ptr += "    *{\n";
  ptr += "      padding: 0;\n";
  ptr += "      margin: 0;\n";
  ptr += "      box-sizing: border-box;\n";
  ptr += "      font-family: arial;\n";
  ptr += "    }\n";
  ptr += "\n";
  ptr += "\n";
  ptr += "    h1{\n";
  ptr += "      font-size: 6mm;\n";
  ptr += "      letter-spacing: 15px;\n";
  ptr += "      color: #0e3742;\n";
  ptr += "      width: 100%;\n";
  ptr += "      text-align: justify\n";
  ptr += "      outline: none;\n";
  ptr += "      animation: animate 5s linear infinite;\n";
  ptr += "\n";
  ptr += "\n";
  ptr += "    }\n";
  ptr += "\n";
  ptr += "    @keyframes animate\n";
  ptr += "    {\n";
  ptr += "      0%, 18%, 20%,40.1%,60%, 65.1%, 80%, 90.1&, 92%\n";
  ptr += "      {\n";
  ptr += "            color: #0e3742;\n";
  ptr += "            box-shadow: none;\n";
  ptr += "      }\n";
  ptr += "      18.1%,20.1%,30%,50%,60.1%,65%,80.1%,90%,92.1%,100%\n";
  ptr += "      {\n";
  ptr += "            color: #0fff;\n";
  ptr += "            box-shadow: 0 0 10px #03bcf4,\n";
  ptr += "            0 0 20px #03bcf4\n";
  ptr += "            0 0 40px #03bcf4\n";
  ptr += "            0 0 80px #03bcf4\n";
  ptr += "            0 0 160px #03bcf4\n";
  ptr += "\n";
  ptr += "      }\n";
  ptr += "    }\n";
  ptr += "\n";
  ptr += "\n";
  ptr += "    }\n";
  ptr += "\n";
  ptr += "    #center{\n";
  ptr += "\n";
  ptr += "    margin-top:1000000px;\n";
  ptr += "    margin-left: 100px;\n";
  ptr += "\n";
  ptr += "\n";
  ptr += "    }\n";
  ptr += "\n";
  ptr += "    td, th{\n";
  ptr += "\n";
  ptr += "      border:2px solid black;\n";
  ptr += "      padding-left: 30px;\n";
  ptr += "      padding-right: 30px;\n";
  ptr += "      padding-top: 10px;\n";
  ptr += "      padding-bottom: 10px;\n";
  ptr += "      color: white;\n";
  ptr += "      background-color: black;\n";
  ptr += "      }\n";
  ptr += "\n";
  ptr += "\n";
  ptr += "      body{\n";
  ptr += "\n";
  ptr += "        align-items: center;\n";
  ptr += "        background: grays;\n";
  ptr += "      }\n";
  ptr += "\n";
  ptr += "    </style>\n";
  ptr += "    </head>\n";
  ptr += "\n";
  ptr += "  <header>\n";
  ptr += "    <h1 class=\"text1\">PARQUEO-MATIC</h1>\n";
  ptr += "  </header>\n";
  ptr += "\n";
  ptr += "\n";
  ptr += "<table id=\"center\">\n";
  ptr += "    <tr>\n";
  ptr += "      <th>No. de Parqueo</th>\n";
  ptr += "      <th>Disponibilidad</th>\n";
  ptr += "    </tr>\n";
  ptr += "\n";
  ptr += "    <tr>\n";
  ptr += "      <td>No.1</td>\n";

  if (recib[0] == 49) {
    ptr += "      <td> No Disponible</td>\n";
  }

  else if (recib[0] == 48) {
    ptr += "      <td> Disponible</td>\n";

  }
  ptr += "    </tr>\n";
  ptr += "\n";
  ptr += "    <tr>\n";
  ptr += "      <td>No.2</td>\n";
  if (recib[1] == 50) {
    ptr += "      <td> No Disponible</td>\n";
  }

  else if (recib[1] == 48) {
    ptr += "      <td> Disponible</td>\n";

  }
  ptr += "    </tr>\n";
  ptr += "\n";
  ptr += "    <tr>\n";
  ptr += "      <td>No.3</td>\n";

  if (recib[2] == 51) {
    ptr += "      <td> No Disponible</td>\n";
  }

  else if (recib[2] == 48) {
    ptr += "      <td> Disponible</td>\n";

  }
  ptr += "    </tr>\n";
  ptr += "\n";
  ptr += "    <tr>\n";
  ptr += "      <td>No.4</td>\n";

  if (recib[3] == 52) {
    ptr += "      <td> No Disponible</td>\n";
  }

  else if (recib[1] == 48) {
    ptr += "      <td> Disponible</td>\n";
  }
  ptr += "    </tr>\n";
  ptr += "\n";
  ptr += "  </table>\n";
  ptr += "  </html>\n";
  ptr += "";
  return ptr;
}
//************************************************************************************************
// Handler de not found
//************************************************************************************************
void handle_NotFound() {
  server.send(404, "text/plain", "Not found");
}



void disp(uint8_t segment) {

  switch (segment) {

    case 0: //0
      digitalWrite(26, LOW); //a
      digitalWrite(25, LOW); //b
      digitalWrite(18, LOW); //c
      digitalWrite(21, LOW); //d
      digitalWrite(19, LOW); //e
      digitalWrite(32, LOW); //f
      digitalWrite(33, HIGH); //g
      break;

    case 1: //1
      digitalWrite(26, HIGH); //a
      digitalWrite(25, LOW); //b
      digitalWrite(18, LOW); //c
      digitalWrite(21, HIGH); //d
      digitalWrite(19, HIGH); //e
      digitalWrite(32, HIGH); //f
      digitalWrite(33, HIGH); //g
      break;
    case 2: //2
      digitalWrite(26, LOW); //a
      digitalWrite(25, LOW); //b
      digitalWrite(18, HIGH); //c
      digitalWrite(21, LOW); //d
      digitalWrite(19, LOW); //e
      digitalWrite(32, HIGH); //f
      digitalWrite(33, LOW); //g
      break;
    case 3: //3
      digitalWrite(26, LOW); //a
      digitalWrite(25, LOW); //b
      digitalWrite(18, LOW); //c
      digitalWrite(21, LOW); //d
      digitalWrite(19, HIGH); //e
      digitalWrite(32, HIGH); //f
      digitalWrite(33, LOW); //g
      break;
    case 4: //4
      digitalWrite(26, HIGH); //a
      digitalWrite(25, LOW); //b
      digitalWrite(18, LOW); //c
      digitalWrite(21, HIGH); //d
      digitalWrite(19, HIGH); //e
      digitalWrite(32, LOW); //f
      digitalWrite(33, LOW);
      break;

    default:
      digitalWrite(26, LOW); //a
      digitalWrite(25, LOW); //b
      digitalWrite(18, LOW); //c
      digitalWrite(21, LOW); //d
      digitalWrite(19, LOW); //e
      digitalWrite(32, LOW); //f
      digitalWrite(33, HIGH); //g
      break;

  }
}
