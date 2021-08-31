// STM32F103
#include "stm32f10x.h"

// cstd
#include <stdbool.h>

#ifndef __MAIN_H__
#define __MAIN_H__


// Config

// Pulses for optical sensors (settings for TIM2) = 
// Switch to the next group of optical sensors
// X * 0.5 us
#define PHASE_PULSE                     32
// Pulse to lock/unlock register with optical sensors output signals (TIM2)
// X * 0.5 us before end of current phase (16 us)
#define UNLOCK_PULSE                    2
#define LOCK_PULSE                      1

// Pulse for multiplexer (settings for TIM3)
// X * 0.5 us
#define MUX_PULSE                       2
// 8 multiplexed outputs should be read
#define DMA_NUM_OF_TRANSACTIONS         64


// Pins
// Pulses power for optical sensors and registers control
#define UNLOCK_PIN          GPIOB, 10   // TIM2, C3
#define LOCK_PIN            GPIOB, 11   // TIM2, C4
// Pulse for multiplexer
#define MUX_PIN             GPIOB, 1    // TIM3, C4
// Reset input and output counters
#define RESET_PIN           GPIOB, 0

// DMA read data port
#define PARALLEL_PORT       GPIOA




#endif



