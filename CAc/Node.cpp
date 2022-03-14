/*
 * Node.cpp
 *
 *
 *      Author:
 */


#ifndef NODE_CPP
#define NODE_CPP


#include "Node.h"

// Constructor - initializes the node
//
Node::Node(char idnum, char adjTempExt, char butStt, Node* nxt, char anew, char menew, char dnew, char hnew,char minew, char snew){
       id = idnum;
       adjustTemperaturaExt = adjTempExt;
       buttonStatus = butStt;
       dtHr.setClockCalendar(anew, menew, dnew, hnew, minew, snew);
       next = nxt;
}

// get controler ID, returns the char value stored in the node
//
char Node::getID()
{
     return id;
}

// get extern temperature adjust, returns the char value stored in the node
//
char Node::getadjustTemperaturaExt()
{
     return adjustTemperaturaExt;
}

// get button status, returns the char value stored in the node
//
char Node::getButtonStatus()
{
     return buttonStatus;
}

// get hour returns the char value stored in the node
//
void Node::getDataHora(char &newa, char &newme, char &newd, char &newh, char &newmi, char &news)
{
     dtHr.getClockCalendar(newa, newme, newd, newh, newmi, news);
}

char Node::showDataHora()// para host
{
     dtHr.showClockCalendar();
}

// getNext returns a pointer for the next node in the linked list
//
Node* Node::getNext(){
     return next;
}

// setNext stores the pointer to the next node in the list in the "next" field
//
void Node::setNext(Node* nxt){
       next = nxt;
}


#endif /* NODE_CPP */
