/*
 * clock.h
 *
 *  Created on: 10 de mar de 2022
 *      Author: rapha
 */

#ifndef CLOCK_H
      #define CLOCK_H

class Clock {
      protected:
            char hora, minuto, segundo;
            Clock ();
            void setClock (char h,char mi, char s);// racebe os valores da UART (host) ou do RTC (uC)
};
#endif //CLOCK_H
