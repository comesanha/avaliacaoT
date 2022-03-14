/*
 * comandoAr.cpp
 *
 *  Created on:
 *      Author:
 */


#ifndef NODE_CPP
#define NODE_CPP


#include "ComandoAr.h"

// Constructor - initializes the objects
//
ComandoAr::ComandoAr(){
       comando = 0;
}

char ComandoAr::getComando()
{
     return comando;
}

void ComandoAr::setComando(char newComando,char anew, char menew, char dnew, char hnew,char minew, char snew)
{
    comando = newComando;
    dtHr.setClockCalendar(anew, menew, dnew, hnew, minew, snew);
}

// get hour returns the char value stored in the object
//
void ComandoAr::getDataHora(char &newa, char &newme, char &newd, char &newh, char &newmi, char &news)
{
     dtHr.getClockCalendar(newa, newme, newd, newh, newmi, news);
}

void ComandoAr::showDataHora()// para host
{
     dtHr.showClockCalendar();
}

#endif /* NODE_CPP */


