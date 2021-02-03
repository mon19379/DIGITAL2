/*FRANCISCO MONTÚFAR
 *CARNET 19379
 *ELECTRÓNICA DIGITAL 2
 *LABORATORIO #2
 *LIBRERÍAS E INTERRUPCIONES
 * 
 */
//******************************************************************************
// Importación de librerias
//******************************************************************************

#include <xc.h>
#include <stdint.h>
#include "Osc.h"
#include "adc.h"
#include "SIETESEG.h"
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


//******************************************************************************
//Variables
//******************************************************************************
uint8_t B1 = 0;
uint8_t B2 = 0;
uint8_t CONT = 0;
uint8_t NH = 0;
uint8_t NL = 0;
uint8_t pot = 0;
uint8_t FLAG = 0;




//******************************************************************************
// Prototipos de funciones
//******************************************************************************
void Setup(void);
void split(void);
void displays(void);

//******************************************************************************
//Interrupción
//******************************************************************************
void __interrupt() isr (void){
    
    if (T0IF == 1){
        TMR0 = 236;
        T0IF = 0;
        displays();
        
        
    }
    
    if (ADIF == 1){        
        pot = ADRESH;
        ADIF = 0;
        ADCON0bits.GO = 1;
    }
    
    if (RBIF == 1){
        if (PORTBbits.RB0 == 0){ //ANTIREBOTE, SE PRESIONA EL BOTON
            B1 = 1; // SE ENCIENDE LA BANDERA DEL CORREDOR 1
        }
        
        else{
            if (B1 == 1 && PORTBbits.RB0 == 1 ){ //SE DEJA DE PRESIONAR EL 
                B1 = 0;                              //BOTON
                PORTD ++;// SE INCREMENTA UN CONTADOR
                //PORTD = CONT;
            }
    }
    
        if (PORTBbits.RB1 == 0){ //ANTIREBOTE, SE PRESIONA EL BOTON
            B2 = 1; // SE ENCIENDE LA BANDERA DEL CORREDOR 1
        }
        
        else{
            if (B2 == 1 && PORTBbits.RB1 == 1 ){ //SE DEJA DE PRESIONAR EL 
                B2 = 0;                              //BOTON
                PORTD --;// SE DECREMENTA UN CONTADOR
                //PORTD = CONT;
            }
    }

     INTCONbits.RBIF = 0;   
        
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
    while(1){
        
}


}
//******************************************************************************
//Configuracion
//******************************************************************************
void Setup(void) {
    
    initOsc(10);
    configADC(2,0);
    ANSEL = 0;
    ANSEL = 0b00000001;  // ENTRADAS DIGITALES Y BIT 0 ANALÓGICA
    ANSELH = 0; 
    PORTA = 0; //PUERTO A EN 0
    PORTB = 0; //PUERTO B EN 0
    PORTC = 0; //PUERTO C EN 0
    PORTD = 0; //PUERTO D EN 0
    PORTE = 0; //PUERTO E EN 0
    //PINES RA0,RA1 Y RA2 COMO ENTRADAS, LOS DEMAS COMO SALIDAS
    TRISA = 0b00000111; 
    TRISB = 0b00000011; //PUERTO B 
    TRISC = 0; //PUERTO C SALIDAS
    TRISD = 0; //PUERTO D SALIDAS
    TRISE = 0; //PUERTO E SALIDAS
    OPTION_REG = 0b00000111; //SE APAGAN LAS PULLUPS DEL PUERTO B
    INTCONbits.GIE = 1;
    INTCONbits.T0IE = 1;
    INTCONbits.PEIE = 1;
    PIE1bits.ADIE = 1;
    INTCONbits.T0IF = 0;
    PIR1bits.ADIF = 0;
    INTCONbits.RBIE = 1;
    INTCONbits.RBIF = 0;
    IOCB = 3;
    
    
    //236 AL TMR0   
  
}
//******************************************************************************
// Subrutinas
//******************************************************************************

void displays(void){
    PORTAbits.RA3 = 0;
    PORTAbits.RA4 = 0;
    if (FLAG == 0){ 
        NL = pot & 0b00001111;
        PORTAbits.RA3 = 1;
        display(NL);
        FLAG = 1;
    }
    else{
        NH = pot;
        NH = NH & 0b11110000;
        NH = NH>>4;
        PORTAbits.RA4 = 1;
        display(NH);
        FLAG =0;
    }
}


    


