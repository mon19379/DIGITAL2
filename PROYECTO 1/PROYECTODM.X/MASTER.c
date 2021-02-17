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
#include "SSP.h"
#include "usartm.h"

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
uint8_t desecho = 0;
uint8_t pot1 = 0;
uint8_t cont1 = 0;
uint8_t CP1 = 0;
uint8_t DP1 = 0;
uint8_t UP1 = 0;
uint8_t C1 = 0;
uint8_t D1 = 0;
uint8_t U1 = 0;
uint8_t INDIC = 0;
uint8_t CONTC = 0;
uint8_t CONTD = 0;
uint8_t CONTU = 0;
uint8_t CO1 = 0;
uint8_t CO2 = 0;
uint8_t CO3 = 0;
uint8_t SEND = 0;
uint8_t term1 = 0;
uint8_t TEMPC = 0;
uint8_t TEMPD = 0;
uint8_t TEMPU = 0;
uint8_t TEMPND = 0;
uint8_t TEMPNU = 0;
uint8_t T1 = 0;
uint8_t T2 = 0;
uint8_t T3 = 0;
uint8_t TN1 = 0;
uint8_t TN2 = 0;
uint8_t TEMP = 0;
uint8_t TEMPN = 0;



//******************************************************************************
// Prototipos de funciones
//******************************************************************************
void Setup(void);
void map(void);
void map2(void);
void map3(void);
void map4(void);
void mandar(void);
void temperatura(void);
void temperatura2(void);
//******************************************************************************
//Interrupción
//******************************************************************************

void __interrupt() ISR(void) {

    if (PIR1bits.TXIF == 1) {
        mandar();
        SEND++;
        PIE1bits.TXIE = 0;
        PIR1bits.TXIF = 0;

    }


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
        INDIC++;
        map();
        map2();
        map3();


        PIE1bits.TXIE = 1;


        if (INDIC == 1) {
            PORTCbits.RC0 = 0;
            __delay_ms(1);
            spiWrite(desecho);
            pot1 = spiRead();

            __delay_ms(1);
            PORTCbits.RC0 = 1;
        }

        if (INDIC == 2) {
            PORTCbits.RC1 = 0;
            __delay_ms(1);
            spiWrite(desecho);
            cont1 = spiRead();

            __delay_ms(1);
            PORTCbits.RC1 = 1;

        }



        if (INDIC == 3) {
            PORTCbits.RC2 = 0;
            __delay_ms(1);
            spiWrite(desecho);
            term1 = spiRead();

            __delay_ms(1);
            PORTCbits.RC2 = 1;
            INDIC = 0;
        }



        Lcd_Set_Cursor(2, 1);
        Lcd_Write_Char(C1);
        Lcd_Set_Cursor(2, 2);
        Lcd_Write_String(".");
        Lcd_Write_Char(D1);
        Lcd_Set_Cursor(2, 4);
        Lcd_Write_Char(U1);

        Lcd_Set_Cursor(2, 7);
        Lcd_Write_Char(CO1);
        Lcd_Set_Cursor(2, 8);
        Lcd_Write_Char(CO2);
        Lcd_Set_Cursor(2, 9);
        Lcd_Write_Char(CO3);






    }
}
//******************************************************************************
//Configuracion
//******************************************************************************

void Setup(void) {
    TRISA = 0;
    TRISE = 0; //PUERTO E SALIDAS
    initOscm(6);
    usartm();
    Lcd_Init();
    Lcd_Cmd(0x8A);
    spiInit(SPI_MASTER_OSC_DIV4, SPI_DATA_SAMPLE_MIDDLE, SPI_CLOCK_IDLE_LOW, SPI_IDLE_2_ACTIVE);
    ANSEL = 0; // ENTRADAS DIGITALES Y BIT 0 ANALÓGICA
    ANSELH = 0;
    PORTA = 0; //PUERTO A EN 0
    PORTB = 0; //PUERTO B EN 0
    PORTC = 0; //PUERTO C EN 0
    PORTD = 0; //PUERTO D EN 0
    PORTE = 0; //PUERTO E EN 0
    //PINES RA0 Y RA2 COMO ENTRADAS, LOS DEMAS COMO SALIDAS
    TRISC = 0b00010000; //PUERTO C SALIDAS
    TRISD = 0; //PUERTO D SALIDAS
    TRISB = 0; //PUERTO B 
    OPTION_REG = 0b10000111; //SE APAGAN LAS PULLUPS DEL PUERTO B
    INTCONbits.GIE = 1; //SE HABILITAN LAS INTERRUPCIONES GLOBALES
    //    INTCONbits.T0IE = 1; //SE HABILITA LA INTERRUPCION DEL TIMER0
    INTCONbits.PEIE = 1; //SE HABILITAN LAS INTERRUPCIONES PERIFERICAS
    //    PIE1bits.ADIE = 1; //SE HABILITA LA INTERRUPCION DEL ADC
    //    INTCONbits.T0IF = 0; // SE LIMPIA LA BANDERA DE INTERRUPCION DEL TIMER 0
    //    PIR1bits.ADIF = 0; //SE LIMPIOA LA BANDERA DE INTERRUPCION DEL ADC
    PIR1bits.TXIF = 0;
    PIE1bits.TXIE = 1;




}

