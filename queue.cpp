/********************************************************************************************
  * File:   queue.cpp
 * Author: Raphael Comesanha 
 * Adapted from Class List stores Nodes (class Node) in a linked list of Eduardo 
 * Bezerra.
 * Function: This file has the implementation for class Queue that is definition for a
 * queue of temperature data log , having the following operations:
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

void Queue::listSelect()// Lista todos os valores da fila.
{
  int inicialAno, inicialMes, inicialDia, finalAno, finalMes,finalDia;
  Node* aux = head;
  std::cout << "\nOs registros ocorridos nesse intervalo foram:\n" << std::endl;
  char anew, menew, dnew, hnew, minew, snew;
  //int registrosEncontrados[];
  int numeroAnos, numeroMes,i;
  i = 0;
  std::cout << "\n\nDATA INICIAL DE BUSCA" << std::endl;
  std::cout << "Digite o dia: ";
  std::cin >> inicialDia;
  std::cout << "Digite o mes: ";
  std::cin >> inicialMes;
  std::cout << "Digite o ano: ";
  std::cin >> inicialAno;
  std::cout << "\n\nDATA FINAL DE BUSCA" << std::endl;
  std::cout << "Digite o dia: ";
  std::cin >> finalDia;
  std::cout << "Digite o mes: ";
  std::cin >> finalMes;
  std::cout << "Digite o ano: ";
  std::cin >> finalAno;
  numeroAnos = finalAno - inicialAno;
  numeroMes = finalMes - inicialMes;
  std::cout << " \nO resultado para a busca no intervalo de datas entre " << inicialDia << "/" << inicialMes << "/" << inicialAno << " e " << finalDia << "/" << finalMes << "/" << finalAno << " e': \n\n";
  if(numeroAnos == 0)// busca em um mesmo ano
  {
    if (numeroMes == 0)// busca em um mesmo mês
    {
      aux = head;
      while (aux != 0)// análise de todos os dados para filtrar 
      {
        aux->getDataHora(anew, menew, dnew, hnew, minew, snew);
        if((dnew >= (char)inicialDia) & (dnew <= (char)finalDia) & (menew == (char)inicialMes) & (anew == (char)inicialAno))
        {
          std::cout << aux->getID() << ", " << aux->getadjustTemperaturaExt() << " e " << aux->getButtonStatus();
          aux->showDataHora();
        }
        aux = aux->getNext();
      }       
    }
    if (numeroMes > 0)// busca em mais de um mês no memso ano
    {
      aux = head;
      // Primeiro mês
      while (aux != 0)// análise de todos os dados para filtrar
      {
        aux->getDataHora(anew, menew, dnew, hnew, minew, snew);
        if ((dnew >= (char)inicialDia) & (dnew <= (char)30) & (menew == (char)inicialMes) & (anew == (char)inicialAno))
        {
          std::cout << aux->getID() << ", " << aux->getadjustTemperaturaExt() << " e " << aux->getButtonStatus();
          aux->showDataHora();
        }
        aux = aux->getNext();
      }
      // meses intermediários
      int mesbuscado = inicialMes + 1;
      while ((mesbuscado > inicialMes) & (mesbuscado < finalMes))
      {
        aux = head;
        while (aux != 0)// análise de todos os dados para filtrar
        {
          aux->getDataHora(anew, menew, dnew, hnew, minew, snew);
          if ((dnew >= (char)1) & (dnew <= (char)30) & (menew == (char)mesbuscado) & (anew == (char)inicialAno))
          {
            std::cout << aux->getID() << ", " << aux->getadjustTemperaturaExt() << " e " << aux->getButtonStatus();
            aux->showDataHora();
          }
          aux = aux->getNext();
        }
        mesbuscado++;
      }
      // último mês.
      aux = head;
      while (aux != 0)// análise de todos os dados para filtrar
      {
        aux->getDataHora(anew, menew, dnew, hnew, minew, snew);
        if ((dnew >= (char)1) & (dnew <= (char)finalDia) & (menew == (char)finalMes) & (anew == (char)inicialAno))
        {
          std::cout << aux->getID() << ", " << aux->getadjustTemperaturaExt() << " e " << aux->getButtonStatus();
          aux->showDataHora();
        }
        aux = aux->getNext();
      }
    }
  }
  if(numeroAnos > 0)// Mais de um ano
  {
    // Primeiro mês do primeiro ano
    aux = head;
    while (aux != 0)// análise de todos os dados para filtrar
    {
      aux->getDataHora(anew, menew, dnew, hnew, minew, snew);
      if ((dnew >= (char)inicialDia) & (dnew <= (char)30) & (menew == (char)inicialMes) & (anew == (char)inicialAno))
      {
        std::cout << aux->getID() << ", " << aux->getadjustTemperaturaExt() << " e " << aux->getButtonStatus();
        aux->showDataHora();
      }
      aux = aux->getNext();
    }
    //meses posteriores ao primeiro do primeiro ano
    aux = head;
    while (aux != 0)// análise de todos os dados para filtrar
    {
      aux->getDataHora(anew, menew, dnew, hnew, minew, snew);
      if ((dnew >= (char)1) & (dnew <= (char)30) & (menew > (char)inicialMes) & (anew == (char)inicialAno))
      {
        std::cout << aux->getID() << ", " << aux->getadjustTemperaturaExt() << " e " << aux->getButtonStatus();
        aux->showDataHora();
      }
      aux = aux->getNext();
    }
    // meses e anos intermediários
    int anobuscado = inicialAno + 1;
    while ((anobuscado > inicialAno) & (anobuscado < finalAno))
    {
      aux = head;
      while (aux != 0)// análise de todos os dados para filtrar
      {
        aux->getDataHora(anew, menew, dnew, hnew, minew, snew);
        if ((dnew >= (char)1) & (dnew <= (char)30) & (menew >= (char)1) & (menew <= (char)12) & (anew == (char)anobuscado))
        {
          std::cout << aux->getID() << ", " << aux->getadjustTemperaturaExt() << " e " << aux->getButtonStatus();
          aux->showDataHora();
        }
        aux = aux->getNext();
      }
      anobuscado++;
    }
    // meses anteriores ao último do ano final
    aux = head;
    while (aux != 0)// análise de todos os dados para filtrar
    {
      aux->getDataHora(anew, menew, dnew, hnew, minew, snew);
      if ((dnew >= (char)1) & (dnew <= (char)finalDia) & (menew < (char)finalMes) & (anew == (char)finalAno))
      {
        std::cout << aux->getID() << ", " << aux->getadjustTemperaturaExt() << " e " << aux->getButtonStatus();
        aux->showDataHora();
      }
      aux = aux->getNext();
    }// último mês do último ano
    aux = head;
    while (aux != 0)// análise de todos os dados para filtrar
    {
      aux->getDataHora(anew, menew, dnew, hnew, minew, snew);
      if ((dnew >= (char)1) & (dnew <= (char)finalDia) & (menew == (char)finalMes) & (anew == (char)finalAno))
      {
        std::cout << aux->getID() << ", " << aux->getadjustTemperaturaExt() << " e " << aux->getButtonStatus();
        aux->showDataHora();
      }
      aux = aux->getNext();
    }
  }
  std::cout << " \nBusca Finalizada!" << std::endl;
}

void Queue::listAll()// Lista todos os valores da fila.
{
  Node* aux = head;
  std::cout << "\nOs elementos atuais da fila sao:\n" << std::endl;
  while (aux != 0)
  {
   std::cout << aux->getID() << ", " << aux->getadjustTemperaturaExt() << " e " << aux->getButtonStatus();
   aux->showDataHora();
   aux = aux->getNext();
  }
}

#endif //QUEUE_CPP