/*
 * File:   newmain.c
 * Author: franc
 *
 * Created on 4 de febrero de 2021, 12:51 PM
 */



#include <xc.h>
#include <stdint.h>
#include <pic16f887.h>
#include "LCD.h"
#include "adc2.h"
#include "osc.h"
#include "usart.h"
//******************************************************************************
// Palabra de configuración
//******************************************************************************
// CONFIG1
#pragma config FOSC = INTRC_NOCLKOUT        // Oscillator Selection bits (XT oscillator: Crystal/resonator on RA6/OSC2/CLKOUT and RA7/OSC1/CLKIN)
#pragma config WDTE = OFF       // Watchdog Timer Enable bit (WDT disabled and can be enabled by SWDTEN bit of the WDTCON register)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (PWRT disabled)
#pragma config MCLRE = OFF      // RE3/MCLR pin function select bit (RE3/MCLR pin function is digital input, MCLR internally tied to VDD)
#pragma config CP = OFF         // Code Protection bit (Program memory code protection is disabled)
#pragma config CPD = OFF        // Data Code Protection bit (Data memory code protection is disabled)
#pragma config BOREN = OFF      // Brown Out Reset Selection bits (BOR disabled)
#pragma config IESO = OFF       // Internal External Switchover bit (Internal/External Switchover mode is disabled)
#pragma config FCMEN = OFF      // Fail-Safe Clock Monitor Enabled bit (Fail-Safe Clock Monitor is disabled)
#pragma config LVP = OFF        // Low Voltage Programming Enable bit (RB3 pin has digital I/O, HV on MCLR must be used for programming)

// CONFIG2
#pragma config BOR4V = BOR40V   // Brown-out Reset Selection bit (Brown-out Reset set to 4.0V)
#pragma config WRT = OFF        // Flash Program Memory Self Write Enable bits (Write protection off)
#define _XTAL_FREQ 4000000      //SE CONFIGURA EL OSCILADOR EXTERNO

//******************************************************************************
//Variables
//******************************************************************************
uint8_t pot1 = 0;
uint8_t pot2 = 0;
uint8_t FLAGADC = 0;
uint8_t CONTADC = 0;
uint8_t TOGGLE = 0;
uint8_t REC = 0;
uint8_t CP1 = 0;
uint8_t DP1 = 0;
uint8_t UP1 = 0;
uint8_t CP2 = 0;
uint8_t DP2 = 0;
uint8_t UP2 = 0;
uint8_t C1 = 0;
uint8_t D1 = 0;
uint8_t U1 = 0;
uint8_t C2 = 0;
uint8_t D2 = 0;
uint8_t U2 = 0;
uint8_t SEND = 0;
uint8_t CONT = 0;
uint8_t R1 = 0;
uint8_t R2 = 0;





//******************************************************************************
// Prototipos de funciones
//******************************************************************************
void Setup(void);
void pots(void);
void mandar(void);
void map(void);
void recibir(void);
void map2(void);
//******************************************************************************
//Interrupción
//******************************************************************************

void __interrupt() ISR(void) {

    if (INTCONbits.T0IF == 1) {
        TMR0 = 236;
        CONTADC++;
        INTCONbits.T0IF = 0;
    }

    if (PIR1bits.ADIF == 1) {
        pots();
        PIR1bits.ADIF = 0;
    }

    if (PIR1bits.RCIF == 1) {
        REC = RCREG;
        recibir();
    }

    if (PIR1bits.TXIF == 1) {
        mandar();
        SEND++;
        PIE1bits.TXIE = 0;

    }
}
//******************************************************************************
//Ciclo pincipal
//******************************************************************************

void main(void) {

    Setup();
    Lcd_Set_Cursor(1, 1);
    Lcd_Write_String("V1");
    Lcd_Set_Cursor(1, 7);
    Lcd_Write_String("V2");
    Lcd_Set_Cursor(1, 13);
    Lcd_Write_String("CONT");






    //**************************************************************************
    // Loop principal
    //**************************************************************************
    while (1) {
        map();
        map2();
        if (CONTADC > 20) {
            ADCON0bits.GO_nDONE = 1;
            CONTADC = 0;
            PIE1bits.TXIE = 1;


        }

        Lcd_Set_Cursor(2, 1);
        Lcd_Write_Char(C1);
        Lcd_Set_Cursor(2, 2);
        Lcd_Write_String(".");
        Lcd_Write_Char(D1);
        Lcd_Set_Cursor(2, 4);
        Lcd_Write_Char(U1);


        Lcd_Set_Cursor(2, 7);
        Lcd_Write_Char(C2);
        Lcd_Set_Cursor(2, 8);
        Lcd_Write_String(".");
        Lcd_Set_Cursor(2, 9);
        Lcd_Write_Char(D2);
        Lcd_Set_Cursor(2, 10);
        Lcd_Write_Char(U2);












    }
}
//******************************************************************************
//Configuracion
//******************************************************************************

