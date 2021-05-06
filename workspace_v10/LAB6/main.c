

#include <stdint.h>
#include <stdbool.h>
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/gpio.h"
#include "driverlib/sysctl.h"
#include "driverlib/pin_map.h"
#include "driverlib/debug.h"



uint8_t FLAG = 0;

int main(void)
{

    SysCtlClockSet(SYSCTL_SYSDIV_4|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_4, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE,GPIO_PIN_1| GPIO_PIN_2|GPIO_PIN_3);


    while(1)
       {

        if(GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4) == 0){
            FLAG = 1;
        }



          if(GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4) == 16 && (FLAG) == 1){


          FLAG = 0;

           GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1| GPIO_PIN_2|GPIO_PIN_3,GPIO_PIN_1);

           SysCtlDelay(20000000);


           GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1| GPIO_PIN_2|GPIO_PIN_3,GPIO_PIN_1|GPIO_PIN_3);

           SysCtlDelay(20000000);



           GPIOPinWrite(GPIO_PORTF_BASE,GPIO_PIN_1| GPIO_PIN_2|GPIO_PIN_3, GPIO_PIN_3);

           SysCtlDelay(20000000);


       }


}
}
