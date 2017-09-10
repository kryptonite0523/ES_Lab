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
	
    // Enable the GPIO port used for the on-board LED.
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
		
		
		//While switch 0 is being held down do this skim through the colors...(atleast that
		// is the plan.
		while(GPIOPinRead (GPIO_PORTF_BASE, GPIO_PIN_0) == 0x0F) 
    {
				//BLINK RED LED
        // Turn on the LED.
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0xF);

        // Delay for a bit.
        for(ui32Loop = 0; ui32Loop < 800000; ui32Loop++)
        {
        }

        // Turn off the LED.
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0x0);

        // Delay for a bit.
        for(ui32Loop = 0; ui32Loop < 80000; ui32Loop++)
        {
        }
				
				//BLINK BLUE LED
				// Turn on the LED.
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0xF);

        // Delay for a bit.
        for(ui32Loop = 0; ui32Loop < 800000; ui32Loop++)
        {
        }

        // Turn off the LED.
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, 0x0);

        // Delay for a bit.
        for(ui32Loop = 0; ui32Loop < 80000; ui32Loop++)
        {
        }
				
					//BLINK GREEN LED
				// Turn on the LED.
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0xF);

        // Delay for a bit.
        for(ui32Loop = 0; ui32Loop < 800000; ui32Loop++)
        {
        }

        // Turn off the LED.
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, 0x0);

        // Delay for a bit.
        for(ui32Loop = 0; ui32Loop < 80000; ui32Loop++)
        {
        }
    }
}
