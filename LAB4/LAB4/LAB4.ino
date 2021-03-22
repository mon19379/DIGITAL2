
#include <stdint.h>

//*****************************************************************************************
//variables
//*****************************************************************************************
uint8_t PL1;
uint8_t PL2;
uint8_t SEM;
uint8_t CONT;
uint8_t CONT1;
uint8_t BO1;
uint8_t BO2;
uint8_t BO3;
uint8_t FLAG;
//******************************************************************************************
//prototipos de funciones
//******************************************************************************************
void setup (void);
void semaforo(void);
void player1 (void);
void player2 (void);
//*******************************************************************************************
//Configuración
//*******************************************************************************************
void setup() {
  // put your setup code here, to run once:
  //LEDS J1
  pinMode(PB_5, OUTPUT);
  pinMode(PB_0, OUTPUT);
  pinMode(PB_1, OUTPUT);
  pinMode(PE_4, OUTPUT);
  pinMode(PE_5, OUTPUT);
  pinMode(PB_4, OUTPUT);
  pinMode(PA_5, OUTPUT);
  pinMode(PA_6, OUTPUT);


  //LEDS J2
  pinMode(PD_0, OUTPUT);
  pinMode(PD_1, OUTPUT);
  pinMode(PD_2, OUTPUT);
  pinMode(PD_3, OUTPUT);
  pinMode(PE_1, OUTPUT);
  pinMode(PE_2, OUTPUT);
  pinMode(PE_3, OUTPUT);
  pinMode(PA_7, OUTPUT);

  //SEMAFORO
  pinMode(PF_3, OUTPUT);
  pinMode(PB_3, OUTPUT);
  pinMode(PC_4, OUTPUT);

  //BOTONES

  pinMode(PB_2, INPUT_PULLUP);
  pinMode(PE_0, INPUT_PULLUP);
  pinMode(PF_0, INPUT_PULLUP);

  //INDICADOR
  pinMode(RED_LED, OUTPUT);
}




//*******************************************************************************************
// Ciclo principal
//*******************************************************************************************
void loop() {
  // put your main code here, to run repeatedly:
  BO1 = digitalRead(PB_2);
  BO2 = digitalRead(PE_0);
  BO3 = digitalRead(PF_0);
  player1();
  player2();

  if (BO1 == HIGH) {
    SEM = 0;
  }

  else {
    if (BO1 == LOW) {
      SEM = 1;
      semaforo();
    }
  }
  if (FLAG == 1) {
    if (BO2 == LOW) {
      PL1 = 1;
    }
    if (PL1 == 1 && BO2 == HIGH) {
      PL1 = 0;
      CONT ++;
    }
  }

  if (FLAG == 1) {
    if (BO3 == LOW) {
      PL2 = 1;
    }
    if (PL2 == 1 && BO3 == HIGH) {
      PL2 = 0;
      CONT1 ++;
    }
  }
  delay(100);
}


//*******************************************************************************************
//Subrutinas
//*******************************************************************************************

void semaforo (void) {
  digitalWrite(RED_LED, LOW);
  digitalWrite(PB_5, LOW);
  digitalWrite(PB_0, LOW);
  digitalWrite(PB_1, LOW);
  digitalWrite(PE_4, LOW);
  digitalWrite(PE_5, LOW);
  digitalWrite(PB_4, LOW);
  digitalWrite(PA_5, LOW);
  digitalWrite(PA_6, LOW);
  CONT = 0;

 
  digitalWrite(PD_0, LOW);
  digitalWrite(PD_1, LOW);
  digitalWrite(PD_2, LOW);
  digitalWrite(PD_3, LOW);
  digitalWrite(PE_1, LOW);
  digitalWrite(PE_2, LOW);
  digitalWrite(PE_3, LOW);
  digitalWrite(PA_7, LOW);
  CONT1 = 0;


  digitalWrite (PC_4, HIGH);
  digitalWrite (PB_3, LOW);
  digitalWrite (PF_3, LOW);
  delay(500);

  digitalWrite (PC_4, LOW);
  digitalWrite (PB_3, HIGH);
  digitalWrite (PF_3, LOW);
  delay(500);

  digitalWrite (PC_4, LOW);
  digitalWrite (PB_3, LOW);
  digitalWrite (PF_3, HIGH);
  FLAG = 1;
  delay(500);

  digitalWrite (PC_4, LOW);
  digitalWrite (PB_3, LOW);
  digitalWrite (PF_3, LOW);

}



