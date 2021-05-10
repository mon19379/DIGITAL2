#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "inc/hw_ints.h"
#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"
#include "driverlib/gpio.h"
#include "driverlib/timer.h"
#include "driverlib/uart.h"
#include "driverlib/pin_map.h"



//***********************************************************************************************************************
//VARIABLES
//***********************************************************************************************************************
uint32_t periodo;
char entra;
char letra;
uint8_t sal = 0;
uint8_t sal1 = 0;
uint8_t sal2 = 0;

//***********************************************************************************************************************
//PROTOTIPOS DE FUNCION
//***********************************************************************************************************************
void setup(void);
void T0Handler(void);
void UARTHandler(void);

//***********************************************************************************************************************
//INTERRUPCION
//***********************************************************************************************************************
void T0Handler(void){
    TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT); //SE LIMPIA EL TIMER


    if(GPIOPinRead(GPIO_PORTF_BASE, entra)){
           GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1| GPIO_PIN_2|GPIO_PIN_3, 0);
    }

    else{
        GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1| GPIO_PIN_2|GPIO_PIN_3, entra);
    }

}

void UARTHandler(void){
    UARTIntClear(UART0_BASE, UART_INT_RX | UART_INT_RT); //SE LIMPIA EL UART
    letra = UARTCharGet(UART0_BASE);


        if (letra == 'r'){
            entra = 2;
            sal++;
        }

        else if (letra == 'g'){
            entra = 8;
            sal1++;
            sal = 0;
            sal2 = 0;
        }

        else if (letra == 'b'){
             entra = 4;
             sal2++;
             sal1 = 0;
             sal = 0;
           }

        if ((sal) == 2 && (entra) == 2){
            sal = 0;
            entra = 0;
        }


        if ((sal1) == 2 && (entra) == 8){
            sal1 = 0;
            entra = 0;
        }


        if ((sal2) == 2 && (entra) == 4){
            sal2 = 0;
            entra = 0;
        }








}

//***********************************************************************************************************************
//MAIN LOOP
//************************************************************************************************************************
int main(void){
    setup();
    while(1){

    }

}

//*************************************************************************************************************************
//FUNCIONES
//************************************************************************************************************************

void setup(void){

    //CONFIGURACION DEL TIMER
    //SysCtlClockSet(OSCILADOR PRINCIPAL, DEFALUT OSC EXT, USAMOS PLL(400MHz) Y SE  DIVIDE DENTRO DE 2, DIVIDIMOS DENTRO DE 5)
       SysCtlClockSet(SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ | SYSCTL_USE_PLL | SYSCTL_SYSDIV_5); //40MHz
       SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);//SE HABILITA PUERTO F
       GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,GPIO_PIN_1| GPIO_PIN_2|GPIO_PIN_3);
       SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0); //SE HABILITA EL TIMER0
       TimerConfigure(TIMER0_BASE, TIMER_CFG_PERIODIC); //SE CONFIGURA EL TIMER
       periodo = (SysCtlClockGet()) / 1;//  SE CALCULA PERIODO DEL TEMP (0.5SEG)
       TimerLoadSet(TIMER0_BASE, TIMER_A, periodo - 1);//SE ESTABLECE EL PERIODO (2s)
       IntEnable(INT_TIMER0A);     // SE HABILITA LA INTERRUPCION
       TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);// SE ESTABLECE LA INTERRUPCION POR TIMEOUT
       TimerIntRegister(TIMER0_BASE, TIMER_A, T0Handler);
       TimerEnable(TIMER0_BASE, TIMER_A);// SE HABILITA EL TIMER


       //CONFIGURACION UART
       SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA); //SE HABILITA PUERTO A
       SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0); //SE HABILITA EL UART
       UARTConfigSetExpClk(UART0_BASE, SysCtlClockGet(), 115200, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |UART_CONFIG_PAR_NONE));
       GPIOPinConfigure(GPIO_PA0_U0RX);
       GPIOPinConfigure(GPIO_PA1_U0TX);
       GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
       IntEnable(INT_UART0);
       UARTIntEnable(UART0_BASE, UART_INT_RX | UART_INT_RT);
       UARTIntRegister(UART0_BASE, UARTHandler);
       UARTEnable(UART0_BASE);

       IntMasterEnable();    // SE HABILITAN LAS INTERRUPCIONES GLOBALES
}
