

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef OSCM_H
#define	OSCM_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>

void initOscm(uint8_t IRCF);



#endif	/* OSCM_H */