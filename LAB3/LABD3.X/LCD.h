
#ifndef LCD_H
#define	LCD_H


#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
#define _XTAL_FREQ 4000000 

#ifndef EN
#define	EN PORTBbits.RB5
#endif

#ifndef RS
#define	RS PORTBbits.RB3
#endif

#ifndef RW
#define	RW PORTBbits.RB4
#endif


void Lcd_Port(char a);
void Lcd_Cmd(char a);
void Lcd_Set_Cursor(char a, char b);
void Lcd_Init();
void Lcd_Write_Char(char a);
void Lcd_Write_String(char *a);
void Lcd_Shift_Right();
void Lcd_Shift_Left();
#endif	/* LCD_H */

