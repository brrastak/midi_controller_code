// STM32F103
#include "stm32f10x.h"

#ifndef __TIMER_H__
#define __TIMER_H__

// CPU and SysTick timer frequency
#define F_CPU 		            72000000UL      // 72MHz
// every 1 ms
#define SYS_TIMER_TICK  	    (F_CPU/1000-1)  // 1kHz

// Ticks
extern volatile uint32_t sys_tick;

// Init SysTick timer
void InitSysTick(void);
// Proceed SysTick value and reset counter
bool IfDelayPassed(uint32_t* cnt, uint32_t delay_ms);
// Reset counter
void ResetCounter(uint32_t* cnt);
// Init TIM2 for PWM generation
void InitTim2(void);
// Init TIM3 for PWM generation
void InitTim3(void);
// Stop TIM3
inline void DisableTim3(void)
{
    TIM3->CR1 &= ~TIM_CR1_CEN;      // stop
    TIM3->EGR = TIM_EGR_UG;         // update
    //TIM2->CCER &= ~TIM_CCER_CC1E;   // out disable
}
// Delay TIM4
void delay_ms(int time);    // 32000ms max
void delay_us(int time);    // 32000us max


#endif
