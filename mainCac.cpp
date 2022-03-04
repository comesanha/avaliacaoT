/********************************************************************************************
  * File:   mainTest.cpp
 * Author: Raphael Comesanha. 
 * Adapted from Augusto Bezerra Test program for Node and list classes.
 * Function: This file has the Test program for Node and queue classes.
 * Created on Fevereiro de 2022.
 * Last Modification:
 * Author Modification: 
 * Modified on
 * 
 * # Compilado no windows 10 PowerShell
 * # Linha de comando: g++ -o test Node.h
 **********************************************************************************************/
#include <iostream>
#include "queue.cpp"
#include "serial_uart.cpp"
using namespace std;

int main()
{

  Queue log1;
  Serial uart1;

  int saida, tempoLigadoHs, tempoLigadoMin;//, i;
  char sentId, sentTempEvent, sentButtonEvent, ano, mes, dia, hora, minuto, segundo;
  int menu = 0;
  
  //i = 0;

  while(menu < 3)
  {
    cout << "++++++++++++++++++++MENU+++++++++++++++++++++" << endl;
    cout << "-------CONTROLADOR DE AR CONDICIONADO--------" << endl;
    cout << "1 - SOLICITAR LOG DE EVENTOS OU TEMPO LIGADO." << endl;
    cout << "2 - EVENTOS POR INTERVALO DE DATAS." << endl;
    cout << "3 - Sair." << endl;
    cin >> menu;

    switch(menu)
    {
      case 1: 
      {
        char commdaux = ' ';
        char dadosR[64];// buffer temporário para recebimento dos dados enviados pela uart.
        char *pD = dadosR;

        uart1.OpenSerial();
        uart1.SetSerialParameter();
        commdaux = uart1.SerialWrite();

        // ETAPA DE RECEPÇÃO FUNCIONANDO, MAS EM FASE DE TESTE COM O uC //
        pD = uart1.SerialRead(); 
        cout << dadosR[1]  << endl;

        if (commdaux == 'l')                                              
        { /*Tratamento da construção da fila com os dados recebidos*/

          //simulação o recebimento do log para teste do código.
          log1.insertAfterLast(0x30, 0x54, 0x46, 22, 02, 27, 17, 10, 30);
          log1.insertAfterLast(0x31, 0x46, 0x54, 22, 02, 27, 17, 10, 40);
          log1.insertAfterLast(0x32, 0x54, 0x54, 22, 02, 27, 17, 10, 50);
          log1.insertAfterLast(0x30, 0x54, 0x46, 22, 02, 28, 17, 10, 30);
          log1.insertAfterLast(0x31, 0x46, 0x54, 22, 02, 28, 17, 10, 40);
          log1.insertAfterLast(0x32, 0x54, 0x54, 22, 02, 28, 17, 10, 50);
          log1.insertAfterLast(0x30, 0x54, 0x46, 22, 03, 01, 17, 10, 30);
          log1.insertAfterLast(0x31, 0x46, 0x54, 22, 03, 01, 17, 10, 40);
          log1.insertAfterLast(0x32, 0x54, 0x54, 22, 03, 01, 17, 10, 50);
          log1.insertAfterLast(0x30, 0x54, 0x46, 22, 03, 02, 17, 10, 30);
          log1.insertAfterLast(0x31, 0x46, 0x54, 22, 03, 02, 17, 10, 40);
          log1.insertAfterLast(0x32, 0x54, 0x54, 22, 04, 02, 17, 10, 50);
          log1.insertAfterLast(0x30, 0x54, 0x46, 23, 02, 01, 17, 10, 30);
          log1.insertAfterLast(0x31, 0x46, 0x54, 23, 02, 01, 17, 10, 40);
          log1.insertAfterLast(0x32, 0x54, 0x54, 23, 02, 01, 17, 10, 50);
          log1.insertAfterLast(0x30, 0x54, 0x46, 23, 03, 01, 17, 10, 30);
          log1.insertAfterLast(0x31, 0x46, 0x54, 23, 03, 02, 17, 10, 40);
          log1.insertAfterLast(0x32, 0x54, 0x54, 24, 03, 02, 17, 10, 50);
          log1.listAll();
          cout << "Log carregado com sucesso!\n" << endl;
        }
       
        if (commdaux == ' '){}// não executa nada

        if (commdaux == 'c')
        {
          /*Tratamento da construção do filtro de tempo ligado por data*/

          // simula o recebimento do valor de tempo ligado utilizando constantes
          tempoLigadoHs = 17;
          tempoLigadoMin = 7;
          cout << "\nO tempo em que o ar permaneceu ligado foi de " << tempoLigadoHs << " horas e " << tempoLigadoMin << " minutos" << endl;
        }
        
        
        uart1.CloseSerial();
        break;
      } 
      case 2:log1.listSelect();break;
        //cout << "Os eventos ocorridos nesse periodo foram: " << endl;
        //log1.listAll();
      case 3: 
      {
        cout << "Sistema Finalizado." << endl;
        break;
      }
      default: cout << "Funcao inexistente!\n\n Tente nomamente." << endl; menu = 0;
    }
    
  }

return 0 ;
  
}

