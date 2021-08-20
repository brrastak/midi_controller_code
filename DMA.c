// STM32F103
#include "stm32f10x.h"

// cstd
#include <stdbool.h>

//user
#include "DMA.h"
#include "main.h"
#include "timer.h"
#include "debug_led.h"

// Using channel 2 of DMA1 with TIM3 DMA request

bool transmitted = true;


// Interrupt handler
void DMA1_Channel3_IRQHandler()
{
    TurnLedOn();
    //DisableTim3();
    // Clear interrupt flag
    DMA1->IFCR |= DMA_IFCR_CTCIF3;
        
    TurnLedOff();
    
    
    // Channel 3 transfer complete
    /*if ((DMA1->ISR & DMA_ISR_TCIF3) != 0) {
        // Clear interrupt flag
        DMA1->IFCR |= DMA_IFCR_CTCIF3;
        
        // Disable channel
        //DMA1_Channel3->CCR &= ~DMA_CCR2_EN;
        
        DisableTim3();
        //transmitted = true;

    }*/
    
    //TurnLedOff();
}
void InitDma(uint8_t * buf, uint32_t num)
{
    // Channel configuration
    // Peripheral address
    DMA1_Channel3->CPAR = (uint32_t)&(PARALLEL_PORT->ODR);
    
    DMA1_Channel3->CCR  =   DMA_CCR3_MEM2MEM    * 0 |   // memory to memory mode
                            DMA_CCR3_MSIZE_1    * 0 |   // memory size 00: 8 bit; 01:16; 11:32
                            DMA_CCR3_MSIZE_0    * 0 |   //
                            DMA_CCR3_PSIZE_1    * 0 |   // peripheral size 00: 8 bit; 01:16; 10:32
                            DMA_CCR3_PSIZE_0    * 0 |   //
                            DMA_CCR3_MINC       * 1 |   // memory increment mode
                            DMA_CCR3_PINC       * 0 |   // peripheral increment mode
                            DMA_CCR3_CIRC       * 1 |   // circular mode
                            DMA_CCR3_DIR        * 0 |   // data transfer direction 0: read from peripheral; 1: from memory
                            DMA_CCR3_TCIE       * 1;    // transfer complete interrupt enable
    
    // Memory address
    DMA1_Channel3->CMAR = (uint32_t)buf;
    // Number of transactions
    DMA1_Channel3->CNDTR = num;
        
    // Channel enable
    DMA1_Channel3->CCR |= DMA_CCR3_EN;
}
// From PARALLEL_PORT to buf
void TransmitDma(uint8_t * buf, uint32_t num)
{
    // Memory address
    DMA1_Channel3->CMAR = (uint32_t)buf;
    // Number of transactions
    DMA1_Channel3->CNDTR = num;
        
    // Channel enable
    DMA1_Channel3->CCR |= DMA_CCR2_EN;
    
    transmitted = false;
}
void DisableDma(void)
{
    DMA1_Channel3->CCR &= ~DMA_CCR3_EN;
}
bool TransmittedDma()
{
    return transmitted;
}
