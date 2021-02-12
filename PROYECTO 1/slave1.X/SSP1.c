#include <pic16f887.h>
#include <xc.h>
#include "SSP1.h"

void configSSP1(uint8_t sspm, uint8_t ckp, uint8_t cke, uint8_t smp) {

    SSPCONbits.SSPEN = 1;
    switch (sspm) {

        case 0: //MASTER, FOSC/4
            SSPCONbits.SSPM3 = 0;
            SSPCONbits.SSPM2 = 0;
            SSPCONbits.SSPM1 = 0;
            SSPCONbits.SSPM0 = 0;
            switch (SMP) {
                case 0:
                    SSPSTATbits.SMP = 0;
                    break;

                case 1:
                    SSPSTATbits.SMP = 1;
                    break;
            }
            break;

        case 1: //MASTER, FOSC/16
            SSPCONbits.SSPM3 = 0;
            SSPCONbits.SSPM2 = 0;
            SSPCONbits.SSPM1 = 0;
            SSPCONbits.SSPM0 = 1;
            switch (SMP) {
                case 0:
                    SSPSTATbits.SMP = 0;
                    break;

                case 1:
                    SSPSTATbits.SMP = 1;
                    break;
            }
            break;

        case 2: //MASTER, FOSC/64
            SSPCONbits.SSPM3 = 0;
            SSPCONbits.SSPM2 = 0;
            SSPCONbits.SSPM1 = 1;
            SSPCONbits.SSPM0 = 0;
            switch (SMP) {
                case 0:
                    SSPSTATbits.SMP = 0;
                    break;

                case 1:
                    SSPSTATbits.SMP = 1;
                    break;
            }
            break;

        case 3: //MASTER, TMR2 OUTPUT/2
            SSPCONbits.SSPM3 = 0;
            SSPCONbits.SSPM2 = 0;
            SSPCONbits.SSPM1 = 1;
            SSPCONbits.SSPM0 = 1;
            switch (SMP) {
                case 0:
                    SSPSTATbits.SMP = 0;
                    break;

                case 1:
                    SSPSTATbits.SMP = 1;
                    break;
            }
            break;

        case 4: //SLAVE, SCK,SS ENABLED
            SSPCONbits.SSPM3 = 0;
            SSPCONbits.SSPM2 = 1;
            SSPCONbits.SSPM1 = 0;
            SSPCONbits.SSPM0 = 0;
            switch (SMP) {
                case 0:
                    SSPSTATbits.SMP = 0;
                    break;
            }
            break;


        case 5: //SLAVE, SCK, SS DISABLED
            SSPCONbits.SSPM3 = 0;
            SSPCONbits.SSPM2 = 1;
            SSPCONbits.SSPM1 = 0;
            SSPCONbits.SSPM0 = 1;

            switch (SMP) {
                case 0:
                    SSPSTATbits.SMP = 0;
                    break;
            }
            break;

        default: //MASTER, FOSC/64
            SSPCONbits.SSPM3 = 0;
            SSPCONbits.SSPM2 = 0;
            SSPCONbits.SSPM1 = 1;
            SSPCONbits.SSPM0 = 0;
            switch (SMP) {
                case 0:
                    SSPSTATbits.SMP = 0;
                    break;

                case 1:
                    SSPSTATbits.SMP = 1;
                    break;
            }
            break;

    }

    switch (ckp) {
        case 0:
            SSPCONbits.CKP = 0;
            switch (CKE) {
                case 0:
                    SSPSTATbits.CKE = 1;
                    break;
                case 1:
                    SSPSTATbits.CKE = 0;
            }

            break;
        case 1:
            SSPCONbits.CKP = 1;
            switch (CKE) {
                case 0:
                    SSPSTATbits.CKE = 1;
                    break;
                case 1:
                    SSPSTATbits.CKE = 0;

            }
            break;

    }





}
