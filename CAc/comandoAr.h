/*
 * comandoAr.h
 * Send command to host as a char data, with date.
 *  Created on:
 *      Author:
 */

#ifndef COMANDOAR_H_
#define COMANDOAR_H_

#include "clockcalendar.h"

class ComandoAr {

    char comando;
    ClockCalendar dtHr;

  public:

    ComandoAr();
    char getComando();
    void setComando(char newComando,char anew, char menew, char dnew, char hnew,char minew, char snew);
    void getDataHora(char &a, char &me, char &d, char &h,char &mi, char &s);// para uC

};


#endif /* COMANDOAR_H_ */
