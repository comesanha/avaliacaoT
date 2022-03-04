/********************************************************************************************
  * File:   Node.h
 * Author: Raphael Comesanha
 * Adapted from Class Node stores integer values for a linked list.Eduardo Augusto Bezerra
 * Function: Class Node stores ID, occurred events and hour/data values for a queue. This file 
 * has the Node's interface (header file).
 * Created on Fevereiro de 2022.
 * Last Modification:
 * Author Modification: 
 * Modified on
 * 
 **********************************************************************************************/

#include <string>
#include "clockcalendar.cpp"

class Node {
    // string temperat;
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
