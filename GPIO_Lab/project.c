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

		GPIO_INIT();
		
		while(1)
		{
			Phasor_Laser();
		}
}
