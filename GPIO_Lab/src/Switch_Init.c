#include "Switch_Init.h"

void Switch_Init(void)
{
	
			SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R8;
	
	while ((SYSCTL_PRGPIO_R&SYSCTL_PRGPIO_R8)==0){};
		
		GPIO_PORTJ_DIR_R = 0;
		GPIO_PORTJ_AFSEL_R = 0;
		GPIO_PORTJ_PUR_R = 0X03;
		GPIO_PORTJ_DEN_R = 0X03;
		GPIO_PORTJ_PCTL_R = 0;
		GPIO_PORTJ_AMSEL_R = 0;
	}
