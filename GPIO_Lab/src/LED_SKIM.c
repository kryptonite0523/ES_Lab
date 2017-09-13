#include "LED_SKIM.h"



void LED_SKIM (void)
{
int delay= 500000;
	
//While switch 0 is being held down do this skim through both LEDs alternatively...(atleast that
		// is the plan.
		while(1) 
    {
				
			//Forward LED Scan
				//Turn ON first LED (PN1)
				GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0xFF);
			 
			  // Delay for a bit.
				SysCtlDelay(delay);
			
			  //Clear PN1 (turn OFF) and turn ON LED (PN2)
			  GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0x0);
			  GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0xFF);
       
			  // Delay for a bit.
				SysCtlDelay(delay);
			
			  // Clear PN2 (turn OFF) and turn ON LED (PN3)
			  GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0x0);
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0xFF);
				
			  // Delay for a bit.
				SysCtlDelay(delay);
       
				//Clear PN3 (turn OFF) and turn ON LED (PN4)
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0x0);
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0xFF);
        
				 // Delay for a bit.
        SysCtlDelay(delay);
				
				// Turn OFF PN4
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0x0);
				

        
	
		//Backward LED Scan
				
				
				// Delay for a bit.
        SysCtlDelay(delay);
				
				//Clear PN4 (turn OFF) and turn ON LED (PN3)
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0x0);
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0xFF);
				
				// Delay for a bit.
        SysCtlDelay(delay);
        
				// Clear PN3 (turn OFF) and turn ON LED (PN2)
			  GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0x0);
        GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0xFF);
				
				// Delay for a bit.
        SysCtlDelay(delay);
				
        //Clear PN2 (turn OFF) and turn ON LED (PN1)
			  GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0x0);
			  

       
    }}