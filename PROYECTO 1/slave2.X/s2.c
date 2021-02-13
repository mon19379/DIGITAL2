#include <xc.h>
#include <stdint.h>
#include <pic16f887.h>

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
uint8_t B1 = 0;
uint8_t B2 = 0;






//******************************************************************************
// Prototipos de funciones
//******************************************************************************
void Setup(void);

//******************************************************************************
//Interrupción
//******************************************************************************

void __interrupt() ISR(void) {
    if (RBIF == 1) { //SE REVISA LA BANDERA DE INTERRUPCION DEL PUERTO B
        if (PORTBbits.RB0 == 0) { //ANTIREBOTE, SI NO SE PRESIONA EL BOTON
            B1 = 1; // SE ENCIENDE LA BANDERA DEL BOTON DE INCREMENTO
        } else {
            if (B1 == 1 && PORTBbits.RB0 == 1) { //SE  PRESIONA EL BOTON
                B1 = 0; //SE APAGA LA BANDERA DE BOTON DE INCREMENTO
                PORTD++; // SE INCREMENTA EL PUERTOD

            }
        }

        if (PORTBbits.RB1 == 0) { //ANTIREBOTE, SI NO SE PRESIONA EL BOTON
            B2 = 1; // SE ENCIENDE LA BANDERA DEL BOTON DE DECREMENTO 
        } else {
            if (B2 == 1 && PORTBbits.RB1 == 1) { //SE PRESIONA EL BOTON
                B2 = 0; //SE APAGA LA BANDERA DE BOTON DE DECREMENTO                
                PORTD--; // SE DECREMENTA UN EL PUERTOD

            }
        }

        INTCONbits.RBIF = 0; //SE APAGA LA BANDERA DE INTERRUPION DEL PUERTO B



    }

}
//******************************************************************************
//Ciclo pincipal
//******************************************************************************

void main(void) {

    Setup();







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
    TRISD = 0;
    TRISE = 0; //PUERTO E SALIDAS
    ANSEL = 0; // ENTRADAS DIGITALES Y BIT 0 ANALÓGICA
    ANSELH = 0;
    PORTA = 0; //PUERTO A EN 0
    PORTB = 0; //PUERTO B EN 0
    PORTC = 0; //PUERTO C EN 0
    PORTD = 0; //PUERTO D EN 0
    PORTE = 0; //PUERTO E EN 0
    //PINES RA0 Y RA2 COMO ENTRADAS, LOS DEMAS COMO SALIDAS
    TRISC = 0b00001000; //PUERTO C SALIDAS
    TRISA = 0b00100000; //PUERTO A SALIDAS
    TRISB = 0b00000011; //PUERTO B 
    OPTION_REG = 0b00000111; //SE ENCIENDEN LAS PULLUPS DEL PUERTO B
    INTCONbits.GIE = 1; //SE HABILITAN LAS INTERRUPCIONES GLOBALES
    INTCONbits.PEIE = 1; //SE HABILITAN LAS INTERRUPCIONES PERIFERICAS
    INTCONbits.RBIE = 1; //SE HABILITA LA INTERRUPCION DEL PUERTO B
    INTCONbits.RBIF = 0; //SE LIMPIA LA BANDERA DEL INTERRUPCION DEL PUERTO B
    IOCB = 3; //SE HABILITA EL INTERRUPT ON CHANGE
    WPUB = 0b0000011;



}

//******************************************************************************
// Subrutinas
//******************************************************************************







