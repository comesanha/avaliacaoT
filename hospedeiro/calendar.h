/*Programm Name: calendar.h
* Author: Raphael Comesanha
* Fonte: https://gse.ufsc.br/bezerra/disciplinas/cpp/aulas/dia1_9_4.html
* Functionality: Avaliaçao 1 PSE
* Date: 10/12/21
* Last Update:
* Daea Update:
* Author Update:
*/

#ifndef CALENDAR_H
	#define CALENDAR_H

class Calendar {
protected:
	char dia, mes, ano;
	Calendar();
	void setCalendar (char a, char me, char d);// racebe os valores da UART (host) ou do RTC (uC)
};

#endif // CALENDAR_H