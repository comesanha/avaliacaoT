/*
 * digPort.h
 *
 *  Created on: 10 de mar de 2022
 *      Author:
 */

#ifndef DIGPORT_H_
    #define DIGPORT_H_

#include <iostream>
#include <stdint.h>
#include <stdbool.h>
#include "inc/tm4c123gh6pm.h"
#include "inc/hw_memmap.h"
#include "inc/hw_types.h"
#include "driverlib/sysctl.h"
#include "driverlib/gpio.h"
#include "driverlib/debug.h"
#include "driverlib/pin_map.h"
#include "inc/hw_gpio.h"




class DigPort {

    uint8_t estadoBotoes;
public:
    DigPort();
  ~DigPort();
  uint8_t GetBotoes();

};


#endif /* DIGPORT_H_ */
