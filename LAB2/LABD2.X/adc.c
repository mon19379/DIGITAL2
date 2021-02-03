#include <pic16f887.h>
#include <xc.h>
#include "adc.h"



//******************************************************************************
// CONFIGURACION DEL ADC
//******************************************************************************
void configADC(uint8_t fosc, uint8_t chan){
    
    switch (fosc) {
        
        case 0:
            ADCON0bits.ADCS = 0b00;
            break;
            
        case 1:
            ADCON0bits.ADCS = 0b01;
            break;
            
        case 2:
            ADCON0bits.ADCS = 0b10;
            break;
            
        case 3:
            ADCON0bits.ADCS = 0b11;
            break;
            
        default:
            ADCON0bits.ADCS = 0b00;
            break;
    }
    switch (chan) {
        case 0:
            ADCON0bits.CHS = 0b0000;
            break;
        
        case 1:
            ADCON0bits.CHS = 0b0001;
            break;
           
        case 2:
            ADCON0bits.CHS = 0b0010;
            break;
            
        case 3:
            ADCON0bits.CHS = 0b0011;
            break;
            
        case 4:
            ADCON0bits.CHS = 0b0100;
            break;
            
        case 5:
            ADCON0bits.CHS = 0b0101;
            break;
            
        case 6:
            ADCON0bits.CHS = 0b0110;
            break;
            
        case 7:
            ADCON0bits.CHS = 0b0111;
            break;
            
        case 8:
            ADCON0bits.CHS = 0b1000;
            break;
            
        case 9:
            ADCON0bits.CHS = 0b1001;
            break;
            
        case 10:
            ADCON0bits.CHS = 0b1010;
            break;
            
        case 11:
            ADCON0bits.CHS = 0b1011;
            break;
            
        case 12:
            ADCON0bits.CHS = 0b1100;
            break;
            
        case 13:
            ADCON0bits.CHS = 0b1101;
            break;
            
        case 14:
            ADCON0bits.CHS = 0b1110;
            break;
            
        case 15:
            ADCON0bits.CHS = 0b1111;
            break;
            
        default:
            ADCON0bits.CHS = 0b0000;
            break;
            
            
    }
    
    
    ADCON0bits.GO_nDONE = 1;
    
 
   
    ADCON0bits.ADON = 1;
    ADCON1 = 0;
            
            
            
    }
   
    
         

