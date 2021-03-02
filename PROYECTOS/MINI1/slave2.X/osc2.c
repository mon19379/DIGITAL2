#include <pic16f887.h>
#include <xc.h>
#include "osc2.h"
//******************************************************************************
//Inicialización del oscilador interno pg. 62
//******************************************************************************
void initOscs2(uint8_t IRCF){
    
    switch (IRCF){
        
        case 0: //OSCILADOR DE 31 kHz
            OSCCONbits.IRCF2 = 0;
            OSCCONbits.IRCF1 = 0;
            OSCCONbits.IRCF0 = 0;
            
            break;
        
        case 1: //OSCILADOR DE 125 kHz
            OSCCONbits.IRCF2 = 0;
            OSCCONbits.IRCF1 = 0;
            OSCCONbits.IRCF0 = 1;
            break;
    
        case 2: //OSCILADOR DE 250 kHz
            OSCCONbits.IRCF2 = 0;
            OSCCONbits.IRCF1 = 1;
            OSCCONbits.IRCF0 = 0;
            break;
            
        case 3: //OSCILADOR DE 500kHz
            OSCCONbits.IRCF2 = 0;
            OSCCONbits.IRCF1 = 1;
            OSCCONbits.IRCF0 = 1;
            break;
            
        case 4: //OSCILADOR DE 1MHz
            OSCCONbits.IRCF2 = 1;
            OSCCONbits.IRCF1 = 0;
            OSCCONbits.IRCF0 = 0;
            break;
            
        case 5: //OSCILADOR DE 2MHz
            OSCCONbits.IRCF2 = 1;
            OSCCONbits.IRCF1 = 0;
            OSCCONbits.IRCF0 = 1;
            break;
            
            
        case 6: //OSCILADOR DE 4MHz
            OSCCONbits.IRCF2 = 1;
            OSCCONbits.IRCF1 = 1;
            OSCCONbits.IRCF0 = 0;
            break;
            
        case 7: //OSCILADOR DE 8MHz
            OSCCONbits.IRCF2 = 1;
            OSCCONbits.IRCF1 = 1;
            OSCCONbits.IRCF0 = 1;
            break;
                   
    
        
        
        default: //OSCILADOR DE 4MHz
            OSCCONbits.IRCF2 = 1;
            OSCCONbits.IRCF1 = 1;
            OSCCONbits.IRCF0 = 0;
            break;
    
    }
    
    OSCCONbits.SCS = 1; //SE VA A USAR EL OSCILADOR INTERNO
    
    
}
