/*
 * calendar.h
 *
 *  Created on: 10 de mar de 2022
 *      Author: rapha
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
