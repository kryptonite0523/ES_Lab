#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include "sysctl.h"
#include "hw_memmap.h"
#include "gpio.h"
#include "../inc/tm4c1294ncpdt.h"
#include "hw_gpio.h"
#include "hw_types.h"
#define PWM0_ENABLE_R           (*((volatile uint32_t *)0x40028008))
#define PWM_ENABLE_PWM1EN       0x00000002  // MnPWM1 Output Enable
#define PWM_ENABLE_PWM0EN       0x00000001  // MnPWM0 Output Enable
#define PWM0_0_CTL_R            (*((volatile uint32_t *)0x40028040))
#define PWM_0_CTL_ENABLE        0x00000001  // PWM Block Enable
#define PWM0_0_LOAD_R           (*((volatile uint32_t *)0x40028050))
#define PWM0_0_COUNT_R          (*((volatile uint32_t *)0x40028054))
#define PWM0_0_CMPA_R           (*((volatile uint32_t *)0x40028058))
#define PWM0_0_CMPB_R           (*((volatile uint32_t *)0x4002805C))
#define PWM0_0_GENA_R           (*((volatile uint32_t *)0x40028060))
#define PWM_0_GENA_ACTCMPAD_ONE 0x000000C0  // Set the output signal to 1
#define PWM_0_GENA_ACTLOAD_ZERO 0x00000008  // Set the output signal to 0
#define PWM0_0_GENB_R           (*((volatile uint32_t *)0x40028064))
#define PWM_0_GENB_ACTCMPBD_ONE 0x00000C00  // Set the output signal to 1
#define PWM_0_GENB_ACTLOAD_ZERO 0x00000008  // Set the output signal to 0
#define PWM0_CC_R               (*((volatile uint32_t *)0x40028FC8))
#define PWM_CC_USEPWM           0x00000100  // Use PWM Clock Divisor
#define PWM_CC_PWMDIV_M         0x00000007  // PWM Clock Divider
#define PWM_CC_PWMDIV_2         0x00000000  // /2
#define GPIO_PORTF_AFSEL_R      (*((volatile uint32_t *)0x4005D420))
#define GPIO_PORTF_DEN_R        (*((volatile uint32_t *)0x4005D51C))
#define GPIO_PORTF_AMSEL_R      (*((volatile uint32_t *)0x4005D528))
#define GPIO_PORTF_PCTL_R       (*((volatile uint32_t *)0x4005D52C))
#define SYSCTL_RCGCGPIO_R       (*((volatile uint32_t *)0x400FE608))
#define SYSCTL_RCGCGPIO_R5      0x00000020  // GPIO Port F Run Mode Clock
                                            // Gating Control
#define SYSCTL_RCGCPWM_R        (*((volatile uint32_t *)0x400FE640))
#define SYSCTL_RCGCPWM_R0       0x00000001  // PWM Module 0 Run Mode Clock
                                            // Gating Control
#define SYSCTL_PRGPIO_R         (*((volatile uint32_t *)0x400FEA08))
#define SYSCTL_PRGPIO_R5        0x00000020  // GPIO Port F Peripheral Ready
#define SYSCTL_PRPWM_R          (*((volatile uint32_t *)0x400FEA40))
#define SYSCTL_PRPWM_R0         0x00000001  // PWM Module 0 Peripheral Ready


void Its_Called_Pulse_Width_Modulation_Jack(uint16_t period, uint16_t duty);