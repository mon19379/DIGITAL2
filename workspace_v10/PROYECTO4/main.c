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
uint8_t estado1;
uint8_t estado2;
uint8_t estado3;
uint8_t estado4;
uint8_t numero;
//***********************************************************************************************************************
//PROTOTIPOS DE FUNCION
//***********************************************************************************************************************
void setup(void);
void T0Handler(void);


//***********************************************************************************************************************
//INTERRUPCION
//***********************************************************************************************************************
void T0Handler(void){
    TimerIntClear(TIMER0_BASE, TIMER_TIMA_TIMEOUT); //SE LIMPIA EL TIMER


    UARTCharPutNonBlocking(UART1_BASE, estado1 + 48);
    UARTCharPutNonBlocking(UART1_BASE, estado2 + 48);
    UARTCharPutNonBlocking(UART1_BASE, estado3 + 48);
    UARTCharPutNonBlocking(UART1_BASE, estado4 + 48);
    UARTCharPutNonBlocking(UART1_BASE, 10);





}



//***********************************************************************************************************************
//MAIN LOOP
//************************************************************************************************************************
int main(void){
    setup();
    while(1){


        //BOTON 1
        if(GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_2) == 0){
            GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_0, 0);
            GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_1, 2);
            estado1 = 1;

        }
        else{
            GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_0, 1);
            GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_1, 0);
            estado1 = 0;

        }

        //BOTON 2
        if(GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_3) == 0){
            GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_2, 0);
            GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_3, 8);
            estado2 = 2;
        }
        else{
            GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_2, 6);
            GPIOPinWrite(GPIO_PORTD_BASE,GPIO_PIN_3, 0);
            estado2 = 0;

        }

        //BOTON 3
        if(GPIOPinRead(GPIO_PORTB_BASE, GPIO_PIN_3) == 0){
            GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_1, 0);
            GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_2, 4);
            estado3 = 3;
        }
        else{
            GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_1, 2);
            GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_2, 0);
            estado3 = 0;
       }


        //BOTON 4
        if(GPIOPinRead(GPIO_PORTC_BASE, GPIO_PIN_4) == 0){
            GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_3, 0);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 2);
            estado4 = 4;
       }
        else{
            GPIOPinWrite(GPIO_PORTE_BASE,GPIO_PIN_3, 8);
            GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1, 0);
            estado4 = 0;

       }

    }

}

//*************************************************************************************************************************
//FUNCIONES
//************************************************************************************************************************

void setup(void){

    //CONFIGURACION DEL uC
    //SysCtlClockSet(OSCILADOR PRINCIPAL, DEFALUT OSC EXT, USAMOS PLL(400MHz) Y SE  DIVIDE DENTRO DE 2, DIVIDIMOS DENTRO DE 5)
       SysCtlClockSet(SYSCTL_OSC_MAIN | SYSCTL_XTAL_16MHZ | SYSCTL_USE_PLL | SYSCTL_SYSDIV_5); //40MHz
       SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);//SE HABILITA PUERTO F
       SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOD);//SE HABILITA PUERTO D
       SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOC);//SE HABILITA PUERTO C
       SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB);//SE HABILITA PUERTO B
       SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOE);//SE HABILITA PUERTO F
       GPIOPinTypeGPIOOutput(GPIO_PORTD_BASE,GPIO_PIN_0| GPIO_PIN_1| GPIO_PIN_2|GPIO_PIN_3);//SALIDAS PUERTO D
       GPIOPinTypeGPIOOutput(GPIO_PORTE_BASE,GPIO_PIN_1| GPIO_PIN_2|GPIO_PIN_3); //SALIDAS PUERTO E
       GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1); //SALIDAS PUERTO F
       GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_2|GPIO_PIN_3, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU); //PULLUPS PUERTO F
       GPIOPadConfigSet(GPIO_PORTB_BASE,GPIO_PIN_3, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU); //PULLUPS PUERTO B
       GPIOPadConfigSet(GPIO_PORTC_BASE, GPIO_PIN_4, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU); //PULLUPS PUERTO C

       //CONFIGURACION DEL TIMER0
       SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0); //SE HABILITA EL TIMER0
       TimerConfigure(TIMER0_BASE, TIMER_CFG_PERIODIC); //SE CONFIGURA EL TIMER
       periodo = (SysCtlClockGet()) / 200;//  SE CALCULA PERIODO DEL TEMP (0.5SEG)
       TimerLoadSet(TIMER0_BASE, TIMER_A, periodo - 1);//SE ESTABLECE EL PERIODO (2s)
       IntEnable(INT_TIMER0A);     // SE HABILITA LA INTERRUPCION
       TimerIntEnable(TIMER0_BASE, TIMER_TIMA_TIMEOUT);// SE ESTABLECE LA INTERRUPCION POR TIMEOUT
       TimerIntRegister(TIMER0_BASE, TIMER_A, T0Handler);
       TimerEnable(TIMER0_BASE, TIMER_A);// SE HABILITA EL TIMER


       //CONFIGURACION UART
       SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOB); //SE HABILITA PUERTO B
       SysCtlPeripheralEnable(SYSCTL_PERIPH_UART1); //SE HABILITA EL UART
       UARTConfigSetExpClk(UART1_BASE, SysCtlClockGet(), 115200, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE |UART_CONFIG_PAR_NONE));
       GPIOPinConfigure(GPIO_PB0_U1RX);
       GPIOPinConfigure(GPIO_PB1_U1TX);
       GPIOPinTypeUART(GPIO_PORTB_BASE, GPIO_PIN_0 | GPIO_PIN_1);
       //IntEnable(INT_UART1);
      // UARTIntEnable(UART1_BASE, UART_INT_RX | UART_INT_RT);
       UARTEnable(UART1_BASE);

       IntMasterEnable();    // SE HABILITAN LAS INTERRUPCIONES GLOBALES
}