void Setup(void) {
    TRISD = 0;
    TRISE = 0; //PUERTO E SALIDAS
    initOsc(6); //SE LLAMA LA CONFIG DEL OSCILADOR
    configADC2(1, 12); //SE LLAMA LA CONFIG DEL ADC
    usart();
    Lcd_Init();
    Lcd_Cmd(0x8A);
    ANSEL = 0; // ENTRADAS DIGITALES Y BIT 0 ANALÓGICA
    ANSELH = 0b00000011;
    PORTA = 0; //PUERTO A EN 0
    PORTB = 0; //PUERTO B EN 0
    PORTC = 0; //PUERTO C EN 0
    PORTD = 0; //PUERTO D EN 0
    PORTE = 0; //PUERTO E EN 0
    //PINES RA0 Y RA2 COMO ENTRADAS, LOS DEMAS COMO SALIDAS
    TRISC = 0b10000000; //PUERTO C SALIDAS
    TRISA = 0; //PUERTO A SALIDAS
    TRISB = 0b00000011; //PUERTO B 
    OPTION_REG = 0b10000111; //SE APAGAN LAS PULLUPS DEL PUERTO B
    INTCONbits.GIE = 1; //SE HABILITAN LAS INTERRUPCIONES GLOBALES
    INTCONbits.T0IE = 1; //SE HABILITA LA INTERRUPCION DEL TIMER0
    INTCONbits.PEIE = 1; //SE HABILITAN LAS INTERRUPCIONES PERIFERICAS
    PIE1bits.ADIE = 1; //SE HABILITA LA INTERRUPCION DEL ADC
    INTCONbits.T0IF = 0; // SE LIMPIA LA BANDERA DE INTERRUPCION DEL TIMER 0
    PIR1bits.ADIF = 0; //SE LIMPIOA LA BANDERA DE INTERRUPCION DEL ADC
    PIR1bits.TXIF = 0;
    PIE1bits.TXIE = 1;
    PIE1bits.RCIE = 1;
    PIR1bits.RCIF = 0;



}

//******************************************************************************
// Subrutinas
//******************************************************************************

void pots(void) {

    if (TOGGLE == 0) {
        configADC2(1, 12);
        pot1 = ADRESH;
        TOGGLE = 1;
    } else {
        configADC2(1, 10);
        pot2 = ADRESH;
        TOGGLE = 0;
    }
}

void map(void) {
    CP1 = ((pot1) / 51);
    DP1 = (((pot1 * 100) / 51)-(CP1 * 100)) / 10;
    UP1 = (((pot1 * 100) / 51)-(CP1 * 100)-(DP1 * 10));

    CP2 = ((pot2) / 51);
    DP2 = (((pot2 * 100) / 51)-(CP2 * 100)) / 10;
    UP2 = (((pot2 * 100) / 51)-(CP2 * 100)-(DP2 * 10));

    C1 = (CP1 + 0x30);
    D1 = (DP1 + 0x30);
    U1 = (UP1 + 0x30);

    C2 = (CP2 + 0x30);
    D2 = (DP2 + 0x30);
    U2 = (UP2 + 0x30);
}

void mandar(void) {
    switch (SEND) {

        case 0:
            TXREG = 0x28;
            break;

        case 1:
            TXREG = C1;
            break;

        case 2:
            TXREG = 0x2E;
            break;
        case 3:
            TXREG = D1;
            break;
        case 4:
            TXREG = U1;
            break;
        case 5:
            TXREG = 0x29;
            break;

        case 6:
            TXREG = 0x2C;
            break;

        case 7:
            TXREG = 0x20;
            break;

        case 8:
            TXREG = 0x28;
            break;

        case 9:
            TXREG = C2;
            break;
        case 10:
            TXREG = 0x2E;
            break;
        case 11:
            TXREG = D2;
            break;
        case 12:
            TXREG = U2;

            break;

        case 13:
            TXREG = 0x29;


        case 14:
            TXREG = 0x0D;
            SEND = 0;
            break;
    }

}

void recibir(void) {
    if (REC == 43) {
        R1 = 1;


    }

    if (REC != 43 && R1 == 1) {
        R1 = 0;
        CONT++;
    }

    if (REC == 45) {
        R2 = 1;


    }

    if (REC != 45 && R2 == 1) {
        R2 = 0;
        CONT--;
    }
}




