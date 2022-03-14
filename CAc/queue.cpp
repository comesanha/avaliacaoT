/*
 * queue.cpp
 *
 *  Created on: 10 de mar de 2022
 *      Author: rapha
 */

#ifndef QUEUE_CPP
      #define QUEUE_CPP

#include "queue.h"
Queue::Queue()// inicializa a fila do log.
{
   head = 0;
}

Queue::~Queue() // esvazia a fila inteira sem retornar valores dos nós
{
  Node* cursor = head;
  while(head)
  {
    cursor = cursor->getNext();
    delete head;
    head = cursor;
  }
  head = 0; // Officially empty
}

void Queue::insertAfterLast(char idnum, char adjTempExt, char butStt, char anew, char menew, char dnew, char hnew,char minew, char snew)// Ineser nó na última posição da fila
{
  Node* p = head;
  Node* q = head;

  if (head == 0)// não há nó na fila
     head = new Node(idnum, adjTempExt, butStt, head, anew, menew, dnew, hnew, minew, snew);// insere o primeiro nó
  else
  {
     while (q != 0)// Há nó na fila.
     {
        p = q;
        q = p->getNext();
     }
     p->setNext(new Node(idnum, adjTempExt, butStt, 0, anew, menew, dnew, hnew, minew, snew));// insere o novo nó na última posição.
  }
}

void Queue::getRemoveFirst(char &idnum, char &adjTempExt, char &butStt, char &anew, char &menew, char &dnew, char &hnew,char &minew, char &snew)// remove o primeiro nó da fila e retorna seu valor
{
  if (head != 0)
  {
     std::cout << "Removendo o no de endereco: " << head << " da fila." << std::endl;
     std::cout << "Contendo os valores: " << head->getID() << ", " << head->getadjustTemperaturaExt() << " e " << head->getButtonStatus() << std::endl;
     idnum = head->getID();
     adjTempExt = head->getadjustTemperaturaExt();
     butStt = head->getButtonStatus();
     head->getDataHora(anew, menew, dnew, hnew, minew, snew);
     Node* oldHead = head;
     head = head->getNext();
     delete oldHead;// libera o espaço de memória criado.
  }

}

int Queue::countAll()// Lista todos os valores da fila.
{
  Node* aux = head;
  int numNos = 0;
  //std::cout << "\nOs elementos atuais da fila sao:\n" << std::endl;
  while (aux != 0)
  {
      numNos++;
      aux = aux->getNext();
  }
  return numNos;
}

#endif //QUEUE_CPP


