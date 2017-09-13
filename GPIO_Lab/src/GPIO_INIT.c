#include "GPIO_INIT.h"



void GPIO_INIT (void)
{
    
	
	// Enable the GPIO port used for the on-board LED.
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
	 	SysCtlPeripheralEnable(SYSCTL_PERIPH_GPION);
		SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOJ);
	  
		// Check if the peripheral access is enabled.
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF))
    {
			
		}
    
		
		// Enable the GPIO pin for the LED (PN1,PN2,PN3, PN4).  Set the direction as output, and
    // enable the GPIO pin for digital function.
    GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_1);
		GPIOPinTypeGPIOOutput(GPIO_PORTN_BASE, GPIO_PIN_0);
		GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_0);
		GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_4);
	
    //Enable the GPIO Pin for the switches (SW0,SW1). Set the direction as an input?
		GPIOPinTypeGPIOInput (GPIO_PORTJ_BASE, GPIO_PIN_0);
		GPIOPinTypeGPIOInput (GPIO_PORTJ_BASE, GPIO_PIN_1);
	}