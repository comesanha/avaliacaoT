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
  unsigned char menu = '0';
  
  while(menu != '3')
  {
    cout << "++++++++++++++++++++MENU+++++++++++++++++++++" << endl;
    cout << "-------CONTROLADOR DE AR CONDICIONADO--------" << endl;
    cout << "1 - SOLICITAR LOG DE EVENTOS OU TEMPO LIGADO." << endl;
    cout << "2 - EVENTOS POR INTERVALO DE DATAS." << endl;
    cout << "3 - Sair." << endl;
    cin >> menu;

    switch(menu)
    {
      case '1': 
      {
        char commdaux;
        unsigned char dadosR[9] = {0};// buffer temporário para recebimento dos dados enviados pela uart.
        
        uart1.OpenSerial();
        uart1.SetSerialParameter();
        uart1.SerialWrite(commdaux);

        if (commdaux == 'l')                                              
        { /*Tratamento da construção da fila com os dados recebidos*/
          // ETAPA DE RECEPÇÃO FUNCIONANDO, MAS EM FASE DE TESTE COM O uC //
          uart1.SerialRead(dadosR);
          cout << " O dado recebido foi: " << dadosR[0] << dadosR[1] << dadosR[2] <<
              dadosR[4] << dadosR[5] << dadosR[6] << dadosR[7] << dadosR[8] << endl;
          dadosR[0] = dadosR[1] = dadosR[2] = dadosR[4] = dadosR[5] = dadosR[6] = dadosR[7] = dadosR[8] = 0;

                    
        }
        if (commdaux == 'c')
        {
          /*Tratamento da construção do filtro de tempo ligado por data*/
          uart1.SerialRead(dadosR);
          // simula o recebimento do valor de tempo ligado utilizando constantes
          tempoLigadoHs = 17;
          tempoLigadoMin = 7;
          cout << "\nO tempo em que o ar permaneceu ligado foi de " << tempoLigadoHs << " horas e " << tempoLigadoMin << " minutos" << endl;

        }
                
        uart1.CloseSerial();
        break;
      }
      case '2':log1.listSelect();break;
        //cout << "Os eventos ocorridos nesse periodo foram: " << endl;
        //log1.listAll();

      case '3':
      { 
        cout << "Sistema Finalizado." << endl;
        break;
      }

      default:
      {
        cout << "Funcao inexistente! Tente nomamente.\n" << endl;
        cout << "++++++++++++++++++++MENU+++++++++++++++++++++" << endl;
        cout << "-------CONTROLADOR DE AR CONDICIONADO--------" << endl;
        cout << "1 - SOLICITAR LOG DE EVENTOS OU TEMPO LIGADO." << endl;
        cout << "2 - EVENTOS POR INTERVALO DE DATAS." << endl;
        cout << "3 - Sair." << endl;
        cin >> menu;
      }
    }
    
  }

return 0 ;
  
}

