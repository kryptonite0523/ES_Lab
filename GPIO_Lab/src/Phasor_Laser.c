#include "Phasor_Laser.h"
#include "GPIO_INIT.h"



void Phasor_Laser (void)
{
	
	//delay 
int delay1 = 450000;
	
	//Forward LED Scan
	
				//Turn ON first LED (PN1)
				GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0xFF);
			 
	// Delay for a bit.
		SysCtlDelay(delay1);
			
			  //Clear PN1 (turn OFF) and turn ON LED (PN2)
			  GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0x0);
			  GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0xFF);
       
	// Delay for a bit.
		SysCtlDelay(delay1);
	
			  // Clear PN2 (turn OFF) and turn ON LED (PN3)
			  GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0x0);
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0xFF);
				
	// Delay for a bit.
		SysCtlDelay(delay1);
       
				//Clear PN3 (turn OFF) and turn ON LED (PN4)
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0x0);
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0xFF);
        
	// Delay for a bit.
     SysCtlDelay(delay1);
				
				// Turn OFF PN4
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0x0);
				
	//Backward LED Scan
				
	// Delay for a bit.
    SysCtlDelay(delay1);
				
				//Clear PN4 (turn OFF) and turn ON LED (PN3)
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0x0);
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0xFF);
				
	// Delay for a bit.
    SysCtlDelay(delay1);
        
				// Clear PN3 (turn OFF) and turn ON LED (PN2)
			  GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0x0);
        GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0xFF);
				
	// Delay for a bit.
    SysCtlDelay(delay1);
				
        //Clear PN2 (turn OFF) and turn ON LED (PN1)
			  GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0x0);
			      
    }