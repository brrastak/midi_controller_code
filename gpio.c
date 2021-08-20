// cstd
#include <stdbool.h>

//user
#include "gpio.h"

void SetGpioMode(GPIO_TypeDef* port, int pin, int mode)
{
    if (pin > 7)
        port->CRH = (port->CRH & ~(0x0f << (pin-8)*4)) | (mode << (pin-8)*4);
    else
        port->CRL = (port->CRL & ~(0x0f << pin*4)) | (mode << pin*4);
}
