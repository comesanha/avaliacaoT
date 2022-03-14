/*
 * Temperatura.cpp
 *
 *  Created on: 10 de mar de 2022
 *      Author: rapha
 */


#ifndef TEMPERATURA_CPP
#define TEMPERATURA_CPP


#include "Temperatura.h"


Temperatura::Temperatura()
{
    setValor(0.0);
    setID(0001624);
    tempValor = 0;

    SysCtlPeripheralEnable(SYSCTL_PERIPH_ADC0);                 // Habilita o periférico ADC
    while(!SysCtlPeripheralReady(SYSCTL_PERIPH_ADC0)){};        //Aguarda a habilitar periférico. Evita falha no barramento.

    // Configuração dos sequenciadores de amostras do ADC.//
    // Configura ADC0, sequenciador de amostras 1 (4 amostras), gatilho de sequência mediada pelo processador e maior prioridade.
    ADCSequenceConfigure(ADC0_BASE, 1, ADC_TRIGGER_PROCESSOR, 0);
    // Etapas 0, 1 e 2 do sequenciador 1, medir sensor de temperatura on chip.
    ADCSequenceStepConfigure(ADC0_BASE, 1, 0, ADC_CTL_TS);
    ADCSequenceStepConfigure(ADC0_BASE, 1, 1, ADC_CTL_TS);
    ADCSequenceStepConfigure(ADC0_BASE, 1, 2, ADC_CTL_TS);
    // Etapa 3 (final) do sequenciador de amostras 1, medir sensor de temperatura on chip,
    // habilita interrupção para ocorrer ao final dessa amostra, indica a lógica do ADC
    //que essa será a última amostra
    ADCSequenceStepConfigure(ADC0_BASE,1,0,ADC_CTL_TS|ADC_CTL_IE|ADC_CTL_END);
    ADCSequenceEnable(ADC0_BASE, 1);//Habilita o sequenciador de amostras 1 do ADC
}

void Temperatura::setSensorId(int id)
{
    setID(id);
}

int Temperatura::getSensorId()
{
    return getID();
}

float Temperatura::getSensorVl()
{
    return getValor();
}

void Temperatura::readSensor()
{
    //Realiza a captura do valor medido do sensro de temperatura
    ADCIntClear(ADC0_BASE, 1);// Limpa a flag da interrupção
    ADCProcessorTrigger(ADC0_BASE, 1);// Ativa o gatilho do ADC por software. Inicia a conversão.
    while(!ADCIntStatus(ADC0_BASE, 1, false))// Aguarda a conclusão da conversão no sequenciador 1.
    {}// false indica que a interrupção não está mascarada para o processador.
    ADCSequenceDataGet(ADC0_BASE, 1, &tempValor);// Armazena as amostras do sequenciador a variável.
    setValor((float)tempValor);

}


#endif /* TEMPERATURA_CPP */
