/*
 * Sensor.h
 *
 *  Created on: 10 de mar de 2022
 *      Author: rapha
 */

#ifndef SENSOR_H_
#define SENSOR_H_

class Sensor {
        int identificacao;
        float valor;
    protected:
        int getID();
        void setID(int);
        float getValor();
        void setValor(float);
        virtual void readSensor() = 0;      // funcao virtual pura
};



#endif /* SENSOR_H_ */
