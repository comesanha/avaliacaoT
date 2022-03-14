/*
 * Temperatura.h
 *
 *  Created on: 10 de mar de 2022
 *      Author: rapha
 */

#ifndef TEMPERATURA_H_
    #define TEMPERATURA_H_

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

#include "Sensor.h"

class Temperatura : public Sensor {
    uint32_t tempValor;
    public:
        Temperatura();
        void setSensorId(int id);
        int getSensorId();
        float getSensorVl();
        void readSensor();

};



#endif /* TEMPERATURA_H_ */
