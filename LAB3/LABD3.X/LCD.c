/*
 * File:   LCD.c
 * Author: Extraído de electrosome.com
 *
 * Created on 4 de febrero de 2021, 12:52 PM
 */

#include <xc.h>
#include <stdint.h>
#include "LCD.h"

void Lcd_Port(char a) {
    PORTD = a;
}

void Lcd_Cmd(char a) {
    Lcd_Port(a);
    RS = 0; // => RS = 0
   
    EN = 1; // => E = 1
    __delay_ms(5);
    EN = 0; // => E = 0
}

Lcd_Clear() {
    Lcd_Cmd(0);
    Lcd_Cmd(1);
}

void Lcd_Set_Cursor(char a, char b) {
    char temp;
    if (a == 1) {
        temp = 0x80 + b - 1;
        Lcd_Cmd(temp);
    } else if (a == 2) {
        temp = 0xC0 + b - 1;
        Lcd_Cmd(temp);
    }
}

void Lcd_Init() {
    
    /////////////////////////////////////////////////////

    Lcd_Cmd(0x38);
    Lcd_Cmd(0x0C);
    Lcd_Cmd(0x06);
    Lcd_Cmd(0x80);
}

void Lcd_Write_Char(char a) {
    RS = 1;             // => RS = 1
   Lcd_Port(a);             //Data transfer
   EN = 1;
   __delay_us(40);
   EN = 0;
   RS = 0;
}

void Lcd_Write_String(char *a) {
   int i;
	for(i=0;a[i]!='\0';i++)
	   Lcd_Write_Char(a[i]);
}

void Lcd_Shift_Right() {
    Lcd_Cmd(0x1C);
   
}

void Lcd_Shift_Left() {
    Lcd_Cmd(0x18);
   
}

