/*FRANCISCO MONT�FAR
 *CARNET 19379
 *ELECTR�NICA DIGITAL 2
 *LABORATORIO #2
 *LIBRER�AS E INTERRUPCIONES
 * 
 */
//******************************************************************************
// Importaci�n de librerias
//******************************************************************************

#include <xc.h>
#include <stdint.h>
#include "Osc.h"
//******************************************************************************
// Palabra de configuraci�n
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


//******************************************************************************
//Variables
//******************************************************************************




//******************************************************************************
// Prototipos de funciones
//******************************************************************************
void Setup(void);


//******************************************************************************
//Interrupci�n
//******************************************************************************
void __interrupt() isr (void){
    
}
//******************************************************************************
//Ciclo pincipal
//******************************************************************************

void main(void) {
    
    Setup();
    //**************************************************************************
    // Loop principal
    //**************************************************************************
    while(1){
        
}



//******************************************************************************
//Configuracion
//******************************************************************************
void Setup(void) {
    
    initOsc(10);
    ANSEL = 0b00000001;  // ENTRADAS DIGITALES Y BIT 0 ANAL�GICA
    ANSELH = 0; 
    PORTA = 0; //PUERTO A EN 0
    PORTB = 0; //PUERTO B EN 0
    PORTC = 0; //PUERTO C EN 0
    PORTD = 0; //PUERTO D EN 0
    PORTE = 0; //PUERTO E EN 0
    //PINES RA0,RA1 Y RA2 COMO ENTRADAS, LOS DEMAS COMO SALIDAS
    TRISA = 0b00000111; 
    TRISB = 0b00000000; //PUERTO B SALIDAS
    TRISC = 0; //PUERTO C SALIDAS
    TRISD = 0; //PUERTO D SALIDAS
    TRISE = 0; //PUERTO E SALIDAS
    OPTION_REG = 0b10000111; //SE APAGAN LAS PULLUPS DEL PUERTO B
    INTCONbits.GIE = 1;
    INTCONbits.T0IE = 1;
    INTCONbits.PEIE = 1;
    
    //236 AL TMR0
    
    
    
       
    
}

//******************************************************************************
// Subrutinas
//******************************************************************************
