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
		int	delay1=450000;
	  int	delay2=1;
	
    // Enable the GPIO port used for the on-board LED.
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION);
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOJ); 	
	
		// Check if the peripheral access is enabled.
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF))
    {
    
		}
		
		// Enable the GPIO pin for the LED (PF1,PF2,PF3).  Set the direction as output, and
    // enable the GPIO pin for digital function.
    GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_1);
		GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_0);
		GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_4);
		GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_0);
		
		
	
    //Enable the GPIO Pin for the switches (PJ0,PJ1). Set the direction as an input?
		GPIOPinTypeGPIOInput (GPIO_PORTJ_BASE, GPIO_PIN_0);
		GPIOPinTypeGPIOInput (GPIO_PORTJ_BASE, GPIO_PIN_1);
		
		
		//While switch 1 is being held down the first LED will illuminate
		//While switch 2 is being held down the second LED will illuminate
		//If neither condition is met the fourth LED will illuminate
		
		while(1)
		{
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
	
	}