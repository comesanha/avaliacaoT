/*
 * clockcalendar.h
 *
 *  Created on: 10 de mar de 2022
 *      Author: rapha
 */

#ifndef CLOCKCALENDAR_H
    #define CLOCKCALENDAR_H

#include <iostream>
#include <iomanip>
#include "clock.h"
#include "calendar.h"


class ClockCalendar : public Clock, public Calendar {
public:
    ClockCalendar ();
    void setClockCalendar (char newa, char newme, char newd, char newh,char newmi, char news);  // host e uC
    void getClockCalendar(char &a, char &me, char &d, char &h,char &mi, char &s);   // apenas uC
    void showClockCalendar();   // apenas host
};
#endif //CLOCKCALENDAR_H
