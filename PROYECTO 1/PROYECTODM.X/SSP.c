/*
 * File            : spi.c
 * Author          : Ligo George
 * Company         : electroSome
 * Project         : SPI Library for MPLAB XC8
 * Microcontroller : PIC 16F877A
 * Created on April 15, 2017, 5:59 PM
 */
#include <pic16f887.h>
#include <xc.h>
#include "SSP.h"

void spiInit(Spi_Type sType, Spi_Data_Sample sDataSample, Spi_Clock_Idle sClockIdle, Spi_Transmit_Edge sTransmitEdge)
{
    TRISC5 = 0;
    if(sType & 0b00000100) //If Slave Mode
    {
        SSPSTAT = sTransmitEdge;
        TRISC3 = 1;
    }
    else              //If Master Mode
    {
        SSPSTAT = sDataSample | sTransmitEdge;
        TRISC3 = 0;
    }
    
    SSPCON = sType | sClockIdle;
}

static void spiReceiveWait()
{
    while ( !SSPSTATbits.BF ); // Wait for Data Receive complete
}

void spiWrite(char dat)  //Write data to SPI bus
{
    SSPBUF = dat;
}

unsigned spiDataReady() //Check whether the data is ready to read
{
    if(SSPSTATbits.BF){
        return 1;
    }
    else{
        return 0;
    }
}

char spiRead() //REad the received data
{
    spiReceiveWait();        // wait until the all bits receive
    return(SSPBUF); // read the received data from the buffer
}


//#include <pic16f887.h>
//#include <xc.h>
//#include "SSP.h"
//
//void configSSP(uint8_t sspm, uint8_t ckp, uint8_t cke, uint8_t smp) {

//    SSPCONbits.SSPEN = 1;
//    switch (sspm) {
//
//        case 0: //MASTER, FOSC/4
//            SSPCONbits.SSPM3 = 0;
//            SSPCONbits.SSPM2 = 0;
//            SSPCONbits.SSPM1 = 0;
//            SSPCONbits.SSPM0 = 0;
//            switch (SMP) {
//                case 0:
//                    SSPSTATbits.SMP = 0;
//                    break;
//
//                case 1:
//                    SSPSTATbits.SMP = 1;
//                    break;
//            }
//            break;
//
//        case 1: //MASTER, FOSC/16
//            SSPCONbits.SSPM3 = 0;
//            SSPCONbits.SSPM2 = 0;
//            SSPCONbits.SSPM1 = 0;
//            SSPCONbits.SSPM0 = 1;
//            switch (SMP) {
//                case 0:
//                    SSPSTATbits.SMP = 0;
//                    break;
//
//                case 1:
//                    SSPSTATbits.SMP = 1;
//                    break;
//            }
//            break;
//
//        case 2: //MASTER, FOSC/64
//            SSPCONbits.SSPM3 = 0;
//            SSPCONbits.SSPM2 = 0;
//            SSPCONbits.SSPM1 = 1;
//            SSPCONbits.SSPM0 = 0;
//            switch (SMP) {
//                case 0:
//                    SSPSTATbits.SMP = 0;
//                    break;
//
//                case 1:
//                    SSPSTATbits.SMP = 1;
//                    break;
//            }
//            break;
//
//        case 3: //MASTER, TMR2 OUTPUT/2
//            SSPCONbits.SSPM3 = 0;
//            SSPCONbits.SSPM2 = 0;
//            SSPCONbits.SSPM1 = 1;
//            SSPCONbits.SSPM0 = 1;
//            switch (SMP) {
//                case 0:
//                    SSPSTATbits.SMP = 0;
//                    break;
//
//                case 1:
//                    SSPSTATbits.SMP = 1;
//                    break;
//            }
//            break;
//
//        case 4: //SLAVE, SCK,SS ENABLED
//            SSPCONbits.SSPM3 = 0;
//            SSPCONbits.SSPM2 = 1;
//            SSPCONbits.SSPM1 = 0;
//            SSPCONbits.SSPM0 = 0;
//            switch (SMP) {
//                case 0:
//                    SSPSTATbits.SMP = 0;
//                    break;
//            }
//            break;
//
//
//        case 5: //SLAVE, SCK, SS DISABLED
//            SSPCONbits.SSPM3 = 0;
//            SSPCONbits.SSPM2 = 1;
//            SSPCONbits.SSPM1 = 0;
//            SSPCONbits.SSPM0 = 1;
//
//            switch (SMP) {
//                case 0:
//                    SSPSTATbits.SMP = 0;
//                    break;
//            }
//            break;
//
//        default: //MASTER, FOSC/64
//            SSPCONbits.SSPM3 = 0;
//            SSPCONbits.SSPM2 = 0;
//            SSPCONbits.SSPM1 = 1;
//            SSPCONbits.SSPM0 = 0;
//            switch (SMP) {
//                case 0:
//                    SSPSTATbits.SMP = 0;
//                    break;
//
//                case 1:
//                    SSPSTATbits.SMP = 1;
//                    break;
//            }
//            break;
//
//    }
//
//    switch (ckp) {
//        case 0:
//            SSPCONbits.CKP = 0;
//            switch (CKE) {
//                case 0:
//                    SSPSTATbits.CKE = 1;
//                    break;
//                case 1:
//                    SSPSTATbits.CKE = 0;
//            }
//
//            break;
//        case 1:
//            SSPCONbits.CKP = 1;
//            switch (CKE) {
//                case 0:
//                    SSPSTATbits.CKE = 1;
//                    break;
//                case 1:
//                    SSPSTATbits.CKE = 0;
//
//            }
//            break;
//
//    }









