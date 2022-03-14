/*
 * queue.h
 *
 *
 *      Author:
 */

#ifndef QUEUE_H
      #define QUEUE_H

#include "Node.h"
#include "comandoAr.h"

class Queue {

  Node* head;

public:
  Queue();
  ~Queue();
  void insertAfterLast(char idnum, char adjTempExt, char butStt, char anew, char menew, char dnew, char hnew, char minew, char snew);
  void getRemoveFirst(char &idnum, char &adjTempExt, char &butStt, char &anew, char &menew, char &dnew, char &hnew,char &minew, char &snew);
  int countAll();

};



#endif //QUEUE_H
