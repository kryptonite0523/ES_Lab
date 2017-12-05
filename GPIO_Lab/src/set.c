#include <stdint.h>
#include "inc/tm4c1294ncpdt.h"
#include "set.h"

//divide value (the divider value for the PLL (4 = Sysdiv2 of 0x02 + Sysdiv3lsb or 0 = 0b100 = 80MHZ)


void InitSys(uint8_t divide)
	
{
	SYSCTL_RCC2_R |= 0X80000000;  //rcc2 Bit Used
	SYSCTL_RCC2_R |= 0x00000800;
	SYSCTL_RCC_r = (SYSCTL_RCC_R & ~0x7C0) + 0x540; //USE 16MHz crystal
	SYSCTL_RCC2_R &= ~0x70; //MOSC configured
	SYSCTL_RCC2_R &= ~0X2000; //pll ON 
	SYSCTL_RCC2_R |= 0x40000000; //400 MHz Pll
	SYSCTL_RCC2_R = (SYSCTL_RCC2_R & ~0x1FC00000) + (divide<<22);
	
	//ppl lock (polling PLLris bit)
	while ((SYSCTL_RIS_R & 0x40)==0);
	
	//PLL on (clearing bypass)
	SYSCTL_RCC2_R &= ~0x800;
	
	
	//busy wait loop delay 24 bit systick timer (2^24-1)*(1/sysclk)
	
	void SysTickDelay(uint32_t delay)
	{
		NVIC_ST_RELOAD_R = delay - 1;
		NVIC_ST_CURRENT_R = 0; //clear current bit
		NVIC_ST_CTRL_R = 5;  //timer on
		
		while ((NVIC_ST_CTRL_R & 0x10000)==0); //wait for loop
		
		NVIC_ST_CTRL_R = 0; //Timer OFF
	}