//******************************************************************************
// Subrutinas
//******************************************************************************

void map(void) {

    CP1 = ((pot1) / 51);
    DP1 = (((pot1 * 100) / 51)-(CP1 * 100)) / 10;
    UP1 = (((pot1 * 100) / 51)-(CP1 * 100)-(DP1 * 10));

    C1 = (CP1 + 0x30);
    D1 = (DP1 + 0x30);
    U1 = (UP1 + 0x30);


}

void map2(void) {
    CONTC = (cont1 / 100);
    CONTD = (cont1 - (CONTC * 100)) / 10;
    CONTU = (cont1 - (CONTC * 100)-(CONTD * 10));

    CO1 = (CONTC + 0x30);
    CO2 = (CONTD + 0x30);
    CO3 = (CONTU + 0x30);

}

void map3(void) {


    if (term1 >= 68) {

        TEMP = (((term1 - 68)*150) / 187);

        TEMPC = (TEMP / 100);
        TEMPD = (TEMP - (TEMPC * 100)) / 10;
        TEMPU = (TEMP - (TEMPC * 100)-(TEMPD * 10));

        T1 = (TEMPC + 0x30);
        T2 = (TEMPD + 0x30);
        T3 = (TEMPU + 0x30);
        temperatura();

    } else if (term1 < 68) {

        TEMPN = (((term1 * (-55)) / 68) + 55);

        TEMPND = (TEMPN / 10);
        TEMPNU = (TEMPN - (TEMPND * 10));

        TN1 = (TEMPND + 0x30);
        TN2 = (TEMPNU + 0x30);

        temperatura2();

    }





}

void mandar(void) {
    switch (SEND) {

        case 0:
            TXREG = 0x20;
            break;
        case 1:
            TXREG = 0x28;
            break;

        case 2:
            TXREG = C1;
            break;

        case 3:
            TXREG = 0x2E;
            break;
        case 4:
            TXREG = D1;
            break;
        case 5:
            TXREG = U1;
            break;
        case 6:
            TXREG = 0x29;
            break;

        case 7:
            TXREG = 0x2C;
            break;

        case 8:
            TXREG = 0x20;
            break;

        case 9:
            TXREG = 0x28;
            break;

        case 10:
            TXREG = CO1;
            break;

        case 11:
            TXREG = CO2;
            break;
        case 12:
            TXREG = CO3;
            break;

        case 13:
            TXREG = 0x29;
            break;
        case 14:
            TXREG = 0x2C;
            break;

        case 15:
            TXREG = 0x20;
            break;
        case 16:
            TXREG = 0x28;
            break;
        case 17:
            if (term1 >= 68) {
                TXREG = T1;
            } else if (term1 < 68) {
                TXREG = 45;
            }
            break;
        case 18:
            if (term1 >= 68) {
                TXREG = T2;
            } else if (term1 < 68) {
                TXREG = TN1;
            }
            break;

        case 19:
            if (term1 >= 68) {
                TXREG = T3;
            } else if (term1 < 68) {
                TXREG = TN2;
            }
            break;

        case 20:
            TXREG = 0x29;
            break;

        case 21:
            TXREG = 0x0D;
            SEND = 0;
            break;
    }

}

void temperatura(void) {
    Lcd_Set_Cursor(2, 12);
    Lcd_Write_String("+");
    Lcd_Set_Cursor(2, 13);
    Lcd_Write_Char(T1);
    Lcd_Set_Cursor(2, 14);
    Lcd_Write_Char(T2);
    Lcd_Set_Cursor(2, 15);
    Lcd_Write_Char(T3);

}

void temperatura2(void) {
    Lcd_Set_Cursor(2, 12);
    Lcd_Write_String("-");
    Lcd_Set_Cursor(2, 14);
    Lcd_Write_Char(TN1);
    Lcd_Set_Cursor(2, 15);
    Lcd_Write_Char(TN2);
}





