/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef ADCS1_H
#define	ADCS1_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>

void configADC1(uint8_t fosc, uint8_t chan);



#endif	/* ADCS1_H*/
