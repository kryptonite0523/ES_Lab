#include "project.h"


#ifdef DEBUG
void
__error__(char *pcFilename, uint32_t ui32Line)
{
}
#endif

int  main(void)
{
	  volatile uint32_t ui32Loop;
	
	//Enables ports
	GPIO_INIT();
	
	//While switch 0 is being held down do this skim through both LEDs alternatively...(atleast that
	// is the plan.
	
	while (1)
	{
	//Turns on and off LEDs in sequence	
	 Phasor_Laser();
		
	}
	
	
}
