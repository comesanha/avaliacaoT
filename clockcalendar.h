/*Programm Name: clockcalendar.h
* Author: Raphael Comesanha
* Fonte: nota de Aula
* Functionality: Avaliação 1 PSE
* Date: 10/12/21
* Last Update:
* Daea Update:
* Author Update:
*/

#ifndef CLOCKCALENDAR_H
	#define CLOCKCALENDAR_H

#include "clock.cpp"
#include "calendar.cpp"


class ClockCalendar : public Clock, public Calendar {
public:
	ClockCalendar ();
	void setClockCalendar (char newa, char newme, char newd, char newh,char newmi, char news);	// host e uC
	void getClockCalendar(char &a, char &me, char &d, char &h,char &mi, char &s);	// apenas uC
	void showClockCalendar();	// apenas host
};
#endif //CLOCKCALENDAR_H