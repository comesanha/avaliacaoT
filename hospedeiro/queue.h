/********************************************************************************************
  * File:   queue.h
 * Author: Raphael Comesanha
 * Adapted from Eduardo Augusto Bezerra Class List stores Nodes (class Node) in a linked list.
 * Function: This file has the implementation for class queue. Class definition for a linked 
 * list, having the following operations:
 *    1. Initialize the queue to an empty queue.
 *    2. Free the nodes of a queue.
 *    3. Determine whether a queue is empty.
 *    4. Add a node with a given value to the end of the queue.
 *    7. Delete the first node from the list retusning it value.
 * Created on Fevereiro de 2022.
 * Last Modification:
 * Author Modification: 
 * Modified on
 * 
 * # Compilado no windows 10 PowerShell
 * # Linha de comando: g++ -o test Node.h
 **********************************************************************************************/

#ifndef QUEUE_H
      #define QUEUE_H

#include "Node.cpp"

class Queue {

  Node* head;

public:
  Queue();
  ~Queue();
  void insertAfterLast(char idnum, char adjTempExt, char butStt, char anew, char menew, char dnew, char hnew, char minew, char snew);
  void getRemoveFirst(char &idnum, char &adjTempExt, char &butStt, char &anew, char &menew, char &dnew, char &hnew,char &minew, char &snew);
  void listSelect();
  void listAll();
};



#endif //QUEUE_H