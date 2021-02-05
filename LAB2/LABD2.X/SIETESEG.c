#include <pic16f887.h>
#include <xc.h>
#include "SIETESEG.h"

void display(uint8_t segment) {

    switch (segment) {

        case 0: //0
            PORTCbits.RC0 = 0;
            PORTCbits.RC1 = 0;
            PORTCbits.RC2 = 0;
            PORTCbits.RC3 = 0;
            PORTCbits.RC4 = 0;
            PORTCbits.RC5 = 0;
            PORTCbits.RC6 = 1;
            PORTCbits.RC7 = 1;
            break;

        case 1: //1
            PORTCbits.RC0 = 1;
            PORTCbits.RC1 = 0;
            PORTCbits.RC2 = 0;
            PORTCbits.RC3 = 1;
            PORTCbits.RC4 = 1;
            PORTCbits.RC5 = 1;
            PORTCbits.RC6 = 1;
            PORTCbits.RC7 = 1;
            break;
        case 2: //2
            PORTCbits.RC0 = 0;
            PORTCbits.RC1 = 0;
            PORTCbits.RC2 = 1;
            PORTCbits.RC3 = 0;
            PORTCbits.RC4 = 0;
            PORTCbits.RC5 = 1;
            PORTCbits.RC6 = 0;
            PORTCbits.RC7 = 1;
            break;
        case 3: //3
            PORTCbits.RC0 = 0;
            PORTCbits.RC1 = 0;
            PORTCbits.RC2 = 0;
            PORTCbits.RC3 = 0;
            PORTCbits.RC4 = 1;
            PORTCbits.RC5 = 1;
            PORTCbits.RC6 = 0;
            PORTCbits.RC7 = 1;
            break;
        case 4: //4
            PORTCbits.RC0 = 1;
            PORTCbits.RC1 = 0;
            PORTCbits.RC2 = 0;
            PORTCbits.RC3 = 1;
            PORTCbits.RC4 = 1;
            PORTCbits.RC5 = 0;
            PORTCbits.RC6 = 0;
            PORTCbits.RC7 = 1;
            break;
        case 5: //5
            PORTCbits.RC0 = 0;
            PORTCbits.RC1 = 1;
            PORTCbits.RC2 = 0;
            PORTCbits.RC3 = 0;
            PORTCbits.RC4 = 1;
            PORTCbits.RC5 = 0;
            PORTCbits.RC6 = 0;
            PORTCbits.RC7 = 1;
            break;
        case 6: //6
            PORTCbits.RC0 = 0;
            PORTCbits.RC1 = 1;
            PORTCbits.RC2 = 0;
            PORTCbits.RC3 = 0;
            PORTCbits.RC4 = 0;
            PORTCbits.RC5 = 0;
            PORTCbits.RC6 = 0;
            PORTCbits.RC7 = 1;
            break;
        case 7: // 7
            PORTCbits.RC0 = 0;
            PORTCbits.RC1 = 0;
            PORTCbits.RC2 = 0;
            PORTCbits.RC3 = 1;
            PORTCbits.RC4 = 1;
            PORTCbits.RC5 = 1;
            PORTCbits.RC6 = 1;
            PORTCbits.RC7 = 1;
            break;
        case 8: //8
            PORTCbits.RC0 = 0;
            PORTCbits.RC1 = 0;
            PORTCbits.RC2 = 0;
            PORTCbits.RC3 = 0;
            PORTCbits.RC4 = 0;
            PORTCbits.RC5 = 0;
            PORTCbits.RC6 = 0;
            PORTCbits.RC7 = 1;
            break;
        case 9: //9
            PORTCbits.RC0 = 0;
            PORTCbits.RC1 = 0;
            PORTCbits.RC2 = 0;
            PORTCbits.RC3 = 0;
            PORTCbits.RC4 = 1;
            PORTCbits.RC5 = 0;
            PORTCbits.RC6 = 0;
            PORTCbits.RC7 = 1;
            break;
        case 10: //A
            PORTCbits.RC0 = 0;
            PORTCbits.RC1 = 0;
            PORTCbits.RC2 = 0;
            PORTCbits.RC3 = 1;
            PORTCbits.RC4 = 0;
            PORTCbits.RC5 = 0;
            PORTCbits.RC6 = 0;
            PORTCbits.RC7 = 1;
            break;
        case 11: //b
            PORTCbits.RC0 = 1;
            PORTCbits.RC1 = 1;
            PORTCbits.RC2 = 0;
            PORTCbits.RC3 = 0;
            PORTCbits.RC4 = 0;
            PORTCbits.RC5 = 0;
            PORTCbits.RC6 = 0;
            PORTCbits.RC7 = 1;
            break;
        case 12: //C
            PORTCbits.RC0 = 0;
            PORTCbits.RC1 = 1;
            PORTCbits.RC2 = 1;
            PORTCbits.RC3 = 0;
            PORTCbits.RC4 = 0;
            PORTCbits.RC5 = 0;
            PORTCbits.RC6 = 1;
            PORTCbits.RC7 = 1;
            break;
        case 13: //d
            PORTCbits.RC0 = 1;
            PORTCbits.RC1 = 0;
            PORTCbits.RC2 = 0;
            PORTCbits.RC3 = 0;
            PORTCbits.RC4 = 0;
            PORTCbits.RC5 = 1;
            PORTCbits.RC6 = 0;
            PORTCbits.RC7 = 1;
            break;
        case 14: //E
            PORTCbits.RC0 = 0;
            PORTCbits.RC1 = 1;
            PORTCbits.RC2 = 1;
            PORTCbits.RC3 = 0;
            PORTCbits.RC4 = 0;
            PORTCbits.RC5 = 0;
            PORTCbits.RC6 = 0;
            PORTCbits.RC7 = 1;
            break;
        case 15: //F
            PORTCbits.RC0 = 0;
            PORTCbits.RC1 = 1;
            PORTCbits.RC2 = 1;
            PORTCbits.RC3 = 1;
            PORTCbits.RC4 = 0;
            PORTCbits.RC5 = 0;
            PORTCbits.RC6 = 0;
            PORTCbits.RC7 = 1;
            break;

        default:
            PORTCbits.RC0 = 0;
            PORTCbits.RC1 = 0;
            PORTCbits.RC2 = 0;
            PORTCbits.RC3 = 0;
            PORTCbits.RC4 = 0;
            PORTCbits.RC5 = 0;
            PORTCbits.RC6 = 1;
            PORTCbits.RC7 = 1;
            break;


    }
}


