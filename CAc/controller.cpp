/*
 * controller.cpp
 *
 *  Created on:
 *      Author:
 */

#include <iostream>
#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/interrupt.h"
#include "driverlib/gpio.h"
#include "driverlib/debug.h"
#include "driverlib/pin_map.h"
#include "driverlib/timer.h"
#include "inc/hw_gpio.h"
#include "driverlib/hibernate.h"
#include "driverlib/uart.h"
#include "driverlib/adc.h"

/* CLASSE IMPLEMENTADAS */
#include "uart_Cac.h"
#include "digPort.h"
#include "Temperatura.h"
#include "queue.h"
#include "comandoAr.h"

UartCac uartCac;

void SendUint32_tAsChar(uint32_t inteiro);

void main(void)
{
    /*CONFIGURANDO O CLOCK DO SISTEMA*/
    SysCtlClockSet(SYSCTL_SYSDIV_2_5|SYSCTL_USE_PLL|SYSCTL_XTAL_16MHZ|SYSCTL_OSC_MAIN|SYSCTL_OSC_EXT32);

    /* CRIANDO OBJETOS */

    DigPort botoesCac;
    Temperatura MedidaCac;
    Queue log;
    ComandoAr cmndLigaDesliga[1000];


    /*CONFIGURAÇÃO DO RTC*/
    HibernateEnableExpClk(SysCtlClockGet());
    HibernateRTCEnable();
    //HibernateRTCTrimSet(0x7FFF);
    //HibernateRTCDisable();
    //HibernateRTCEnable();
    HibernateRTCSet(0);

    /* HABILITANDO E CONFIGURANDO PORTA SERIAL UART */
    uartCac.SetSerialParameter();
    uartCac.OpenSerial();

    /* DECLARANDO VARIÁVEIS */

    char R[2] = {0};// Buffer de recepção
    char T[9] = {0};// Buffer de transmissão
    uint32_t tempoI[1000], tempoF[1000];
    int index;
    uint8_t botaoaux;
    uint8_t tempAjst;
    float tempAtual1, tempAtual2;
    char estados = 'a'; // Inicia em E-spra
    char flagTemp = 'F';// Sem evento de variação de tenperatura externa
    char flagBot = '0'; // Sem evento de botões
    char tempCmd;
    uint32_t tempoLigado, tempoValorF, tempoValorI, contador;
    uint32_t contCmnd = 0;
    tempoLigado = 0;
    tempoValorF = 0;
    tempoValorI = 0;

    /* LOOP INFINITO DO SISTEMA EMBARCADO*/
    while(1)
    {
        // realização da medida do valor do sensor de temperatura
        MedidaCac.readSensor();

        //Execução dos estados do CAc
        switch(estados)
        {
            case 'a'://E-spra
            {
                botaoaux = botoesCac.GetBotoes();// captura estado de botões função ligar aparelho

                //bot1 e bot2
                if(botaoaux == 0x00)
                {
                    tempoValorI = HibernateRTCGet();// registra o tempo em que o aparelho foi ligado
                    tempoI[contCmnd] = tempoValorI;
                    cmndLigaDesliga[contCmnd].setComando('L', 22, 2, 18, 10, 12, 35);
                    contCmnd++;
                    // Simula comando Bluetooth para ligar aparelho
                    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3|GPIO_PIN_2|GPIO_PIN_1, GPIO_PIN_3|GPIO_PIN_2|GPIO_PIN_1);// Acende todos os LEDs
                    for(contador = 0; contador == 8000000; contador++){}
                    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3|GPIO_PIN_2|GPIO_PIN_1, 0);// Apaga todos os LEDs

                    estados = 'l';// estado E-cntrl
                }else

                //Se houve comando enviado pela serial
                if(UARTCharsAvail(UART0_BASE))// Verifica se há dado no Rx do UART
                {
                    estados = 'c';// estado E-cmnc
                }else

                // Sem entrada ou bot 1 ou bot2 ou VariaTempEx -> permanece em E-spra
                estados = 'a';

                break;
            }
            case 'l'://E-cntrl
            {
                /* Ainda faltando implementar Tensorflow relacionando entradar e saídas */

                // Sem entrada -> permanece em E-cntrl
                GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3|GPIO_PIN_2|GPIO_PIN_1, 0);// Apaga todos os LEDs

                tempAjst = botoesCac.GetBotoes();// Leitura de estado dos botões de ajuste

                contador ++;

                //Captura de valores de temperatura externa com tempos diferentes.
                if(contador == 200000000)
                    tempAtual1 = MedidaCac.getSensorVl();// Leitura de valor de emperatura externa a priori

                if(contador == 400000000)
                {
                    tempAtual2 = MedidaCac.getSensorVl();// Leitura de valor de emperatura externa a posteriori
                    contador = 0;
                }

                //Estatdo das entradas permanecem inalterados
                flagTemp = 'F';
                flagBot = '0';

                //bot1 e bot2
                if(botaoaux == 0x00 )
                {
                    tempoValorF = HibernateRTCGet();// registra o tempo em que o aparelho foi desligado
                    tempoF[contCmnd] = tempoValorF;
                    cmndLigaDesliga[contCmnd].setComando('D', 22, 2, 18, 10, 12, 35);
                    contCmnd++;
                    //acumula o tempo do aparelho ligado evitando estouro do RTC
                    if(tempoValorF > tempoValorI)
                    tempoLigado = tempoLigado + (tempoValorF - tempoValorI);

                    // Simula comando Bluetooth para desligar aparelho
                    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3|GPIO_PIN_2|GPIO_PIN_1, GPIO_PIN_3|GPIO_PIN_2|GPIO_PIN_1);// Acende todos os LEDs
                    for(contador = 0; contador == 8000000; contador++){}
                    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3|GPIO_PIN_2|GPIO_PIN_1, 0);// Apaga todos os LEDs

                    estados = 'a';// estado E-spra
                }else

                // bot 1 ou bot2 ou VariaTempEx -> permanece em E-spra
                if(tempAjst == 0x10 | tempAjst == 0x01 && (tempAtual1 != tempAtual2))// Havendo algura aleteração nas entradas
                {
                    estados = 'd';// estado E-cmnd
                }else

                if(UARTCharsAvail(UART0_BASE))// Verifica se há dado no Rx do UART
                {
                    estados = 'c';// estado E-cmnc
                }else

                estados = 'l';// estado E-cntrl
                break;
            }
            case 'd'://E-cnmd
            {
                if(tempAjst == 0x10)// Botão reduz temperatura pressionado
                {
                    flagBot = 'R';// indica evento de redução de temperatura

                    // Insere nó na última posição da fila com data e hora constantes
                    log.insertAfterLast(1, flagTemp,  flagBot, 23, 3, 8, 17, 30, 34);

                    // Simula comando Bluetooth para o aparelho aumentar  temperatura
                    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3|GPIO_PIN_2|GPIO_PIN_1, 0);
                    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3, GPIO_PIN_3);// acende led azul

                    estados = 'l';// estado E-cntrl
                }else
                if(tempAjst == 0x01)// Botão aumenta temperatura pressionado
                {
                    flagBot = 'A';// indica evento de aumento de temperatura

                    // Insere nó na última posição da fila com data e hora constantes
                    log.insertAfterLast(1, flagTemp,  flagBot, 22, 2, 8, 17, 30, 34);

                    // Simula comando Bluetooth para o aparelho reduzir  temperatura
                    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3|GPIO_PIN_2|GPIO_PIN_1, 0);
                    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_2, GPIO_PIN_2);// ascende led verde

                    estados = 'l';// estado E-cntrl
                }else
                if(tempAtual2 != tempAtual2)
                {
                    flagTemp = 'T'; // indica evento de ajuste de temperatura devido temperatura externa

                    // Insere nó na última posição da fila com data e hora constantes
                    log.insertAfterLast(1, flagTemp,  flagBot, 22, 3, 8, 17, 30, 34);

                    // Simula comando Bluetooth para o aparelho ajuste de temperatura de acordo com temperatura externa
                    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_3|GPIO_PIN_2|GPIO_PIN_1, 0);
                    GPIOPinWrite(GPIO_PORTF_BASE, GPIO_PIN_1, GPIO_PIN_1);// ascende led vermelho

                    estados = 'l';// estado E-cntrl
                }else
                if(UARTCharsAvail(UART0_BASE))// Verifica sehá dado no Rx do UART
                {
                    estados = 'c';// estado E-cmnc
                }

                estados = 'l';// estado E-cntrl
                break;
            }
            case 'c'://E-cmnc
            {
                int quantidadeNos;
                uartCac.SerialRead(R);// Realiza leitura do buffer de RX da uart.

                if(R[0] == 0x6c)// caractere l
                {
                    for(quantidadeNos = 0; quantidadeNos < (log.countAll()); quantidadeNos++)
                    {
                        // remove o primeiro nó da fila e retorna seus valores pata o buffer de transmissão
                        log.getRemoveFirst(T[0], T[1],T[2], T[3], T[4], T[5], T[6],T[7], T[8]);

                        // transmite os dados do buffer de transmissão para o TX da Uart.
                        for (index = 0; index < 9; index++)
                        {
                            uartCac.SerialWrite(T[index]);
                            T[index] = 0;// Limpa o buffer de transmissão
                        }
                    }

                }else
                if(R[0] == 0x63)// caractere c
                {
                    SendUint32_tAsChar(tempoLigado);
                    index = 0;
                    while(cmndLigaDesliga[index].getComando() > '0')
                    {
                        char a, me, d, h, mi, s;
                        tempCmd = cmndLigaDesliga[index].getComando();
                        cmndLigaDesliga[index].getDataHora(a, me, d, h, mi, s);
                        SendUint32_tAsChar(tempoF[index]);
                        SendUint32_tAsChar(tempoI[index]);
                        uartCac.SerialWrite(tempCmd);
                        uartCac.SerialWrite(a);
                        uartCac.SerialWrite(me);
                        uartCac.SerialWrite(d);
                        cmndLigaDesliga[index].setComando(0, 0, 0, 0, 0, 0, 0);// Limpa o buffer de transmissão
                        tempoF[index] = 0;
                        tempoI[index] = 0;
                        index++;
                    }


                }

                // Limpa o buffer de recepção
                for(index = 0; index < sizeof(R); index++)
                R[index] = 0;

                estados = 'a';// estado E-spra
                break;
            }
        }
    }
}

void SendUint32_tAsChar(uint32_t inteiro)
{
    char tempChar = (char)inteiro;
    uartCac.SerialWrite(tempChar);
    tempChar = (char)(inteiro >>8);
    uartCac.SerialWrite(tempChar);
    tempChar = (char)(inteiro >>8);
    uartCac.SerialWrite(tempChar);
    tempChar = (char)(inteiro >>8);
    uartCac.SerialWrite(tempChar);
}
