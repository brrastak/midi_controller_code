/*
    1. Configure LED_PIN as output push-pull
    2. Init RCC: RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
*/

// user
#include "GPIO.h"

#ifndef __DEBUG_LED_H__
#define __DEBUG_LED_H__

#define LED_PIN                 GPIOC, 13

// Onboard LED
inline void TurnLedOn(void)
{
    ResetPin(LED_PIN);
}
inline void TurnLedOff(void)
{
    SetPin(LED_PIN);
}
inline void BlinkLed(void)
{
    TogglePin(LED_PIN);
}


#endif