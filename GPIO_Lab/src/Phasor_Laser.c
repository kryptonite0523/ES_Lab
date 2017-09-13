#include "Phasor_Laser.h"

void Phasor_Laser(void)
{
	int delay1=450000; 

			GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0xFF);
		
      SysCtlDelay(delay1);		
		
			GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_1, 0x0);
			
			GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0xFF);
		
      SysCtlDelay(delay1);		
		
			GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0x0);
			
			GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0xFF);
		
			SysCtlDelay(delay1);
			
			GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, 0x0);
		
			GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0xFF);
			
			SysCtlDelay(delay1);
			
			GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_0, 0x0);
			
			GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0xFF);
			
			SysCtlDelay(delay1);
			
			GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_4, 0x0);
			
			GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0xFF);
			
			SysCtlDelay(delay1);
			
			GPIOPinWrite(GPIO_PORTN_BASE, GPIO_PIN_0, 0x0);
			
			SysCtlDelay(delay1);
	
	}