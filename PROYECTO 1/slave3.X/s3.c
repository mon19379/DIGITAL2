#include <xc.h>
#include <stdint.h>
#include <pic16f887.h>
#include "oscs3.h"
#include "adcs3.h"
#include "SSP3.h"

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

uint8_t term = 0;
uint8_t CONTERM = 0;




//******************************************************************************
// Prototipos de funciones
//******************************************************************************
void Setup(void);

//******************************************************************************
//Interrupción
//******************************************************************************

void __interrupt() ISR(void) {
    
    
     if (INTCONbits.T0IF == 1) {
        TMR0 = 236;
        CONTERM++;
        INTCONbits.T0IF = 0;
    }

    if (PIR1bits.SSPIF == 1) {
        spiWrite(term);
        PIR1bits.SSPIF = 0;
    }


     if (PIR1bits.ADIF == 1) {
        term = ADRESH;
        PIR1bits.ADIF = 0;
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
         if (CONTERM > 20) {
            ADCON0bits.GO_nDONE = 1;
            CONTERM = 0;
        }
        PORTD = term;











    }
}
//******************************************************************************
//Configuracion
//******************************************************************************

void Setup(void) {
    configADC3(1, 10); //SE LLAMA LA CONFIG DEL ADC
    initOscs3(6);
    spiInit(SPI_SLAVE_SS_EN, SPI_DATA_SAMPLE_MIDDLE, SPI_CLOCK_IDLE_LOW, SPI_IDLE_2_ACTIVE);
    ANSEL = 0; // ENTRADAS DIGITALES Y BIT 0 ANALÓGICA
    ANSELH = 0b00000010;
    PORTA = 0; //PUERTO A EN 0
    PORTB = 0; //PUERTO B EN 0
    PORTC = 0; //PUERTO C EN 0
    PORTD = 0; //PUERTO D EN 0
    PORTE = 0; //PUERTO E EN 0
    //PINES RA0 Y RA2 COMO ENTRADAS, LOS DEMAS COMO SALIDAS
    TRISC = 0b00001000; //PUERTO C SALIDAS
    TRISA = 0b00100000; //PUERTO A SALIDAS
    TRISB = 0b00000010; //PUERTO B 
    TRISD = 0;
    TRISE = 0;
    OPTION_REG = 0b10000111; //SE APAGAN LAS PULLUPS DEL PUERTO B
    INTCONbits.GIE = 1; //SE HABILITAN LAS INTERRUPCIONES GLOBALES
    INTCONbits.PEIE = 1; //SE HABILITAN LAS INTERRUPCIONES PERIFERICAS
    PIE1bits.ADIE = 1; //SE HABILITA LA INTERRUPCION DEL ADC
    PIR1bits.ADIF = 0; //SE LIMPIOA LA BANDERA DE INTERRUPCION DEL ADC
    PIR1bits.SSPIF = 0;
    PIE1bits.SSPIE = 1;
    INTCONbits.T0IE = 1;
    INTCONbits.T0IF = 0;


}




//******************************************************************************
// Subrutinas
//******************************************************************************








