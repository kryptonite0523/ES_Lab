#include "project.h"
#include <stdio.h>
#include <stdint.h>
#include "GPIO_Enable.h"
#include "LED_SKIM.h"


#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
}
#endif


int  main(void)
{
	  volatile uint32_t ui32Loop;
		
   GPIO_Enable();
	
	 LED_SKIM ();
	
}
