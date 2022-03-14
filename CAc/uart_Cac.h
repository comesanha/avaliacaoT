/*
 * uart_Cac.h
 *
 *  Created on:
 *      Author:
 */


#ifndef UART_CAC_H_
    #define UART_CAC_H_

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
#include "driverlib/uart.h"

#include "serial.h"

class UartCac : public Serial {

public:
    UartCac();
  ~UartCac();
  void OpenSerial();
  void SetSerialParameter();
  void SerialWrite(char &T);
  void SerialRead(char *pR);
  void CloseSerial();

};

#endif //UART_CAC_H_
