/*Programm Name: calendar.cpp
* Author: Raphael Comesanha
* Fonte: https://gse.ufsc.br/bezerra/disciplinas/cpp/aulas/dia1_9_4.html
* Functionality: Avaliação 1 PSE
* Date: 10/12/21
* Last Update:
* Daea Update:
* Author Update:
*/

#ifndef CALENDAR_CPP
      #define CALENDAR_CPP

#include "calendar.h"
//#include <ctime> // biblioteca de tempo
#include <unistd.h>// for sleep

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