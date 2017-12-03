#include "project.h"
#include <stdint.h>
#include <string.h>
#include "inc/tm4c1294ncpdt.h"
#include "inc/hw_timer.h"
#include "inc/hw_gpio.h"
#include "set.h"


#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
}
#endif

int  main(void)
{
	  SYSCTL_RCGCTIMER_R = 0x3;               //enable clock (timers 0 and 1)
		SYSCTL_RCGCGPIO_R |= 0x00000007;				//turn on clock for port A, B, and C
		SYSCTL_RCGCUART_R |=SYSCTL_RCGCUART_R4	//turn on clock for UART 4
	
	//Initializing PLL for 80 MHz SYSCLLK
	InitSys(4);
	
	//Initializing matrix hardware level
	InitMatrix();
	
	//Initializing hardware for gaming purposes
	InitGaming();
	
	//Initialzing UART
	InitUART(521);
	
	//Enabling timer for LED matrix
	TIMER0_CTL_R |= 0x1;
	
	//Enabling timer to drive game looping
	TIMER1_CTL_R |=0x1;

  //Main loooooop
	while(1)
	{
	}
}
	
