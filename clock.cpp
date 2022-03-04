/*Programm Name: clock.cpp
* Author: Raphael Comesanha
* Fonte: https://gse.ufsc.br/bezerra/disciplinas/cpp/aulas/dia1_9_4.html
* Functionality: Avaliação 1 PSE
* Date: 10/12/21
* Last Update:
* Daea Update:
* Author Update:
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