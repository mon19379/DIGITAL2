#include <pic16f887.h>

#include "usart.h"

void usart(void){
    
    //CONFIG TX
    TXSTAbits.TX9 = 0; //TRANSMISION DE 8 BITS
    TXSTAbits.SYNC = 0; //ASINCRONO
    TXSTAbits.BRGH = 1; //HIGH SPEED
    BAUDCTLbits.BRG16 = 0; //BAUD RATE DE 8 BITS
    SPBRGH = 0;
    SPBRG = 25;
    PIE1bits.TXIE = 1;
    TXSTAbits.TXEN = 1;
    
    //CONFIG RX
    RCSTAbits.SPEN = 1;
    RCSTAbits. RX9 = 0;
    RCSTAbits.CREN = 1;
}