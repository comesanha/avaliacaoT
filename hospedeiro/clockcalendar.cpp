/*Programm Name: 

* Author: Raphael Comesanha
* Fonte: https:Nota de Aula
* Functionality: Avaliação 1 PSE
* Date: 12/12/21
* Last Update:
* Daea Update:
* Author Update:
*/

#ifndef CLOCKCALENDAR_CPP
    #define CLOCKCALENDAR_CPP

#include "clockcalendar.h"
#include <iostream>
#include <iomanip>

ClockCalendar::ClockCalendar () : Clock (), Calendar () {}

void ClockCalendar::setClockCalendar(char newa, char newme, char newd, char newh,char newmi, char news)
{// recebe data e hora para o nó da UART (host) ou do RTC (uC)
	setClock (newh, newmi, news);
	setCalendar(newa, newme, newd);
}

void ClockCalendar::showClockCalendar()// mostra data e hora do nó na IHM (host)
{
	std::cout << " - " << (int)dia << "/" << (int)mes << "/" << (int)ano << " - " << (int)hora << ":" << (int)minuto << ":"<< (int)segundo << std::endl;
}

void ClockCalendar::getClockCalendar(char &a, char &me, char &d, char &h,char &mi, char &s)// apenas Uc
{
    // Consulta os valores de data e hora e passa às variáveis da função
    d = dia;
    me = mes;
    a = ano;
    h = hora;
    mi = minuto;
    s = segundo;
}

#endif // CLOCKCALENDAR_CPP