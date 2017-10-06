
#include "Systick_helper.h"


void SysTickEnable(unsigned long delay)
{
	NVIC_ST_CTRL_R=0;
  NVIC_ST_RELOAD_R = delay-1; 
	NVIC_ST_CURRENT_R= 0;
	while ((NVIC_ST_CTRL_R&0X00010000)==0)
	{
		
	}
	
}


//wait 10ms
void SystickWait(unsigned long delay)
{
	unsigned long i;
	for(i=0;i<delay;i++)
	{
		 SysTickEnable(800000);
	}
}
