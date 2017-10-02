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
		uint8_t a;
		GPIO_INIT();
		Switch_Init();
		int32_t i,n;
		UART_Init();              // initialize UART
		int b = Decision_Maker();
	
 	while(1)
		{
			Phasor_Laser(b);
		}
}