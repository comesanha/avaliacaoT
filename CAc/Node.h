/*
 * Node.h
 *
 *  Created on:
 *      Author:
 */

#ifndef NODE_H
#define NODE_H

#include "clockcalendar.h"

class Node {

    char id;
    char adjustTemperaturaExt;
    char buttonStatus;// verificar a possibilidade de utilizar apenas uma variável
    ClockCalendar dtHr;
    Node* next;

  public:

    Node(char idnum, char adjTempExt, char butStt, Node* nxt,char anew, char menew, char dnew, char hnew,char minew, char snew);
    char getID();
    char getadjustTemperaturaExt();
    char getButtonStatus();
    void getDataHora(char &a, char &me, char &d, char &h,char &mi, char &s);// para uC
    char showDataHora();// para host
    Node* getNext();
    void setNext(Node* nxt);
};



#endif /* NODE_H */
