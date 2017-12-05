#include <stdint.h>
#include <string.h>
#include "inc/tm4c1294ncpdt.h"
#include "inc/hw_timer.h"
#include "inc/hw_gpio.h"
#include "matrix.h"

static uint8_t row_1;
static Color row_1_color;
static Color matrix[max_row][max_color];

static uint_t current_bcm_cycle;

static const uint8_t DemuxValue[]= {0,1,2,4,5,2,3,6,7,8,9,12,13,10,11,14,15};

//length of each bcm cycle (sysclk cycles)

static const uint32_t BCMLength[]={ 240,480,960,1920,3840,7680,15360,30720};

static const uint8_t MaxBCM = 6;



void InitMatrix(void)
{
	TIMER0_CTL_R &~0x1;
	TIMER0_CFG_R = 0;
	TIMER0_TAMR_R |= 0X32;
	TIMER0_TAILR_R = 8000;
	TIMER0_TAMTCHR_R = 8000;
	TIMER_IMR_R |=0X10;
	
	NVIC_EN0_R |= 0X80000;
	
	//setting dataport and control port as outputs
	DATAPORT_DIR |= ALL_DATAPORT_PINS;
	CTRLPORT_DIR |= ALL_CTRLPORT_PINS;
	
	// Initializing DATAPORT and CTRLPORT pins as low
	DATAPORT &= ~ALL_DATAPORT_PINS;
	CTRLPORT &= ~ALL_CTRLPORT_PINS;
	
//enabling dataport and control pins as digital pins
	DATAPORT_DEN |= ALL_DATAPORT_PINS;
	CTRLPORT_DEN |= ALL_CTRLPORT_PINS;
}

void InitTimer0A (void)
{
	uint8_t i= 0;
	int Other = row_1 +16; //row that needs to be displayed
	
	//Timer disable
	TIMER0_CTL_R &= ~0X1; 
	
	//Clearing interrupt flags
	TIMER0_ICR_R |= TIMER_ICR_TAMCINT; 
	NVIC_UNPEND0_R |= 0x80000; 
	
	CTRLPORT |= OE;
	CTRLPORT &= ~(DEMUXA|DEMUXB|DEMUXC|DEMUXD|SCLK|LATCH);
	CTRLPORT |= demux_vals[row_1] & 0xF;
	
	//clear dataport values
	DATAPORT &= ~ALL_DATAPORTS_PINS;
	
	
	


