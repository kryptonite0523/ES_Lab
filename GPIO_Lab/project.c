#include "project.h"
#include <stdio.h>
#include <stdint.h>



#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
}
#endif


int  main(void)
{
    volatile uint32_t ui32Loop;
	
    // Enable the GPIO port that is used for the on-board LED.
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    
		// Check if the peripheral access is enabled.
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF))
    {
    
		}
    
		
		// Enable the GPIO pin for the LED (PF1,PF2,PF3).  Set the direction as output, and
    // enable the GPIO pin for digital function.
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1);
		GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_2);
		GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_3);
	
    //Enable the GPIO Pin for the switches (PF0,PF4). Set the direction as an input?
		GPIOPinTypeGPIOInput (GPIO_PORTF_BASE, GPIO_PIN_0);
		GPIOPinTypeGPIOInput (GPIO_PORTF_BASE, GPIO_PIN_4);
		
		
		
		while(1)
    {
				
        // Turn on the LED.
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0xF);

        // Delay for a bit.
        for(ui32Loop = 0; ui32Loop < 200000; ui32Loop++)
        {
        }

        // Turn off the LED.
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0x0);

        // Delay for a bit.
        for(ui32Loop = 0; ui32Loop < 200000; ui32Loop++)
        {
        }
    }
}
