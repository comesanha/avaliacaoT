/*Programm Name: clock.h
* Author: Raphael Comesanha
* Fonte: https://gse.ufsc.br/bezerra/disciplinas/cpp/aulas/dia1_9_4.html
* Functionality: Avaliação 1 PSE
* Date: 09/12/21
* Last Update:Clok
* Daea Update:
* Author Update:
*/

#ifndef CLOCK_H
      #define CLOCK_H

class Clock { 
      protected: 
            char hora, minuto, segundo;
            Clock ();
            void setClock (char h,char mi, char s);// racebe os valores da UART (host) ou do RTC (uC)
};
#endif //CLOCK_H