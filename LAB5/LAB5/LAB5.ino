


#include <SPI.h>
#include <SD.h>

int menu;
File myFile;

void setup()
{
  // Open serial communications and wait for port to open:
  Serial.begin(9600);
  SPI.setModule(0);


  Serial.print("Initializing SD card...");
  // On the Ethernet Shield, CS is pin 4. It's set as an output by default.
  // Note that even if it's not used as the CS pin, the hardware SS pin
  // (10 on most Arduino boards, 53 on the Mega) must be left as an output
  // or the SD library functions will not work.
  pinMode(PA_3, OUTPUT);

  if (!SD.begin(PA_3)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  myFile = SD.open("/");


  printDirectory(myFile, 0);

  Serial.println("done!");
  Serial.println("Escoger imagen 1, 2 o 3 ");
  Serial.println("1. Link.txt ");
  Serial.println("2. Mr.Game.txt ");
  Serial.println("3. Tri.txt ");


}

void loop()
{
  menu = Serial.read();
  if (menu == 49) {
    // re-open the file for reading:
    myFile = SD.open("Link.txt");
    if (myFile) {
      Serial.println("Link.txt:");

      // read from the file until there's nothing else in it:
      while (myFile.available()) {
        Serial.write(myFile.read());

      }
      // close the file:
      myFile.close();
    } else {
      // if the file didn't open, print an error:
      Serial.println("Escoger imagen 1, 2 o 3 ");
      Serial.println("1. Link.txt ");
      Serial.println("2. Mr.Game.txt ");
      Serial.println("3. Tri.txt ");


    }
    Serial.println("Escoger imagen 1, 2 o 3 ");
    Serial.println("1. Link.txt ");
    Serial.println("2. Mr.Game.txt ");
    Serial.println("3. Tri.txt ");

  }
  if (menu == 50) {
    // re-open the file for reading:
    myFile = SD.open("Mrgame.txt");
    if (myFile) {
      Serial.println("Mrgame.txt:");

      // read from the file until there's nothing else in it:
      while (myFile.available()) {
        Serial.write(myFile.read());

      }
      // close the file:
      myFile.close();
    } else {
      // if the file didn't open, print an error:
      Serial.println("Escoger imagen 1, 2 o 3 ");
      Serial.println("1. Link.txt ");
      Serial.println("2. Mr.Game.txt ");
      Serial.println("3. Tri.txt ");


    }
    Serial.println("Escoger imagen 1, 2 o 3 ");
    Serial.println("1. Link.txt ");
    Serial.println("2. Mr.Game.txt ");
    Serial.println("3. Tri.txt ");

  }
  if (menu == 51) {
    // re-open the file for reading:
    myFile = SD.open("Tri.txt");
    if (myFile) {
      Serial.println("Tri.txt:");

      // read from the file until there's nothing else in it:
      while (myFile.available()) {
        Serial.write(myFile.read());

      }
      // close the file:
      myFile.close();
    } else {
      // if the file didn't open, print an error:
      Serial.println("Escoger imagen 1, 2 o 3 ");
      Serial.println("1. Link.txt ");
      Serial.println("2. Mr.Game.txt ");
      Serial.println("3. Tri.txt ");


    }
    Serial.println("Escoger imagen 1, 2 o 3 ");
    Serial.println("1. Link.txt ");
    Serial.println("2. Mr.Game.txt ");
    Serial.println("3. Tri.txt ");

  }
}

void printDirectory(File dir, int numTabs) {
  while (true) {

    File entry =  dir.openNextFile();
    if (! entry) {
      // no more files
      break;
    }
    for (uint8_t i = 0; i < numTabs; i++) {
      Serial.print('\t');
    }
    Serial.print(entry.name());
    if (entry.isDirectory()) {
      Serial.println(" ");

    } else {
      // files have sizes, directories do not
      Serial.print("\t\t");
      Serial.println(entry.size());
    }
    entry.close();
  }
}
