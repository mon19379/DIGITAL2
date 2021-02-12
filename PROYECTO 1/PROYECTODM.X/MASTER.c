/*
 * File:   newmain.c
 * Author: franc
 *
 * 
 */



#include <xc.h>
#include <stdint.h>
#include <pic16f887.h>
#include "LCDM.h"
#include "oscm.h"

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






//******************************************************************************
// Prototipos de funciones
//******************************************************************************
void Setup(void);

//******************************************************************************
//Interrupción
//******************************************************************************

void __interrupt() ISR(void) {

  
}
//******************************************************************************
//Ciclo pincipal
//******************************************************************************

void main(void) {

    Setup();
    Lcd_Set_Cursor(1, 1);
    Lcd_Write_String("ADC");
    Lcd_Set_Cursor(1, 7);
    Lcd_Write_String("CONT");
    Lcd_Set_Cursor(1, 13);
    Lcd_Write_String("TEMP");







    //**************************************************************************
    // Loop principal
    //**************************************************************************
    while (1) {
       










    }
}
//******************************************************************************
//Configuracion
//******************************************************************************

void Setup(void) {
    TRISA = 0;
    TRISE = 0; //PUERTO E SALIDAS
    initOscm(6);
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
    TRISC = 0; //PUERTO C SALIDAS
    TRISD = 0; //PUERTO D SALIDAS
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







