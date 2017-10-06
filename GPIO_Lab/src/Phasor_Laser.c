#include "Phasor_Laser.h"



void Phasor_Laser (b)
{
	
	//delay 
	int ddelay;
  int delay1 = 450000;
	int delay2 = 150000;
	
	if (b==0x31)
	{
				ddelay=delay1;
	}
	else
	{
				ddelay=delay1;
	}
	
	
	//Forward LED Scan
	
				//Turn ON first LED (PN1)
				GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0xFF);
			 
	// Delay for a bit.
		SysCtlDelay(ddelay);
			
			  //Clear PN1 (turn OFF) and turn ON LED (PN2)
			  GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0x0);
			  GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0xFF);
       
	// Delay for a bit.
		SysCtlDelay(ddelay);
	
			  // Clear PN2 (turn OFF) and turn ON LED (PN3)
			  GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0x0);
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0xFF);
				
	// Delay for a bit.
		SysCtlDelay(ddelay);
       
				//Clear PN3 (turn OFF) and turn ON LED (PN4)
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0x0);
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0xFF);
        
	// Delay for a bit.
     SysCtlDelay(ddelay);
				
				// Turn OFF PN4
        GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0x0);
				
	//Backward LED Scan
				
	// Delay for a bit.
    SysCtlDelay(ddelay);
				
				//Clear PN4 (turn OFF) and turn ON LED (PN3)
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0x0);
				GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0xFF);
				
	// Delay for a bit.
    SysCtlDelay(ddelay);
        
				// Clear PN3 (turn OFF) and turn ON LED (PN2)
			  GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0x0);
        GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0xFF);
				
	// Delay for a bit.
    SysCtlDelay(ddelay);
				
        //Clear PN2 (turn OFF) and turn ON LED (PN1)
			  GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0x0);
			      
    }