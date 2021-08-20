// STM32F103
#include "stm32f10x.h"

// cstd
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

//user
#include "main.h"
#include "init.h"
#include "gpio.h"
#include "debug_led.h"
#include "timer.h"
#include "dma.h"



uint8_t dma_buf[256];



int main()
{    
    // System init
    InitRcc();
    InitGpio();
    InitSysTick();
    
    InitInterrupt();
    InitDma(dma_buf, DMA_NUM_OF_TRANSACTIONS);
    InitTim3();
    InitTim2();
    
    
    TurnLedOff();

    
    // Time counters
    /*uint32_t temp_cnt;
    uint32_t disp_cnt;
    uint32_t btn_cnt;
    
    ResetCounter(&temp_cnt);
    ResetCounter(&disp_cnt);
    ResetCounter(&btn_cnt);
    
    // Start button
    btn_t StartBtn = {START_BTN_PIN, 0, 20, false, false, false};
    */
    
    while (true) {
        
        delay_ms(1000);
        //BlinkLed();
        
    }
    
}