void player1 (void) {
  if (CONT == 1) {
    digitalWrite(PB_5, HIGH);
    digitalWrite(PB_0, LOW);
    digitalWrite(PB_1, LOW);
    digitalWrite(PE_4, LOW);
    digitalWrite(PE_5, LOW);
    digitalWrite(PB_4, LOW);
    digitalWrite(PA_5, LOW);
    digitalWrite(PA_6, LOW);

  }
  else if (CONT == 2) {
    digitalWrite(PB_5, LOW);
    digitalWrite(PB_0, HIGH);
    digitalWrite(PB_1, LOW);
    digitalWrite(PE_4, LOW);
    digitalWrite(PE_5, LOW);
    digitalWrite(PB_4, LOW);
    digitalWrite(PA_5, LOW);
    digitalWrite(PA_6, LOW);

  }
  else if (CONT == 3) {
    digitalWrite(PB_5, LOW);
    digitalWrite(PB_0, LOW);
    digitalWrite(PB_1, HIGH);
    digitalWrite(PE_4, LOW);
    digitalWrite(PE_5, LOW);
    digitalWrite(PB_4, LOW);
    digitalWrite(PA_5, LOW);
    digitalWrite(PA_6, LOW);

  }
  else if (CONT == 4) {
    digitalWrite(PB_5, LOW);
    digitalWrite(PB_0, LOW);
    digitalWrite(PB_1, LOW);
    digitalWrite(PE_4, HIGH);
    digitalWrite(PE_5, LOW);
    digitalWrite(PB_4, LOW);
    digitalWrite(PA_5, LOW);
    digitalWrite(PA_6, LOW);

  }
  else if (CONT == 5) {
    digitalWrite(PB_5, LOW);
    digitalWrite(PB_0, LOW);
    digitalWrite(PB_1, LOW);
    digitalWrite(PE_4, LOW);
    digitalWrite(PE_5, HIGH);
    digitalWrite(PB_4, LOW);
    digitalWrite(PA_5, LOW);
    digitalWrite(PA_6, LOW);

  }
  else if (CONT == 6) {
    digitalWrite(PB_5, LOW);
    digitalWrite(PB_0, LOW);
    digitalWrite(PB_1, LOW);
    digitalWrite(PE_4, LOW);
    digitalWrite(PE_5, LOW);
    digitalWrite(PB_4, HIGH);
    digitalWrite(PA_5, LOW);
    digitalWrite(PA_6, LOW);

  }
  else if (CONT == 7) {
    digitalWrite(PB_5, LOW);
    digitalWrite(PB_0, LOW);
    digitalWrite(PB_1, LOW);
    digitalWrite(PE_4, LOW);
    digitalWrite(PE_5, LOW);
    digitalWrite(PB_4, LOW);
    digitalWrite(PA_5, HIGH);
    digitalWrite(PA_6, LOW);

  }
  else if (CONT == 8) {
    digitalWrite(PB_5, LOW);
    digitalWrite(PB_0, LOW);
    digitalWrite(PB_1, LOW);
    digitalWrite(PE_4, LOW);
    digitalWrite(PE_5, LOW);
    digitalWrite(PB_4, LOW);
    digitalWrite(PA_5, LOW);
    digitalWrite(PA_6, HIGH);


  }

  else if (CONT == 9) {
    digitalWrite(PB_5, LOW);
    digitalWrite(PB_0, LOW);
    digitalWrite(PB_1, LOW);
    digitalWrite(PE_4, LOW);
    digitalWrite(PE_5, LOW);
    digitalWrite(PB_4, LOW);
    digitalWrite(PA_5, LOW);
    digitalWrite(PA_6, LOW);
    digitalWrite(RED_LED, HIGH);
    FLAG = 0;
    CONT = 0;

  }

}

