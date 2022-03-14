/*
 * Sensor.cpp
 *
 *  Created on: 10 de mar de 2022
 *      Author: rapha
 */


#ifndef SENSOR_CPP
    #define SENSOR_CPP

#include "Sensor.h"

int Sensor::getID(){
    return identificacao;
}

void Sensor::setID(int newID){
    identificacao = newID;
}

float Sensor::getValor(){
    return valor;
}

void Sensor::setValor(float newValor){
    valor = newValor;
}


#endif /* SENSOR_CPP */
