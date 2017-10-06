#include "Phasor_Laser.h"


void Phasor_Laser(b)
{
	int ddelay;
	int delay1=450000; 
	int delay2=150000;

			if(b==0x31)
			{
				ddelay=delay1;
			}
			else 
			{
				ddelay=delay2;
			}
			
			GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0xFF);
		
      SysCtlDelay(ddelay);		
		
			GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0x0);
			
			GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0xFF);
		
      SysCtlDelay(ddelay);		
		
			GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0x0);
			
			GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0xFF);
		
			SysCtlDelay(ddelay);
			
			GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0x0);
		
			GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0xFF);
			
			SysCtlDelay(ddelay);
			
			GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0x0);
			
			GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0xFF);
			
			SysCtlDelay(ddelay);
			
			GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0x0);
			
			GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0xFF);
			
			SysCtlDelay(ddelay);
			
			GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0x0);
			
			SysCtlDelay(ddelay);
	
	}

