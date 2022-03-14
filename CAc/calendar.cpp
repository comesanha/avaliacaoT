/*
 * calendar.cpp
 *
 *  Created on: 10 de mar de 2022
 *      Author: rapha
 */


#ifndef CALENDAR_CPP
      #define CALENDAR_CPP

#include "calendar.h"

Calendar::Calendar()
{
      dia = 0;
      mes = 0;
      ano = 0;
}

void Calendar::setCalendar(char a, char me, char d)// racebe os valores da UART (host) ou do RTC (uC)
{
      dia = d;
      mes = me;
      ano = a;
}

#endif // CALENDAR_CPP

