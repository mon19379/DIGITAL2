

void setup() {
  Serial.begin(9600); // opens serial port, sets data rate to 9600 bps
  Serial2.begin(9600, SERIAL_8N1, 16, 17); 
  
}

void loop() {
  // send data only when you receive data:
  if (Serial2.available() > 0) {
    // read the incoming byte:
    Serial.print(char(Serial2.read()));
  
    

 
  }
}
