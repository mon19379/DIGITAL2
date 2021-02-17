/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef ADCS3_H
#define	ADCS3_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>

void configADC3(uint8_t fosc, uint8_t chan);



#endif	/* ADCS3_H*/
