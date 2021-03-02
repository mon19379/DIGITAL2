
#ifndef LCDM_H
#define	LCDM_H


#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
#define _XTAL_FREQ 4000000 

#ifndef EN
#define	EN PORTEbits.RE0
#endif

#ifndef RS
#define	RS PORTEbits.RE1
#endif

#ifndef RW
#define	RW 
#endif


void Lcd_Port(char a);
void Lcd_Cmd(char a);
void Lcd_Set_Cursor(char a, char b);
void Lcd_Init();
void Lcd_Write_Char(char a);
void Lcd_Write_String(char *a);
void Lcd_Shift_Right();
void Lcd_Shift_Left();
#endif	/* LCDM_H */