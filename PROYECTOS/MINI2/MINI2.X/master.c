/*
 * File:   newmain.c
 * Author: franc
 *
 * 
 */



#include <xc.h>
#include <stdint.h>
#include <pic16f887.h>
#include "I2C.h"
#include "OSC.h"

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
#define _XTAL_FREQ 8000000      //SE CONFIGURA EL OSCILADOR EXTERNO

//******************************************************************************
//Variables
//******************************************************************************
uint8_t CONT = 0;
uint8_t SEND = 0;
uint8_t SEC = 0;
uint8_t MIN = 0;
uint8_t H = 0;
uint8_t DAY = 0;
uint8_t MONTH = 0;
uint8_t YEAR = 0;
uint8_t NADA = 0;
uint8_t SECU = 0;
uint8_t SECD = 0;
uint8_t MINU = 0;
uint8_t MIND = 0;
uint8_t HORAU = 0;
uint8_t HORAD = 0;
uint8_t DAYU = 0;
uint8_t DAYD = 0;
uint8_t MONTHU = 0;
uint8_t MONTHD = 0;
uint8_t YEARU = 0;
uint8_t YEARD = 0;
uint8_t SU = 0;
uint8_t SD = 0;
uint8_t MU = 0;
uint8_t MD = 0;
uint8_t HU = 0;
uint8_t HD = 0;
uint8_t DU = 0;
uint8_t DD = 0;
uint8_t MOU = 0;
uint8_t MOD = 0;
uint8_t YU = 0;
uint8_t YD = 0;




//******************************************************************************
// Prototipos de funciones
//******************************************************************************
void Setup(void);
void mandar(void);
void timeout(void);
void timein(void);
void conver(void);

//******************************************************************************
//Interrupción
//******************************************************************************

void __interrupt() ISR(void) {
    if (INTCONbits.T0IF == 1) {
        TMR0 = 236;
        CONT++;
        INTCONbits.T0IF = 0;
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
    timeout();
    if (CONT > 20) {
        ADCON0bits.GO_nDONE = 1;
        CONT = 0;
        PIE1bits.TXIE = 1;





        //**************************************************************************
        // Loop principal
        //**************************************************************************
        while (1) {








        }
    }

}
//******************************************************************************
//Configuracion
//******************************************************************************

void Setup(void) {
    I2C_Master_Init(100000);
    initOsc(6);
    TRISA = 0;
    TRISE = 0; //PUERTO E SALIDAS
    ANSEL = 0; // ENTRADAS DIGITALES Y BIT 0 ANALÓGICA
    ANSELH = 0;
    PORTA = 0; //PUERTO A EN 0
    PORTB = 0; //PUERTO B EN 0
    PORTC = 0; //PUERTO C EN 0
    PORTD = 0; //PUERTO D EN 0
    PORTE = 0; //PUERTO E EN 0
    //PINES RA0 Y RA2 COMO ENTRADAS, LOS DEMAS COMO SALIDAS
    TRISD = 0; //PUERTO D SALIDAS
    TRISB = 0; //PUERTO B 
    OPTION_REG = 0b10000111; //SE APAGAN LAS PULLUPS DEL PUERTO B
    INTCONbits.GIE = 1; //SE HABILITAN LAS INTERRUPCIONES GLOBALES
    INTCONbits.PEIE = 1; //SE HABILITAN LAS INTERRUPCIONES PERIFERICAS
    PIR1bits.TXIF = 0;
    PIE1bits.TXIE = 1;





}

//******************************************************************************
// Subrutinas
//******************************************************************************

void mandar(void) {
    switch (SEND) {

        case 0:
            TXREG = SU;
            break;
        case 1:
            TXREG = SD;
            break;

        case 2:
            TXREG = 0x3A;
            break;

        case 3:
            TXREG = MU;
            break;
        case 4:
            TXREG = MD;
            break;
        case 5:
            TXREG = 0x3A;
            break;
        case 6:
            TXREG = HU;
            break;

        case 7:
            TXREG = HD;
            break;

        case 8:
            TXREG = 0x20;
            break;

        case 9:
            TXREG = DAYU;
            break;

        case 10:
            TXREG = DAYD;
            break;

        case 11:
            TXREG = 0x2F;
            break;
        case 12:
            TXREG = MOU;
            break;

        case 13:
            TXREG = MOD;
            break;
        case 14:
            TXREG = 0x2F;
            break;
            
        case 15:
            TXREG = YU;
            break;
            
        case 16:
            TXREG = YD;
            break;
            
        case 17:
            TXREG = 0x0D;
            SEND = 0;
            break;
    }
}

void timeout(void) {
    I2C_Master_Start();
    I2C_Master_Write(0xD0);
    I2C_Master_Write(0);
    I2C_Master_Write(0b00000000);
    I2C_Master_Write(0b00000011);
    I2C_Master_Write(0b01010011);
    I2C_Master_Write(1);
    I2C_Master_Write(0x20);
    I2C_Master_Write(0x10);
    I2C_Master_Write(0x21);
    I2C_Master_Stop();




}

void timein(void) {
    I2C_Master_Start();
    I2C_Master_Write(0xD1);
    I2C_Master_Write(0);

    I2C_Master_Start();
    I2C_Master_Write(0xD1);
    SEC = I2C_Master_Read(0);
    MIN = I2C_Master_Read(0);
    H = I2C_Master_Read(0);
    NADA = I2C_Master_Read(0);
    DAY = I2C_Master_Read(0);
    MONTH = I2C_Master_Read(0);
    YEAR = I2C_Master_Read(1);
    I2C_Master_Stop();



}

void conver(void) {
    SECU = (SEC & 0b00001111);
    SECD = ((SEC & 0b00001111) >> 4);
    MINU = (MIN & 0b00001111);
    MIND = ((MIN & 0b00001111) >> 4);
    HORAU = (H & 0b00001111);
    HORAD = ((H & 0b00001111) >> 4);
    DAYU = (DAY & 0b00001111);
    DAYD = ((DAY & 0b00001111) >> 4);
    MONTHU = (MONTH & 0b00001111);
    MONTHD = ((MONTH & 0b00001111) >> 4);
    YEARU = (YEAR & 0b00001111);
    YEARD = ((YEAR & 0b00001111) >> 4);


    SU = (SECU + 0x30);
    SD = (SECD + 0x30);
    MU = (MINU + 0x30);
    MD = (MIND + 0x30);
    HU = (HORAU + 0x30);
    HD = (HORAD + 0x30);
    DU = (DAYU + 0x30);
    DD = (DAYD + 0x30);
    MOU = (MONTHU + 0x30);
    MOD = (MONTHD + 0x30);
    YU = (YEARU + 0x30);
    YD = (YEARD + 0x30);




}