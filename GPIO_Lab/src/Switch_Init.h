#include <stdbool.h>
#include <stdint.h>
#include "sysctl.h"
#include "hw_memmap.h"
#include "gpio.h"
#include "../inc/tm4c1294ncpdt.h"
#include "hw_gpio.h"
#include "hw_types.h"
#define GPIO_PORTJ_DATA_R       (*((volatile uint32_t *)0x400603FC))
#define GPIO_PORTJ_DIR_R        (*((volatile uint32_t *)0x40060400))
#define GPIO_PORTJ_AFSEL_R      (*((volatile uint32_t *)0x40060420))
#define GPIO_PORTJ_PUR_R        (*((volatile uint32_t *)0x40060510))
#define GPIO_PORTJ_DEN_R        (*((volatile uint32_t *)0x4006051C))
#define GPIO_PORTJ_AMSEL_R      (*((volatile uint32_t *)0x40060528))
#define GPIO_PORTJ_PCTL_R       (*((volatile uint32_t *)0x4006052C))
#define PJ0       (*((volatile uint32_t *)0x40060004))
#define PJ1       (*((volatile uint32_t *)0x40060008))

void Switch_Init(void);