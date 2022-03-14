/*
 * digPort.cpp
 *
 *  Created on: 10 de mar de 2022
 *      Author:
 */

#ifndef DIGPORT_CPP_
    #define DIGPORT_CPP_

#include "digPort.h"

DigPort::DigPort()
{
    SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOF);
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOF)){};       //Aguarda a habilitar periférico. Evita falha no barramento.
    GPIOPinTypeGPIOOutput(GPIO_PORTF_BASE, GPIO_PIN_1|GPIO_PIN_2|GPIO_PIN_3);
    HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = GPIO_LOCK_KEY;
    HWREG(GPIO_PORTF_BASE + GPIO_O_CR) |= 0x01;
    HWREG(GPIO_PORTF_BASE + GPIO_O_LOCK) = 0;
    GPIODirModeSet(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0, GPIO_DIR_MODE_IN);
    GPIOPadConfigSet(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0, GPIO_STRENGTH_2MA, GPIO_PIN_TYPE_STD_WPU);
    GPIOIntTypeSet(GPIO_PORTF_BASE, GPIO_INT_PIN_0|GPIO_INT_PIN_4,GPIO_FALLING_EDGE);
}

uint8_t DigPort::GetBotoes()
{
    estadoBotoes = GPIOPinRead(GPIO_PORTF_BASE, GPIO_PIN_4|GPIO_PIN_0);
    return estadoBotoes;
}



#endif /* DIGPORT_CPP_ */
