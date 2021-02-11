

  
#ifndef SSP_H
#define	SSP_H

#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>

void configSSP(uint8_t sspm, uint8_t ckp, uint8_t sspen, uint8_t cke, uint8_t smp);


#endif	/* SSP_H */

