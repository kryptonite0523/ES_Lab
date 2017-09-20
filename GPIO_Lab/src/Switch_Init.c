#include "Switch_Init.h"

void Switch_Init(void)
{
	SYSCTL_RCGCGPIO_R |= SYSCTL_RCGCGPIO_R8;
                                   // allow time for clock to stabilize
  while((SYSCTL_PRGPIO_R&SYSCTL_PRGPIO_R8) == 0){};
  GPIO_PORTJ_DIR_R = 0;            // make PJ1-0 in (PJ1-0 built-in SW2-1)
  GPIO_PORTJ_AFSEL_R = 0;          // disable alt funct on PJ1-0
  GPIO_PORTJ_PUR_R = 0x03;         // enable pull-up on PJ1-0
  GPIO_PORTJ_DEN_R = 0x03;         // enable digital I/O on PJ1-0
  GPIO_PORTJ_PCTL_R = 0;           // configure PJ1-0 as GPIO
  GPIO_PORTJ_AMSEL_R = 0;          // disable analog functionality on PJ1-0
}