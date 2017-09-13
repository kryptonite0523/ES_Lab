#include "project.h"
#include <stdio.h>
#include <stdint.h>
#include "GPIO_Enable.c"


#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
}
#endif


int  main(void)
{
	  volatile uint32_t ui32Loop;
		int delay= 500000;
	
   GPIO_Enable();
	
		//While switch 0 is being held down do this skim through both LEDs alternatively...(atleast that
		// is the plan.
		while(1) 
    {
			//BLINK FIRST LED
        
				// Turn on the LED.
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0xFF);

        // Delay for a bit.
        SysCtlDelay(delay);

        // Turn off the LED.
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0x00);

        // Delay for a bit.
        SysCtlDelay(delay);
				
			//BLINK SECOND LED
				
				// Turn on the LED.
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0xFF);

        // Delay for a bit.
				SysCtlDelay(delay);

        // Turn off the LED.
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0x00);

        // Delay for a bit.
        SysCtlDelay(delay);
				
			//TURN BOTH LEDS ON
				
				// Turn on the LED.
       
			 GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0x0);
			 GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0xFF);
       
			 // Delay for a bit.
        SysCtlDelay(delay);
				

        // Turn off the LED.
				//GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0x0);
			  //GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0x0);
        

        // Delay for a bit.
        SysCtlDelay(delay);
				
			GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0x0);
			 GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0xFF);
       
			 // Delay for a bit.
        SysCtlDelay(delay);
				

        // Turn off the LED.
				GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0x0);
			  GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0x0);
    }
}
