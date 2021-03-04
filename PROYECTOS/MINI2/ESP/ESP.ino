

#include "config.h"
char t[17];
int flag = 0;
int Bot1 = 0;
int Bot2 = 0;
int flagl = 0;
int flagl2 = 0;

AdafruitIO_Feed *Tiempo = io.feed("Tiempo");
AdafruitIO_Feed *Led1 = io.feed("Led1");
AdafruitIO_Feed *Led2 = io.feed("Led2");

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  io.connect();
  Led1->onMessage(handleMessage);
  Led2->onMessage(handleMessage2);

  Serial2.begin(9600, SERIAL_8N1, 16, 17);
  while (io.status() < AIO_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.println(io.statusText());
  Led1->get();
  Led2->get();
}

void loop() {
  io.run();
  // send data only when you receive data:
  while (Serial2.available()) {
    // read the incoming byte:
    // t = Serial.print(char(Serial2.read()));
    Serial2.write(1);
  
    Serial2.readBytesUntil(10, t, 17);

      if(flagl == 1 && flagl2 == 0){
      Serial2.write(2);
    }

    else if(flagl == 0 && flagl2 == 1){
      Serial2.write(3);
    }

    else if(flagl == 1 && flagl2 == 1){
      Serial2.write(4);
    }
  }


  Serial.print("sending -> ");
  Serial.println(t);
  Serial.println(flagl);
  Serial.println(flagl2);
  delay(3000);


  Tiempo->save(t);




}

void handleMessage(AdafruitIO_Data*data) {
  Bot1 = data->toInt();
  if (Bot1 == 0) {
    flagl = 0;
  }
  if (Bot1 == 1) {
    flagl = 1;
  }
}


void handleMessage2(AdafruitIO_Data*data) {
  Bot2 = data->toInt();
  if (Bot2 == 0) {
    flagl2 = 0;
  }
  if (Bot2 == 1) {
    flagl2 = 1;
  }
}
