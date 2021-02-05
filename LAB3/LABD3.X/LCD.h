
#ifndef LCD_H
#define	LCD_H

char EN;
char RS;



#include <xc.h> // include processor files - each processor file is guarded.  
#include <stdint.h>
void Lcd_Port(char a);
void Lcd_Cmd(char a);
void Lcd_Set_Cursor(char a, char b);
void Lcd_Init();
void Lcd_Write_Char(char a);
void Lcd_Write_String(char *a);
void Lcd_Shift_Right();
void Lcd_Shift_Left();
#endif	/* LCD_H */

