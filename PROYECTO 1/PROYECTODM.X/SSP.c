#include <pic16f887.h>
#include <xc.h>
#include "SSP.h"

void main(uint8_t sspm, uint8_t ckp, uint8_t sspen, uint8_t cke, uint8_t smp) {

    switch (sspm) {
        case 0:
            SSPCONbits.SSPM3 = 0;
            SSPCONbits.SSPM2 = 0;
            SSPCONbits.SSPM1 = 0;
            SSPCONbits.SSPM0 = 0;
            break;

        case 1:
            SSPCONbits.SSPM3 = 0;
            SSPCONbits.SSPM2 = 0;
            SSPCONbits.SSPM1 = 0;
            SSPCONbits.SSPM0 = 1;
            break;

        case 2:
            SSPCONbits.SSPM3 = 0;
            SSPCONbits.SSPM2 = 0;
            SSPCONbits.SSPM1 = 1;
            SSPCONbits.SSPM0 = 0;
            break;

        case 3:
            SSPCONbits.SSPM3 = 0;
            SSPCONbits.SSPM2 = 0;
            SSPCONbits.SSPM1 = 1;
            SSPCONbits.SSPM0 = 1;
            break;

        case 4:
            SSPCONbits.SSPM3 = 0;
            SSPCONbits.SSPM2 = 1;
            SSPCONbits.SSPM1 = 0;
            SSPCONbits.SSPM0 = 0;
            break;

        case 5:
            SSPCONbits.SSPM3 = 0;
            SSPCONbits.SSPM2 = 1;
            SSPCONbits.SSPM1 = 0;
            SSPCONbits.SSPM0 = 1;
            break;

        default:
            SSPCONbits.SSPM3 = 0;
            SSPCONbits.SSPM2 = 0;
            SSPCONbits.SSPM1 = 1;
            SSPCONbits.SSPM0 = 0;
            break;

    }
    
    switch (ckp){
        case 0:
            SSPCONbits.CKP = 
    }

}

