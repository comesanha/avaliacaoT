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

Queue::~Queue() // esvazia a fila inteira sem retornar valores dos n�s
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

void Queue::insertAfterLast(char idnum, char adjTempExt, char butStt, char anew, char menew, char dnew, char hnew,char minew, char snew)// Ineser n� na �ltima posi��o da fila
{
  Node* p = head;
  Node* q = head;

  if (head == 0)// n�o h� n� na fila
     head = new Node(idnum, adjTempExt, butStt, head, anew, menew, dnew, hnew, minew, snew);// insere o primeiro n�
  else
  {
     while (q != 0)// H� n� na fila.
     {
        p = q;
        q = p->getNext();
     }
     p->setNext(new Node(idnum, adjTempExt, butStt, 0, anew, menew, dnew, hnew, minew, snew));// insere o novo n� na �ltima posi��o.
  }
}

void Queue::getRemoveFirst(char &idnum, char &adjTempExt, char &butStt, char &anew, char &menew, char &dnew, char &hnew,char &minew, char &snew)// remove o primeiro n� da fila e retorna seu valor
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
     delete oldHead;// libera o espa�o de mem�ria criado.
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


