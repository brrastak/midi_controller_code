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



volatile uint8_t dma_buf[DMA_NUM_OF_TRANSACTIONS];
bool data_updated;


// Sensor position
// Power pulse phase 0..5
#define PHASE_NUM       1
// Number of register 0..7
#define REG_NUM         0
// Number of bit in register
#define BIT_NUM         1



int main()
{    
    // System init
    InitRcc();
    InitGpio();
    InitSysTick();
    
    // Reset hardware
    TurnLedOff();
    SetPin(RESET_PIN);
    delay_ms(1);
    ResetPin(RESET_PIN);
    delay_ms(1);
    
    InitInterrupt();
    InitDma((uint8_t *)dma_buf, &data_updated);
    InitTim3();
    InitTim2();
    

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
        
        TurnLedOff();
        
        /*if ((dma_buf[PHASE_NUM*8 + REG_NUM] & (1 << BIT_NUM)) == 0)
            TurnLedOn();*/
        
        if (((dma_buf[16] & (1 << 0)) == 0) && ((dma_buf[16] & (1 << 1)) != 0))
            TurnLedOn();
        
    }
    
}








