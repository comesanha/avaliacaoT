/*
 * uart_Cac.cpp
 *
 *  Created on:
 *      Author:
 */


#ifndef UART_CAC_CPP
      #define UART_CAC_CPP

#include "uart_Cac.h"

int i;
uint32_t count;

UartCac::UartCac()
{
  SysCtlPeripheralEnable(SYSCTL_PERIPH_UART0);                // Os pinos da UART0 est�o conectados fisicamente no GPIOs da porta A.
  while(!SysCtlPeripheralReady(SYSCTL_PERIPH_UART0)){};       //Aguarda a habilitar perif�rico. Evita falha no barramento.
  SysCtlPeripheralEnable(SYSCTL_PERIPH_GPIOA);
  while(!SysCtlPeripheralReady(SYSCTL_PERIPH_GPIOA)){};       //Aguarda a habilitar perif�rico. Evita falha no barramento.

  // Configura os pinos 0 e 1 da porta A como receptor e transmissor UART.
  //Configura fun��o alternativa da GPIO
  GPIOPinConfigure(GPIO_PA0_U0RX);
  GPIOPinConfigure(GPIO_PA1_U0TX);

  // Configura os pino para serem usados como perif�ricos UART
  GPIOPinTypeUART(GPIO_PORTA_BASE, GPIO_PIN_0 | GPIO_PIN_1);
}

UartCac::~UartCac()
{
  UARTDisable(UART0_BASE);
  //std::cout << "\nPorta Fechada!\n" << std::endl;
}

void UartCac::OpenSerial()
{
    // Habilita FIFO da UART
    UARTEnable(UART0_BASE);
}


void UartCac::SetSerialParameter()
{

    // Configura��o da UART - endere�o, clock da UART, BaudRate, (palavra de 8 bits|1 stop bit|sem paridade)
    UARTConfigSetExpClk(UART0_BASE, 80000000, 115200, (UART_CONFIG_WLEN_8 | UART_CONFIG_STOP_ONE | UART_CONFIG_PAR_NONE));

    //Configurando n�vel da FIFO
    UARTFIFODisable(UART0_BASE);// Desabilita FIFO TX e RX
    UARTFIFOLevelSet(UART0_BASE, UART_FIFO_TX6_8, UART_FIFO_RX1_8);// FIFO com 4 bytes de dados


}

void UartCac::SerialWrite(char &T)
{
    UARTCharPut(UART0_BASE,(T));
}

void UartCac::SerialRead(char *pR)
{
    i = 0;
    while(UARTCharsAvail(UART0_BASE))
    {
        pR[i] = UARTCharGet(UART0_BASE);// l� char da FIFO na ordem de recep��o
        i++;
    }
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3|GPIO_PIN_2|GPIO_PIN_1, GPIO_PIN_3|GPIO_PIN_2|GPIO_PIN_1);
    count = 40000000/3;
    SysCtlDelay(count);
    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3|GPIO_PIN_2|GPIO_PIN_1, 0);
}

void UartCac::CloseSerial()
{
    UARTDisable(UART0_BASE);
    //std::cout << "\nPorta Fechada!\n" << std::endl;
}



#endif //UART_CAC_CCP