void player2 (void) {
  if (CONT1 == 1) {
    digitalWrite(PD_0, HIGH);
    digitalWrite(PD_1, LOW);
    digitalWrite(PD_2, LOW);
    digitalWrite(PD_3, LOW);
    digitalWrite(PE_1, LOW);
    digitalWrite(PE_2, LOW);
    digitalWrite(PE_3, LOW);
    digitalWrite(PA_7, LOW);

  }
  else if (CONT1 == 2) {
    digitalWrite(PD_0, LOW);
    digitalWrite(PD_1, HIGH);
    digitalWrite(PD_2, LOW);
    digitalWrite(PD_3, LOW);
    digitalWrite(PE_1, LOW);
    digitalWrite(PE_2, LOW);
    digitalWrite(PE_3, LOW);
    digitalWrite(PA_7, LOW);

  }
  else if (CONT1 == 3) {
    digitalWrite(PD_0, LOW);
    digitalWrite(PD_1, LOW);
    digitalWrite(PD_2, HIGH);
    digitalWrite(PD_3, LOW);
    digitalWrite(PE_1, LOW);
    digitalWrite(PE_2, LOW);
    digitalWrite(PE_3, LOW);
    digitalWrite(PA_7, LOW);

  }
  else if (CONT1 == 4) {
    digitalWrite(PD_0, LOW);
    digitalWrite(PD_1, LOW);
    digitalWrite(PD_2, LOW);
    digitalWrite(PD_3, HIGH);
    digitalWrite(PE_1, LOW);
    digitalWrite(PE_2, LOW);
    digitalWrite(PE_3, LOW);
    digitalWrite(PA_7, LOW);

  }
  else if (CONT1 == 5) {
    digitalWrite(PD_0, LOW);
    digitalWrite(PD_1, LOW);
    digitalWrite(PD_2, LOW);
    digitalWrite(PD_3, LOW);
    digitalWrite(PE_1, HIGH);
    digitalWrite(PE_2, LOW);
    digitalWrite(PE_3, LOW);
    digitalWrite(PA_7, LOW);

  }
  else if (CONT1 == 6) {
    digitalWrite(PD_0, LOW);
    digitalWrite(PD_1, LOW);
    digitalWrite(PD_2, LOW);
    digitalWrite(PD_3, LOW);
    digitalWrite(PE_1, LOW);
    digitalWrite(PE_2, HIGH);
    digitalWrite(PE_3, LOW);
    digitalWrite(PA_7, LOW);

  }
  else if (CONT1 == 7) {
    digitalWrite(PD_0, LOW);
    digitalWrite(PD_1, LOW);
    digitalWrite(PD_2, LOW);
    digitalWrite(PD_3, LOW);
    digitalWrite(PE_1, LOW);
    digitalWrite(PE_2, LOW);
    digitalWrite(PE_3, HIGH);
    digitalWrite(PA_7, LOW);

  }
  else if (CONT1 == 8) {
    digitalWrite(PD_0, LOW);
    digitalWrite(PD_1, LOW);
    digitalWrite(PD_2, LOW);
    digitalWrite(PD_3, LOW);
    digitalWrite(PE_1, LOW);
    digitalWrite(PE_2, LOW);
    digitalWrite(PE_3, LOW);
    digitalWrite(PA_7, HIGH);


  }

  else if (CONT1 == 9) {
    digitalWrite(PD_0, LOW);
    digitalWrite(PD_1, LOW);
    digitalWrite(PD_2, LOW);
    digitalWrite(PD_3, LOW);
    digitalWrite(PE_1, LOW);
    digitalWrite(PE_2, LOW);
    digitalWrite(PE_3, LOW);
    digitalWrite(PA_7, LOW);
    digitalWrite(RED_LED, HIGH);
    FLAG = 0;
    CONT1 = 0;
  }

}
