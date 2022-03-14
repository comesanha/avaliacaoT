/*
 * clock.cpp
 *
 *  Created on: 10 de mar de 2022
 *      Author:
 */

#ifndef CLOCK_CPP
      #define CLOCK_CPP

#include "clock.h"
//#include <ctime> // biblioteca de tempo



Clock::Clock ()
{
      hora = 0;
      minuto = 0;
      segundo = 0;
}

void Clock::setClock (char h,char mi, char s)// racebe os valores da UART (host) ou do RTC (uC)
{
      hora = h;
      minuto = mi;
      segundo = s;
}


#endif //CLOCK_CPP


